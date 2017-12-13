#pragma once
#include <string>
#include "Item.h"
using namespace std;
#pragma once
class Weapon : public Item
{
	int weaponHitStrength_, weaponHealth_;
public:
	Weapon();
	Weapon(string weaponName, int value, float weight, int hitStrength, int health);
	~Weapon();

	virtual float GetItemWeight() override;
	virtual void SetItemWeight(float weight) override;

	virtual string GetItemName()override;
	virtual void SetItemName(string name) override;

	int GetWeaponHitStrength();
	void SetWeaponHitStrength(int strength);
	int GetWeaponHealth();
	void SetWeaponHealth(int health);
};
