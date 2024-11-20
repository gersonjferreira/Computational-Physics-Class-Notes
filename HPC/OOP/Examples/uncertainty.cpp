#include <iostream>
#include <cmath>
using namespace std;

class uncertain {
    public:
        // properties
        double v; // value
        double u; // uncertainty
        // methods
        uncertain(double vi, double ui); // constructor
        // overloads
        uncertain operator+(const uncertain&a);
    private:
};

// constructor: init vars
uncertain::uncertain(double vi=0, double ui=0) {
    v = vi;
    u = ui;
}

uncertain uncertain::operator+(const uncertain&a) {
    uncertain r;
    r.v = this->v + a.v;
    r.u = sqrt(pow(this->u, 2) + pow(a.u, 2));
    return(r);
}

int main() {
    uncertain x(3, 1);
    uncertain y(10,1);
    uncertain z;
    uncertain p = 10.2;

    z = x + y;
    z = z + 5.3;

    cout << x.v << ", " << x.u << endl;
    cout << y.v << ", " << y.u << endl;
    cout << z.v << ", " << z.u << endl;
    cout << p.v << ", " << p.u << endl;

    return(0);
}