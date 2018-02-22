// this finds the greatest commond divisor
// recursively with values of 64 bits
//
// rduarte@ciencias.unam.mx

#include <stdint.h>
uint64_t gcd64(uint64_t x, uint64_t y)
{
if(x%y == 0) return y;
else
return gcd64(y,x%y);
}
