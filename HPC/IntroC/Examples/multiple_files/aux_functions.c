int maior(int x, int y) {
    /******************************************************
     * FUNCTION maior
     * 
     * Description: returns largest between x and y.
     * 
     * INPUT:
     *  int x: number to compare
     *  int y: number to compare
     * 
     * OUTPUT:
     *  int: largest number
     ******************************************************/    
    if (x>=y) {
        return(x);
    }
    // else is implied, since the code only gets here if
    // the condition above is not satisfied.
    return(y);
}

void troca(int *x, int *y) {
    /******************************************************
     * FUNCTION troca
     * 
     * Description: switches the content of x and y
     * 
     * INPUT:
     *  int *x: pointer to the content of x
     *  int *y: pointer to the content of y
     * 
     * OUTPUT:
     *  does not return anything explicitly (void)
     *  but on exit flips the concent of x and y
     ******************************************************/
    int c; // aux variable for the switch
    c = *x; // saves the content of x
    *x = *y; // moves content of x to y
    *y = c; // recover original content of x and puts in y
}
