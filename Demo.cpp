/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/Fraction.hpp"

using namespace ariel;


int main() {
    Fraction a(5,3), b(14,21);
    cout << "a: " << a << "b: " << b << endl;
    cout << "a+b" << a+b << endl; 
    cout << "a-b" << a-b << endl; 
    cout << "a/b" << a/b << endl; 
    cout << "a*b" << a*b << endl; 
    cout << "2.3*b" << 2.3*b << endl; 
    cout << "a+2.421" << a+2.421 << endl; 
    Fraction c = a+b-1;
    cout << c++ << endl;
    cout << --c << endl;

    cout << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1) cout << " a is bigger than 1.1" << endl;
    else cout << " a is smaller than 1.1" << endl;

    
    cout << "--------------------- bar -----------------" << endl;
    Fraction s{-2, 5};
    Fraction h{3, -5};
    cout << "s  > h ? : " << (s > h) << endl; // true

    Fraction bar{2,5};
    cout << "bar" << bar+0.0 << endl; 


    // add to test A
    Fraction test1{14,21};
    Fraction test2{28,42};
    cout << "s  > h ? : " << (test1 == test2) << endl;

    Fraction test3{1,2};
    cout << "s  > h ? : " << (test3 == test2) << endl;
    cout << "--------------------- bar -----------------" << endl;

}
