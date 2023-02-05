/*
   Made by:
        Name:                                  ID:
        Mohamed Samy Abdelsalam Elsebaey,      20200445    S3
        Fouad Sayed Fouad Sayed,               20200384    S3
*/
// The Solution of task 1 of Ass 2
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
double degree;              // Declare global value (the degrees which the user will enter)to use it in more than one function

double get_degree() {
    cout << "please Enter the angle in degrees: ";     // Get the angle in degrees from the user
    cin >> degree;
    cout << "You Entered: " << degree << " degrees\n";
    return degree;
}

long double deg_rad() {
    long double rad;                                       // Function to Convert the angle which the user entered in degrees to radian
    rad = get_degree() * 3.141592654 / 180;
    cout << "The angle you entered in radian: " << fixed << setprecision(8) << rad << "\n";
    return rad;
}

long double power(long double base, int exp) {
    long double result = 1;
    while (exp > 0) {                                        //  Function to compute the power
        result *= base;
        exp--;
    }
    return result;
}

long double factorial(long double num) {
    int temp = num;
    for (int i = 1; i < temp; i++) {                            //  Function to compute the Factorial
        num *= (temp - i);
    }
    return num;
}

void sine(long double rad) {
    long double sine = 0, exponent, numerator, denominator;
    for (int i = 0; i < 15; i++) {
        denominator = factorial((2 * i) + 1);
        numerator = power(-1, i);                                        //  Function to compute the sine of the angle which the user entered
        exponent = power(rad, (2 * i + 1));                                  //  and Display it to the user
        sine += (numerator / denominator * exponent);
    }
    cout << "sin of the angle: " << fixed << setprecision(10) << sine << "\n";
}

void cosine(long double rad) {
    long double cos = 1, exponent, numerator, denominator;
    for (int i = 1; i < 15; i++) {
        denominator = factorial(2 * i);                                  //  Function to compute the cosine of the angle which the user entered
        numerator = power(-1, i);                                       //  and Display it to the user
        exponent = power(rad, (i * 2));
        cos += (numerator * exponent / denominator);
    }
    cout << "cos of the angle: " << fixed << setprecision(10) << cos << "\n";
}

long double bernoulli(int k) {                             // Function to get the Bernoulli Series
    long double a, b, c;
    if (k == 0) {
        a = 1, b = 6;
    }
    else if (k == 1) {
        a = -1, b = 30;
    }
    else if (k == 2) {
        a = 1, b = 42;
    }
    else if (k == 3) {
        a = -1, b = 30;
    }
    else if (k == 4) {
        a = 5, b = 66;
    }
    else if (k == 5) {
        a = -691, b = 2730;
    }
    else if (k == 6) {
        a = 7, b = 6;
    }
    else if (k == 7) {
        a = -3617, b = 510;
    }
    else if (k == 8) {
        a = 43867, b = 798;
    }
    else if (k == 9) {
        a = -174611, b = 330;
    }
    else if (k == 10) {
        a = 854513, b = 138;
    }
    else if (k == 11) {
        a = -236364091, b = 2730;
    }
    else if (k == 12) {
        a = 8553103, b = 6;
    }
    else if (k == 13) {
        a = -23749461029, b = 870;
    }
    else if (k == 14) {
        a = 8615841276005, b = 14322;
    }
    c = a / b;
    return c;
}

long double tan_degree(){
    long double rad;                                   // Function to make the angle degrees in range the tan and convert it to radian
    while (degree>360){                                // to compute the tangent of the angle
        degree=degree-360;
    }
    while (degree<-360){
        degree=degree+360;
    }
    if (degree<90 && degree>=0){
        degree=degree;
    } else if (degree>90 && degree <=180){
        degree=degree-180;
    } else if (degree>180 && degree<270){
        degree=degree-180;
    } else if (degree>270 && degree<=360){
        degree=degree-360;
    }
    rad = degree * 3.141592654 / 180;
    return rad;
}

int check_tan_undefined() {           // Function to check the angle is in range of tan
    int n = 0,s;                      // to check tan is undefined or not
    if (degree < 0) {
        while ((90 - (180 * n)) >= degree) {
            if ((90 - (180 * n)) == degree) {
                s = 0;
            }
            else {
                s = 1;
            }
            n++;
        }
    }
    else if (degree > 0) {
        while ((90 + (180 * n)) <= degree) {
            if ((90 + (180 * n)) == degree) {
                s = 0;
            }
            else {
                s = 1;
            }
            n++;
        }
    }
    return s;
}

void tangent(long double rad) {
    long double tangentt = 0, exponent, numerator, denominator;
    for (int i = 0; i < 15; i++) {
        denominator = factorial((2 * i) + 2);
        numerator = (power(-1, i)) * (power(2, (2 * i) + 2)) * ((power(2, (2 * i) + 2)) - 1) * bernoulli(i);
        exponent = power(rad, (i * 2 + 1));
        tangentt += (numerator / denominator * exponent);                   //  Function to compute the tangent of the angle which the user entered
    }                                                                       //  and Display it to the user
    if (check_tan_undefined()) {
        cout << "tan of the angle: " << fixed << setprecision(10) << tangentt << "\n";
    }
    else {
        cout << "tan of the angle is undefined \n";
    }
}

int main() {                                // the main function
    long double radian;
    radian = deg_rad();                     // calling function to get the angle from the user in degrees and convert it to radian
    sine(radian);                           // calling function to get sine of the angle which the user entered
    cosine(radian);                         // calling function to get cosine of the angle which the user entered
    tangent(tan_degree());                  // calling function to get tangent of the angle which the user entered

    return 0;
}
