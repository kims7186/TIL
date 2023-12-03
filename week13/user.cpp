#include "user.h"
User::User(int x, int y, string shape) {
  this->x = x;
  this -> y = y;
  this->shape = shape;
  this->hp = 20;
};
void User::DecreaseHP(int dec_hp) { hp = hp - dec_hp; }
void User::IncreaseHP(int inc_hp) { hp = hp + inc_hp; }
void User::doAttack() { cout << "공격합니다."<<endl; }
int User::GetHP() { return hp; }

// User 클래스 doAttack 재정의 
void Magician::doAttack() { cout << "마법 사용"<<endl; }

void Warrior::doAttack() { cout << "베기 사용" << endl; }

Magician::Magician(int x, int y) : User(x, y, "maci |") {}

Warrior::Warrior(int x, int y) : User(x, y, "warri |") {}
