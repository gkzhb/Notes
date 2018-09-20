#include<iostream>	
class Hey
{
public:
	Hey():data(0) { }
	static int i;
	static int add(Hey &x)
	{
		return ++x.data;
	}
private:
		int data;
};
int Hey::i=0;
int main(void)
{


	Hey x;

	std::cout<<x.i<<std::endl;
	std::cout<<Hey::i<<std::endl;
	x.i=10;
	std::cout<<Hey::add(x)<<std::endl;
	std::cout<<x.i<<std::endl;
	std::cout<<Hey::i<<std::endl;
	
	std::cout<<"What the hell?"<<std::endl;
	return 0;
}
