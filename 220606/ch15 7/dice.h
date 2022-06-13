#ifndef DICE_H
#define DICE_H

class Dice
{
public:
	Dice();
	Dice(int numSides);
	virtual int rollDice() const;

protected:
	int numSides;
};

#endif // !DICE_H