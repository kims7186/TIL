#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Player {
 public:
  string name;         //�÷��̾� �̸�
  string pre_pos;      //��ȣ ������
  string non_pre_pos;  //��ȣ ������
  Player(); //�⺻ ������ 
  Player(string name, string pre_pos, string non_pre_pos);
  void InsertPlayer(vector<Player> &players);  // �÷��̾� �߰�
  void DeletePlayer(vector<Player> &players);  //�÷��̾� ����
  void EditPlayer(vector<Player> &players);  // �÷��̾� ����
  void GetInformation(const vector<Player> &players);  // �÷��̾� ���� �����ִ� �Լ�
  string GetValidPosition(const string &prompt);  // �Էµ� ������ ��ȿ�� �˻� �� �ùٸ� �Է� ��ȯ�ϴ� �Լ�
};
