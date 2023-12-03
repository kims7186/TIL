#pragma once

#include <iostream>
using namespace std;

class User {
 private:
  int hp;  // ���� ü��
 protected:
  int x;  //���� x��ǥ
  int y;  //���� y��ǥ 
  string shape; //��ǥ ��� 
 public:
  void DecreaseHP(int dec_hp);
  void IncreaseHP(int inc_hp);
  int GetHP();
  void doAttack();
  User(int x,int y, string shape);
};

//User Ŭ���� ���
class Magician : public User {
 public:
  void doAttack();
  Magician(int x, int y);
};

class Warrior : public User {
 public:
  void doAttack();
  Warrior(int x, int y);
};
