// Local definitions
// this definitions for the pollard rho algorithm
// types, and functions
// rduarte@ciencias.unam.mx
//

#ifndef _LOCALTYPES_H

#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

typedef struct pair64_t
{
  uint64_t f1, f2;
} pair64;

typedef struct _prime_info
{
  uint64_t *set;
  uint64_t cardinality;
} prime_info;

typedef struct _prime_chk
{
  uint8_t type:1;
  uint64_t where;
} prime_chk;

prime_info primes_in_n (register uint64_t max);
prime_chk primality_check (register uint64_t x);
uint8_t
prime (uint64_t x);
uint64_t gcd64(uint64_t x, uint64_t y);
pair64 pollard_rho (uint64_t N, uint64_t init,uint8_t prime_flag);
uint64_t
f_cuad (uint64_t k);

#endif
