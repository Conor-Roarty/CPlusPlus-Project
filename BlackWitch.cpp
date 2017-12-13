#include "BlackWitch.h"
#include "GameCharacter.h"
#include "Common.h"

BlackWitch::BlackWitch() {

}
BlackWitch::BlackWitch( string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, int food,
	/*vector<Weapon> weapons, vector<Armour> armour,*/ CharacterState state, int magic, int darkPower) : GameCharacter{ characterName, health, weightLimit, equippedWeapon, equippedArmour,food,/*weapons,armour,*/state }, darkPower_{ darkPower }, magicProficiency_{ magic } {

}
BlackWitch::BlackWitch(string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, int food,
	vector<Weapon> weapons, vector<Armour> armour, CharacterState state, int magic, int darkPower) : GameCharacter{ characterName, health, weightLimit, equippedWeapon, equippedArmour,food,weapons,armour,state }, darkPower_{ darkPower }, magicProficiency_{ magic } {

}
BlackWitch::BlackWitch(string characterName, float health, float weightLimit, /*int equippedWeapon, int equippedArmour,*/ int food,
	/*vector<Weapon> weapons, vector<Armour> armour,*/ CharacterState state, int magic, int darkPower) : GameCharacter{ characterName, health, weightLimit,-1,-1,food,/*weapons,armour,*/state }, darkPower_{ darkPower }, magicProficiency_{ magic } {

}
BlackWitch::~BlackWitch() {

}

