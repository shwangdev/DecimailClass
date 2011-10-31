#include <math.h>
#include "AutoString.h"
#include "Decimal.h"
#include "stdio.h"
#include <iostream>
int Decimal::precision=0;
__int64 Decimal::q=0;
char* Decimal::pad=0L;

// static initialization.  Sets up all decimal arithmetic functions
void Decimal::Initialize(int prec)
{
	precision=prec;
	// create an array of 0's for padding
	pad=new char[precision+1];
	memset(pad, '0', precision);
	pad[precision]='\0';
	// get fractional precision
	q=(__int64)pow(10.0, (double)prec);
}

Decimal::Decimal(void)
{
	n=0;
}

Decimal::Decimal(const Decimal& d)
{
	n=d.n;
}

Decimal::Decimal(const __int64 n)
{
	this->n=n;
}

Decimal::Decimal(int intPart, int fractPart)
{
	n=intPart;
	n*=q;
	n+=(__int64)fractPart;
}

Decimal::Decimal(AutoString num)
{
	// get the integer component
	AutoString intPart=num.LeftEx('.');
	// get the fractional component
	AutoString fractPart=num.RightEx('.');

	// "multiply" the fractional part by the desired precision
	fractPart+=&pad[strlen(fractPart.c_str())];

	// create the 64bit integer as a composite of the
	// integer and fractional components.
	n=atoi(intPart.c_str());
	n*=q;
	n+=atoi(fractPart.c_str());
}

Decimal::~Decimal(void)
{
}

Decimal Decimal::operator+(const Decimal& d)
{
	return Decimal(n + d.n);
}

Decimal Decimal::operator-(const Decimal& d)
{
	return Decimal(n - d.n);
}

Decimal Decimal::operator*(const Decimal& d)
{
	return Decimal(n * d.n / q);
}

Decimal Decimal::operator/(const Decimal& d)
{
	return Decimal(n * q / d.n);
}


Decimal Decimal::operator +=(const Decimal& d)
{
	n=n + d.n;
	return *this;
}

Decimal Decimal::operator -=(const Decimal& d)
{
	n=n - d.n;
	return *this;
}

Decimal Decimal::operator *=(const Decimal& d)
{
	n=n * d.n / q;
	return *this;
}

Decimal Decimal::operator /=(const Decimal& d)
{
	n=n * q / d.n;
	return *this;
}

bool Decimal::operator==(const Decimal& d) const
{
	return n == d.n;
}

bool Decimal::operator!=(const Decimal& d) const
{
	return n != d.n;
}

bool Decimal::operator<(const Decimal& d) const
{
	return n < d.n;
}

bool Decimal::operator<=(const Decimal& d) const
{
	return n <= d.n;
}

bool Decimal::operator>(const Decimal& d) const
{
	return n > d.n;
}

bool Decimal::operator>=(const Decimal& d) const
{
	return n >= d.n;
}

std::string Decimal::ToString(void) const
{
	char s[64];
	__int64 n2=n/q;
	int fract=(int)(n-n2*q);
	sprintf(s, "%d.%0*d", (int)n2, precision, fract);
	return s;
}

double Decimal::ToDouble(void) const
{
	return atof(ToString().c_str());
}


