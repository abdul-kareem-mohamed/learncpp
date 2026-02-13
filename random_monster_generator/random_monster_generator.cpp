#include <iostream>
#include "random.h"

class Monster
{
public:
    enum Type 
    {
        ogre,
        dragon,
        orc,
        goblin,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterTypes
    };
    explicit Monster(Monster::Type type, std::string_view name, std::string_view roar, int noOfHitPts)
    : m_type {type},
    m_name {name},
    m_roar {roar},
    m_noOfHitPts {noOfHitPts}
    {

    }

    std::string_view getTypeString(Type type)
    {
        switch (type)
        {
        case Type::ogre: return "the Ogre";
        case Type::dragon: return "the Dragon";
        case Type::orc: return "the Orc";
        case Type::goblin: return "the Goblin";
        case Type::skeleton: return "the Skeleton";
        case Type::troll: return "the Troll";
        case Type::vampire: return "the Vampire";
        case Type::zombie: return "the Zombie";
        default: return "???";
        }
    }

    void print()
    {
        if (m_noOfHitPts)
            std::cout << m_name << " " << getTypeString(m_type) << " has " << m_noOfHitPts << " hit points and says " << m_roar << "\n";
        else 
            std::cout << m_name << " " << getTypeString(m_type) << " is dead.\n";
    }

private:
    Type m_type {};
    std::string m_name {};
    std::string m_roar {};
    int m_noOfHitPts {};
};

namespace MonsterGenerator
{
    std::string_view getName(int n)
	{
        switch (n)
        {
            case 0:  return "Blarg";
            case 1:  return "Moog";
            case 2:  return "Pksh";
            case 3:  return "Tyrn";
            case 4:  return "Mort";
            case 5:  return "Hans";
            default: return "???";
        }
    }

    std::string_view getRoar(int n)
	{
        switch (n)
        {
            case 0:  return "*ROAR*";
            case 1:  return "*peep*";
            case 2:  return "*squeal*";
            case 3:  return "*whine*";
            case 4:  return "*growl*";
            case 5:  return "*burp*";
            default: return "???";
        }
    }

    Monster generate()
	{
		return Monster{ static_cast<Monster::Type>(Random::get(0, 9)), getName(Random::get(0, 5)), getRoar(Random::get(0, 5)), Random::get(1, 100) };
	}
};


int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}
