/*
* GameCharacter.h
*
* Version information v0.1
* Author: <Conor Roarty - B00657634>
* Date: 24/11/2017
* Description: header file for the abstract GameCharacter class
* Copyright notice
*/
#include <string>
#include <vector>
#include "Weapon.h"
#include "Armour.h"
#include "Common.h"

using namespace std;
#pragma once
class GameCharacter
{

private:
	std::string characterName_;
	float health_, weightLimit_;
	int equippedWeapon_, equippedArmour_, food_;
	vector<Weapon> weapons_;
	vector<Armour> armour_;
	CharacterState state_;
public:
	GameCharacter();

	GameCharacter(std::string characterName,float health, float weightLimit,int equippedWeapon, int equippedArmour, int food,/*vector<Weapon> weapons,vector<Armour> armour,*/ CharacterState state);
	GameCharacter(std::string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, int food, vector<Weapon> weapons,vector<Armour> armour, CharacterState state);
	GameCharacter(std::string characterName, float health, float weightLimit,  int food, CharacterState state);

	~GameCharacter();

	virtual bool Attack(GameCharacter &character)=0;
	virtual void Defend(int armour)=0;
	virtual void Walk() = 0;
	virtual void Run() = 0;
	virtual void Sleep()=0;
	virtual Weapon GetWeapon(int index) = 0;
	virtual Armour GetArmour(int index) = 0;
	virtual bool PickUpWeapon(Weapon &weapon)=0;
	virtual bool PickUpArmour(Armour &armour)=0;
	virtual void DropItem(Weapon &item)=0;
	virtual void DropItem(Armour &item)=0;
	virtual bool EquipWeapon(int weapon) = 0;
	virtual void AddFood(int amount) = 0;
	virtual void Eat()=0;

	virtual std::string GetCharacterName() = 0;
	virtual void SetCharacterName(std::string name) = 0;
	virtual float GetHealth() = 0;
	virtual void SetHealth(float health) = 0;
	virtual float GetWeightLimit() = 0;
	virtual void SetWeightLimit(float weightLimit) = 0;
	virtual int GetEquippedWeapon() = 0;
	virtual void SetEquippedWeapon(int equippedWeapon) = 0;
	virtual int GetEquippedArmour() = 0;
	virtual void SetEquippedArmour(int equippedArmour) = 0;
	virtual int GetFood() = 0;
	virtual void SetFood(int food) = 0;
	virtual vector<Weapon> GetWeapons() = 0;
	virtual void SetWeapons(vector<Weapon> weapons) = 0;
	virtual vector<Armour> GetArmour() = 0;
	virtual void SetArmour(vector<Armour> armour) = 0;
	virtual CharacterState GetState() = 0;
	virtual void SetState(CharacterState state) = 0;
};