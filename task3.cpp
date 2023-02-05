/*
   Made by:
        Name:                                  ID:
        Mohamed Samy Abdelsalam Elsebaey,      20200445    S3
        Fouad Sayed Fouad Sayed,               20200384    S3
*/
// The Solution of task 3 of Ass 2
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

int counts=0;                   //Declare a global variable  (the number of the credit card number) to use it in more than one function
unsigned long long int credit__number;   //Declare a global variable  (the credit card number) to use it in more than one function
string cre_str ;
// Function to get the credit card number from the user and compute the number of digits of the credit card number
unsigned long long int credit_number(){
    cout<<"Please enter your credit card number here: ";
    cin>>credit__number;
    counts=log10(credit__number)+1;
    while (counts>16 || counts<14){
        cout<<"Your credit card number is false (credit card number must be in range 14 to 16 number)\n";
        cout<<"Please correct your credit card number here: ";
        cin>>credit__number;
        counts=log10(credit__number)+1;
    }
    stringstream credit___number___string;
    credit___number___string<<credit__number;
    cre_str = credit___number___string.str();
}
// Function to check if the number have two digit it will sum them until it will be one digit
int check_single_digit(long int digita){
    int a,b;
    int counta=log10(digita)+1;
    a=digita;
    while(counta!=1){
        b=a%10;
        a=a/10;
        digita=a+b;
        counta=log10(digita)+1;
    }
    return digita ;
}
// Function to multiply each second digit by 2 from the right
unsigned long long int p23(unsigned long long int cred_num){
    int multi,resulto=0;
    unsigned long long int a=cred_num,b;
    for(int i =0;i<counts;i++){
        a=a/10;
        b=a%10;
        if (counts==15){
            if (i>=0 && i%2!=0){
                multi=2*b;
                resulto+=check_single_digit(multi);
            }
        } else if (counts==14 || counts==16){
            if(i>=0 && i%2==0){
                multi=2*b;
                resulto+=check_single_digit(multi);
            }
        }
    }
    return resulto;
}
//Function to Sum the digits that had not been multiplied by 2 in previous function
unsigned long long int p4(){
    int sum=0;
    if (counts==14){
        int h=1;
        for(int k=0;k<7;k++){
            sum+=(cre_str[h]-48);
            h+=2;
        }
    } else if (counts==15){
        int h=0;
        for(int k=0;k<8;k++){
            sum+=(cre_str[h]-48);
            h+=2;
        }
    }else if (counts==16){
        int h=1;
        for(int k=0;k<8;k++){
            sum+=(cre_str[h]-48);
            h+=2;
        }
    }
    return sum;
}
//function to check Credit card number validation
string validity(){
    unsigned long long int result;
    credit_number();
    result=p23(credit__number)+p4();
    if (result%10==0){
        return "true";
    } else {
        return "false";
    }
}
// the main function
int main(){
    cout<<validity()<<"\n";
    return 0;
}