bool BlackWitch::Attack(GameCharacter &character) {
	GameCharacter::Attack(character);
	int random{ 0 };
	if(darkPower_ == 100)
		random = rand() % 80 + 1;
	else
		random = rand() % 100 + 1;

	if (this->GetEquippedWeapon() != -1)
	{
		if (character.GetState() != CharacterState::Dead)
		{
			if (this->GetHealth() >= 20)
			{
				if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() >= this->GetWeapon(this->GetEquippedWeapon()).GetWeaponHitStrength())
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
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - 10);
							else {
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
								character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
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
								character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
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
								character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
							}
						}
						return true;
					}
					else
					{
						int selfDamage = rand() % 20 + 10;

						if (this->GetWeapon(this->GetEquippedWeapon()).GetWeaponHitStrength() >= selfDamage)
							this->GetWeapon(this->GetEquippedWeapon()).SetWeaponHitStrength(this->GetWeapon(this->GetEquippedWeapon()).GetWeaponHitStrength() - selfDamage);
						else
						{
							this->GetWeapon(this->GetEquippedWeapon()).SetWeaponHitStrength(0);
							this->GetWeapons().erase(this->GetWeapons().begin() + this->GetEquippedWeapon());
						}
						return false;
					}
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
								character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
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
								character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
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
								character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
							}
						}
						return true;
					}
					else
					{
						int selfDamage = rand() % 20 + 10;

						if (this->GetWeapon(this->GetEquippedWeapon()).GetWeaponHitStrength() >= selfDamage)
							this->GetWeapon(this->GetEquippedWeapon()).SetWeaponHitStrength(this->GetWeapon(this->GetEquippedWeapon()).GetWeaponHitStrength() - selfDamage);
						else
						{
							this->GetWeapon(this->GetEquippedWeapon()).SetWeaponHitStrength(0);
							this->GetWeapons().erase(this->GetWeapons().begin() + this->GetEquippedWeapon());
						}
						return false;

					}
				}
			}
			else
				//maybe say "Too Weak To Attack, else do above code for failure"
				return false;
			}
		else
			return false;
			}	//ask if they need reduced health for these 2 or if the attack never gets carried out
	else
		return false;
		
}
bool BlackWitch::Bewitch(GameCharacter &character) {
	GameCharacter::SetState(CharacterState::Idle);
	int random = rand() % 100 + 1;
	int chance = 10+(magicProficiency_*5);
	if (character.GetState() != CharacterState::Sleeping)
	{
		if (random <= chance)
		{
			character.SetState(CharacterState::Sleeping);
			return true;
		}
		else
			return false;
	}
	else
	{
		//maybe a message saying already in sleeping state
		return false;
	}
}
void BlackWitch::Sleep() {
	this->SetState(CharacterState::Sleeping);
	if (this->GetHealth() < 85)
		this->SetHealth(this->GetHealth() + ((this->GetHealth() / 100) * 15));
	else
		this->SetHealth(100);
}
void BlackWitch::Eat() {
	GameCharacter::Eat();
}
int BlackWitch::GetMagicProficiency() {
	return magicProficiency_;
}
void BlackWitch::SetMagicProficiency(int magic) {
	magicProficiency_ = magic;
}
int BlackWitch::GetDarkPower() {
	return darkPower_;
}
void BlackWitch::SetDarkPower(int darkPower) {
	darkPower_ = darkPower;
}
std::string BlackWitch::GetCharacterName() {
	return GameCharacter::GetCharacterName();
}
void BlackWitch::SetCharacterName(std::string name) {
	GameCharacter::SetCharacterName(name);
}
float BlackWitch::GetHealth() {
	return GameCharacter::GetHealth();
}
void BlackWitch::SetHealth(float health) {
	GameCharacter::SetHealth(health);
}
float BlackWitch::GetWeightLimit() {
	return GameCharacter::GetWeightLimit();
}
void BlackWitch::SetWeightLimit(float weightLimit) {
	GameCharacter::SetWeightLimit(weightLimit);
}
int BlackWitch::GetEquippedWeapon() {
	return GameCharacter::GetEquippedWeapon();
}
void BlackWitch::SetEquippedWeapon(int equippedWeapon) {
	GameCharacter::SetEquippedWeapon(equippedWeapon);
}
int BlackWitch::GetEquippedArmour() {
	return GameCharacter::GetEquippedArmour();
}
void BlackWitch::SetEquippedArmour(int equippedArmour) {
	GameCharacter::SetEquippedArmour(equippedArmour);
}
int BlackWitch::GetFood() {
	return GameCharacter::GetFood();
}
void BlackWitch::SetFood(int food) {
	GameCharacter::SetFood(food);
}
vector<Weapon> BlackWitch::GetWeapons() {
	return GameCharacter::GetWeapons();
}
void BlackWitch::SetWeapons(vector<Weapon> weapons) {
	GameCharacter::SetWeapons(weapons);
}
vector<Armour> BlackWitch::GetArmour() {
	return GameCharacter::GetArmour();
}
void BlackWitch::SetArmour(vector<Armour> armour) {
	GameCharacter::SetArmour(armour);
}
CharacterState BlackWitch::GetState() {
	return GameCharacter::GetState();
}
void BlackWitch::SetState(CharacterState state) {
	GameCharacter::GetState();
}
bool BlackWitch::PickUpWeapon(Weapon &weapon) {
	return GameCharacter::PickUpWeapon(weapon);
}
bool BlackWitch::PickUpArmour(Armour &armour) {
	return GameCharacter::PickUpArmour(armour);
}
Armour BlackWitch::GetArmour(int index) {
	return GameCharacter::GetArmour(index);
}
void BlackWitch::DropItem(Weapon &item) {
	GameCharacter::DropItem(item);
}
void BlackWitch::DropItem(Armour &item) {
	GameCharacter::DropItem(item);
}

void BlackWitch::Defend(int armour) {
	GameCharacter::Defend(armour);
}
void BlackWitch::Walk() {
	GameCharacter::Walk();
}
void BlackWitch::Run() {
	GameCharacter::Run();
}
Weapon BlackWitch::GetWeapon(int index) {
	return GameCharacter::GetWeapon(index);
}
bool BlackWitch::EquipWeapon(int weapon) {
	return GameCharacter::EquipWeapon(weapon);
}
void BlackWitch::AddFood(int amount) {
	GameCharacter::AddFood(amount);
}