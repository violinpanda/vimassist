#include <string>
#include <map>
#include <iostream>
using namespace std;

void ArraySize(int a[])
{
    cout <<"a.size() = " <<sizeof(a) / sizeof(int) <<endl;
}

void ArrayTest()
{
    int a[] = {1, 3,};
    ArraySize(a);
}