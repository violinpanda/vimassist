#include <string>
#include <map>
#include <iostream>
using namespace std;

class A
{
public:
    A()
    {}

    A(string name)
        :name(name)
    {}

    ~A()
    {
        cout <<"~A, " <<name <<endl;
    }

private:
    string name;
};

void StlTest()
{
    map<string, A> factory;
    factory["haha"] = A("haha");
    factory["heihei"] = A("heihei");
}