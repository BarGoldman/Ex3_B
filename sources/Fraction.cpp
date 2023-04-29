#include "Fraction.hpp"
#include <cmath>
#include <algorithm>

namespace ariel
{
};

int gcd(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    return gcd(num2, num1 % num2);
}

// constructor
Fraction::Fraction(const int num_erator, const int denominator)
{
    if (denominator == 0)
    {
        // throw std::invalid_argument("Divide by zero exception");
        throw std::runtime_error("Divide by zero exception");
    }
    if(num_erator > std::numeric_limits<int>::max() || denominator > std::numeric_limits<int>::max()
    || num_erator < std::numeric_limits<int>::min() || denominator < std::numeric_limits<int>::min() ){
        throw std::overflow_error("Multiplication overflow");
    }
    int ans = gcd(abs(num_erator), abs(denominator));
    // if((denominator < 0 && num_erator > 0) || (num_erator < 0 && denominator > 0) && ans < 0){
    //     ans = ans * (-1);
    // }
    // cout << " ans "<< ans << endl;
    _numerator = num_erator / ans;
    _denominator = denominator / ans;
    if(_denominator < 0){
        _numerator = _numerator * (-1);
        _denominator = _denominator * (-1);
    }
};

Fraction::Fraction(float num)
{
    if(num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min()){
        throw std::overflow_error("Multiplication overflow");
    }
    // cout << "hii1" << endl;
    //  cout << " num " << num << endl;
    int numerator = num * 1000;
    int denominator = 1000;
    int ans = gcd(numerator, denominator);
    // cout << " ans " << ans << endl;
    if (ans < 0)
    {
        ans = ans * (-1);
    }
    _numerator = numerator / ans;
    _denominator = denominator / ans;
    // cout << " _numerator " << _numerator << endl;
    // cout << " _denominator " << _denominator  << endl;
};

Fraction::Fraction(double num)
{
    cout << "hii" << endl;
    int numerator = num * 1000;
    int denominator = 1000;
    int ans = gcd(numerator, denominator);
    if (ans < 0)
    {
        ans = ans * (-1);
    }
    _numerator = numerator / ans;
    _denominator = denominator / ans;
};

// get & set
int Fraction::getNumerator()
{
    return this->_numerator;
};
int Fraction::getDenominator()
{
    return this->_denominator;
}

// The + operator to add two fractions and return their sum as another fraction in reduced form.
Fraction Fraction::operator+(const Fraction &other) const
{
    int numeratorNew = (_numerator * other._denominator) + (_denominator * other._numerator);
    int denominatorNem = _denominator * other._denominator;
    return Fraction(numeratorNew, denominatorNem);
}

// https://www.geeksforgeeks.org/stdgcd-c-inbuilt-function-finding-gcd/
Fraction Fraction::operator+(const float num) const
{
    float temp = (float) _numerator / _denominator + num;
    Fraction ans(temp);
    return (ans);
}

Fraction operator+(float num, const Fraction &other)
{
    float temp = (float) other._numerator / other._denominator + num;
    Fraction ans(temp);
    return (ans);
}

// The - operator to subtract two fractions and return their difference as another fraction in reduced form.
Fraction Fraction::operator-(const Fraction &other) const
{
    // cout<< "hii "<< endl;
    int numeratorNew = (_numerator * other._denominator) - (_denominator * other._numerator);
    int denominatorNem = _denominator * other._denominator;
    return Fraction(numeratorNew, denominatorNem);
}

Fraction Fraction::operator-(float num) const
{
    Fraction t(num);
    return *this - t;
    // float temp = (float) _numerator / _denominator - num;
    // cout << "temp " << temp << endl;
    // Fraction ans(temp);
    // return (ans);
}

Fraction operator-(float num, const Fraction &other)
{

    Fraction t(num);
    // cout << "t " << t._numerator << " / "<< t._denominator << endl;
    return t - other;
    // float temp = num - (float)other._numerator / other._denominator;
    // Fraction ans(temp);
    // return (ans);
}
// Fraction operator-(double num, const Fraction &other)
// {

//     float temp = num - (float)other._numerator / other._denominator;
//     Fraction ans(temp);
//     return (ans);
// }

