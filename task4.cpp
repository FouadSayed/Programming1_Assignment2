/*
   Made by:
        Name:                                  ID:
        Mohamed Samy Abdelsalam Elsebaey,      20200445    S3
        Fouad Sayed Fouad Sayed,               20200384    S3
*/
// The Solution of task 4 of Ass 2
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;
long double rejected=0,expenses=0;
int time__start,days__number ,time__end;
// Message to welcome the user
void welcome(){
    cout<<setw(96)<<"--------------------------------------------------------------------\n";
    cout<<setw(95)<<"Calculator to compute refund to your employee in the business trip\n";
    cout<<setw(97)<<"--------------------------------------------------------------------\n\n";
    cout<<setw(119)<<"Please answer the following questions which we are needed to compute refund to your employee in the business trip\n\n\n";
}
// Function to get The number of business trip days from the user
int days_number(){
    cout<<"How many days were spent on the trip?: ";
    cin>>days__number;
    cout<<"-----------------------------------------\n";
    while(days__number<1){
        cout<<"\n"<<setw(94)<<"You are not allowed to enter less than 1 for the number of days\n\n";
        cout<<"Please try again and enter how many days were spent on the trip here: ";
        cin>>days__number;
        cout<<"-------------------------------------------------------------------------\n";
    }
}
// Function to get The depart time on the first day
int time_start(){
    cout<<"\nwhat time did the employee depart on the first day of the trip?  \n";
    cout<<"1) Before 08:00 am\n";
    cout<<"2) Before 12:00 pm\n";
    cout<<"3) Before 06:00 pm\n";
    cout<<"Enter 1 or 2 or 3: ";
    cin>>time__start;
    while (time__start!=1 && time__start!=2 && time__start!=3){
        cout<<"Invalid Value Please Try Again: ";
        cin>>time__start;
    }
    cout<<"---------------------------------------------------------------\n\n";
}
// Function to get The arrive time in the last day
int time_end(){
    cout<<"what time did the employee arrive back home on the last day of the trip?  \n";
    cout<<"1) After 09:00 am\n";
    cout<<"2) After 01:00 pm\n";
    cout<<"3) After 07:00 pm\n";
    cout<<"Enter 1 or 2 or 3: ";
    cin>>time__end;
    while (time__end!=1 && time__end!=2 && time__end!=3){
        cout<<"Invalid Value Please Try Again: ";
        cin>>time__end;
    }
    cout<<"------------------------------------------------------------------------\n\n";
}
// Function to know How much did the plane tickets cost (if travelling by plane) from the user
long long int plane_ticket(long double &expenses_){
    cout<<"Please if you traveled by a plane Enter 1 and if you did not travel by plane Enter 0: ";
    int a,b;
    cin>>a;
    while (a!=0 && a!=1){
        cout<<"Invalid Value Please Try Again: ";
        cin>>a;
    }
    if (a==1){
        cout<<"If you traveled by plane once Enter 0 or if you travel twice Enter 1: ";
        cin>>b;
        while (b!=0 && b!=1){
            cout<<"Invalid Value Please Try Again: ";
            cin>>b;
        }
        if (b==0){
            cout<<"Please Enter the ticket price here: ";
            long long int planeticket;
            cin>>planeticket;
            while (planeticket<0){
                cout<<"Invalid Value Please Try Again: ";
                cin>>planeticket;
            }
             expenses_+=planeticket;
        } else{
            cout<<"Please Enter the tickets price here: ";
            long long int planeticket;
            for (int i=0 ;i<2;i++){
                cin>>planeticket;
                while (planeticket<0){
                    cout<<"Invalid Value Please Try Again: ";
                    cin>>planeticket;
                }
                expenses_+=planeticket;
            }
        }
    }
    cout<<"----------------------------------------------------------------------------------------\n\n";
}
//Function to know from the user how much did the employee pay If he rented a car
long double rented_car(long double &expenses_){
    cout<<"Please if you rented a car Enter the car rent price and if you did not rented a car Enter 0: ";
    long double rentedcar;
    cin>>rentedcar;
    while(rentedcar<0){
        cout<<"Invalid Value Please Try Again: ";
        cin>>rentedcar;
    }
    cout<<"-----------------------------------------------------------------------------------------------\n\n";
    expenses_+=rentedcar;
}
// Function to know from the user If the employee used his own vehicle
long double private_car(long double &expenses_){
    cout<<"Please if you had a private car enter How many kilometers the private car has driven\n ";
    cout<<"And if you did not have a private car please enter 0:  ";
    long double privatecar,total;
    cin>>privatecar;
    while(privatecar<0){
        cout<<"Invalid Value Please Try Again: ";
        cin>>privatecar;
    }
    cout<<"-------------------------------------------------------------------------------------\n\n";
    total=privatecar*0.775;
    expenses_+=total;
}
//Function to know from the user how much did the employee pay for parking fees
long double parking_fees(long double &expenses_,long double &rejected_){
    cout<<"0) if you had not any car Enter 0\n";
    cout<<"1) if you had a private car or rented car Enter 1\n";
    int a;
    long double price;
    cin>>a;
    while(a!=1 && a!=0){
        cout<<"Invalid Value Please Try Again: ";
        cin>>a;
    }
    if(a==1){
        cout<<"How many days you used a private car or rented car and you paid to parking fees: ";
        int b;
        cin>>b;
        while(b<0){
            cout<<"Invalid Value Please Try Again: ";
            cin>>b;
        }
        cout<<"And How Much you paid to parking fees for each day :\n";
        for (int i=0;i<b;i++){
            cout<<"for day "<<i+1<<" you pay: ";
            cin>>price;
            while(price<0){
                cout<<"Invalid Value Please Try Again: ";
                cin>>price;
            }
            if (price>25){
                expenses_+=25;
                rejected_+=(price-25);
            } else {
                expenses_+=price;
            }
        }
        cout<<"----------------------------------------------------------------------------------\n\n";
    } else{
        cout<<"-------------------------------------------------\n\n";
    }
}
//Function to know from the user how much did the employee pay for Taxi fees
long double taxi_fees(long double &expenses_,long double &rejected_){
    cout<<"0) if you did not use a Taxi Enter 0\n";
    cout<<"1) if you used a Taxi Enter 1\n";
    int a;
    long double price;
    cin>>a;
    while(a!=1 && a!=0){
        cout<<"Invalid Value Please Try Again: ";
        cin>>a;
    }
    if(a==1){
        cout<<"How many days you used a Taxi: ";
        int b;
        cin>>b;
        while(b<0){
            cout<<"Invalid Value Please Try Again: ";
            cin>>b;
        }
        cout<<"And How Much you paid to use a taxi for each day :\n";
        for (int i=0;i<b;i++){
            cout<<"for day "<<i+1<<" you pay: ";
            cin>>price;
            while(price<0){
                cout<<"Invalid Value Please Try Again: ";
                cin>>price;
            }
            if (price>100){
                expenses_+=100;
                rejected_+=(price-100);
            } else {
                expenses_+=price;
            }
        }
        cout<<"---------------------------------------------------\n\n";
    } else{
        cout<<"----------------------------------------------\n\n";
    }
}
//Function to know from the user how much did the employee pay for conference or seminar
long double conference_seminar(long double &expenses_){
    long double price;
    cout<<"0) if you did not attend conference or seminar Enter 0 \n";
    cout<<"1) if you attended conference or seminar Enter 1 \n";
    int a,b;
    cin>>a;
    while (a!=0 && a!=1){
        cout<<"Invalid Value Please Try Again: ";
        cin>>a;
    }
    if (a==1){
        cout<<"How many conferences or seminars: ";
        cin>>b;
        while(b<0){
            cout<<"Invalid Value Please Try Again: ";
            cin>>b;
        }
        cout<<"And How Much you paid in conferences or seminars:\n";
        for (int i=0;i<b;i++){
            cout<<"for day "<<i+1<<" you pay: ";
            cin>>price;
            while(price<0){
                cout<<"Invalid Value Please Try Again: ";
                cin>>price;
            }
            expenses_+=price;
        }
        cout<<"-------------------------------------------------------\n\n";
    } else {
        cout<<"-------------------------------------------------------\n\n";
    }
}
//Function to know from the user how much did the employee pay for accommodation
long double accommodation(long double &expenses_,long double &rejected_){
    long double price;
    cout<<"how much money you paid for your accommodation for each day:\n";
    for (int i=0;i<days__number;i++){
            cout<<"for day "<<i+1<<" you pay: ";
            cin>>price;
            while(price<0){
                cout<<"Invalid Value Please Try Again: ";
                cin>>price;
            }if (price>500){
                expenses_+=500;
                rejected+=(price-500);
            } else{
                expenses_+=price;
            }
    }
    cout<<"------------------------------------------------------------\n\n";
}
//Function to know from the user how much did the employee pay for the breakfast for each day
long double breakfast(long double &expenses_,long double &rejected_){
    long double price;
    cout<<"how much money you paid for your break fast for each day:\n";
    for (int i=0;i<days__number;i++){
        cout<<"for day "<<i+1<<" you pay: ";
        cin>>price;
        while(price<0){
            cout<<"Invalid Value Please Try Again: ";
            cin>>price;
        }
        if (i==0){
            if(time__start==1){
                if (price>40){
                    expenses_+=40;
                    rejected_+=(price-40);
                }else{
                    expenses_+=price;
                }
            }
        } else if (i=days__number-1){
            if(time__end==1){
                if (price>40){
                    expenses_+=40;
                    rejected_+=(price-40);
                }else{
                    expenses_+=price;
                }
            }
        } else{
            if (price>40){
                expenses_+=40;
                rejected_+=(price-40);
            }else{
                expenses_+=price;
            }
        }
    }
    cout<<"---------------------------------------------------------\n\n";
}
//Function to know from the user how much did the employee pay for the lunch for each day
long double lunch(long double &expenses_,long double &rejected_){
    long double price;
    cout<<"how much money you paid for your lunch for each day:\n";
    for (int i=0;i<days__number;i++){
        cout<<"for day "<<i+1<<" you pay: ";
        cin>>price;
        while(price<0){
            cout<<"Invalid Value Please Try Again: ";
            cin>>price;
        }
        if (i==0){
            if(time__start==2){
                if (price>60){
                    expenses_+=60;
                    rejected_+=(price-60);
                }else{
                    expenses_+=price;
                }
            }
        } else if (i=days__number-1){
            if(time__end==2){
                if (price>60){
                    expenses_+=60;
                    rejected_+=(price-60);
                }else{
                    expenses_+=price;
                }
            }
        } else{
            if (price>60){
                expenses_+=40;
                rejected_+=(price-40);
            }else{
                expenses_+=price;
            }
        }
    }
    cout<<"----------------------------------------------------\n\n";
}
//Function to know from the user how much did the employee pay for the dinner for each day
long double dinner(long double &expenses_,long double &rejected_){
    long double price;
    cout<<"how much money you paid for your dinner for each day:\n";
    for (int i=0;i<days__number;i++){
        cout<<"for day "<<i+1<<" you pay: ";
        cin>>price;
        while(price<0){
            cout<<"Invalid Value Please Try Again: ";
            cin>>price;
        }
        if (i==0){
            if(time__start==3){
                if (price>80){
                    expenses_+=80;
                    rejected_+=(price-80);
                }else{
                    expenses_+=price;
                }
            }
        } else if (i=days__number-1){
            if(time__end==3){
                if (price>80){
                    expenses_+=80;
                    rejected_+=(price-80);
                }else{
                    expenses_+=price;
                }
            }
        } else{
            if (price>80){
                expenses_+=80;
                rejected_+=(price-80);
            }else{
                expenses_+=price;
            }
        }
    }
    cout<<"-----------------------------------------------------\n\n";
}
//Function to display The total expenses paid by the employee and The total expenses that were accepted for refund by the system and The total expenses that were rejected for refund by the system
long double result(long double &expenses_,long double &rejected_){
    long double refund;
    refund=expenses_-rejected_;
    cout<<"________________________________________________________________________________________________________________________\n\n\n";
    cout<<"The total expenses paid by the employee: "<<fixed<<setprecision(2)<<expenses_<<"\n";
    cout<<"-------------------------------------------------\n\n\n";
    cout<<"The total expenses that were accepted for refund by the system: "<<fixed<<setprecision(2)<<refund<<"\n";
    cout<<"-------------------------------------------------------------------------\n\n\n";
    cout<<"The total expenses that were rejected for refund by the system: "<<fixed<<setprecision(2)<<rejected_<<"\n";
    cout<<"----------------------------------------------------------------------\n\n\n";
}
//The main Function
int main(){
    welcome();
    days_number();
    time_start();
    time_end();
    plane_ticket(expenses);
    rented_car(expenses);
    private_car(expenses);
    parking_fees(expenses,rejected);
    taxi_fees(expenses,rejected);
    conference_seminar(expenses);
    accommodation(expenses,rejected);
    breakfast(expenses,rejected);
    lunch(expenses,rejected);
    dinner(expenses,rejected);
    result(expenses,rejected);
}


