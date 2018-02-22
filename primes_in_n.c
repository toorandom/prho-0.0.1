//
// This resturns a set of numbers that are primes from 2 to n
// rduarte@ciencias.unam.mx
//
#include "localtypes.h"
	prime_info
primes_in_n (register uint64_t max) 
{
 register uint64_t i, j;
 register prime_info q;
 register uint64_t *_group, *new, c = 0, k = c;
  _group = (uint64_t *) malloc (max * sizeof (uint64_t));
  memset (_group, 0x0, max * sizeof (uint64_t));
  for (i = 1; i <= max; i++)
    _group[i - 1] = i;  

  for (j = 1; j < max; j++) 
    {
      if (_group[j] != 0) 
        c++;
      for (i = 0; i <= max; i++)
        if ((_group[i] != _group[j]) && (_group[j] != 0)) 
          if (_group[j] < _group[i])   
            if ((_group[i] % _group[j]) == 0) 
              _group[i] = 0;   
    }
  new = (uint64_t *) malloc (sizeof (uint64_t) * c);
  memset (new, 0x0, c * sizeof (uint64_t));
  for (i = 0; i < max; i++)
    if (_group[i] != 0)
      {
        new[k] = _group[i]; 
        k++;
      }
  q.set = new;   
  q.cardinality = c; 
 // free (_group);   
  return q;
}
