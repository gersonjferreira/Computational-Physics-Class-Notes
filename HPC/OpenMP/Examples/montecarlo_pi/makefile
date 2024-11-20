
CFLAGS=-O3 -Wall

all: montecarlo_pi_seq.c montecarlo_pi_omp.c
	gcc $(CFLAGS) montecarlo_pi_seq.c -o pi_seq.out
	gcc $(CFLAGS) montecarlo_pi_omp.c -o pi_omp.out -fopenmp

clean:
	rm *.out
