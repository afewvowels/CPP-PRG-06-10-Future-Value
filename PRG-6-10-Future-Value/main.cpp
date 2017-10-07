//
//  main.cpp
//  PRG-6-10-Future-Value
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Suppose you have a certain amount of money in a savings account that earns compound
//  monthly interest, and you want to calculate the amount that you will have
//  after a specific number of months. The formula, which is known as the future value
//  formula, is
//
//  F = P * (1 + i)^t
//
//  The terms in the formula are as follows:
//
//  * F is the future value of the account after the specified time period.
//  * P is the present value of the account.
//  * i is the monthly interest rate.
//  * t is the number of months.
//
//  Write a program that prompts the user to enter the account's present value, monthly
//  interest rate, and the number of months that the money will be left in the account. The
//  program should pass these values to a function named futureValue that returns the
//  future value of the account, after the specified number of months. The program should
//  display the account's future value.

#include <iostream>
#include<iomanip>
#include <cmath>

using namespace std;

float presentValue(float, float);

// Global variables!
float const FLT_NUMBER_OF_YEARS = 10.0f;

float fltFutureValue,
      fltAnnualInterestRate,
      fltPresentValue;

int main()
{
    cout << "How much do you have in your account today?\n";
    cin >> fltPresentValue;
    
    while(!cin || fltPresentValue <= 0.0f)
    {
        cout << "Please enter a positive value for present value:\n";
        cin.clear();
        cin.ignore();
        cin >> fltPresentValue;
    }
    
    cout << "What interest rate do you have on your account?\n";
    cin >> fltAnnualInterestRate;
    
    while(!cin || fltAnnualInterestRate < 0)
    {
        cout << "Please enter a valid whole number for your interest rate:\n";
        cin.clear();
        cin.ignore();
        cin >> fltAnnualInterestRate;
    }
    
    fltFutureValue = presentValue(fltPresentValue, fltAnnualInterestRate);
    
    // Configure decimal to two points of precision for dollar amount
    cout << setprecision(2) << fixed << showpoint;
    
    cout << "You will have $" << fltFutureValue << " in your bank account in 10 years.\n";
    
    return 0;
}

float presentValue(float fltPresentValue, float fltAnnualInterestRate)
{
    float fltAnnualInterestRateAdjusted;
    
    fltAnnualInterestRateAdjusted = (fltAnnualInterestRate / 100.0f) + 1.0f;
    
    fltFutureValue = (fltPresentValue) * pow(fltAnnualInterestRateAdjusted, FLT_NUMBER_OF_YEARS);
    
    return fltFutureValue;
}

