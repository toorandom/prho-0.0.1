//
// Poor implementation of pollard rho algorithm
// with 64 bit values
// rduarte@ciencias.unam.mx
//
#include "localtypes.h"
uint64_t c = 1;
uint8_t e;
pair64
pollard_rho (uint64_t N, uint64_t init, uint8_t prime_flag)
{
  pair64 k;
  uint64_t i, d, a, b;
  e=0;
  if (prime_flag == TRUE)
    {
      printf ("Checking if prime... this make take a lot of time...\n");
      if (prime (N) == TRUE)
	{
	  printf
	    ("The number is prime.. so it does not have any factors [ !! ]\n");
	  exit (-1);
	}
      else
	printf ("The number is composite [ OK ]\n");
    }
  init += 2;
  a = b = init;			// init might be a random number
  c = N % (init / 2);
  if (c == 0)
    c++;
  for (i = 1; i < (int) sqrt ((float) N) + 1; i++)
    {
      a = f_cuad (a) % N;
      b = f_cuad (f_cuad (b)) % N;
      if (a == b)
	{
	  k.f1 = 1;
	  k.f2 = 1;
	  break;
	}
      if ((d = gcd64 (a - b, N)) > 1)
	{
	  k.f1 = d;
	  k.f2 = N / d;
	  break;
	}
      else if ((d == N) || (d == 0))
	{
	  k.f1 = 0;
	  k.f2 = 0;
	  printf
	    ("Failed: found just a trivial divisor (itself) check -p in argv[3]\n");
	  e=1;
	  break;
	}
    }
  if (k.f1 * k.f2 != N)
    {
      k.f1 = 1;
      k.f2 = 1;
      printf ("Failed: loop exceeded and no factors were assigned\n");
      e=1;
    }
  return k;
}

uint64_t
f_cuad (uint64_t k)
{
  return (k * k) + c;
}


int
main (int argc, char **argv)
{
  uint64_t k, n ;
  int32_t fd;
  uint8_t prime_flag = FALSE, i = 0;
  pair64 m, m1h, m2h;
  m1h.f1 = m1h.f2 = m2h.f1 = m2h.f2 = 1;
  if(argv[1] == NULL || argv[2] == NULL) { 
	  printf("error in arguments\nexample:\nshell%% %s 932873 /dev/urandom\nuse -p in argv[3] for primality providing if necesary\n",argv[0]);
	  exit(-1);
  }
  n = atoll (argv[1]);
  if ((fd = open (argv[2], O_RDONLY)) < 0)
    {
      perror ("open");
      exit (-1);
    }
  read (fd, &k, sizeof (uint64_t));
  if (argv[3] != NULL)
    if (strcmp (argv[3], "-p") == 0)
      prime_flag = TRUE;
  m = pollard_rho (n, (k % n), prime_flag);
  if ((m.f1 == 1) || (m.f2 == 1))
    {
      printf
	("Found just a trivial factor... maybe is prime? or try again using an entropy (/dev/urandom) or use -p in argv[3] for primality providing\n");
      exit (-1);
    }
  if (m.f1 > 150)
    if (prime (m.f1) == FALSE)
      while (e != 1)
	{
	m1h = pollard_rho (m.f1, ((k + i) % m.f1), FALSE);
	if(m1h.f1 > 1);
	i++;
	}
  i = 0;
  if (m.f2 > 150)
    if (prime (m.f2) == FALSE)
      while (e != 1)
	{
	  m2h = pollard_rho (m.f2, ((k + i) % m.f2), FALSE);
	  i++;
	  if(m2h.f1 > 1)
		  break;
	}
  if ((m1h.f1 != 1) && (m1h.f2 != 1))
    printf ("%lld*%lld", m1h.f1, m1h.f2);
  else
    printf ("%lld", m.f1);

  if ((m2h.f1 != 1) && (m2h.f2 != 1))
    printf ("*%lld*%lld", m2h.f1, m2h.f2);
  else
    printf ("*%lld", m.f2);

printf("=%lld\n",n);
  close (fd);
  return 0;
}
