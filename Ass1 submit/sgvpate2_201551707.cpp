// Student name : Viraj Patel
// Student number : 201351707

// COMP124_Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Struggled to succesfully implement the loop termination
//


#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// declare variables here
	int num = 0;
	int positive = 0;  //The count initialised for how many Positive numbers exist
	int negative = 0; // the count for how many negative numbers exist
	int zero = 0; // the count for how many Zeros exist
	int count = 0; // the count for the amount of inputs the user will input
	char msg1[] = "How many numbers: "; // creating a message to ask the user to input how many numbers with will input
	char msg2[] = "Enter a number: "; // the message to ask the user to input a number
	char msg3[] = "Positive : %d/n";
	char msg4[] = "Negative : %d/n";
	char msg6[] = "--------------------";
	char msg5[] = "Zero : %d/n";
	char fmt1[] = "%d"; // user input variable for amount of numbers
	char fmt2[] = "%d"; // user input for number check
	
	_asm {
	// put assemble code here
		lea eax, msg1 //loading msg1 into the register
		push eax
		call printf //printing what exists ontop of the stack/ msg1 is printed
		pop eax // clearing the stack

		lea eax, count
		push eax
		lea eax, fmt1
		push eax
		call scanf //asking the console for the user input
		pop ecx
		
		//pop eax // clearing the stack
		
		
		mov ecx, count // setting up count to be the loop counter
		
		floop: //creating the start of the loop
		// this a test to see the values of  the relavant varables
		lea eax, positive
		lea eax, negative
		lea eax, zero
		pop eax

		push ecx // store exc , loop counter on stack
		pop ecx




		//printing the message asking the user to input a number
		lea eax, msg2
		push eax
		call printf // calling print to print whats ontop of the stack
		pop eax // clearing the eax stack

		lea eax, num
		push eax
		lea eax, fmt2
		push eax
		call scanf
		lea eax, num
		mov eax, num
		test eax ,num
		
		sub ecx ,1
		

		jnz posorneg //creating the jump condition

		zeroresult: // flag for if inputted number ==0
			pop eax
			mov eax, zero
			add eax, 1
			mov zero, eax
			//pop ecx
			jmp endif

		posorneg: //flag to check weather the number is positive or negative
			mov eax, num
			cmp eax, -1
			jge positiveresult
			pop eax
			//pop ecx
			mov eax, negative
			add eax, 1// adding 1 to the variable negative
			mov negative, eax
			lea eax, negative // checking weather the negative variable has been appended
			//pop ecx

		positiveresult: // flag for if num is greater than -1 and =! 0
			pop eax
			mov eax, positive
			add eax, 1
			mov positive, eax// adding 1 to the variable positive
			lea eax, positive // checking weather positive variable has been appended
			//pop ecx


		
		//endif:
		sub eax, 1
			endif:
		loop floop
		
		// returning the values of Positive, negative and zero's entered
		
		lea eax, msg6
		push eax
		call printf
		add esp,8
	
		push positive // returning the count of inputted positive numbers
		lea eax, msg3
		push eax
		call printf
		add esp, 8

		push negative // returning the count of inputted negative numbers
		lea eax, msg4
		push eax
		call printf
		add esp,8

		push zero // returning the count of inputted 0 numbers
		lea eax, msg5
		push eax
		call printf
		add esp, 8
	}
	return 0;

}