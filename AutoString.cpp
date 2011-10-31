#include <stdio.h>
#include <string.h>

#include "AutoString.h"
#include<algorithm>
#include<string.h>
AutoString::AutoString(int i, const char* format, DWORD options)
{
	char s[64];							// Eeek, a hard coded limit on integer sizes!
	sprintf(s, format, i);
	if (options & COMMA_DELIMIT)
	{
		CString::operator=(CommaDelimitNumber(s));
	}
	else
	{
		CString::operator=(s);
	}
}


AutoString::AutoString(double d, const char* format, DWORD options)
{
	char s[64];							// Eeek, a hard coded limit on double sizes!
/*
  double m=d-(int)d;
  m*=100;
  m=m-(int)m;
  if (m>=.50)
  {
  d+=.01;
  }
*/
	sprintf(s, format, d);
	if (options & COMMA_DELIMIT)
	{
		CString::operator=(CommaDelimitNumber(s));
	}
	else
	{
		CString::operator=(s);
	}
}


// extracts string to the left of c, or entire string if c does not exist in str
AutoString AutoString::LeftEx(char c, int q) const
{
	int n=0;
	while (q)
	{
		n=find(c, n);
		if (n != -1)
		{
			++n;
		}
		else
		{
			return *this;
		}
		--q;
	}

	return Left(n-1);
}


// extracts string to the right of c, or returns empty string if c does not exist in str
AutoString AutoString::RightEx(char c, int q) const
{
	int n=0;
	while (q)
	{
		n=find(c, n);
		if (n == -1)
		{
			return "";
		}
		--q;
		++n;
	}
	return Right(GetLength()-n);
}


// return the string to the right of the rightmost instance of c, or an empty string if c does not exist in str
AutoString AutoString::Rightmost(char c) const
{
	//int n=ReverseFind(c);
    int n = rfind(c);
	if (n == -1)
	{
		return "";
	}
	return Right(GetLength()-n-1);
}


// return the string to the left of the rightmost instance of c, or an empty string if c does not exist in str
AutoString AutoString::LeftOfRightmost(char c) const
{
	//int n=ReverseFind(c);
    int n = rfind(c);
	if (n == -1)
	{
		return "";
	}
	return Left(n);
}


AutoString AutoString::SubStr(int begin, int len) const
{
	return Mid(begin, len);
}


AutoString AutoString::CommaDelimitNumber(const char* s)
{
	AutoString s2=s;										// convert to AutoString
	AutoString q=s2.LeftEx('.');								// get everything to the left of the first decimal point
	char posNegChar=q[0];									// get the first char
	bool posNeg=!isdigit(posNegChar);							// if not digit, then assume + or -
	if (posNeg)											// if so, strip off
	{
		q=q.SubStr(1, strlen(q.c_str())-1);
	}
	AutoString dp=s2.RightEx('.');								// remember everything to the right of the decimal point
	AutoString q2;											// working string
	while (strlen(q.c_str()) > 3)									// if more than three digits...
	{
		AutoString s3=AutoString(",")+q.SubStr(strlen(q.c_str())-3, 3);	// insert a comma before the last three digits (100's)
		q2=s3+q2;											// append this to our working string
		q=q.SubStr(0, strlen(q.c_str())-3);							// get everything except the last three digits
	}
	q2=q+q2;												// prepend remainder to the working string
	if (dp != "")											// if we have decimal point...
	{
		q2=q2+"."+dp;										// append it and the digits
	}
	if (posNeg)											// if we stripped off a +/- ...
	{
		q2=AutoString(posNegChar+q2);							// add it back in
	}
	return q2;											// this is our final comma delimited string
}
