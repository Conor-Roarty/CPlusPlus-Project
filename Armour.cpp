#include "Armour.h"
#include "Common.h"

Armour::Armour() {

}
Armour::Armour(string armourName, int value, float weight, int armourStrength, int armourHealth, ArmourType armourType) : Item{ armourName, value, weight }, 
defence_{ armourStrength }, armourHealth_{ armourHealth }, armourType_{armourType} {

}
Armour::~Armour() {

}

int Armour::GetDefence() {
	return defence_;
}
void Armour::SetDefence(int defence) {
	defence_ = defence;
}
int Armour::GetArmourHealth() {
	return armourHealth_;
}
void Armour::SetArmourHealth(int health) {
	armourHealth_ = health;
}
ArmourType Armour::GetArmourType() {
	return armourType_;
}
void Armour::SetArmourHealth(ArmourType type) {
	armourType_ = type;
}
float Armour::GetItemWeight() {
	return Item::GetItemWeight();
}
void Armour::SetItemWeight(float weight) {
	Item::SetItemWeight(weight);
}
string Armour::GetItemName() {
	return Item::GetItemName();
}
void Armour::SetItemName(string name) {
	Item::SetItemName(name);
}