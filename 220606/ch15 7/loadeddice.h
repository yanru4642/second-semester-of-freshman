#pragma once
#include "dice.h"

class LoadedDice :public Dice {
public:
	LoadedDice();
	LoadedDice(int numSides);
	virtual int rollDice() const override;
};