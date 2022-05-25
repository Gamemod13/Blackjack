#ifndef MONSTER_H
#define MONSTER_H
#include<string>
#include<iostream>



class Monster
{
public:
	enum MonsterType {
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		MAX_MONSTER_TYPES
	};
private:
	MonsterType m_type;
	std::string m_name;
	int m_health;
public:
	Monster(MonsterType type, std::string name, int health) :
		m_type(type), m_name(name), m_health(health)
	{
	}
	std::string getTypeString() const;
	void print() {
		std::cout << m_name << " is the " << getTypeString() << " that has " << m_health << " health points." << std::endl;
	}
};
#endif


