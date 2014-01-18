#ifndef __SOURCE_FILE_H__
#define __SOURCE_FILE_H__
#include "Basic\Common.h"
#include <vector>

class Token;

class SourceFile
{
public:
	SourceFile(const _TCHAR* path);
	~SourceFile();

    void ParseFile();
    const Token* MoveToNext();
    const Token* MoveToPrev();

private:
    const char* path;
    vector<Token*> tokens;
    int currentIndex;
};

#endif
