/*
* GameCharacter.cpp
*
* Version information v0.1
* Authors: <Conor Roarty - B00657634>
* Date: 24/11/2017
* Description: Implementation for GameCharacter class
* Copyright notice
*/

#include "GameCharacter.h"
#include "Common.h"
//GameCharacter c{};
using namespace std;
GameCharacter::GameCharacter() :
	characterName_{ "" }, health_{ 100 }, weightLimit_{ 0 }, equippedWeapon_{ -1 }, equippedArmour_{ -1 }, food_{ 0 }, state_{ CharacterState::Idle } {

}

GameCharacter::GameCharacter(string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, int food, /*vector<Weapon> weapons, vector<Armour> armour,*/ CharacterState state) :
	characterName_{ characterName }, health_{ health }, weightLimit_{ weightLimit }, equippedWeapon_{ equippedWeapon }, equippedArmour_{ equippedArmour }, food_{ food }, /*weapons_{ weapons }, armour_{ armour },*/ state_{state} {

}
GameCharacter::GameCharacter(string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, int food, vector<Weapon> weapons, vector<Armour> armour, CharacterState state) :
	characterName_{ characterName }, health_{ health }, weightLimit_{ weightLimit }, equippedWeapon_{ equippedWeapon }, equippedArmour_{ equippedArmour }, food_{ food }, weapons_{ weapons }, armour_{ armour }, state_{ state } {

}
GameCharacter::GameCharacter(string characterName, float health, float weightLimit,/* int equippedWeapon, int equippedArmour,*/ int food, /*vector<Weapon> weapons, vector<Armour> armour,*/ CharacterState state) :
	characterName_{ characterName }, health_{ health }, weightLimit_{ weightLimit },/* equippedWeapon_{ equippedWeapon }, equippedArmour_{ equippedArmour },*/ food_{ food }, /*weapons_{ weapons }, armour_{ armour },*/ state_{ state } {

}

GameCharacter::~GameCharacter(){
}

