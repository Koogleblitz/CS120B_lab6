/*	Author: Richard Tobing, rlumb001@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #6  Exercise #2
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
unsigned char out = 1;
unsigned char prev, in;
unsigned char  toggle,restart;

void Tick(){
  switch(state) {
    case state1:
      out = 1;
      restart = 0;
      //--------------------------------------------------------
      state = state2;
      prev = 1;
    break;


    case state2:
      if(!restart){out = 2; }
      //--------------------------------------------------------
      if(!restart){
        if(prev == 1){state = state3; }
        else{state = state1;}
      }
      else{state = state1; }
      
      prev = 2;
    break;


    case state3:
      if(!restart){out = 4; }
      //-------------------------------------------------------
      if(restart){state = state1; }
      else{state = state2; };
      prev = 3;
    break;
  }
  // if(state == state1){
  //     if((out==4) || (out==0)){ out = 1; }
  //     else{out = 2*out; }
  // }
}


int main(void) {
    DDRA = 0x00;  PORTA = 0xFF;
    DDRB = 0xFF;  PORTB = 0x00;
    TimerSet(300);
    TimerOn();

    state = state1;
    toggle = 0;
    restart = 0;


    while (1) {

      in = !PINA;
        
        if(in){
          toggle = !toggle; 
          restart = 1; 
        }

        if(!toggle){Tick();}
        

        while (!TimerFlag)
        TimerFlag = 0;

    PORTB = out; 
    }
    //return 1;
}

