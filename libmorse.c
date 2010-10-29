
/* 0 means short and 1 means long */
/* a == 01      => 101 = 0x05
   b == 1000
   c == 1010
   d == 100
   e == 0
   f == 0010
   g == 110
   h == 0000
   i == 00
   j == 0111
   k == 101
   l == 0100
   m == 11
   n == 10
   o == 111
   p == 0110
   q == 1101
   r == 010
   s == 000
   t == 1
   u == 001
   v == 0001
   w == 011
   x == 1001
   y == 1011
   z == 1100

   0 == 11111
   1 == 01111
   2 == 00111
   3 == 00011
   4 == 00001
   5 == 00000
   6 == 10000
   7 == 11000
   8 == 11100
   9 == 11110

   to encode them we can use "1"+"CODE" so that we use up to 6 bit to encode a sign
   and no "0" at the first position get lost.
*/
/** this function sends and returns the code above */
int sign2code(char c) {
  switch (c) {
    case 'a': return 101;
    case 'b': return 11000;
    case 'c': return 11010;
    case 'd': return 1100;
    case 'e': return 10;
    case 'f': return 10010;
    case 'g': return 1110;
    case 'h': return 10000;
    case 'i': return 100;
    case 'j': return 10111;
    case 'k': return 1101;
    case 'l': return 10100;
    case 'm': return 111;
    case 'n': return 110;
    case 'o': return 1111;
    case 'p': return 10110;
    case 'q': return 11101;
    case 'r': return 1010;
    case 's': return 1000;
    case 't': return 11;
    case 'u': return 1001;
    case 'v': return 10001;
    case 'w': return 1011;
    case 'x': return 11001;
    case 'y': return 11011;
    case 'z': return 11100;

    case '0': return 111111;
    case '1': return 101111;
    case '2': return 100111;
    case '3': return 100011;
    case '4': return 100001;
    case '5': return 100000;
    case '6': return 110000;
    case '7': return 111000;
    case '8': return 111100;
    case '9': return 111110;

    default: return 0;
}
