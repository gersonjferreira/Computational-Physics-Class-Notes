

def:
	echo "specify option"

simple_raw: 1_simple.c
	gcc 1_simple.c
	./a.out > 1_simple_raw.dat

simple_o3: 1_simple.c
	gcc 1_simple.c -O3
	./a.out > 1_simple_o3.dat

simple_fast: 1_simple.c
	gcc 1_simple.c -Ofast
	./a.out > 1_simple_fast.dat

blas: 2_blas.c
	gcc 2_blas.c -lcblas -lopenblas
	./a.out > 2_blas.dat

clean:
	rm *.out

