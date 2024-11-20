CFLAGS=
DEPS=aux_functions.h
OBJ=main_code.o aux_functions.o

%.o: %.c $(DEPS)
	gcc -c -o $@ $< $(CFLAGS)

main_code: $(OBJ)
	gcc -o $@.out $^ $(CFLAGS)

clean:
	rm *.o *.out
