#include<iostream>
class Base{
public:
    //Base(int y=0):y_(y){std::cout<<"Base("<<y<<")\n";}
    Base(int y=0);
    ~Base(){std::cout << "~Base()\n";}
    void print(){std::cout<<y_<<" ";}
private:
    int y_;
};
class Derived: public Base{
public:
    Derived(int y,int z):Base(y),z_(z){}
    ~Derived(){std::cout << "~Derived()\n";}
    void print(){
        Base::print();
        std::cout<<z_<<" ";
    }
private:
    int z_;
};
Base::Base(int y):y_(y){std::cout<<"Base("<<y<<")\n";}
int main(){
    Derived d(10,20);
    d.print();
    return 0;
}

