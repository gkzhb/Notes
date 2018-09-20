#include<iostream>
#include<iomanip>
int main(void) 
{
	std::streamsize t=std::cout.precision();
	
	std::cout<<t<<' '<<1.5555555555<<' '<<std::setprecision(3)<<1.5555555555<<' '
			 <<1.5555555555<<std::setprecision(t)<<' '<<1.5555555555<<' '
			 <<123121231233.123124123;
	return 0;
}
