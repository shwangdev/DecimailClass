#ifndef CSTRINGEX_H
#define CSTRINGEX_H

#include<string>
//#include "StdString.h"

template<class Type>
inline const Type& SSMIN(const Type& arg1, const Type& arg2)
{
	return arg2 < arg1 ? arg2 : arg1;
}
template<class Type>
inline const Type& SSMAX(const Type& arg1, const Type& arg2)
{
	return arg2 > arg1 ? arg2 : arg1;
}

typedef unsigned int DWORD;
typedef std::string CString;

class AutoString: public std::string
{
public:

    enum Options
    {
        NO_OPTIONS=0,
        COMMA_DELIMIT=1,
    };

public:

    AutoString(void) {};
    AutoString(const CString& s) : CString(s) {}
    AutoString(const char* s) : CString(s) {}
    AutoString(const char c) {char s[2]={'\0', '\0'}; s[0]=c; CString::operator=(s);}
    AutoString(int i, const char* format="%d", DWORD options=NO_OPTIONS);
    AutoString(double d, const char* format="%.04lf", DWORD options=NO_OPTIONS);
    virtual ~AutoString() {};

    AutoString Left(int n ) const
    {
        return substr(n);
    }
    AutoString Right( int  n ) const
    {
        return substr( size() - n - 1, n);
    }
    AutoString LeftEx(char c, int n=1) const;					// everything to the left of the nth occurance of <c>
    AutoString RightEx(char c, int n=1) const;					// everything to the right of the nth occurance of <c>
    AutoString Rightmost(char c) const;							// everything to the right of the last occurance of <c>
    AutoString LeftOfRightmost(char c) const;					// everything to the left of the last occurance of <c>
    AutoString SubStr(int begin, int len) const;					// substring from s[begin] to s[begin+len]
    AutoString Mid(int begin, int end) const
    {
        return substr(begin,end);
    }
    size_t GetLength() const {
        return size();
    }

    AutoString CommaDelimitNumber(const char* s);
    AutoString& operator=(const CString& s) {CString::operator=(s); return *this;}
    AutoString& operator=(const char* s) {CString::operator=(s); return *this;}

};

#endif
