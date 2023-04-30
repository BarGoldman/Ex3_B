#include "Fraction.hpp"
#include <cmath>

namespace ariel
{
};

// https://www.geeksforgeeks.org/program-to-find-gcd-or-hcf-of-two-numbers/
int gcd(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    return gcd(num2, num1 % num2);
}


// constructor
Fraction::Fraction()
{
    _numerator = 0;
    _denominator = 1;
}

Fraction::Fraction(int num_erator, int denominator):_numerator(num_erator),_denominator(denominator)
{
    if (denominator == 0)
    {
        throw std::invalid_argument("Divide by zero exception");
    }
    int ans = gcd(_numerator , _denominator);
    _numerator = _numerator / ans;
    _denominator = _denominator / ans;
    
    // if the "-" is on the _denominator over to the _numerator
    if (_denominator < 0)
    {
        _numerator = _numerator * (-1);
        _denominator = _denominator * (-1);
    }
};

Fraction::Fraction(float num)
{
    _numerator = num * 1000;
    _denominator = 1000;
    int ans = gcd(_numerator, _denominator);
    _numerator = _numerator / ans;
    _denominator = _denominator / ans;

    // if the "-" is on the _denominator over to the _numerator
    if (_denominator < 0)
    {
        _numerator = _numerator * (-1);
        _denominator = _denominator * (-1);
    }
};

// constructor for the test
Fraction::Fraction(double num)
{
    _numerator = num * 1000;
    _denominator = 1000;
    int ans = gcd(_numerator, _denominator);
    _numerator = _numerator / ans;
    _denominator = _denominator / ans;

    // if the "-" is on the _denominator over to the _numerator
    if (_denominator < 0)
    {
        _numerator = _numerator * (-1);
        _denominator = _denominator * (-1);
    }
};

// get & set
int Fraction::getNumerator() const
{
    return _numerator;
};

int Fraction::getDenominator() const
{
    return _denominator;
}

//////////////////////////////////////////     + operator  //////////////////////////////////////////

// The + operator to add two fractions and return their sum as another fraction in reduced form.
Fraction Fraction::operator+(const Fraction &other) const
{
    long long numeratorNew = (long long)(_numerator * other._denominator) + (long long)(_denominator * other._numerator);
    long long denominatorNew = (long long)_denominator * (long long)other._denominator;
    if (numeratorNew/denominatorNew > std::numeric_limits<int>::max() || numeratorNew/denominatorNew < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Multiplication resulted in integer overflow");
    }
    return Fraction((int)numeratorNew, (int)denominatorNew);
    // return Fraction(numeratorNew, denominatorNew);
}

Fraction Fraction::operator+(float num) const
{
    Fraction temp(num);
    return *this + temp;
}

Fraction operator+(float num, const Fraction &other)
{
    Fraction temp(num);
    return temp + other;
}

//////////////////////////////////////////     - operator  //////////////////////////////////////////
// The - operator to subtract two fractions and return their difference as another fraction in reduced form.
Fraction Fraction::operator-(const Fraction &other) const
{
    int numeratorNew = (_numerator * other._denominator) - (_denominator * other._numerator);
    int denominatorNew = _denominator * other._denominator;
    return Fraction(numeratorNew, denominatorNew);
}

Fraction Fraction::operator-(float num) const
{
    Fraction temp(num);
    return *this - temp;
}

Fraction operator-(float num, const Fraction &other)
{
    Fraction temp(num);
    return temp - other;
}

//////////////////////////////////////////     * operator  //////////////////////////////////////////
// The * operator to multiply two fractions and return their product as another fraction in reduced form.
Fraction Fraction::operator*(const Fraction &other) const
{

    long long numeratorNew = (long long)_numerator * (long long)other._numerator;
    long long denominatorNew = (long long)_denominator * (long long)other._denominator;
    if (numeratorNew/denominatorNew > std::numeric_limits<int>::max() || numeratorNew/denominatorNew < std::numeric_limits<int>::min()) {
        throw std::overflow_error("Multiplication resulted in integer overflow");
    }
    return Fraction((int)numeratorNew, (int)denominatorNew);


    // int numeratorNew = _numerator * other._numerator;
    // int denominatorNew = _denominator * other._denominator;
    // return Fraction(numeratorNew, denominatorNew);
}

Fraction Fraction::operator*(float num) const
{
    Fraction temp(num);
    return *this * temp;
}

Fraction operator*(float num, const Fraction &other)
{
    Fraction temp(num);
    return temp * other;
}

//////////////////////////////////////////     / operator  //////////////////////////////////////////
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
    Fraction temp(num);
    return *this / temp;
}
Fraction operator/(float num, const Fraction &other)
{
    if (other._numerator == 0)
    {
        throw std::runtime_error("Divide by zero exception");
    }
    Fraction temp(num);
    return temp / other;
}

// The == operator to compare two fractions for equality and return true or false.
bool Fraction::operator==(const Fraction &other) const
{ 
    int a =  ((float) _numerator / _denominator ) * 1000;
    int b =  ((float) other._numerator / other._denominator ) * 1000;   
    return (a == b);
}
bool Fraction::operator==(float num) const
{
    Fraction temp(num);
    return (temp == *this);
}
bool operator==(float num, const Fraction &other)
{
    Fraction temp(num);
    return (temp == other);
}

// All comparison operations (>,<,>=,<=)
//  >
bool Fraction::operator>(const Fraction &other) const
{
    int a =  ((float) _numerator / _denominator ) * 1000;
    int b =  ((float) other._numerator / other._denominator ) * 1000;   
    return (a > b);
}

bool Fraction::operator>(float num) const
{
    Fraction temp(num);
    return (*this > temp);
}

bool operator>(float num, const Fraction &other)
{
    Fraction temp(num);
    return (temp > other);
}

// <
bool Fraction::operator<(const Fraction &other) const
{
    int a =  ((float) _numerator / _denominator ) * 1000;
    int b =  ((float) other._numerator / other._denominator ) * 1000;   
    return (a < b);
}

bool Fraction::operator<(float num) const
{
    Fraction temp(num);
    return (*this < temp);
}

bool operator<(float num, const Fraction &other)
{
    Fraction temp(num);
    return (temp < other);
}

// >=
bool Fraction::operator>=(const Fraction &other) const
{
    return(other == *this || *this > other);
}

bool Fraction::operator>=(float num) const
{
    Fraction temp(num);
    return(*this >= temp);
}

bool operator>=(float num, const Fraction &other)
{
    Fraction temp(num);
    return(temp >= other);
}

// <=
bool Fraction::operator<=(const Fraction &other) const
{
    return(other == *this || *this < other);
}

bool Fraction::operator<=(float num) const
{
    Fraction temp(num);
    return(*this <= temp);
}

bool operator<=(float num, const Fraction &other)
{
    Fraction temp(num);
    return(temp <= other);
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
    input >> new_numerator;
    if (!(input >> new_denominator))
    {
        throw std::runtime_error("the input is one number Or not int num");
    }
    if (new_denominator == 0)
    {
        throw std::runtime_error("Divide by zero exception");
    }
    other = Fraction(new_numerator, new_denominator);
    return input;
}