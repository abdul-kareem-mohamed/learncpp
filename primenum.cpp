#include <iostream>

bool checkPrime(int x)
{
    return x == 2 || x == 3 || x == 5 || x == 7;
}

int main() 
{
    int x{};
    std::cout << "Enter an integer with 0 to 9: ";
    std::cin >> x;

    if (checkPrime(x))
        std::cout << "Number is prime";
    else 
        std::cout << "Number is not prime";
    
    return 0;
}
