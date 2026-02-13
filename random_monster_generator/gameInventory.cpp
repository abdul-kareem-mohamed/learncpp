#include <iostream>
#include <vector>
#include <assert.h>

namespace Items
{
    enum Item 
    {
        healthPotion,
        torch,
        arrow,
        maxItems
    };
}

std::string_view getTypeStringSingular(Items::Item type)
	{
        switch (type)
        {
            case Items::healthPotion:  return "health potion";
            case Items::torch:  return "torch";
            case Items::arrow:  return "arrow";
            default: return "???";
        }
    }

std::string_view getTypeStringPlural(Items::Item type)
{
    switch (type)
    {
        case Items::healthPotion:  return "health potions";
        case Items::torch:  return "torches";
        case Items::arrow:  return "arrows";
        default: return "???";
    }
}

int countTotalItems(const std::vector<int>& inventory)
{
    
    int sum {0};
    for (int item : inventory)
        sum += item;
    return sum;
}

void printEachItems(const std::vector<int>& inv)
{
    for (int index{0}; index < inv.size(); ++index) 
    {
        std::cout << "You have " << inv[index] << " ";
        std::cout << ((inv[index] > 1) ? getTypeStringPlural(static_cast<Items::Item>(index)) : getTypeStringSingular(static_cast<Items::Item>(index))) << "\n";
    }
}

int main() 
{
    std::vector inventory {1, 5, 10};

    assert(inventory.size() == static_cast<int>(Items::maxItems) && "The size of the inventory not matching with the size of eachItems list");

    printEachItems(inventory);

    std::cout << "You have " << countTotalItems(inventory) << " total items.\n";
}
