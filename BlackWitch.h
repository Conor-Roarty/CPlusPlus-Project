#pragma once
#include <string>
#include "GameCharacter.h"
#include "Common.h"
using namespace std;

class BlackWitch : public GameCharacter
{
	int magicProficiency_, darkPower_;
public:
	BlackWitch();
	BlackWitch( string characterName,float health, float weightLimit,int equippedWeapon, int equippedArmour, int food,
		/*vector<Weapon> weapons,vector<Armour> armour,*/ CharacterState state, int magic, int darkPower);

	//full constructor in the event the player has played before and is using a saved file
	BlackWitch(string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, int food,
		vector<Weapon> weapons,vector<Armour> armour, CharacterState state, int magic, int darkPower);

	BlackWitch(string characterName, float health, float weightLimit, /*int equippedWeapon, int equippedArmour,*/ int food,
		/*vector<Weapon> weapons,vector<Armour> armour,*/ CharacterState state, int magic, int darkPower);
	~BlackWitch();

	virtual bool Attack(GameCharacter &character) override;
	virtual bool Bewitch(GameCharacter &character);

	virtual void Sleep() override;
	virtual void Eat() override;

	int GetMagicProficiency();
	void SetMagicProficiency(int magic);
	int GetDarkPower();
	void SetDarkPower(int darkPower);

	virtual string GetCharacterName() override;
	virtual void SetCharacterName(std::string name)override;
	virtual float GetHealth()override;
	virtual void SetHealth(float health)override;
	virtual float GetWeightLimit()override;
	virtual void SetWeightLimit(float weightLimit)override;
	virtual int GetEquippedWeapon()override;
	virtual void SetEquippedWeapon(int equippedWeapon)override;
	virtual int GetEquippedArmour()override;
	virtual void SetEquippedArmour(int equippedArmour)override;
	virtual int GetFood()override;
	virtual void SetFood(int food)override;
	virtual vector<Weapon> GetWeapons()override;
	virtual void SetWeapons(vector<Weapon> weapons)override;
	virtual vector<Armour> GetArmour()override;
	virtual void SetArmour(vector<Armour> armour)override;
	virtual CharacterState GetState()override;
	virtual void SetState(CharacterState state)override;
	virtual Armour GetArmour(int index)override;

	virtual bool PickUpWeapon(Weapon &weapon) override;
	virtual bool PickUpArmour(Armour &armour) override;
	virtual void DropItem(Weapon &item)override;
	virtual void DropItem(Armour &item)override;
	virtual void Defend(int armour)override;
	virtual void Walk()override;
	virtual void Run()override;
	virtual Weapon GetWeapon(int index)override;
	virtual bool EquipWeapon(int weapon)override;
	virtual void AddFood(int amount)override;


};
