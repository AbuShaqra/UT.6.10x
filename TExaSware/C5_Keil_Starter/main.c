//**** Documentation Section
// This Program calculates the area of  square shaped rooms
// Author: Ramesh Yerraballi  and Jon Valavano
// Date:   6/28/2013

// Pre-processorr Directives Section
//  INCLUDES: Lists any external libraries we will refer to using
//  a #include tag
#include <stdio.h>  // Diamond braces for sys lib: Standard I/O
#include <stdint.h>
#include <stdbool.h>
#include "uart.h"   // Quotes for user lib: UART lib

//global variables

uint32_t error; //variable to keep track of number of errors

//input: none
//output: none
//notes: function to inialize the global variables

void initialize(){
	error = 0;
}

int32_t Calc_area(int32_t side){
	int32_t result;
	if(side<=25 && side>0){
	 result= side*side;
	}
	else if(side=0){
	result= -1;	
	}
	else {
		result=0;
		error+=1;
	}
		return result;
}

// Subroutines section
// MAIN: Mandatory subroutine for a C Program to be executable
 int main(void) {
	long side; //room wall in meters
	long area; //size in squared meters
	
	UART_Init();   // call subroutine to init uart lib
	initialize();
	printf("This program calculates areas of square shaped rooms\n");
	printf("Enter to zero to exit program");

  while(1){
    printf("\nEnter room side length: ");
		scanf("%ld", &side);
		area = Calc_area(side); //area in squared meters
		if (area>0){
		printf("\nArea of the room with a side of %ld m is %ld sqr m \n",side,area);
	 }
   else if(area<0){
		printf("\nprogram exit..");
		 break;
	 }		 
	 else{
		 printf("\nside cannot exceed 25m!");
	 }
	}
}

