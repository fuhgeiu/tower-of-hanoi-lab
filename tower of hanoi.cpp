/*
program
alex carnes 6/6
*/


/*  notes
program to simulate gam of tower of hanoi
current
to create letters used in game, user enters how many letter to put in up to 25 letters
asks user to verify the board of not can enter no to reset letter range
does protect against bad data in all inputs with differnt methods
prevents getting source from emtpy and sending to destinaiton if alphabeticla order is not preserved
will ask again if data is not acceptable
will display the letter being transfered and where it is being transfered to
display the board after trasnfer is complete with an autoscaled board

autoscale board

    store size of each tower in a array after source gets transfered to dest
    sort than assign the greatest element as a variable to use in print function
*/



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void protect();                                                                   // protect data by cin.fail only
char process_C(int);                                                              // processes cin of strings
void Print(vector<char>,char &);                                                  // print board, only start
void stack(vector <char> & );                                                     // stores game  letters into vector
void verify(vector <char>,vector <char>,vector <char>,int,char &,char &,char &);  // verify tower source and destination
void LT_choice(vector<char> &, vector <char> &, vector <char> &);           // transfers data between vectors
void print_U(vector<char>,vector <char>, vector <char>);                      // print updated board


int main () {

    bool ls1 = 1;

//program loop
    while (ls1) {

//  variables and memory values to reset
//  reset letter vector and tower vector

        vector <char> T1C_vector;                   // for storing tower 1 data when plyaer input range
        vector <char> T2C_vector;                   // for storing tower 2 data when plyaer input range
        vector <char> T3C_vector;                   // for storing tower 3 data when plyaer input range

        bool ls2 = 1, ls3 =1;                 // declare variables for new game

// when beginning a game and only when restarting, print board with blank spaces
        char ls01 = '0';
        Print(T1C_vector,ls01);

// game loop
    while (ls3) {
//  to get letter stack with range input
        stack(T1C_vector);              // loop and store letter in vector
        ls01 = '1';     Print(T1C_vector, ls01);    // change prong and call function, print with letters

        if (ls01 == 'n') break;       // to print board with letters and confirm
//repeat game loop for entering in tower moves
        while (ls2) {
//      func to get and verify moving letter from a tower to another
//        verify the tower itself is in alphabetical order
//        confirm by display example | A --> T1 |
            LT_choice(T1C_vector,T2C_vector,T3C_vector);
//      display updated board
//            print_U(T1C_vector,T2C_vector,T3C_vector,maxS);

        }
    }
    }

    return 0;
}


// to protect data universal
void protect() {

    bool c = 1;
    while (c) {
        if (cin.fail()) {                       // if stream error
            cout << "incorrect input \n";
            cin.clear();                        // clears buffer
            cin.ignore();                       // ignores data from stream
        } else break;
    }
}


//function to handle all inputs of string
char process_C(int T) {
    // change value of t when calling this funciton to enable prongs
    string N,P,F;              // temopray variable to store string before process     // input string
    bool L = true;
    int R;
// 1st prong, verify board
    if (T == 003) {    //indicator that we are calling to execute a specific prong
        while (L) {    cin >> N;
            if (N == "no") {R = 'n'; break;}
            if (N == "yes") {break;}
            else cout << "enter a valid input\n"; }
    }

//  second prong,
    if (T == 004) {     // prong 2, for function handling tower inputs func.temp
        cin >> P;
        if (P == "T1" || P == "1" || P == "tower 1" || P == "t1") R = '1';
        else if (P == "T2" || P == "2" || P == "tower 2" || P == "t2") R = '2';
        else if (P == "T3" || P == "3" || P == "tower 3" || P == "t3") R = '3';
        else cout << "input not valdi\n";
    }
    return R;
}


// print new board and board with characters
void Print(vector<char> T1C_vector,char &ls01) {

    if (ls01 == '0') {                  // first prong
        // to print fresh board
        cout << " \n\n play tower of hanoi \n goal is to move all letters to T03\n "
             << "rule 1 :letters in must be in alphabetical order for each tower\n"
             << "type 'new' anytime to restart game or 'exit' to end program\n\n";

        for (int i = 0; i < 3; i++) cout << "  _    _    _  \n";          // print blank board
        cout << " T01  T02  T03  \n";
    }

    if (ls01 == '1') {                   // seocond prong

        cout << "\n";       // used to execute specific prong in the called funciton process_C
        for (int i = (T1C_vector.size()-1); i >= 0; i--) {            // to print the board with letters on left side
            cout << "  " << T1C_vector[i] << "    _    _\n";
            if (i==0) { cout << " T01  T02  T03 \n\n"; }
        }

        // comfirm if board is good
        cout << "if this board ia not correct type 'no'.if it is type 'yes' \n";
        ls01 = process_C(003);
    }

}


// to get and store letter to be used in game
void stack(vector <char> &T1C_vector) {

    T1C_vector.clear();                                   // clears vector, before new lettters loaded
    int SC;
    cout << "\nhow many letter in the stack (must be less than 25)? :";

    do { cin >> SC; protect(); if (SC < 1 || SC > 25)                   // check if int and in range
            cout << "must be a number between 1 - 25\n";}
    while (SC > 25 || SC < 1);

    for (int i = 'A'; i < (65 + SC); i++) {
        T1C_vector.push_back(static_cast <char> (i));
    }
}


