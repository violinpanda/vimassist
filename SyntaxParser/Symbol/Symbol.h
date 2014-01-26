#ifndef __TYPE_H__
#define __TYPE_H__

class Type
{
public:
    Type();
    ~Type();
    const wstring GetName();
    const wstring GetId();

private:
    Type *parentScope;
    wstring name;
}

#endif
