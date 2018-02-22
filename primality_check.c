//
// primality check with erathostenes sieve
// (slow) soon ill implement elliptic curves
// rduarte@ciencias.unam.mx
//
#include "localtypes.h"
prime_chk
primality_check (register uint64_t x)
{
  register uint64_t i, sq_v;
  register prime_chk q;
  register prime_info p;
  q.type = FALSE;             
  q.where = 0;
  sq_v = (int64_t) sqrt (abs(x)); 
  if ((sq_v * sq_v) == x)    
    {
      q.where = sq_v;       
      return q;
    }
  p = primes_in_n (sq_v);
  for (i = 0; i <= p.cardinality; i++) 
    {
      if (p.set[i] != 0 && p.set[i] != 1)
        if (x % p.set[i] == 0  ) 
          {
           q.where = p.set[i];
           return q;
          }
    }
  //free (p.set);
  q.type = TRUE;  
  return q;
}
