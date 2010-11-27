# define F_CPU 8000000UL

// Standard-Include für Ein-/Ausgabe
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>
#include <string.h>
#include "libmorse.h"
#include "uart.h"

/*  **** Hello World ****
    
    This is an Example for using the libmorse.c
    with a microcontroler.
    ( It sends "hello world" ^^ )
*/

void own_sleep_ms(uint16_t ms);

/** turn the signal on */
void on(void)  {
  //you may have to change this line - depending on your hardware
  PORTD = 0x00;
}

/** turn the signal off */
void off(void) {
  //you may have to change this line - depending on your hardware
  PORTD = 0xFF;
}

/** wait some time */
void wait(void) {
  own_sleep_ms(500);
}



// Hauptprogramm
int main(void)
{

	   uart_init();

	   sei();
	uart_putstr ("\r\n");
	uart_putstr ("Hello\r\n");


     // Port B als Ausgang konfigurieren
     DDRD = 0xFF;

     //leds an
     on();

     // etwas warten
     own_sleep_ms(2000); //2sek warten

     off();
     wait();

     while(1) { //send hello world
       morse_str("ha e");
       morse_char('o');
			uart_putstr ("in der while schleife:\r\n");
     }
     return 0;
}

/** This function waits till the given milli seconds are over */
void own_sleep_ms(uint16_t ms){
  while(ms){
    ms--;
    _delay_ms(1);
  }
}
