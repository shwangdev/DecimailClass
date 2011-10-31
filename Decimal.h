#pragma once
#ifndef WIN32
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
typedef int64_t __int64;
#endif
#include <iostream>
class Decimal
{
public:

    static void Initialize(int precision);

    Decimal(void);
    Decimal(AutoString num);
    Decimal(const Decimal& d);
    Decimal(const __int64 n);
    Decimal(int intPart, int fractPart);

    virtual ~Decimal(void);

    Decimal operator+(const Decimal&);
    Decimal operator-(const Decimal&);
    Decimal operator*(const Decimal&);
    Decimal operator/(const Decimal&);

    Decimal operator +=(const Decimal&);
    Decimal operator -=(const Decimal&);
    Decimal operator *=(const Decimal&);
    Decimal operator /=(const Decimal&);

    bool operator==(const Decimal&) const;
    bool operator!=(const Decimal&) const;
    bool operator<(const Decimal&) const;
    bool operator<=(const Decimal&) const;
    bool operator>(const Decimal&) const;
    bool operator>=(const Decimal&) const;

    std::string ToString(void) const;
    double ToDouble(void) const;

    friend std::ostream & operator << ( std::ostream & os, const Decimal & dec)
    {
        os<<dec.ToString();
        return os;
    }

protected:

    __int64 n;

    static int precision;
    static __int64 q;
    static char* pad;
};



