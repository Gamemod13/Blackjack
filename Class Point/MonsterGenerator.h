#pragma once
#include"Monster.h"
#include<string>



class MonsterGenerator
{
private:
	static int getRandomNumber(int min , int max );
public:
	static Monster generateMonster();

};