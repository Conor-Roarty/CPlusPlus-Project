#include "Weapon.h"

Weapon::Weapon() {

}
Weapon::Weapon(string weaponName, int value, float weight, int hitStrength, int health) 
	: Item{ weaponName, value, weight },weaponHitStrength_{ hitStrength }, weaponHealth_{ health } {

}
Weapon::~Weapon() {

}
int Weapon::GetWeaponHitStrength() {
	return weaponHitStrength_;
}
void Weapon::SetWeaponHitStrength(int strength) {
	weaponHitStrength_ = strength;
}
int Weapon::GetWeaponHealth() {
	return weaponHealth_;
}
void Weapon::SetWeaponHealth(int health) {
	weaponHealth_ = health;
}
float Weapon::GetItemWeight() {
	return Item::GetItemWeight();
}

void Weapon::SetItemWeight(float weight) {
	Item::SetItemWeight(weight);
}
string Weapon::GetItemName() {
	return Item::GetItemName();
}
void Weapon::SetItemName(string name) {
	Item::SetItemName(name);
}