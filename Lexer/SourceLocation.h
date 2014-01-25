#ifndef __SOURCE_LOCATION_H__
#define __SOURCE_LOCATION_H__

class SourceLocation
{
public:
    SourceLocation(int row, int column)
        : Row(row),
        Column(column)
    {
    }

    SourceLocation()
        : Row(0), Column(0)
    {
    }

    int Row;
    int Column;
};
#endif
