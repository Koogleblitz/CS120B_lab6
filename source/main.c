/*	Author: Richard Tobing, rlumb001@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #6  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding timer.h or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

//----------------------------------------timer.h----------------------------------------------//
volatile unsigned char TimerFlag = 0; 
unsigned long _avr_timer_M = 1; 
unsigned long _avr_timer_cntcurr = 0; 
void TimerOn() {
  TCCR1B = 0x0B;
  OCR1A = 125;
  TIMSK1 = 0x02;
  TCNT1 = 0;
  _avr_timer_cntcurr = _avr_timer_M;
  SREG |= 0x80;
}
void TimerOff() {TCCR1B = 0x00;}
void TimerISR() {TimerFlag = 1;}
ISR(TIMER1_COMPA_vect) {
	_avr_timer_cntcurr--; 
	if(_avr_timer_cntcurr == 0) { 
		TimerISR(); 
		_avr_timer_cntcurr = _avr_timer_M;
	}
}
void TimerSet(unsigned long M) {
	_avr_timer_M = M;
	_avr_timer_cntcurr = _avr_timer_M;
}
////----------------------------------------/timer.h----------------------------------------------////

enum States{state1, state2, state3}state;
unsigned char out = 0;


void Tick(){
  switch(state) {
    case state1:
      out = 1;
      //--------------------------------------------------------
      state = state2;
    break;

    case state2:
      out = 2;
      //--------------------------------------------------------
      state = state3;
    break;

    case state3:
      out = 4;
      //-------------------------------------------------------
      state = state1;
    break;
  }



  // if(state == state1){
  //     if((out==4) || (out==0)){ out = 1; }
  //     else{out = 2*out; }
  // }

}


int main(void) {
    DDRB = 0xFF;  PORTB = 0x00;

    TimerSet(1000);
    TimerOn();

    state = state1;


    while (1) {
        
        Tick();
        while (!TimerFlag); 
        TimerFlag = 0;
    PORTB = out; 
    }
    //return 1;
}

