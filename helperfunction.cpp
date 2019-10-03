//Henry McGee
//CPSC 2310 Section 1
//Assignment 2
//Due July 16
#include <iostream>
#include <tgmath.h> //for pow function
using namespace std;

int addbinary(int c, int* acc, int* multiplicand) {
	//for loop for adding 8 bit binary
	for(int i = 0; i < 8; i++) {
		//when adding 1 and 0 without a carry, answer is 0
		if((c == 0) && ((acc[i] == 0 && multiplicand[i] == 1)
		|| (acc[i] == 1 && multiplicand[i] == 0))) {
			acc[i] = 1;
		}
		//when adding 1 and 0 with carry, answer is 0 with carry 
		else if((c == 1) && ((acc[i] == 0 && multiplicand[i] == 1) 
		|| (acc[i] == 1 && multiplicand[i] == 0))) {
			acc[i] = 0;
		}
		//when adding 1 and 1, answer is 0 with carry
		else if((c == 0) && (acc[i] == 1) && (multiplicand[i] == 1)) {
			acc[i] = 0;
			c = 1;
		}
		//when adding 1 and 1 with carry, answer is 0 with carry
		else if((c == 1) && (acc[i] == 1) && (multiplicand[i] == 1)) {
			acc[i] = 1;
		}
		//when adding 0 to 0 with carry, answer is 0
		else if((c == 1) && (acc[i] == 0) && (multiplicand[i] == 0)) {
			acc[i] = 1;
			c = 0;
		}
	}
	return c;
}

int shiftRight(int* acc, int* mdr, int c) {	
	//keep last value of acc to add to mdr
	int temp = acc[0];	
	//shift values to right	
	for(int i = 0; i < 7; i++) {
		acc[i] = acc[i+1];
		mdr[i] = mdr[i+1];
	}
	//first value of acc must be 0	
	acc[7] = c;
	c = 0;
	//first value of mdr = previous last value of acc
	mdr[7] = temp;

	return c;
}

int convertToDecimal(int* acc, int* mdr) {
	//sum is the final solution
	int sum = 0;
	//for finding values in acc
	int j = 8;
	for(int i = 0; i < 8; i++) {
		//add values of mdr to solution
		//only uses 2 to the power of 1-8
		sum += mdr[i] * pow(2, i);
		//adds values of acc to solution
		//only uses 2 to the power of 9-16
		sum += acc[i] * pow(2, j);
		j++;	
	}	
	//return sum	
	return sum;
}
