#include <iostream>
using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};
Fraction& findLargest(Fraction& f1, Fraction& f2, Fraction& f3) {

    double val1 = (double)f1.numerator / f1.denominator;
    double val2 = (double)f2.numerator / f2.denominator;
    double val3 = (double)f3.numerator / f3.denominator;
    
    if (val1 >= val2 && val1 >= val3) {
        return f1;
    }
    else if (val2 >= val3) {
        return f2;
    }
    else {
        return f3;
    }
}