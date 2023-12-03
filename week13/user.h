#pragma once

#include <iostream>
using namespace std;

class User {
 private:
  int hp;  // 유저 체력
 protected:
  int x;  //유저 x좌표
  int y;  //유저 y좌표 
  string shape; //좌표 모양 
 public:
  void DecreaseHP(int dec_hp);
  void IncreaseHP(int inc_hp);
  int GetHP();
  void doAttack();
  User(int x,int y, string shape);
};

//User 클래스 상속
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
