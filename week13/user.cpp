#include "user.h"
User::User(int x, int y, string shape) {
  this->x = x;
  this -> y = y;
  this->shape = shape;
  this->hp = 20;
};
void User::DecreaseHP(int dec_hp) { hp = hp - dec_hp; }
void User::IncreaseHP(int inc_hp) { hp = hp + inc_hp; }
void User::doAttack() { cout << "�����մϴ�."<<endl; }
int User::GetHP() { return hp; }

// User Ŭ���� doAttack ������ 
void Magician::doAttack() { cout << "���� ���"<<endl; }

void Warrior::doAttack() { cout << "���� ���" << endl; }

Magician::Magician(int x, int y) : User(x, y, "maci |") {}

Warrior::Warrior(int x, int y) : User(x, y, "warri |") {}
