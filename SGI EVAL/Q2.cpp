/*
    Author: AJ Blooi 
    File: Q2.cpp
    Date: June, 02 , 2021
    purpose: To create a algorithm that can determine any combination of 2,3 
    and 5.It should be able to find any number in any postion. see 
    SGI_Programmer_Evaluation.pdf for definition of postions. 
    Goal: get postion 1500 in the series, correct answer is "859963392".
*/
#include <iostream>
#include <vector>

using namespace std;

// This function is to see if a number is divisble by 2,3 and/or 5.
int divisible(int num)
{
    int a=2,b=3,c=5;

    while(num % a == 0) num = num / a;
    while(num % b == 0) num = num / b;
    while(num % c == 0) num = num / c;

    if(num == 1) return(1);
    else return(0); 
}

int main()
{
    cout << "\n Start";
    int size = 1500;
    int i = 1;
    int k;
    int count = 1;
    std::vector< int > list;   
    list.push_back(i);

    while (1)
        {
            k = list.size();
            // Check list size for predeterminded size
            if(k == size)
            {
                break;
            }
            i++;

            // Function call
            if (divisible(i)) 
            {
                list.push_back(i);
                count++;
            }
        }
    cout <<"\n The item in the array's 1500th slot is: " << list[size-1];
}