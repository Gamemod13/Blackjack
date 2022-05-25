#include "Monster.h"

std::string Monster::getTypeString() const {
	switch (m_type)
	{
	case Monster::Dragon:
		return "Dragon";
		break;
	case Monster::Goblin:
		return "Goblin";
		break;
	case Monster::Ogre:
		return "Ogre";
		break;
	case Monster::Orc:
		return "Orc";
		break;
	case Monster::Skeleton:
		return "Skeleton";
		break;
	case Monster::Troll:
		return "Troll";
		break;
	case Monster::Vampire:
		return "Vampire";
		break;
	case Monster::Zombie:
		return "Zombie";
		break;
	default:
		return "ERROR";
		break;
	}
}