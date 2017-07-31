/**
    bigint.hpp
    Purpose: Declaration of BigInt class

    @author Bojan Sofronievski
    @version 1.0 7/27/17
*/

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <algorithm>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

enum class SIGN {NEGATIVE, NEUTRAL, POSITIVE};

class BigInt{
public:
    //Constructors
    BigInt(); //no argument constructor
    BigInt(std::string number); //std::string constructor
    BigInt(const char* number); //const char* constructor
    BigInt(int number); //integer constructor
    BigInt(long number); //long integer constructor
    BigInt(long long number); //long long integer constructor
    BigInt(unsigned int number); //unsigned integer constructor
    BigInt(unsigned long number); //unsigned long integer constructor
    BigInt(unsigned long long number); //unsigned long long integer constructor
    BigInt(const BigInt& rhs); //copy constructor
    ~BigInt(); //destructor
    //Assignment operator
    BigInt& operator=(const BigInt& rhs);
    //Insertion and extraction operators
    friend std::istream& operator>>(std::istream& inStream, BigInt& bigint);
    friend std::ostream& operator<<(std::ostream& outStream, BigInt& bigint);
    //Relational and comparison operators
    bool operator>(const BigInt& rhs) const;
    bool operator<(const BigInt& rhs) const;
    bool operator==(const BigInt& rhs) const;
    bool operator!=(const BigInt& rhs) const;
    bool operator>=(const BigInt& rhs) const;
    bool operator<=(const BigInt& rhs) const;
    //Arithmetic operators
    const BigInt operator+(const BigInt& rhs) const;
    const BigInt operator-(const BigInt& rhs) const;
    const BigInt operator*(const BigInt& rhs) const;
    const BigInt operator/(const BigInt& rhs) const; //TODO
    const BigInt operator%(const BigInt& rhs) const; //TODO
    //Compound assignment operators
    BigInt& operator+=(const BigInt& rhs);
    BigInt& operator-=(const BigInt& rhs);
    BigInt& operator*=(const BigInt& rhs);
    BigInt& operator/=(const BigInt& rhs); //TODO
    BigInt& operator%=(const BigInt& rhs); //TODO
    //Increment and decrement operators
    BigInt& operator++();
    BigInt& operator--();
    BigInt operator++(int postfixflag);
    BigInt operator--(int postfixflag);
    //class methods
    BigInt abs() const; //returns absolute value of BigInt
private:
    //private class helper methods
    void ignoreLeadingZeros(); //erase leading zeros in BigInt
    std::string toString(); //convert BigInt to string
    BigInt digitMultiply(unsigned int digit) const; //multiply BigInt by digit
    //class members
    std::vector<unsigned int> digits; //vector of unsigned ints which holds the digits
    bool sign; //true if BigInt is positive or zero, false otherwise
};

#endif // BIGINT_HPP
