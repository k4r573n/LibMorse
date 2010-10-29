# define F_CPU 8000000UL

// Standard-Include für Ein-/Ausgabe
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>

//Hello World für µC

//Prototypen
void sleep_ms(uint16_t ms);
extern void show_sign(char s);
extern int sign2code(char c);

/** to switch the LED on */
void on(void)  {
  PORTD = 0x00;
}

/** to switch the LED off */
void off(void) {
  PORTD = 0xFF;
}

/** wait some time */
void wait(void) {
/*  int i =0;
  while (i<100000) {
    i++;
  }
  */sleep_ms(500);
}



// Hauptprogramm
int main(void)
{
     // Port B als Ausgang konfigurieren
     DDRD = 0xFF;

     //leds an
     on();

     // etwas warten
     sleep_ms(2000); //1sek warten

     off();
     wait();

     while(1) {
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

/*  Diese Funktion lässt den Controller
    "ms" Millisekunden warten.
  Die while-Schleife wird so oft durchlaufen,
  wie der Funktion übergeben wurde.
  Bei jedem Duchlauf wir noch 1ms gewartet.
*/
void sleep_ms(uint16_t ms){
  while(ms){
    ms--;
    _delay_ms(1);
  }
}
