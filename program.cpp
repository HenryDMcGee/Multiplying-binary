//Henry McGee
//CPSC 2310 Section 1
//Assignment 2
//Due July 16
//Description: shows steps for 8-bit by 8-bit multiplication.
//Includes helper functions from helperfunction.cpp, so remember to
//compile with program.cpp and helperfunction.cpp
#include <iostream>
#include "helperfunction.h"
using namespace std;

int main() {
	int multiplicand = 0;
	int multiplier = 0;
	int c = 0;
	int acc[8] = {0,0,0,0,0,0,0,0};

	int register0[8] = {0,0,0,0,0,0,0,0};	//holds multiplier  (mq)
	int register1[8] = {0,0,0,0,0,0,0,0};  //holds multiplicand (mdr)
	int register3[8] = {0,0,0,0,0,0,0,0};  //holds original binary multiplier
	
	//Input the multiplicand
	cout << "multiplicand: ";
	cin >> multiplicand; 				
	if((multiplicand < 0) || (multiplicand > 255)) {
		cout << "Multiplicand out of range." << endl;
		return 0;
	}

	//Input the multiplier
	cout << "multiplier: ";
	cin >> multiplier;
	if((multiplier < 0) || (multiplier > 255)) {
		cout << "Multiplier out of range." << endl;
		return 0;
	}

	//used to remember where the last binary digit is placed. 
	int register0Length = 0;
	
	//temp holds the value of multiplicand. 
	//temp will be divided during the binary convertion,
	//leaving the original multiplicand intact. 
	int temp = multiplier;	
	
	//convert temp to binary and store in register0, and copy in register3
	while(temp != 0) {
		register0[register0Length] = temp % 2;	
		register3[register0Length] = temp % 2; 	//makes a copy of the mq
		temp = temp / 2;
		register0Length++;
	}

	//same as previous code but for multiplicand
	int register1Length = 0;
	temp = multiplicand;
 
	while(temp != 0) {
		register1[register1Length] = temp % 2;	
		temp = temp / 2;
		register1Length++;
	}

	cout << endl;
	
	//checks that acc is zero before step 1
	for(int i = 0; i < 8; i++) {
		if(acc[i] > 0) {
			cout << "Error acc is not zero." << endl;
			return 0;
		}
	}

	//checks that c is zero before step 1
	if(c > 0) {
		cout << "Error c is not zero." << endl;
	}

	cout << "c and acc set to 0" << endl;

	cout << "mq set to multiplier    = " << multiplier << " and ";
	
	for(int i = 7; i >= 0; i--)
		cout << register0[i]; 
	cout << " binary" << endl;

	cout << "mdr set to multiplicand = " << multiplicand << " and ";

	for(int i = 7; i >= 0; i--)
		cout << register1[i];
	cout << " binary" << endl;
	cout << "-----------------------------------------------" << endl;


	//for loop for steps 1-8
	for(int i = 0; i < 8; i++) {

		cout << "step" << i+1 << ":   " << c << " ";
		for(int i = 7; i >= 0; i--)
			cout << acc[i];
		cout << " ";
		for(int i = 7; i >= 0; i--)
			cout << register0[i];
		cout << endl << "       +   ";
		
		//if last digit of mdr is 1, add
		if(register0[0] == 1) {
				for(int i = 7; i >= 0; i--)
					cout << register1[i];
		}
		//otherwise do not add
		else
			cout << "00000000";
		cout << "        ^ "; 



		//if last digit of mdr is 1, add
		if(register0[0] == 1) {
			cout << "add based on lsb=1" << endl;
		}
		else {
			cout << "no add based on lsb=0" << endl;
		}
		cout << "-----------------------------------------------" << endl;

		/*this is the function where the multiplier 
		is added to the acc*/
		if(register0[0] == 1) {
			c = addbinary(c, acc, register1);
		}
		

		cout << "         " << c << " ";
		for(int i = 7; i >= 0; i--)
			cout << acc[i];
		cout << " ";
		for(int i = 7; i >= 0; i--)
			cout << register0[i];

		cout << endl;
		cout << "      >>                     shift right" << endl;
		//shift right after adding
		c = shiftRight(acc, register0, c);

		cout << "         " << c << " ";
		for(int i = 7; i >= 0; i--)
			cout << acc[i];
		cout << " ";
		for(int i = 7; i >= 0; i--)
			cout << register0[i];

		cout << endl << endl;
	}
		cout << "-----------------------------------------------" << endl;
		cout << "check:            binary   decimal" << endl;
		cout << "                "; 
		for(int i = 7; i >= 0; i--)
			cout << register1[i];
		cout << "        " << multiplicand << endl;
		cout << "        x       ";
		for(int i = 7; i >= 0; i--)
			cout << register3[i];
		cout << "  x     " << multiplier << endl;
		cout << "        ----------------    ------" << endl;
		cout << "        ";
		for(int i = 7; i >= 0; i--)
			cout << acc[i];
		for(int i = 7; i >= 0; i--)
			cout << register0[i];

		cout << "      ";
		
		//convert final product to decimal	
		int sum = convertToDecimal(acc, register0);
		cout << sum << endl;

	return 0;
} 
