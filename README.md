## Synopsis

Class for supporting arbitrary size integers in C++

## How to use

It is very easy to use:
1. Copy bigint.hpp and bigint.cpp in your project folder
2. Include bigint.hpp
That's it :)
Also be sure that your compiler supports C++11 standard and enable it

## Code example

```c++
#include "bigint.hpp"

int main()
{
   BigInt b1 = 21344;
   BigInt b2("-1231435242643275473473747275548935798");
   BigInt product = b1 * b2;
   std::cout<<b1<<" * "<<b2<<" = "<<product<<std::endl;
}

```

## TODO

- Implement division and modulo operators

