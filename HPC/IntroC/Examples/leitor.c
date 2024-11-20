#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float get_par(char par[], char arq[]) {
    /*************************************
     * Search for par in arq and 
     * return its value.
     * 
     * The file arq must be written 
     * with 3 columns as
     * 
     * <parameter> <value> <unit>
     * 
     * <parameter> is a string
     * <value> is read as float
     * <unit> is a string and it will
     *   be ignored here.
     * 
     * INPUT:
     *   par: string with the parameter
     *        to be searched
     *   arq: filename
     * 
     * OUTPUT:
     *   value read from arq matching par
     * 
     * If par is not found, returns an error
     * 
     **************************************/

    FILE *fp = fopen(arq, "r"); // opens file for reading
    float value; // float to store the value
    char item[30]; // string to store read parameter name
    char unidade[30]; // string to store unit
    // setting chars to 30 characters limits the parameter and unit strings on the file
    // they cannot be larger than 30 charaters or the code will break

    // while not! end of file
    while(!feof(fp)) {
        // reads 3 columns and saves on the addresses fof these variables
        fscanf(fp, "%s %f %s", item, &value, unidade);
        // if the string item matches the string par at position 0
        if (strcmp(item, par) == 0) {
            // if means that we have found the paramter
            // so let's close the file
            fclose(fp);
            // and return the value
            return(value); 
        }
    }
    // if it reaches this point it means that we didn't
    // find par in arq, so let emit an error
     
    // close the file first
    fclose(fp);
    // and prints the error
    printf("ERRO 2: not found: %s\n", par);
    exit(2); // force exit of the code
    // we'll never get here, but it's better to put a return at 
    // the end, so the compiler won't complain
    return(0.0);
}

int main(int argc, char *argv[]) {
    float temp, Lx;
    int num;

    printf("Number of parameters: %d\n", argc);
    if (argc != 2) {
        printf("ERROR 1: requer 1 arquivo de parâmetro\n");
        exit(1);
    } else {
        printf("Usando arquivo: %s\n", argv[1]);
    }

    temp = get_par("temperatura", argv[1]);
    Lx = get_par("comprimento", argv[1]);
    num = (int) get_par("num_moleculas", argv[1]);

    printf("Temperatura: %f\n", temp);
    printf("Comprimento: %f\n", Lx);
    printf("Num Moleculas: %d\n", num);

    return(0);
}