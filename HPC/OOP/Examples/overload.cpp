#include <iostream>
using namespace std;

int test(int a, int b) {
    return a+b;
}

float test(float a, float b) {
    return a*b;
}

float test(float a) {
    return a*a;
}

int main () {
    int a,b,c;
    float x,y,z,k;

    a = 1;
    b = 2;
    c = test(a, b);

    x = 1.0;
    y = 2.0;
    z = test(x, y);

    k = test(y);

    cout << "c=" << c << endl;
    cout << "z=" << z << endl;
    cout << "k=" << k << endl;

    return(0);
}