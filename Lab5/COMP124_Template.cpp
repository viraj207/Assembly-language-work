// COMP124_Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// declare variables here
	char fmt[] = "%d";
	int num = 0;




	_asm {
		lea eax,num
		push eax
		lea eax, fmt
		push eax
		call scanf
		add esp, 8

	}





	return 0;

}