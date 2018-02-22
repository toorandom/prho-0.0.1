CCFLAGS=-Wall -O3 -pipe -fomit-frame-pointer -funroll-loops 
CC=gcc
LD=gcc
LDFLAGS=-lm
OBJS=gcdrec.o pollard_rho.o primality_check.o prime.o primes_in_n.o 

all: prho
prho: $(OBJS)
	$(LD) $(LDFLAGS) -o prho $(OBJS) 
gcdrec.o: 
	$(CC) $(CCFLAGS) -c gcdrec.c
pollard_rho.o:
	$(CC) $(CCFLAGS) -c pollard_rho.c
primality_check.o: 
	$(CC) $(CCFLAGS) -c primality_check.c
prime.o: 
	$(CC) $(CCFLAGS) -c prime.c
primes_in_n.o: 
	$(CC) $(CCFLAGS) -c primes_in_n.c

clean:
	rm -f $(OBJS) prho
install:
	make ; cp -f prho /usr/local/bin 
