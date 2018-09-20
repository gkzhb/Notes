#include <iostream>
#include <string>
int main()
{
    std::string me = "这是啥？";
    std::cout << me << std::endl;
    std::cout << "Hello, world!\t???" << std::endl;
    std::cout << "This (\") is a quote, and this (\\) is a backslash." << std::endl;

    std::string name;
    std::cin >> name;
    const std::string greeting = "Hello, " + name + "! ";
    const std::string spaces(greeting.size() + 1, ' ');
    const std::string second = "*" + spaces + "*";
    const std::string first(second.size(), '*');
    std::cout<<std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << "*" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;
    return 0;
}