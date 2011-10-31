#include "AutoString.h"
#include "Decimal.h"
#include "stdio.h"
#include <iostream>
int main( )
{
/*	int nRetCode = 0;

    Decimal::Initialize(4);
    double n=.3;
    n-=.099;
    n*=1000;

    printf("n=%.04lf  (int)n=%d\r\n", n, (int)n);
    printf("n == 201 ? %s\r\n", n==201 ? "yes" : "no");
    printf("n >= 201 ? %s\r\n", n>=201 ? "yes" : "no");

    Decimal dec(".3");
    dec-=Decimal(".099");
    dec*=Decimal("1000");

    printf("dec=%s\r\n", dec.ToString().c_str());
    printf("dec == 201 ? %s\r\n", dec==Decimal("201") ? "yes" : "no");
    printf("dec >= 201 ? %s\r\n", dec>=Decimal("201") ? "yes" : "no");

	return nRetCode;
*/

    Decimal::Initialize(16);
    double n = .3;
    Decimal dec("200");
    std::cout<<dec<<std::endl;
}
