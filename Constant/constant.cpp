#include <iostream>

#define MY_NAME "Alex"

void printInt(const int x)
{
    std::cout << x << '\n';
}

const int getValue()
{
    return 5;
}

int main()
{
    std::cout << "Enter your age: ";
    int age{};
    std::cin >> age;

    const int constAge { age }; // initialize const variable using non-const value

    age = 5;      // ok: age is non-const, so we can change its value
    //constAge = 6; // error: constAge is const, so we cannot change its value

    printInt(5); // 5 will be used as the initializer for x
    printInt(6); // 6 will be used as the initializer for x

    std::cout << getValue() << '\n';
    std::cout << "My name is: " << MY_NAME << '\n';

    return 0;
}