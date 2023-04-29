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

int main()
{
    Fraction a(5, 3), b(14, 21);
    cout << "a: " << a << "b: " << b << endl;
    cout << "a+b" << a + b << endl;
    cout << "a-b" << a - b << endl;
    cout << "a/b" << a / b << endl;
    cout << "a*b" << a * b << endl;
    cout << "2.3*b" << 2.3 * b << endl;
    cout << "a+2.421" << a + 2.421 << endl;
    Fraction c = a + b - 1;
    cout << c++ << endl;
    cout << --c << endl;

    cout << "c >=b ? : " << (c >= b) << endl;
    if (a > 1.1)
        cout << " a is bigger than 1.1" << endl;
    else
        cout << " a is smaller than 1.1" << endl;

    cout << "--------------------- bar -----------------" << endl;
    Fraction d(4, 5);
    float e = 0.4;
    Fraction f = d / e; // 4/5 / 2/5 = 4/5 * 5/2 = 20 / 10 = 2/1
    cout << "f.getNumerator() == 2)  " << (f.getNumerator() == 2) << endl; // 4.654
    cout << "(f.getDenominator() == 1)  " << (f.getDenominator() == 1) << endl; // 4.654

    Fraction aa(1,3);
    cout << "aa:  " << (aa + 4.321) << endl; // 4.654

    // Fraction neg_frac1{-2, 7};
    // cout << "neg_frac:  " << neg_frac1++ << endl;


    // std::stringstream ss;
    // Fraction frac2{30, -60};
    // Fraction bare{-1, 2};
    // ss << bare;
    // cout << "ss " << ss.str() << endl;
    // cout << "bare:  " << bare << endl;
    // cout << "c >=b ? : " << (frac2 == bare) << endl;

    // Fraction neg_frac{-7, 9};
    // ss << neg_frac;
    // cout << "ss " << ss.str() << endl;
    // cout << "neg_frac:  " << neg_frac << endl;

    // //CHECK_EQ(Fraction{1, 3} + 4.321, 4.654);

    // Fraction s{-2, 5};
    // Fraction h{3, -5};
    // cout << "s  > h ? : " << (s > h) << endl; // true

    // Fraction bar{2,5};
    // cout << "bar" << bar+0.0 << endl;

    // Fraction bar1{-8, 14};
    // Fraction bar2{4, -7};
    // Fraction bb = 1*bar1;
    // cout << "bar1 " << bar1 << endl; // -4/7
    // cout << "bar1 " << bb << endl; // -4/7
    // cout << "bar2 " << (bar1 == bar2) << endl; //

    // Fraction bar3{7,9};
    // Fraction bar4{1,2};
    // Fraction ans{7 ,18};
    // Fraction bb1 = (bar3 * 0.5);
    // cout << "bb1 " << bb1 << endl;
    // cout << "my test " << (bb1 == ans) << endl;

    // // add to test A
    // // (Fraction{6, 10} / Fraction{0, 10000})
    // // CHECK_EQ(1 * Fraction{-8, 14}, Fraction{4, -7});

    // Fraction test1{14,21};
    // Fraction test2{28,42};
    // cout << "s  > h ? : " << (test1 == test2) << endl;

    // Fraction test3{1,2};
    // cout << "s  > h ? : " << (test3 == test2) << endl;
    cout << "--------------------- bar -----------------" << endl;
}
