#include "Orc.h"
#include "Common.h"
Orc::Orc(){

}
Orc::Orc(string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, int food,
	/*vector<Weapon> weapons, vector<Armour> armour,*/ CharacterState state,int strength, int ferociousness) : GameCharacter{ characterName, health, weightLimit, equippedWeapon, equippedArmour,food,/*weapons,armour,*/state }, strength_{ strength }, ferociousness_{ferociousness} {

}
Orc::Orc(string characterName, float health, float weightLimit, int equippedWeapon, int equippedArmour, int food,
	vector<Weapon> weapons, vector<Armour> armour, CharacterState state, int strength, int ferociousness) : GameCharacter{ characterName, health, weightLimit, equippedWeapon, equippedArmour,food,weapons,armour,state }, strength_{ strength }, ferociousness_{ ferociousness } {

}
Orc::Orc(string characterName, float health, float weightLimit, int food,CharacterState state, int strength, int ferociousness)
	: GameCharacter{ characterName, health, weightLimit,-1,-1,food,state }, strength_{ strength }, ferociousness_{ ferociousness } {

}
Orc::~Orc() {

}

bool Orc::Attack(GameCharacter &character) {
	GameCharacter::Attack(character);
	int random = rand() % 100 + 1;

	int impact{ 0 };
	impact = (strength_ / 10) * 5;

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

								character.SetHealth(character.GetHealth() - (20 + impact));
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
	}//ask if they need reduced health for these 2 or if the attack never gets carried out
	else
		return false;
}
bool Orc::Scream(GameCharacter &character) {
	GameCharacter::SetState(CharacterState::Idle);
	int random = rand() % 100 + 1;
	int chance = 20 + (ferociousness_*5);
	if (random <= chance)
	{
		//flee??
		character.SetState(CharacterState::Running);//???
		return true;
	}
	else
		return false;
}
void Orc::Eat() {
	GameCharacter::Eat();
}
void Orc::Sleep() {
	this->SetState(CharacterState::Sleeping);
	if (this->GetHealth() < 85)
		this->SetHealth(this->GetHealth() + ((this->GetHealth() / 100) * 15));
	else
		this->SetHealth(100);
}
int Orc::GetStrength() {
	return strength_;
}
void Orc::SetStrength(int strength) {
	strength_ = strength;
}
int Orc::GetFerociousness() {
	return ferociousness_;
}
void Orc::SetFerociousness(int ferociousness) {
	ferociousness_ = ferociousness;
}

std::string Orc::GetCharacterName() {
	return GameCharacter::GetCharacterName();
}
void Orc::SetCharacterName(std::string name) {
	GameCharacter::SetCharacterName(name);
}
float Orc::GetHealth() {
	return GameCharacter::GetHealth();
}
void Orc::SetHealth(float health) {
	GameCharacter::SetHealth(health);
}
float Orc::GetWeightLimit() {
	return GameCharacter::GetWeightLimit();
}
void Orc::SetWeightLimit(float weightLimit) {
	GameCharacter::SetWeightLimit(weightLimit);
}
int Orc::GetEquippedWeapon() {
	return GameCharacter::GetEquippedWeapon();
}
void Orc::SetEquippedWeapon(int equippedWeapon) {
	GameCharacter::SetEquippedWeapon(equippedWeapon);
}
int Orc::GetEquippedArmour() {
	return GameCharacter::GetEquippedArmour();
}
void Orc::SetEquippedArmour(int equippedArmour) {
	GameCharacter::SetEquippedArmour(equippedArmour);
}
int Orc::GetFood() {
	return GameCharacter::GetFood();
}
void Orc::SetFood(int food) {
	GameCharacter::SetFood(food);
}
vector<Weapon> Orc::GetWeapons() {
	return GameCharacter::GetWeapons();
}
void Orc::SetWeapons(vector<Weapon> weapons) {
	GameCharacter::SetWeapons(weapons);
}
vector<Armour> Orc::GetArmour() {
	return GameCharacter::GetArmour();
}
void Orc::SetArmour(vector<Armour> armour) {
	GameCharacter::SetArmour(armour);
}
CharacterState Orc::GetState() {
	return GameCharacter::GetState();
}
void Orc::SetState(CharacterState state) {
	GameCharacter::GetState();
}
bool Orc::PickUpWeapon(Weapon &weapon) {
	return GameCharacter::PickUpWeapon(weapon);
}
bool Orc::PickUpArmour(Armour &armour) {
	return GameCharacter::PickUpArmour(armour);
}
Armour Orc::GetArmour(int index) {
	return GameCharacter::GetArmour(index);
}
void Orc::DropItem(Weapon &item) {
	GameCharacter::DropItem(item);
}
void Orc::DropItem(Armour &item) {
	GameCharacter::DropItem(item);
}

void Orc::Defend(int armour) {
	GameCharacter::Defend(armour);
}
void Orc::Walk() {
	GameCharacter::Walk();
}
void Orc::Run() {
	GameCharacter::Run();
}
Weapon Orc::GetWeapon(int index) {
	return GameCharacter::GetWeapon(index);
}
bool Orc::EquipWeapon(int weapon) {
	return GameCharacter::EquipWeapon(weapon);
}
void Orc::AddFood(int amount) {
	GameCharacter::AddFood(amount);
}
