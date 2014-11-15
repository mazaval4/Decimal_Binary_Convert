//
//
//  Decimal Binary Converter
//
//  Created by Miguel Zavala on 11/14/14.
//  Purpose: Changes a binary number to a decimal number or a decimal number to a binary number
//


//import necessary libraries
#include <cctype>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;


//forward declaration of functions
int decimalToBinary(int number,int *array);
int binaryToDecimal(char number[]);



int main(int argc, const char * argv[])
{
    
    
    char answer;    //takes in answer to switch statement
    
    int number,index;   //number is the user inputted decimal number to be converted. index is the
    //index for the binary array
    char userBin[100];      //binary char that the user wants to be converted
    
    int *binary = new int [100]; //binary array that holds the converted decimal number
    
    char contin;    //holds the user input that tells whether or not to continue the program
    
    //do while loop that runs if the user enters a 'y' for yes
    do
    {
        
        //asks the user if they want to convert a decimal or a binary number
        cout<<"Is the number a binary or decimal number?"<<endl;
        cout<<"\n";
        cout<<"D for decimal B for binary"<<endl;
        
        //user input that changes the switch statement
        cin>>answer;
        
        //changes the user input to a lower case letter
        answer = tolower(answer);
        
        
        
        
        
        //switch statement that chooses what to do based on the user input
        switch (answer)
        {
                //this chooses the option to change a decimal to a binary number
            case 'd':
                
                
                cout<<"Please enter the decimal number"<<endl;
                
                //decimal number to be converted to binary
                cin>> number;
                
                //prints out the converted number
                cout<<"\n"<<number<<" in binary is(msb->lsb): ";
                index = decimalToBinary(number,binary);
                
                //gets the numbers from the array
                for (int x = (index-1); x >= 0; x--)
                {
                    cout<<*(binary+x);
                }
                
                break;
                
                //this chooses the option to change a binary to a decimal number
            case 'b':
                
                cout<<"Please enter the binary number(msb->lsb)"<<endl;
                
                //binary number to be converted to decimal
                cin>> userBin;
                
                //prints out the converted number
                cout<<userBin<<" in decimal is "<<binaryToDecimal(userBin);
                break;
                
                //runs when neither d or b are chosen
            default:
                cout<<"Not a valid choice"<<endl;
                break;
                
                
        }//end switch
        
        //asks the user if they want to convert another number
        cout<<" "<<endl;
        cout<<"\nDid you want to do another? y for yes n for no";
        cin >> contin;
        contin = tolower(contin);
        
    }//end do loop
    while (contin == 'y');
    
} // end of main




//this function changes a decimal number to a binary number
//inputs are the user entered number and the array that will hold the binary number
int decimalToBinary(int number,int *array)
{
    
    int index = 0;  //the index of the array
    
    //number is the user inputted decimal number
    while (number > 0)
    {
        //if mod 2 of the number is zero then it is divisible by 2 and a 0 is put into the array
        if(number % 2 == 0)
        {
            *(array+index) = 0;
        }
        
        //if mode 2 of the number is not zero then it is not divisible by 2 and a 1 is put into the array
        else
        {
            *(array+index) = 1;
        }
        
        //divide the number by 2
        number = number/2;
        
        //add one to the index
        index++;
    }
    
    return index;
    
}


//this function changes a binary number to a decimal number
//inputs are the user inputted binary number to be converted
int binaryToDecimal(char number[100])
{
    
    int length = strlen(number);    //finds the length of the user inputted number
    
    int index = (length - 1), sum = 0;  //index gets the char at a certain index, sum is the
    //total of the added weights which will be the decimal form of the
    //user inputted binary number
    
    int power = 0;  //power is the weight of each binary number
    
    //checks to see if there is a 1 at the index given, if there is 2^power is added to the sum
    while (index >= 0)
    {
        
        if ( number[index] == '1')
        {
            sum+= pow(2,power);
        }
        index--;
        power++;
    }
    
    
    //sum is the binary number converted to decimal
    return sum;
}
