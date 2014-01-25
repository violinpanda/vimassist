#ifndef __TYPE_TABLE_H__
#define __TYPE_TABLE_H__

class TypeTable
{
public:
    static TypeTable& GetMe();
    static void Release();

private:
    TypeTable();
    map<wstring, Type> table;
}

#endif