// The * operator to multiply two fractions and return their product as another fraction in reduced form.
Fraction Fraction::operator*(const Fraction &other) const
{
    int numeratorNew = _numerator * other._numerator;
    int denominatorNem = _denominator * other._denominator;
    return Fraction(numeratorNew, denominatorNem);
}
Fraction Fraction::operator*(float num) const
{
    // cout << "good  "<< endl;
    // int temp = num * 1000;
    // int denominatorNew = this->_denominator * 1000; // multiply denominator by 1000
    // int numeratorNew = this->_numerator * 1000 + round(num * this->_denominator * 1000);
    // return Fraction(numeratorNew, denominatorNew); // simplify fraction and return as a new Fraction object

    float temp = (float) _numerator / _denominator * num;
    Fraction ans(temp);
    return (ans);
    // float temp = (float)this->_numerator / this->_denominator * num;
    // cout << "temp for me  " << temp << endl;
    // float f_number = temp * 1000;
    // int denominatorNem = 1000;
    // int numeratorNew = (int)f_number;
    // return Fraction(numeratorNew, denominatorNem);
}
Fraction operator*(float num, const Fraction &other)
{
    float temp = num * (float) other._numerator / other._denominator;
    Fraction ans(temp);
    return (ans);
    // float temp = (float)other._numerator / other._denominator * num;
    // cout << "temp " << temp << endl;
    // float f_number = temp * 1000;
    // int denominatorNem = 1000;
    // int numeratorNew = (int)f_number;
    // return Fraction(numeratorNew, denominatorNem);
}

// The / operator to divide two fractions and return their quotient as another fraction in reduced form.
Fraction Fraction::operator/(const Fraction &other) const
{
    if (other._numerator == 0)
    {
        throw std::runtime_error("Divide by zero exception");
    }
    int numeratorNew = _numerator * other._denominator;
    int denominatorNem = _denominator * other._numerator;
    return Fraction(numeratorNew, denominatorNem);
}
Fraction Fraction::operator/(float num) const
{
    if (num == 0)
    {
        throw std::runtime_error("Divide by zero exception");
    }
    Fraction t(num);
    return *this / t;
    // float temp = ((float) _numerator / _denominator) / num;
    // Fraction ans(temp);
    // return (ans);
}
Fraction operator/(float num, const Fraction &other)
{
    if (other._numerator == 0)
    {
        throw std::runtime_error("Divide by zero exception");
    }
       Fraction t(num);
    return t / other;
    // float temp = num / ((float) other._numerator / other._denominator);
    // Fraction ans(temp);
    // return (ans);
}

// The == operator to compare two fractions for equality and return true or false.
bool Fraction::operator==(const Fraction &other) const
{
    return (_numerator == other._numerator && _denominator == other._denominator);
}
bool Fraction::operator==(float num) const
{
    float temp = (float)this->_numerator / this->_denominator;
    return (temp == num);
}
bool operator==(float num, const Fraction &other)
{
    float temp = (float)other._numerator / other._denominator;
    return (temp == num);
}

// All comparison operations (>,<,>=,<=)
//  >
bool Fraction::operator>(const Fraction &other) const
{
    return ((float)_numerator / _denominator) > ((float)other._numerator / other._denominator);
}

bool Fraction::operator>(float num) const
{
    float temp = (float)this->_numerator / this->_denominator;
    return (temp > num);
}

bool operator>(float num, const Fraction &other)
{
    float temp = (float)other._numerator / other._denominator;
    return (num > temp);
}

// <
bool Fraction::operator<(const Fraction &other) const
{
    return ((float)_numerator / _denominator) < ((float)other._numerator / other._denominator);
}

bool Fraction::operator<(float num) const
{
    float temp = (float)this->_numerator / this->_denominator;
    return (temp < num);
}

bool operator<(float num, const Fraction &other)
{
    float temp = (float)other._numerator / other._denominator;
    return (num < temp);
}

// >=
bool Fraction::operator>=(const Fraction &other) const
{
    return (_numerator == other._numerator && _denominator == other._denominator ||
            (((float)_numerator / _denominator) > ((float)other._numerator / other._denominator)));
}

bool Fraction::operator>=(float num) const
{
    float temp = (float)this->_numerator / this->_denominator;
    return (temp >= num);
}

bool operator>=(float num, const Fraction &other)
{
    float temp = (float)other._numerator / other._denominator;
    return (num >= temp);
}

// <=
bool Fraction::operator<=(const Fraction &other) const
{
    return (_numerator == other._numerator && _denominator == other._denominator ||
            (((float)_numerator / _denominator) < ((float)other._numerator / other._denominator)));
}

bool Fraction::operator<=(float num) const
{
    float temp = (float)this->_numerator / this->_denominator;
    return (temp <= num);
}

bool operator<=(float num, const Fraction &other)
{
    float temp = (float)other._numerator / other._denominator;
    return (num <= temp);
}

// The << operator to print a fraction to an output stream in the format “numerator/denominator”.
ostream &operator<<(ostream &output, const Fraction &other)
{
    return (output << other._numerator << '/' << other._denominator);
}

// The >> operator to read a fraction from an input stream by taking two integers as input.
istream &operator>>(istream &input, Fraction &other)
{
    int new_numerator, new_denominator;
    if (input >> new_numerator >> new_denominator)
    {
        other = Fraction(new_numerator, new_denominator);
    }
    else{
        // throw std::invalid_argument("the input is one number");
        throw std::runtime_error("Divide by zero exception");
    }
    return input;
}