#pragma once
#include <string>
#include "Item.h"
#include "Common.h"
using namespace std;
#pragma once
class Armour : public Item
{
	//enum ArmourType {Cardboard, Leather, Wood, Iron, Steel};
	int defence_, armourHealth_;
	ArmourType armourType_;
public:
	Armour();
	Armour(string armourName, int value, float weight, int armourStrength, int armourHealth, ArmourType armourType);
	~Armour();

	int GetDefence();
	void SetDefence(int defence);
	int GetArmourHealth();
	void SetArmourHealth(int health);
	ArmourType GetArmourType();
	void SetArmourHealth(ArmourType type);


	virtual string GetItemName()override;
	virtual void SetItemName(string name) override;

	virtual float GetItemWeight() override;
	virtual void SetItemWeight(float weight) override;

};
