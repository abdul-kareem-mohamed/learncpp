#include <iostream>
#include <string>
#include <string_view>

enum class MonsterType 
{
    ogre,
    slime,
    dragon,
    orc,
    giant_spider,
};

struct MyMonster
{
    MonsterType type{};
    std::string name{};
    int health{};
};

const std::string_view getMonsterTypeString(const MonsterType m)
{
    switch(m) 
    {
        case MonsterType::ogre: return "Ogre";
        case MonsterType::slime: return "Slime";
        case MonsterType::dragon: return "Dragon";
        case MonsterType::orc: return "Orc";
        case MonsterType::giant_spider: return "Giant Spider";
        default: return "Unknown";
    }
}

void printMonster(const MyMonster& p)
{
    std::cout << "This " << getMonsterTypeString(p.type) << " is named " << p.name << " and has " << p.health << " health.\n";
}

int main()
{
    MyMonster monster1 {MonsterType::ogre, "Shrek", 145};
    MyMonster monster2 {MonsterType::slime, "Shady", 23};

    printMonster(monster1);
    printMonster(monster2);

    return 0;
}
