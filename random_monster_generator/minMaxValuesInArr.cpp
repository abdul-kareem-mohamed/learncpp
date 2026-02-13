#include <iostream>
#include <vector>
#include <utility>
#include <limits>

template <typename T>
std::pair<int, int> findMinMax(const std::vector<T>& v)
{
    int minInd{};
    int maxInd{};
    for (int index{0}; index < v.size(); ++index)
    {
        if (v[index] > v[maxInd])
        {
            maxInd = index;
        }
        if (v[index] < v[minInd])
        {
            minInd = index;
        }
    }

    return {minInd, maxInd};
}

template <typename T>
void print(const std::pair<int, int>& p, const std::vector<T>& v)
{
    bool comma { false };
    std::cout << "With array ( ";
    for (const auto& e: v)
    {
        if (comma)
            std::cout << ", ";

        std::cout << e;
        comma = true;
    }
    std::cout << " ):\n";

    std::cout << "The min element has index " << p.first << " and value " << v[p.first] << "\n";
    std::cout << "The max element has index " << p.second << " and value " << v[p.second] << "\n";
    std::cout << "\n";
}

int main() 
{
    std::vector<int> v { };
    std::cout << "Enter numbers to add (use -1 to stop): ";

    while (true)
    {
        int input{};
        std::cin >> input;
        if (input == -1)
            break;

        if (!std::cin) // if the previous extraction failed
        {
            std::cin.clear(); // put us back in 'normal' operation mode
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // and remove the bad input
            continue;
        }

        v.push_back(input);
    }

    // If the array is empty
    if (v.size() == 0)
    {
        std::cout << "The array has no elements\n";
    }

    print( findMinMax(v), v );

    return 0;
}
