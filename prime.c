//
//  this can handle easy the primality providing from main()
//  rduarte@ciencias.unam.mx
//
#include "localtypes.h"
	uint8_t
prime (uint64_t x)
{
  register prime_chk status;
  status = primality_check (x);
  return status.type;
}
