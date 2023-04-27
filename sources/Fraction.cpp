#include "Fraction.hpp"
#include <cmath>
#include <algorithm>

namespace ariel
{
};



// constructor
Fraction::Fraction(const int num_erator = 0, const int denominator = 1)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Divide by zero exception");
    }
    int ans = __gcd(num_erator, denominator);
    _numerator = num_erator / ans;
    _denominator = denominator / ans;
};

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
    float temp = this->_numerator / this->_denominator + num;
    float f_number = temp * 1000;
    int denominatorNem = 1000;
    int numeratorNew = (int)f_number;
    return Fraction(numeratorNew, denominatorNem);
}

Fraction operator+(float num, const Fraction &other)
{
    float temp = (float)other._numerator / other._denominator + num;
    float f_number = temp * 1000;
    int denominatorNem = 1000;
    int numeratorNew = (int)f_number;
    return Fraction(numeratorNew, denominatorNem);
}

// The - operator to subtract two fractions and return their difference as another fraction in reduced form.
Fraction Fraction::operator-(const Fraction &other) const
{
    int numeratorNew = (_numerator * other._denominator) - (_denominator * other._numerator);
    int denominatorNem = _denominator * other._denominator;
    return Fraction(numeratorNew, denominatorNem);
}

Fraction Fraction::operator-(float num) const
{
    float temp = this->_numerator / this->_denominator - num;
    float f_number = temp * 1000;
    int denominatorNem = 1000;
    int numeratorNew = (int)f_number;
    return Fraction(numeratorNew, denominatorNem);
}

Fraction operator-(float num, const Fraction &other)
{
    float temp = (float)other._numerator / other._denominator - num;
    float f_number = temp * 1000;
    int denominatorNem = 1000;
    int numeratorNew = (int)f_number;
    return Fraction(numeratorNew, denominatorNem);
}

// The * operator to multiply two fractions and return their product as another fraction in reduced form.
Fraction Fraction::operator*(const Fraction &other) const
{
    int numeratorNew = _numerator * other._numerator;
    int denominatorNem = _denominator * other._denominator;
    return Fraction(numeratorNew, denominatorNem);
}
Fraction Fraction::operator*(float num) const
{
   float temp = this->_numerator / this->_denominator * num;
    float f_number = temp * 1000;
    int denominatorNem = 1000;
    int numeratorNew = (int)f_number;
    return Fraction(numeratorNew, denominatorNem);
}
Fraction operator*(float num, const Fraction &other)
{
    float temp = (float)other._numerator / other._denominator * num;
    float f_number = temp * 1000;
    int denominatorNem = 1000;
    int numeratorNew = (int)f_number;
    return Fraction(numeratorNew, denominatorNem);
}

// The / operator to divide two fractions and return their quotient as another fraction in reduced form.
Fraction Fraction::operator/(const Fraction &other) const
{
    int numeratorNew = _numerator * other._denominator;
    int denominatorNem = _denominator * other._numerator;
    return Fraction(numeratorNew, denominatorNem);
}
Fraction Fraction::operator/(float num) const
{
   float temp = this->_numerator / this->_denominator / num;
    float f_number = temp * 1000;
    int denominatorNem = 1000;
    int numeratorNew = (int)f_number;
    return Fraction(numeratorNew, denominatorNem);
}
Fraction operator/(float num, const Fraction &other)
{
    float temp = (other._numerator / other._denominator) / num;
    float f_number = temp * 1000;
    int denominatorNem = 1000;
    int numeratorNew = (int)f_number;
    return Fraction(numeratorNew, denominatorNem);
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
    return (_numerator * other._denominator > _denominator * other._numerator);
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
    return (_numerator * other._denominator < _denominator * other._numerator);
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
    _numerator >= other._numerator && _denominator >= other._denominator);
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
    _numerator <= other._numerator && _denominator <= other._denominator);
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
    int new_numerator = 0, new_denominator = 0;
    input >> new_numerator >> new_denominator;
    if (new_denominator == 0)
    {
        // handle division by zero error
        input.setstate(std::ios_base::failbit);
    }

    other = Fraction(new_numerator, new_denominator);
    return input;
}