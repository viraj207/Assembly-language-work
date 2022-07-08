// COMP124_Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// declare variables here
	signed int count1 = -10;
	int count2 = 5;
	int num = 0;
	//signed int num = -2;
	char alpha = 'a';
	char name[] = "Jo Smith\n";

	_asm {
    // put assemble code here
		mov eax, count1
		add eax, count2
		sub eax, 10
		mov num, eax


	}
	printf("%d\n", num);  // 
	return 0;

}