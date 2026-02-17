#include <iostream>

int main()
{
    std::cout << "Enter a character: ";

    char input{};
    std::cin >> input;

    std::cout << "The ASCII value of " << input << " is " << static_cast<int>(input) << "\n";

    return 0;
}
