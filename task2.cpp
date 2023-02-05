/*
   Made by:
        Name:                                  ID:
        Mohamed Samy Abdelsalam Elsebaey,      20200445    S3
        Fouad Sayed Fouad Sayed,               20200384    S3
*/
// The Solution of task 2 of Ass 2
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include<algorithm>
using namespace std;
// Declare global variable (the names of the three candidates) to use it in more than function
string fir_cand,sec_cand,third_cand;
// Function to get the names of the three candidates from the user
void names_of_3_candidates() {
    cout << "Please enter the names of the three candidates: ";
    cin >> fir_cand>>sec_cand>>third_cand;
    while (fir_cand==sec_cand || fir_cand==sec_cand || sec_cand==third_cand){
        cout<<"You are not allowed to duplicate name of candidate\n";
        cout << "Please enter the names of the three candidates: ";
        cin>>fir_cand>>sec_cand>>third_cand;
    }
}
// Function to get the number of voters from the user
int number_of_voters() {
    int num;
    cout << "Please enter number of voters: ";
    cin >> num;
    return num;
}
// Declare global variable to use it in more than function
string fir_vote,sec_vote,third_vote;
// Function to get the number of voters from the user
void voter_choice(string v1,string v2,string v3) {
    cout << "Please enter your choice of three candidates in order of preference: ";
    cin >> fir_vote >> sec_vote >> third_vote;
    while ((fir_vote != v1 && fir_vote != v2 && fir_vote != v3) || (sec_vote != v1 && sec_vote != v2 && sec_vote != v3) || (third_vote != v1 && third_vote != v2 && third_vote != v3) || fir_vote == sec_vote || fir_vote == third_vote || sec_vote == third_vote) {
        cout << "Please enter names correctly in order of preference and you are not allowed to duplicate one candidate [ " << v1 << " , " << v2 << " , " << v3 << " ] : \n";
        cin >> fir_vote >> sec_vote >> third_vote;
    }
}
// Function to compute points for each candidate with the normal majority election system
void old_system(string g ,string g1,string g2 ,string g3, int &y1 ,int &y2 , int &y3) {
    if (g == g1) {
        y1++;
    }
    else if (g == g2) {
        y2++;
    }
    else if (g == g3) {
        y3++;
    }
}
// Function to compute points for each candidate with the new point system
void new_system(string na1,string na2,string na3,string ca1,string ca2,string ca3,int &k1,int &k2,int &k3) {
    if (na1 == ca1) {
        k1 += 3;
    }
    else if (na1 == ca2) {
        k2 += 3;
    }
    else if (na1 == ca3) {
        k3 += 3;
    }
    if (na2 == ca1) {
        k1 += 2;
    }
    else if (na2 == ca2) {
        k2 += 2;
    }
    else if (na2 == ca3) {
        k3 += 2;
    }
    if (na3 == ca1) {
        k1 += 1;
    }
    else if (na3 == ca2) {
        k2 += 1;
    }
    else if (na3 == ca3) {
        k3 += 1;
    }

}
// Function to compute who is winner with old system and new system and display his name
void winner(int x,int y,int z ,int a ,int b , int c,string can1,string can2,string can3) {
    int win_old, win_new;
    win_old = max(x, max(y, z));
    win_new = max(a, max(b, c));
    if (win_old == x) {
        cout << "the winner in old system is: " <<can1 << " with " << x << " Point\n";
    }
    else if (win_old == y) {
        cout << "the winner in old system is: " << can2 << " with " << y << " Point\n";
    }
    else if (win_old == z) {
        cout << "the winner in old system is: " << can3 << " with " << z << " Point\n";
    }
    if (win_new == a) {
        cout << "the winner in new system is: " << can1 << " with " << a << " Point\n";
    }
    else if (win_new == b) {
        cout << "the winner in new system is: " << can2 << " with " << b << " Point\n";
    }
    else if (win_new == c) {
        cout << "the winner in new system is: " << can3 << " with " << c << " Point\n";
    }

}
// Function to calling each function in order to know the winner in The Egyptian Sewing Syndicate
void vote() {
    names_of_3_candidates();
    int fir_old = 0, sec_old = 0, third_old = 0, fir_new = 0, sec_new = 0, third_new = 0;
    int num = number_of_voters();
    for (int i = 0; i < num; i++) {
        voter_choice(fir_cand,sec_cand,third_cand);
        old_system(fir_vote,fir_cand,sec_cand,third_cand,fir_old,sec_old,third_old);
        new_system(fir_vote,sec_vote,third_vote,fir_cand,sec_cand,third_cand,fir_new,sec_new,third_new);
    }
    winner(fir_old,sec_old,third_old,fir_new,sec_new,third_new,fir_cand,sec_cand,third_cand);
}
// the main function
int main() {
    vote();
    return 0;
}