bool GameCharacter::Attack(GameCharacter &character) {

	state_ = CharacterState::Idle;
	int random = rand() % 100 + 1;
	if (equippedWeapon_ != -1)
	{
		if (character.state_ !=CharacterState::Dead)
		{
			if (health_ >= 20) 
			{
				if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() >= weapons_[equippedWeapon_].GetWeaponHitStrength())
				{
					if (random <= 20)
					{
						if (character.GetState() == CharacterState::Defending)
						{
							//character.SetHealth(character.GetHealth() - 10);
							if (character.GetHealth() > 10)
								character.SetHealth(character.GetHealth() - 10);
							else {
								character.SetHealth(0);
								character.SetState(CharacterState::Dead);
							}
							if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > 10)
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth()-10);
							else {
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
								character.GetArmour().erase(character.GetArmour().begin() + character.equippedWeapon_);
							}
								
						}
						else if (character.GetState() == CharacterState::Sleeping)
						{
							character.SetHealth(0);
							character.SetState(CharacterState::Dead);

							if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > 10)
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - 10);
							else {
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
								character.GetArmour().erase(character.GetArmour().begin() + character.equippedWeapon_);
							}
						}
						else
						{
							//character.SetHealth(character.GetHealth() - 10);
							if (character.GetHealth() > 20)
								character.SetHealth(character.GetHealth() - 20);
							else {
								character.SetHealth(0);
								character.SetState(CharacterState::Dead);
							}
							if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > 10)
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - 10);
							else {
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
								character.GetArmour().erase(character.GetArmour().begin() + character.equippedWeapon_);
							}
						}
					}
					else
					{
						int selfDamage = rand() % 20 + 10;

						if(weapons_[equippedWeapon_].GetWeaponHitStrength() >= selfDamage)
							weapons_[equippedWeapon_].SetWeaponHitStrength(weapons_[equippedWeapon_].GetWeaponHitStrength() - selfDamage);
						else
						{
							weapons_[equippedWeapon_].SetWeaponHitStrength(0);
							weapons_.erase(weapons_.begin() + equippedWeapon_);
						}
						return false;
					}
					return true;
				}
				else if (character.GetEquippedArmour() == -1)
				{
					if (random <= 80)
					{
						if (character.GetState() == CharacterState::Defending)
						{
							//character.SetHealth(character.GetHealth() - 10);
							if (character.GetHealth() > 10)
								character.SetHealth(character.GetHealth() - 10);
							else {
								character.SetHealth(0);
								character.SetState(CharacterState::Dead);
							}
						}
						else if (character.GetState() == CharacterState::Sleeping)
						{
							character.SetHealth(0);
							character.SetState(CharacterState::Dead);
						}
						else
						{
							//character.SetHealth(character.GetHealth() - 10);
							if (character.GetHealth() > 20)
								character.SetHealth(character.GetHealth() - 20);
							else {
								character.SetHealth(0);
								character.SetState(CharacterState::Dead);
							}
						}
						return true;
					}
					else
						return false;
				}
				else
				{
					if (random <= 60)
					{
						if (character.GetState() == CharacterState::Defending)
						{
							//character.SetHealth(character.GetHealth() - 10);
							if (character.GetHealth() > 10)
								character.SetHealth(character.GetHealth() - 10);
							else {
								character.SetHealth(0);
								character.SetState(CharacterState::Dead);
							}
							if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > 10)
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - 10);
							else {
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
								character.GetArmour().erase(character.GetArmour().begin() + character.equippedWeapon_);
							}

						}
						else if (character.GetState() == CharacterState::Sleeping)
						{
							character.SetHealth(0);
							character.SetState(CharacterState::Dead);

							if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > 10)
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - 10);
							else {
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
								character.GetArmour().erase(character.GetArmour().begin() + character.equippedWeapon_);
							}
						}
						else
						{
							//character.SetHealth(character.GetHealth() - 10);
							if (character.GetHealth() > 20)
							{
								character.SetHealth(character.GetHealth() - 20);
							}
							else {
								character.SetHealth(0);
								character.SetState(CharacterState::Dead);
							}
							if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > 10)
							{
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - 10);
							}
							else {
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
								character.GetArmour().erase(character.GetArmour().begin() + character.equippedWeapon_);
							}
						}
						return true;
					}
					else
					{
						int selfDamage = rand() % 20 + 10;

						if (weapons_[equippedWeapon_].GetWeaponHitStrength() >= selfDamage)
							weapons_[equippedWeapon_].SetWeaponHitStrength(weapons_[equippedWeapon_].GetWeaponHitStrength() - selfDamage);
						else
						{
							weapons_[equippedWeapon_].SetWeaponHitStrength(0);
							weapons_.erase(weapons_.begin() + equippedWeapon_);
						}
						return false;
					}
				}
			}
			else {
				//maybe say "Too Weak To Attack, else do above code for failure"
				return false;
			}
		}
		else
			return false;
	}//ask if they need reduced health for these 2 or if the attack never gets carried out
	else
		return false;
}
void GameCharacter::Defend(int armour) {
	
	if (armour < -1 || armour >= armour_.size())
		equippedArmour_ = -1;
	else {
		equippedArmour_ = armour;
		state_ = CharacterState::Defending;
	}
}
void GameCharacter::Walk() {
	state_ = CharacterState::Walking;
}
void GameCharacter::Run() {
	state_ = CharacterState::Running;
}
void GameCharacter::Sleep() {
	state_ = CharacterState::Sleeping;
	if (health_ < 80)
		health_ = health_ + (health_ / 5);
	else
		health_ = 100;
}
Weapon GameCharacter::GetWeapon(int index) {
	return weapons_[index];
}
Armour GameCharacter::GetArmour(int index) {
	return armour_[index];
}
bool GameCharacter::PickUpWeapon(Weapon &weapon) {
	float currentWeight{ 0.0f };
	for each (Weapon w in weapons_){
		currentWeight += w.GetItemWeight();
	}
	for each (Armour a in armour_) {
		currentWeight += a.GetItemWeight();
	}

	if (weightLimit_ < (currentWeight + weapon.GetItemWeight()))
		return false;
	else{
		weapons_.push_back(weapon);
		return true;
	}
}
bool GameCharacter::PickUpArmour(Armour &armour) {
	float currentWeight{ 0.0f };
	for each (Weapon w in weapons_) {
		currentWeight += w.GetItemWeight();
	}
	for each (Armour a in armour_) {
		currentWeight += a.GetItemWeight();
	}
	if (weightLimit_ < (currentWeight + armour.GetItemWeight()))
		return false;
	else {
		armour_.push_back(armour);
		return true;
	}
}
void GameCharacter::DropItem(Weapon &item) {
	//NEEDS UPDATE FOR IF ITS THE EQUIPPED WEAPON THEN EQUIPPED EQUALS -1
	//Weapon w{ item };
	//int i{ 0 };
	bool found = false;
	for(int i = 0; i < weapons_.size(); i++)//Weapon weapon in weapons_)
	{
		if (found == false) {
			if (item.GetItemName() == weapons_[i].GetItemName())
				if (item.GetItemWeight() == weapons_[i].GetItemWeight())
					if (item.GetWeaponHealth() == weapons_[i].GetWeaponHealth())
						if (item.GetWeaponHitStrength() == weapons_[i].GetWeaponHitStrength())
							if (item.GetValue() == weapons_[i].GetValue()) {
								weapons_.erase(weapons_.begin() + i);
								found = true;
							}
		}
		//i++;
		if (found == true && i == equippedWeapon_)
			equippedWeapon_ = -1;


	}
	//auto i = weapons_.end() - std::find(weapons_.begin(), weapons_.end(), item);
	//ptrdiff_t pos = find(weapons_.begin(), weapons_.end(), item) - weapons_.begin();
	//weapons_.erase(weapons_.begin() + pos);
	//weapons_.erase(std::find(weapons_.begin(), weapons_.end(), item), weapons_.end());
}
void GameCharacter::DropItem(Armour &item) {
	//Armour a{ item };
	//int i{ 0 };
	bool found = false;
	for (int i = 0; i < armour_.size(); i++)
	{
		if (found == false) {
			if (armour_[i].GetItemName() == item.GetItemName())
				if (armour_[i].GetItemWeight() == item.GetItemWeight())
					if (armour_[i].GetArmourHealth() == item.GetArmourHealth())
						if (armour_[i].GetArmourType() == item.GetArmourType())
							if (armour_[i].GetDefence() == item.GetDefence())
								if (armour_[i].GetValue() == item.GetValue()) {
									armour_.erase(armour_.begin() + i);
									found = true;
								}
		}
		//i++;
		if (found == true && i == equippedWeapon_)
			equippedWeapon_ = -1;

	}

	//auto i = std::find(armour_.begin(), armour_.end(), a);
	//armour_.erase(i);
	//armour_.erase(std::find(armour_.begin(), armour_.end(), item), armour_.end());

}
bool GameCharacter::EquipWeapon(int weapon) {
	if (weapon <= weapons_.size()) {
		if (weapon != -1) {
			equippedWeapon_ = weapon;
			return true;
		}
		else//maybe a message to say unequipped
			return false;
	}
	else
		return false;//for weapon does not exist

}
void GameCharacter::AddFood(int amount) {
	food_ = food_ + amount;
}
void GameCharacter::Eat() {
	int units{ 0 };
	float healthToAdd{0};
	if (health_ < 100) {

		units = food_ / 5;
		healthToAdd = (float)units / 4;
		food_ = food_ - (food_ / 5);

		if (health_ <= (100- healthToAdd))
			health_ = health_ + healthToAdd;
		else
			health_ = 100;
	}
	else
	{
		food_ = food_ - (food_ / 5);
	}
}

