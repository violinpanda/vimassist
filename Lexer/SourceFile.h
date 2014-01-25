#ifndef __SOURCE_FILE_H__
#define __SOURCE_FILE_H__
#include "Basic\Common.h"
#include <vector>
#include <string>

class Token;

class SourceFile
{
public:
	SourceFile(const string path);
	~SourceFile();

    void ParseFile();
    const Token* MoveToNext();
    const Token* MoveToPrev();

private:
    void SkipWhitespaces(const wstring &stream, int &pos, int &spaceCount, int &tabCount);
    const string path;
    vector<Token*> tokens;
    int currentIndex;
};

#endif