// to get and verify tower choices
void verify(vector <char> T1C_vector,vector <char> T2C_vector, vector <char> T3C_vector, int W,char &T01,char &V,char &U){

    int T;       // U is from tower, V is destination tower, for T1 U/V = 1, for T2 U/V = 2
    bool ls01 = true; bool ls02 = true;     // for loop control
    if (W == 0) {
        while (ls01) {

            cout << "\nwhat tower should a letter be moved from :";
            U = process_C(004);         // gives U the value coresponding to from tower, if T1 =1,T2 =2,T3 = 3
// check if source tower is empty
            if (U == '1'){  if (T1C_vector.size() > 0) { T01 = T1C_vector.back(); break; }
                else cout << "tower is empty enter a new source\n";}
            if (U == '2'){  if (T2C_vector.size() > 0) { T01 = T2C_vector.back(); break; }
                else cout << "tower is empty enter a new source\n";}
            if (U == '3'){  if (T3C_vector.size() > 0) { T01 = T3C_vector.back(); break; }
                else cout << "tower is empty enter a new source\n"; }
        }
    }

    if (W == 1) {
        while (ls01) {

            cout << "\nwhat tower should the letter be moved to :";
            V = process_C(004);     // gives U the value coresponding to from tower, if T1 =1,T2 =2,T3 = 3
// if empty than move on, if full deny request
// check if the destination tower will still be in alphabetical order, if not deny request
            if (V == '1') {     if (T1C_vector.size() < 1) {break;}
                else if (static_cast <int>(T1C_vector.back()) > static_cast <int> (T01))
                    cout << "tower would no longer be in alphabetical order, put in new input";  else {break;}}

            if (V == '2') {     if (T2C_vector.size() < 1) {break;}
                else if (static_cast <int>(T2C_vector.back()) > static_cast <int> (T01))
                    cout << "tower would no longer be in alphabetical order, put in new input";  else {break;}}

            if (V == '3') {     if (T3C_vector.size() < 1) {break;}
                else if (static_cast <int>(T3C_vector.back()) > static_cast <int> (T01))
                    cout << "tower would no longer be in alphabetical order, put in new input";  else {break;}}
        }
    }

}


//get letter choice and tower choice, and display choice
void LT_choice(vector<char> &T1C_vector, vector <char> &T2C_vector, vector <char> &T3C_vector) {

    int W; char T01,V,U,SW;                                 // declare varibales used in this fucntion
    verify(T1C_vector,T2C_vector,T3C_vector,0,T01,V,U);   //  get starting tower uses prong indicator W

    verify(T1C_vector,T2C_vector,T3C_vector,1,T01,V,U);   //  get desitnaiton tower uses prong indicator W
// display the transfer of letter
    cout <<T01<< "-->"; if (V == '1')cout<<"T1\n\n"; else if (V == '2')cout<<"T2\n\n"; else if (V == '3')cout<<"T3\n\n";

    if (U == '1') {
        if (V == '2') { T2C_vector.push_back(T1C_vector.back()); T1C_vector.pop_back();}     // transfer T1 to T2
        if (V == '3') { T3C_vector.push_back(T1C_vector.back()); T1C_vector.pop_back();}     // transfer T1 to T3
    }
    if (U == '2') {
        if (V == '1') { T1C_vector.push_back(T2C_vector.back()); T2C_vector.pop_back();}     // transfer T2 to T1
        if (V == '3') { T3C_vector.push_back(T2C_vector.back()); T2C_vector.pop_back();}     // transfer T2 to T3
    }
    if (U == '3') {
        if (V == '1') { T1C_vector.push_back(T3C_vector.back()); T3C_vector.pop_back();}     // transfer T3 to T1
        if (V == '2') { T2C_vector.push_back(T3C_vector.back()); T3C_vector.pop_back();}     // transfer T3 to T2
    }

    print_U(T1C_vector,T2C_vector,T3C_vector);         // print board

}



// print updated board with letter moved
void print_U(vector<char> T1C_vector,vector <char> T2C_vector, vector <char> T3C_vector) {

    // to autoscale height of board
    int maxs [3];

    maxs [0] = T1C_vector.size();
    maxs [1] = T2C_vector.size();
    maxs [2] = T3C_vector.size();

    sort(maxs,maxs + 3);
    int maxS = maxs[2];

    // to prevent segmentation error
    while (T1C_vector.size() < maxS) T1C_vector.push_back(' ');
    while (T2C_vector.size() < maxS) T2C_vector.push_back(' ');
    while (T3C_vector.size() < maxS) T3C_vector.push_back(' ');

    for (int i = (maxS-1); i >= 0; i--) {                           // to print proper number of lines

        cout << "  " << T1C_vector[i] << "  ";
        cout << "  " << T2C_vector[i] << "  ";
        cout << "  " << T3C_vector[i] << "  ";
        cout << "\n";
    }
    cout << " T01  T02  T03 \n";


}