//GETS AND SETS
string GameCharacter::GetCharacterName() {
	return characterName_;
}
void GameCharacter::SetCharacterName(string name) {
	characterName_ = name;
}
float GameCharacter::GetHealth() {
	return health_;
}
void GameCharacter::SetHealth(float health) {
	health_ = health;
}
float GameCharacter::GetWeightLimit() {
	return weightLimit_;
}
void GameCharacter::SetWeightLimit(float weightLimit) {
	weightLimit_ = weightLimit;
}
int GameCharacter::GetEquippedWeapon() {
	return equippedWeapon_;
}
void GameCharacter::SetEquippedWeapon(int equippedWeapon) {
	equippedWeapon_ = equippedWeapon;
}
int GameCharacter::GetEquippedArmour() {
	if (armour_.size() <= 0)
		return -1;
	else
		return equippedArmour_;
}
void GameCharacter::SetEquippedArmour(int equippedArmour) {
	equippedArmour_ = equippedArmour;
}
int GameCharacter::GetFood() {
	return food_;
}
void GameCharacter::SetFood(int food) {
	food_ = food;
}
vector<Weapon> GameCharacter::GetWeapons() {
	return weapons_;
}
void GameCharacter::SetWeapons(vector<Weapon> weapons) {
	weapons_ = weapons;
}
vector<Armour> GameCharacter::GetArmour() {
	return armour_;
}
void GameCharacter::SetArmour(vector<Armour> armour) {
	armour_ = armour;
}
CharacterState GameCharacter::GetState() {
	return state_;
}
void GameCharacter::SetState(CharacterState state) {
	state_ = state;
}
