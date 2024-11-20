#include <iostream>
#include <cmath>
using namespace std;

int periodic(int i, int n=3) {
    return ((i + n) % n);
}

float periodic(float x, float L=3.0) {
    return (x - floor(x/L) * L);
}

int main () {

    //for (int i=-3; i<=6; i++) {
    //    cout << i << " -> " << periodic(i) << endl;
    //}

    for (float x=-3.0; x<=6.5; x+=0.5) {
        cout << x << " -> " << periodic(x) << endl;
    }


    return(0);
}