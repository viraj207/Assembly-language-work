// COMP124_Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// declare variables here
	int num = 10;

	_asm {
	// put assemble code here
		mov eax, num  // load num into accumulator
		sub eax, 10   // subtract 10 from num
		jnz store	// if (num==0) then num = 100
		mov eax, 100 // JNZ means jump if not zero , so here the vode will jump over the next line if num +=! 0
					//  if num = 0 so we continue as normal, if not we jump over the next line
					// if num is 0 then 100 is loaded into the acc
		store:
		mov num, eax  // if num=! 0 then num is not chnaged and is loaded into the ACC
			// for exapmple to see how the jumps work , change the Num variable to aomething greater than 10
	}
	return 0;

}