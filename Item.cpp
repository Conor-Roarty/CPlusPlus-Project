#include "Item.h"

Item::Item() {

}
Item::Item(string name, int value, float weight) : itemName_{ name }, itemValue_{ value }, weight_{weight} {

}
Item::~Item() {

}
string Item::GetItemName() {
	return itemName_;
}
void Item::SetItemName(string name) {
	itemName_ = name;
}
float Item::GetItemWeight() {
	return weight_;
}
void Item::SetItemWeight(float weight) {
	weight_ = weight;
}
int Item::GetValue() {
	return itemValue_;
}
void Item::SetValue(int value) {
	itemValue_ = value;
}