#include "Brawler.h"
//#include "Common.h"
Brawler::Brawler() {

}
Brawler::Brawler(string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, int food,
	/*vector<Weapon> weapons, vector<Armour> armour,*/ CharacterState state, int strength, int punchDamage) : GameCharacter{ characterName, health, weightLimit, equippedWeapon, equippedArmour,food,/*weapons,armour,*/state }, strength_{ strength }, punchDamage_{ punchDamage } {


}
Brawler::Brawler(string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, int food,
	vector<Weapon> weapons, vector<Armour> armour, CharacterState state, int strength, int punchDamage) : GameCharacter{ characterName, health, weightLimit, equippedWeapon, equippedArmour,food,weapons,armour,state }, strength_{ strength }, punchDamage_{ punchDamage } {


}
Brawler::Brawler(string characterName, float health, float weightLimit, /*int equippedWeapon, int equippedArmour,*/ int food,
	/*vector<Weapon> weapons, vector<Armour> armour,*/ CharacterState state, int strength, int punchDamage) : GameCharacter{ characterName, health, weightLimit, -1,-1,food,/*weapons,armour,*/state }, strength_{ strength }, punchDamage_{ punchDamage } {


}
Brawler::~Brawler(){

}
bool Brawler::Attack(GameCharacter &character) {
	GameCharacter::Attack(character);
	int random = rand() % 100 + 1;

	int impact{ 0 };
	impact = (strength_ / 10) * 5;

	if (GameCharacter::GetEquippedWeapon() != -1)
	{
		if (character.GetState() != CharacterState::Dead)
		{
			if (GameCharacter::GetHealth() >= 20)
			{
				if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() >= this->GetWeapon(this->GetEquippedWeapon()).GetWeaponHitStrength())
				{
					if (random <= 20)
					{
						if (character.GetState() == CharacterState::Defending)
						{
							//character.SetHealth(character.GetHealth() - 10);
							if (character.GetHealth() > (10 + impact))
								character.SetHealth(character.GetHealth() - (10 + impact));
							else {
								character.SetHealth(0);
								character.SetState(CharacterState::Dead);
							}
							if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > (10 + impact))
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - (10 + impact));
							else {
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
								character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
							}

						}
						else if (character.GetState() == CharacterState::Sleeping)
						{
							character.SetHealth(0);
							character.SetState(CharacterState::Dead);

							if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > (10 + impact))
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - (10 + impact));
							else {
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
								character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
							}
						}
						else
						{
							//character.SetHealth(character.GetHealth() - 10);
							if (character.GetHealth() > (20 + impact))
								character.SetHealth(character.GetHealth() - (20 + impact));
							else {
								character.SetHealth(0);
								character.SetState(CharacterState::Dead);
							}
							if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > (10 + impact))
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - (10 + impact));
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
							if (character.GetHealth() > (10 + impact))
								character.SetHealth(character.GetHealth() - (10 + impact));
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
							if (character.GetHealth() > (20 + impact))
								character.SetHealth(character.GetHealth() - (20 + impact));
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
							if (character.GetHealth() > (10 + impact))
								character.SetHealth(character.GetHealth() - (10 + impact));
							else {
								character.SetHealth(0);
								character.SetState(CharacterState::Dead);
							}
							if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > (10 + impact))
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - (10 + impact));
							else {
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
								character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
							}

						}
						else if (character.GetState() == CharacterState::Sleeping)
						{
							character.SetHealth(0);
							character.SetState(CharacterState::Dead);

							if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > (10 + impact))
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - (10 + impact));
							else {
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
								character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
							}
						}
						else
						{
							//character.SetHealth(character.GetHealth() - 10);
							if (character.GetHealth() > (20 + impact))
							{

								character.SetHealth(character.GetHealth() - (20+impact));
							}
							else {
								character.SetHealth(0);
								character.SetState(CharacterState::Dead);
							}
							if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > (10 + impact))
							{
								character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - (10 + impact));
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
			else {
				//maybe say "Too Weak To Attack, else do above code for failure"
				return false;
			}
		}
		else
			return false;
	}
	else {
		
		Brawl(character);
		return false;
	}
}
bool Brawler::Brawl(GameCharacter &character) {
	this->SetState(CharacterState::Idle);
	int random = rand() % 100 + 1;
	if (character.GetState() != CharacterState::Dead)
	{
		if (this->GetHealth() >= 20)
		{
			if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() >= punchDamage_)
			{
				if (random <= 20)
				{
					if (character.GetState() == CharacterState::Defending)
					{
						//character.SetHealth(character.GetHealth() - 10);
						if (character.GetHealth() > (5))
							character.SetHealth(character.GetHealth() - (5));
						else {
							character.SetHealth(0);
							character.SetState(CharacterState::Dead);
						}
						if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > (5))
							character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - 5);
						else {
							character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
							character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
						}

					}
					else if (character.GetState() == CharacterState::Sleeping)
					{
						character.SetHealth(0);
						character.SetState(CharacterState::Dead);

						if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > (5))
							character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - (5));
						else {
							character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
							character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
						}
					}
					else
					{
						//character.SetHealth(character.GetHealth() - 10);
						if (character.GetHealth() > (10))
							character.SetHealth(character.GetHealth() - (10));
						else {
							character.SetHealth(0);
							character.SetState(CharacterState::Dead);
						}
						if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > (5))
							character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - (5));
						else {
							character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
							character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
						}
					}
					return true;
				}
				else
					return false;
			}
			else if (character.GetEquippedArmour() == -1)
			{
				if (random <= 80)
				{
					if (character.GetState() == CharacterState::Defending)
					{
						//character.SetHealth(character.GetHealth() - 10);
						if (character.GetHealth() > (5))
							character.SetHealth(character.GetHealth() - (5));
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
						if (character.GetHealth() > (10))
							character.SetHealth(character.GetHealth() - (10));
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
						if (character.GetHealth() > (5))
							character.SetHealth(character.GetHealth() - (5));
						else {
							character.SetHealth(0);
							character.SetState(CharacterState::Dead);
						}
						if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > (5))
							character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - 5);
						else {
							character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
							character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
						}

					}
					else if (character.GetState() == CharacterState::Sleeping)
					{
						character.SetHealth(0);
						character.SetState(CharacterState::Dead);

						if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > (5))
							character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - (5));
						else {
							character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
							character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
						}
					}
					else
					{
						//character.SetHealth(character.GetHealth() - 10);
						if (character.GetHealth() > (10))
						{

							character.SetHealth(character.GetHealth() - (10));
						}
						else {
							character.SetHealth(0);
							character.SetState(CharacterState::Dead);
						}
						if (character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() > (5))
						{
							character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(character.GetArmour(character.GetEquippedArmour()).GetArmourHealth() - (5));
						}
						else {
							character.GetArmour(character.GetEquippedArmour()).SetArmourHealth(0);
							character.GetArmour().erase(character.GetArmour().begin() + character.GetEquippedArmour());
						}
					}
					return true;
				}
				else
					return false;
			}
		}
		else {
			//maybe say "Too Weak To Attack, else do above code for failure"
			return false;
		}
	}
	else
		return false;
}
void Brawler::Sleep() {
	GameCharacter::Sleep();
}
void Brawler::Eat() {
	GameCharacter::Eat();
}
int Brawler::GetStrength() {
	return strength_;

}
void Brawler::SetStrength(int strength) {
	strength_ = strength;
}
int Brawler::GetPunchDamage() {
	return punchDamage_;
}
void Brawler::SetPunchDamage(int damage) {
	punchDamage_ = damage;
}

