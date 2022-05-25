#include "MonsterGenerator.h"

static int getRandomNumber(int min = 1, int max = 100) {
 static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
 return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

static Monster generateMonster() {
	static std::string s_names[6]{ "Andriy","Ann","Jack","Collombo","Bob","Mary" };
	return Monster(Monster::MonsterType(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1)),
		s_names[getRandomNumber(0, 5)],
		getRandomNumber(1, 100));
}