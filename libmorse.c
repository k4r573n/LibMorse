/*
   Libary to easyly use the morse code

   write this to your programm:

   void sleep_ms(uint16_t ms);
   extern void show_sign(char s);
   extern int sign2code(char c);

   or see for details the readme file
 */

#include "libmorse.h"

/* 
   0 means short and 1 means long 

   e.g.  a == 01 

   to encode them we can use "1"+"CODE" so that we use up to 6 bits to encode one sign
   and haven't got a leading "0" in the internal code.

   e.g.  a == 01  =>  101 == 0x05
*/
/** this function sends and returns the code above */
int sign2code(char c) {
  switch (c) {
    case 'a': return 0x05; //101;
    case 'b': return 0x18; //11000;
    case 'c': return 0x1a; //11010;
    case 'd': return 0x0c; //1100;
    case 'e': return 0x02; //10;
    case 'f': return 0x12; //10010;
    case 'g': return 0x0e; //1110;
    case 'h': return 0x10; //10000;
    case 'i': return 0x04; //100;
    case 'j': return 0x17; //10111;
    case 'k': return 0x0d; //1101;
    case 'l': return 0x14; //10100;
    case 'm': return 0x07; //111;
    case 'n': return 0x06; //110;
    case 'o': return 0x0f; //1111;
    case 'p': return 0x16; //10110;
    case 'q': return 0x1d; //11101;
    case 'r': return 0x0a; //1010;
    case 's': return 0x08; //1000;
    case 't': return 0x03; //11;
    case 'u': return 0x09; //1001;
    case 'v': return 0x11; //10001;
    case 'w': return 0x0b; //1011;
    case 'x': return 0x19; //11001;
    case 'y': return 0x1b; //11011;
    case 'z': return 0x1c; //11100;

    case '0': return 0x3f; //111111;
    case '1': return 0x2f; //101111;
    case '2': return 0x27; //100111;
    case '3': return 0x23; //100011;
    case '4': return 0x21; //100001;
    case '5': return 0x20; //100000;
    case '6': return 0x30; //110000;
    case '7': return 0x38; //111000;
    case '8': return 0x3c; //111100;
    case '9': return 0x3e; //111110;

    default: return 0; // unknown
  }
}

/** this function decode the sign and sends it away */
void show_sign(char s) {
  if (s==0) {
    //unknown sign
  }else{
    int i=7;
    //scipp the leading zeros
    while ( (s & (1 << i)) == 0 )
      i--;

    i--; //scipp the "1" to identify the beginning

    for (;i>=0; i-- ) {
      if ( (s & (1 << i)) == 0 ) { // short
        on();
        wait();
        off();
        wait();
      }else { //long
        on();
        wait();
        wait();
        off();
        wait();
      }
    }
    wait();//to terminate the sign
  }
}


