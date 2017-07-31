/**
    bigint.cpp
    Purpose: Definition of BigInt class

    @author Bojan Sofronievski
    @version 1.0 7/27/17
*/

#include "bigint.hpp"

/**
    @brief no argument constructor.

    @param nothing.
    @return nothing.
*/
BigInt::BigInt(){
    digits.push_back(0);
    sign = true;
}

/**
    @brief std::string constructor.

    @param number The number represented as std::string.
    @return nothing.
*/
BigInt::BigInt(std::string number){
    if(number.at(0) == '-'){
        sign = false;
        for(unsigned int i = 1; i < number.length(); i++)
            digits.push_back(number.at(i) - '0');
    } else{
        sign = true;
        if(number.at(0) == '+')
            for(unsigned int i = 1; i < number.length(); i++)
                digits.push_back(number.at(i) - '0');
        else
            for(unsigned int i = 0; i < number.length(); i++)
                digits.push_back(number.at(i) - '0');
    }

    ignoreLeadingZeros();
    if(digits.at(0) == 0)
        sign = true;
}

/**
    @brief int constructor.

    @param number An integer number.
    @return nothing.
*/
BigInt::BigInt(int number){
    if(number < 0){
        sign = false;
        number = -number;
    } else{
        sign = true;
    }
    if(number == 0)
        digits.push_back(0);
    while(number != 0){
        digits.push_back(number % 10);
        number /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    ignoreLeadingZeros();
}

/**
    @brief long constructor.

    @param number A long integer number.
    @return nothing.
*/
BigInt::BigInt(long number){
    if(number < 0){
        sign = false;
        number = -number;
    } else{
        sign = true;
    }
    if(number == 0)
        digits.push_back(0);
    while(number != 0){
        digits.push_back(number % 10);
        number /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    ignoreLeadingZeros();
}

/**
    @brief long long constructor.

    @param number A long long integer number.
    @return nothing.
*/
BigInt::BigInt(long long number){
    if(number < 0){
        sign = false;
        number = -number;
    } else{
        sign = true;
    }
    if(number == 0)
        digits.push_back(0);
    while(number != 0){
        digits.push_back(number % 10);
        number /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    ignoreLeadingZeros();
}

/**
    @brief unsigned int constructor.

    @param number An unsigned integer number.
    @return nothing.
*/
BigInt::BigInt(unsigned int number){
    sign = true;
    if(number == 0)
        digits.push_back(0);
    while(number != 0){
        digits.push_back(number % 10);
        number /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    ignoreLeadingZeros();
}

/**
    @brief unsigned long constructor.

    @param number An unsigned long integer number.
    @return nothing.
*/
BigInt::BigInt(unsigned long number){
    sign = true;
    if(number == 0)
        digits.push_back(0);
    while(number != 0){
        digits.push_back(number % 10);
        number /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    ignoreLeadingZeros();
}

/**
    @brief unsigned long long constructor.

    @param number An unsigned long long integer number.
    @return nothing.
*/
BigInt::BigInt(unsigned long long number){
    sign = true;
    if(number == 0)
        digits.push_back(0);
    while(number != 0){
        digits.push_back(number % 10);
        number /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    ignoreLeadingZeros();
}

/**
    @brief copy constructor.

    @param constant BigInt reference.
    @return nothing.
*/
BigInt::BigInt(const BigInt& rhs){
    sign = rhs.sign;
    digits.clear();
    digits = rhs.digits;
}

/**
    @brief destructor.

    @param nothing.
    @return nothing.
*/
BigInt::~BigInt(){

}

/**
    @brief erase leading zeros.

    @param nothing.
    @return nothing.
*/
void BigInt::ignoreLeadingZeros(){
    while(digits.at(0) == 0 && digits.size() != 1)
        digits.erase(digits.begin(), digits.begin() + 1);
}

/**
    @brief convert BigInt to std::string.

    @param nothing.
    @return std::string of the BigInt.
*/
std::string BigInt::toString(){
    std::string str = "";
    if(!sign)
        str+="-";
    for(unsigned int i = 0; i < digits.size(); i++)
        str += std::to_string(digits.at(i));
    return str;
}

/**
    @brief assignment operator.

    @param constant reference to BigInt.
    @return reference to BigInt.
*/
BigInt& BigInt::operator=(const BigInt& rhs){
    if(this == &rhs)
        return *this;
    sign = rhs.sign;
    digits.clear();
    digits = rhs.digits;
    return *this;
}

/**
    @brief input number via input stream.

    @param reference to input stream, reference to BigInt.
    @return reference to input stream.
*/
std::istream& operator>>(std::istream& inStream, BigInt& bigint){
    std::string number;
    inStream >> number;

    bigint.digits.clear();
    if(number.at(0) == '-'){
        bigint.sign = false;
        for(size_t i = 1; i < number.length(); i++)
            bigint.digits.push_back(number.at(i) - '0');
    } else{
        bigint.sign = true;
        if(number.at(0) == '+')
            for(size_t i = 1; i < number.length(); i++)
                bigint.digits.push_back(number.at(i) - '0');
        else
            for(size_t i = 0; i < number.length(); i++)
                bigint.digits.push_back(number.at(i) - '0');
    }

    bigint.ignoreLeadingZeros();
    if(bigint.digits.at(0) == 0)
        bigint.sign = true;
    return inStream;
}

/**
    @brief output number via output stream.

    @param reference to output stream, reference to BigInt.
    @return reference to output stream.
*/
std::ostream& operator<<(std::ostream& outStream, BigInt& bigint){
    std::string number = bigint.toString();
    outStream << number;
    return outStream;
}

bool BigInt::operator>(const BigInt& rhs) const{
    if(sign == true && rhs.sign == false) return true;
    else if(sign == false && rhs.sign == true) return false;
    else{
        if(digits.size() > rhs.digits.size())
            return true;
        else if(digits.size() < rhs.digits.size())
            return false;
        else{
            for(size_t i = 0; i<digits.size(); i++){
                if(digits.at(i) > rhs.digits.at(i))
                    return true;
                else if(digits.at(i) < rhs.digits.at(i))
                    return false;
            }
        }
    }
    return false;
}

bool BigInt::operator<(const BigInt& rhs) const{
    if(sign == false && rhs.sign == true) return true;
    else if(sign == true && rhs.sign == false) return false;
    else{
        if(digits.size() < rhs.digits.size())
            return true;
        else if(digits.size() > rhs.digits.size())
            return false;
        else{
            for(size_t i = 0; i<digits.size(); i++){
                if(digits.at(i) < rhs.digits.at(i))
                    return true;
                else if(digits.at(i) > rhs.digits.at(i))
                    return false;
            }
        }
    }
    return false;
}

bool BigInt::operator==(const BigInt& rhs) const{
    if(sign == rhs.sign){
        if(digits.size() > rhs.digits.size() || digits.size() < rhs.digits.size())
            return false;
        else{
            for(size_t i = 0; i < digits.size(); i++){
                if(digits.at(i) != rhs.digits.at(i))
                    return false;
            }
        }
        return true;
    }
    else
        return false;
}

bool BigInt::operator!=(const BigInt& rhs) const{
    if(!(*this == rhs))
        return true;
    else
        return false;
}

bool BigInt::operator>=(const BigInt& rhs) const{
    if(*this > rhs || *this == rhs)
        return true;
    else
        return false;
}

bool BigInt::operator<=(const BigInt& rhs) const{
    if(*this < rhs || *this == rhs)
        return true;
    else
        return false;
}
/**
    @brief Returns absolute value of BigInt.

    @param nothing.
    @return BigInt.
*/
BigInt BigInt::abs() const{
    BigInt a(*this);
    if(a.sign == false) a.sign = true;
    return a;
}

const BigInt BigInt::operator+(const BigInt& rhs) const{
    BigInt sum;
    if(digits.at(0) == 0 && rhs.digits.at(0) == 0) return sum;
    if(sign == rhs.sign){
        sum.digits.clear();
        sum.sign = sign;
        unsigned int carry = 0;
        int index1 = digits.size() - 1;
        int index2 = rhs.digits.size() - 1;
        while(index1 >=0 || index2 >= 0){
            unsigned int d1 = (index1 >= 0) ? digits.at(index1) : 0;
            unsigned int d2 = (index2 >= 0) ? rhs.digits.at(index2) : 0;
            unsigned int digitsum = d1 + d2 + carry;
            if(digitsum > 9){
                carry = digitsum / 10;
                digitsum -= 10;
            } else carry = 0;
            sum.digits.push_back(digitsum);
            index1--;
            index2--;
        }
        if(carry != 0)
            sum.digits.push_back(carry);
        std::reverse(sum.digits.begin(), sum.digits.end());
    } else{
        if(this->abs() > rhs.abs()){
            sum.digits.clear();
            sum = this->abs() - rhs.abs();
            sum.sign = sign;
        } else{
            sum.digits.clear();
            sum = rhs.abs() - this->abs();
            sum.sign = rhs.sign;
        }
    }
    return sum;
}

const BigInt BigInt::operator-(const BigInt& rhs) const{
    BigInt difference;
    if(digits.at(0) == 0 && rhs.digits.at(0) == 0) return difference;
    if(sign == rhs.sign){
        difference.digits.clear();
        std::vector<unsigned int> operand1;
        std::vector<unsigned int> operand2;
        if(this->abs() > rhs.abs()){
            operand1 = digits;
            operand2 = rhs.digits;
            difference.sign = sign;
        } else{
            operand1 = rhs.digits;
            operand2 = digits;
            if(rhs.sign == false)
                difference.sign = true;
            else
                difference.sign = false;
        }

        if(operand1.size() != operand2.size()){
            while(operand1.size() > operand2.size())
                operand2.insert(operand2.begin(), 0);
            while(operand2.size() > operand1.size())
                operand1.insert(operand1.begin(), 0);
        }
        for(int i = operand1.size() - 1; i>=0; i--){
            int j = i-1;
            if(operand1[i] < operand2[i]){
                while(operand1[j] == 0)
                    j--;
                for(int k = j+1; k<i; k++)
                    operand1[k] += 9;
                operand1[j] -= 1;
                operand1[i] +=10;
            }
            difference.digits.push_back(operand1[i] - operand2[i]);
        }
        std::reverse(difference.digits.begin(), difference.digits.end());
        difference.ignoreLeadingZeros();
        if(difference.digits.at(0) == 0)
            difference.sign = true;
    } else{
        difference.digits.clear();
        difference = this->abs() + rhs.abs();
        difference.sign = sign;
    }
    return difference;
}

BigInt& BigInt::operator+=(const BigInt& rhs){
    *this = *this + rhs;
    return *this;
}

BigInt& BigInt::operator-=(const BigInt& rhs){
    *this = *this - rhs;
    return *this;
}

BigInt& BigInt::operator++(){
    BigInt one(1);
    *this += one;
    return *this;
}

BigInt& BigInt::operator--(){
    BigInt one(1);
    *this -= one;
    return *this;
}

BigInt BigInt::operator++(int postfixflag){
    BigInt temp(*this);
    ++(*this);
    return temp;
}

BigInt BigInt::operator--(int postfixflag){
    BigInt temp(*this);
    --(*this);
    return temp;
}

BigInt BigInt::digitMultiply(unsigned int digit) const{
    BigInt result;
    result.digits.clear();
    result.sign = true;
    unsigned int carry = 0;
    for(int i = digits.size()-1; i>=0; i--){
        unsigned int digitproduct = digits.at(i) * digit + carry;
        if(digitproduct > 9){
            carry = digitproduct / 10;
            digitproduct %= 10;
        }
        else
            carry = 0;

        result.digits.push_back(digitproduct);
    }
    if(carry != 0)
        result.digits.push_back(carry);

    std::reverse(result.digits.begin(), result.digits.end());
    return result;
}

const BigInt BigInt::operator*(const BigInt& rhs) const{
    BigInt product;
    BigInt psum;
    unsigned int zeros_to_insert = 0;
    for(int i = rhs.digits.size() - 1; i>=0; i--){
        unsigned int digit = rhs.digits.at(i);
        product = this->digitMultiply(digit);
        product.digits.insert(product.digits.end(), zeros_to_insert++, 0);
        psum += product;
    }
    if(sign != rhs.sign && (digits.at(0) != 0 && rhs.digits.at(0) !=0)) psum.sign = false;
    return psum;
}

BigInt& BigInt::operator*=(const BigInt& rhs){
    *this = *this * rhs;
    return *this;
}
