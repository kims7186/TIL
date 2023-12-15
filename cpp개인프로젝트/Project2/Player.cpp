#include "Player.h"

#include <iomanip>  //setw()����ϱ� ����
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// ������ ���ǿ� �ʱ�ȭ ��� ���
Player::Player() {}
Player::Player(string name, string pre_pos, string non_pre_pos) {
  if (name.size() < 3) {
    name = " " + name;
  } else {
    this->name = name;
  }

  this->pre_pos = pre_pos;
  this->non_pre_pos = non_pre_pos;
}

