// COMP124_Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// declare variables here
	int num = 10; // declaring num as a variable to equal 10

	_asm {

		// put assemble code here
		mov eax, num // loading the num variable into the accumulator
		add eax, 12  // adding 12 to the accumulator variable
		mov num, eax // storing the accumulator value back into num		 // so num now equals 22


	}
	return 0;


}