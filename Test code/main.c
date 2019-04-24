// 0.Documentation Section 
// main.c
// Runs on TM4C123
// Test_1, Input from PF0 (SW2), output to PF3 (green LED)
// Authors: Albara Abu Shaqra
// Date: April 21, 2019

// LaunchPad built-in hardware
// SW1 left switch is negative logic PF4 on the Launchpad
// SW2 right switch is negative logic PF0 on the Launchpad
// red LED connected to PF1 on the Launchpad
// blue LED connected to PF2 on the Launchpad
// green LED connected to PF3 on the Launchpad

#include "PortF_Init.h"
	
	
// 2. Declarations Section
//   Global Variables
unsigned long PF0_state=0x00;

// 3. Subroutines Section
// MAIN: Mandatory for a C Program to be executable
int main(void){    // initialize PF0 and PF4 and make them inputs
  PortF_Init();    // make PF3-1 out (PF3-1 built-in LEDs)
  PF0_state=PF0&0x01;
	while(1){
   PF3=PF0_state<<3;
  }
}


