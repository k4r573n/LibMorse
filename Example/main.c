# define F_CPU 8000000UL

// Standard-Include für Ein-/Ausgabe
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

/*  **** Hello World ****
    
    This is an Example for using the libmorse.c
    with a microcontroler.
    ( It sends "hello world" ^^ )
*/

//Prototypen
void sleep_ms(uint16_t ms);
extern void show_sign(char s);
extern int sign2code(char c);

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
  sleep_ms(500);
}



// Hauptprogramm
int main(void)
{
     // Port B als Ausgang konfigurieren
     DDRD = 0xFF;

     //leds an
     on();

     // etwas warten
     sleep_ms(2000); //2sek warten

     off();
     wait();

     while(1) { //send hello world
       show_sign(sign2code('h'));
       show_sign(sign2code('e'));
       show_sign(sign2code('l'));
       show_sign(sign2code('l'));
       show_sign(sign2code('o'));
       wait();
       show_sign(sign2code('w'));
       show_sign(sign2code('o'));
       show_sign(sign2code('r'));
       show_sign(sign2code('l'));
       show_sign(sign2code('d'));
       wait();

     }
     return 0;
}

/** This function waits till the given milli seconds are over */
void sleep_ms(uint16_t ms){
  while(ms){
    ms--;
    _delay_ms(1);
  }
}
