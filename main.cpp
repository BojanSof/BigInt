#include <iostream>
#include "bigint.hpp"

using namespace std;

int main()
{
    BigInt p = 1;
    for(int i = 1; i <= 100; i++)
        p*=i;
    cout<<"100! = "<<p<<endl;
}