std::string Brawler::GetCharacterName() {
	return GameCharacter::GetCharacterName();
}
void Brawler::SetCharacterName(std::string name) {
	GameCharacter::SetCharacterName(name);
}
float Brawler::GetHealth() {
	return GameCharacter::GetHealth();
}
void Brawler::SetHealth(float health) {
	GameCharacter::SetHealth(health);
}
float Brawler::GetWeightLimit() {
	return GameCharacter::GetWeightLimit();
}
void Brawler::SetWeightLimit(float weightLimit) {
	GameCharacter::SetWeightLimit(weightLimit);
}
int Brawler::GetEquippedWeapon() {
	return GameCharacter::GetEquippedWeapon();
}
void Brawler::SetEquippedWeapon(int equippedWeapon) {
	GameCharacter::SetEquippedWeapon(equippedWeapon);
}
int Brawler::GetEquippedArmour() {
	return GameCharacter::GetEquippedArmour();
}
void Brawler::SetEquippedArmour(int equippedArmour) {
	GameCharacter::SetEquippedArmour(equippedArmour);
}
int Brawler::GetFood() {
	return GameCharacter::GetFood();
}
void Brawler::SetFood(int food) {
	GameCharacter::SetFood(food);
}
vector<Weapon> Brawler::GetWeapons() {
	return GameCharacter::GetWeapons();
}
void Brawler::SetWeapons(vector<Weapon> weapons) {
	GameCharacter::SetWeapons(weapons);
}
vector<Armour> Brawler::GetArmour() {
	return GameCharacter::GetArmour();
}
void Brawler::SetArmour(vector<Armour> armour) {
	GameCharacter::SetArmour(armour);
}
CharacterState Brawler::GetState() {
	return GameCharacter::GetState();
}
void Brawler::SetState(CharacterState state) {
	GameCharacter::GetState();
}
bool Brawler::PickUpWeapon(Weapon &weapon) {
	return GameCharacter::PickUpWeapon(weapon);
}
bool Brawler::PickUpArmour(Armour &armour) {
	return GameCharacter::PickUpArmour(armour);
}
Armour Brawler::GetArmour(int index) {
	return GameCharacter::GetArmour(index);
}
void Brawler::DropItem(Weapon &item) {
	GameCharacter::DropItem(item);
}
void Brawler::DropItem(Armour &item) {
	GameCharacter::DropItem(item);
}


void Brawler::Defend(int armour) {
	GameCharacter::Defend(armour);
}
void Brawler::Walk() {
	GameCharacter::Walk();
}
void Brawler::Run() {
	GameCharacter::Run();
}
Weapon Brawler::GetWeapon(int index) {
	return GameCharacter::GetWeapon(index);
}
bool Brawler::EquipWeapon(int weapon) {
	return GameCharacter::EquipWeapon(weapon);
}
void Brawler::AddFood(int amount) {
	GameCharacter::AddFood(amount);
}
