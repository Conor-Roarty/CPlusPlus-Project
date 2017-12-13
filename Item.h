#pragma once
#include <string>


using namespace std;
#pragma once
class Item
{
	string itemName_;
	float weight_;
	int itemValue_;
public:
	Item();
	Item(string name, int value, float weight);
	~Item();

	virtual string GetItemName()=0;
	virtual void SetItemName(string name)=0;
	virtual float GetItemWeight()=0;
	virtual void SetItemWeight(float weight)=0;
	int GetValue();
	void SetValue(int value);
};