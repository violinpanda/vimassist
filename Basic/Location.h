#ifndef __SOURCE_LOCATION_H__
#define __SOURCE_LOCATION_H__

class Location
{
public:
    Location(int row, int column)
        : Row(row),
        Column(column)
    {
    }

    Location()
        : Row(0), Column(0)
    {
    }

    int Row;
    int Column;
};

#endif
