// COMP124_Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// declare variables here
	int fib0 = 0;
	int fib1 = 1;
	int fib2 = 2;


	_asm {
	// put assemble code here
	while1:
		mov eax, fib2
		cmp eax, 500  
		jge end_while
		mov fib0, eax
		mov eax, fib2
		mov fib1, eax
		add eax, fib0
		mov fib2, eax
		jmp while1
	end_while:

	}
	return 0;

} // cmp means compare
// jge means jump if greater than