#include "Cleric.h"
#include "Common.h"

Cleric::Cleric() {

}
Cleric::Cleric(string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, int food,
	/*vector<Weapon> weapons, vector<Armour> armour,*/ CharacterState state, int pietyLevel) : GameCharacter{ characterName, health, weightLimit, equippedWeapon, equippedArmour,food,/*weapons,armour,*/state}, pietyLevel_{ pietyLevel } {

}
Cleric::Cleric(string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, int food,
	vector<Weapon> weapons, vector<Armour> armour, CharacterState state, int pietyLevel) : GameCharacter{ characterName, health, weightLimit, equippedWeapon, equippedArmour,food,weapons,armour,state }, pietyLevel_{ pietyLevel } {

}
Cleric::Cleric(string characterName, float health, float weightLimit, /*int equippedWeapon, int equippedArmour,*/ int food,
	/*vector<Weapon> weapons, vector<Armour> armour,*/ CharacterState state, int pietyLevel) : GameCharacter{ characterName, health, weightLimit, -1,-1,food,/*weapons,armour,*/state }, pietyLevel_{ pietyLevel } {

}
Cleric::~Cleric() {

}

void Cleric::PrayFor(GameCharacter &character) {
	GameCharacter::SetState(CharacterState::Idle);
	int random = rand() % 100 + 1;
	int healthBoost{0};
	healthBoost = 5 * pietyLevel_;
	if (random <= 50)
	{
		if(character.GetHealth() <= 100 - healthBoost)
			character.SetHealth(character.GetHealth()+healthBoost);
		else
			character.SetHealth(100);
	}
	//else
	//{
	//	//message saying unsuccessful
	//}
}
void Cleric::Sleep() {
	GameCharacter::Sleep();
}
void Cleric::Eat() {
	GameCharacter::Eat();
}
int Cleric::GetPietyLevel() {
	return pietyLevel_;
}
void Cleric::SetPietyLevel(int pietyLevel) {
	pietyLevel_ = pietyLevel;
}

std::string Cleric::GetCharacterName() {
	return GameCharacter::GetCharacterName();
}
void Cleric::SetCharacterName(std::string name) {
	GameCharacter::SetCharacterName(name);
}
float Cleric::GetHealth() {
	return GameCharacter::GetHealth();
}
void Cleric::SetHealth(float health) {
	GameCharacter::SetHealth(health);
}
float Cleric::GetWeightLimit() {
	return GameCharacter::GetWeightLimit();
}
void Cleric::SetWeightLimit(float weightLimit) {
	GameCharacter::SetWeightLimit(weightLimit);
}
int Cleric::GetEquippedWeapon() {
	return GameCharacter::GetEquippedWeapon();
}
void Cleric::SetEquippedWeapon(int equippedWeapon) {
	GameCharacter::SetEquippedWeapon(equippedWeapon);
}
int Cleric::GetEquippedArmour() {
	return GameCharacter::GetEquippedArmour();
}
void Cleric::SetEquippedArmour(int equippedArmour) {
	GameCharacter::SetEquippedArmour(equippedArmour);
}
int Cleric::GetFood() {
	return GameCharacter::GetFood();
}
void Cleric::SetFood(int food) {
	GameCharacter::SetFood(food);
}
vector<Weapon> Cleric::GetWeapons() {
	return GameCharacter::GetWeapons();
}
void Cleric::SetWeapons(vector<Weapon> weapons) {
	GameCharacter::SetWeapons(weapons);
}
vector<Armour> Cleric::GetArmour() {
	return GameCharacter::GetArmour();
}
void Cleric::SetArmour(vector<Armour> armour) {
	GameCharacter::SetArmour(armour);
}
CharacterState Cleric::GetState() {
	return GameCharacter::GetState();
}
void Cleric::SetState(CharacterState state) {
	GameCharacter::GetState();
}
bool Cleric::PickUpWeapon(Weapon &weapon) {
	return GameCharacter::PickUpWeapon(weapon);
}
bool Cleric::PickUpArmour(Armour &armour) {
	return GameCharacter::PickUpArmour(armour);
}
Armour Cleric::GetArmour(int index) {
	return GameCharacter::GetArmour(index);
}
void Cleric::DropItem(Weapon &item) {
	GameCharacter::DropItem(item);
}
void Cleric::DropItem(Armour &item) {
	GameCharacter::DropItem(item);
}

void Cleric::Defend(int armour) {
	GameCharacter::Defend(armour);
}
void Cleric::Walk() {
	GameCharacter::Walk();
}
void Cleric::Run() {
	GameCharacter::Run();
}
Weapon Cleric::GetWeapon(int index) {
	return GameCharacter::GetWeapon(index);
}
bool Cleric::EquipWeapon(int weapon) {
	return GameCharacter::EquipWeapon(weapon);
}
void Cleric::AddFood(int amount) {
	GameCharacter::AddFood(amount);
}
