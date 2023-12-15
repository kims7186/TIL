#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include <iomanip>  //setw()����ϱ� ����

using namespace std;

// �ٸ� ��� �Լ����� ������ ���⿡ �߰�
void InsertPlayer(vector<Player> &players) {
  cout << "------------------------------------------------------\n";
  cout << "�÷��̾ �߰��մϴ�.\n\n";
  cout << "�÷��̾��� ������ �̸�/��ȣ ������/��ȣ ������ ������ "
          "�Է��ϼ���.\n\n";
  cout << "��ȣ/��ȣ �������� ����/�߾�/����/��Ű��/���� �߿��� "
          "�Է����ּ���\n\n";
  Player input;
  // �̸� �Է�
  cout << "�̸�: ";
  cin >> input.name;

  // ��ȣ ������ �Է� �� ��ȿ�� �˻�
  input.pre_pos = GetValidPosition("��ȣ ������: ");
  input.non_pre_pos = GetValidPosition("��ȣ ������: ");
  players.push_back(input);
  cout << "------------------------------------------------------\n";
  cout << "������ �߰��Ǿ����ϴ�.\n\n";
  cout << "------------------------------------------------------\n";
}

void DeletePlayer(vector<Player> &players) {
  cout << "------------------------------------------------------\n";
  cout << "�÷��̾ �����մϴ�.\n\n";
  cout << "������ �÷��̾��� ��ȣ�� �Է����ּ��� \n\n";

  int delete_index;  // ������ �÷��̾� ��ȣ

  // ������ ��ȣ �Է�
  cout << "��ȣ: ";
  cin >> delete_index;
  players.erase(players.begin() + delete_index - 1);

  cout << "������ ���� �Ǿ����ϴ�.\n";
}

void EditPlayer(vector<Player> &players) {
  cout << "------------------------------------------------------\n";
  cout << "�÷��̾ �����մϴ�.\n\n";
  cout << "������ �÷��̾��� ��ȣ�� �Է����ּ��� \n\n";

  int edit_index;  //������ �÷��̾� ��ȣ

  // ������ �÷��̾� ��ȣ �Է�
  cout << "������ �÷��̾� ��ȣ: ";
  cin >> edit_index;
  cout << "�÷��̾��� ������ �̸�/��ȣ ������/��ȣ ������ ������ "
          "�Է��ϼ���.\n\n";
  cout << "��ȣ/��ȣ �������� ����/�߾�/����/��Ű��/���� �߿��� "
          "�Է����ּ���\n\n";
  cout << "�̸�: ";
  cin >> players[edit_index - 1].name;
  players[edit_index - 1].pre_pos = GetValidPosition("��ȣ ������:");
  players[edit_index - 1].pre_pos = GetValidPosition("��ȣ ������:");

  cout << "���������� ���� �Ǿ����ϴ�.\n";
}

void GetInformation(const vector<Player> &players) {
  cout << "��ȣ |  �̸�               | ��ȣ ������      | ��ȣ ������\n";
  cout << "------------------------------------------------------\n";

  for (int i = 0; i < players.size(); i++) {
    cout << setw(4) << i + 1;
    cout << " | " << setw(19) << players[i].name;
    cout << " | " << setw(16) << players[i].pre_pos;
    cout << " | " << players[i].non_pre_pos << endl;
  }
  cout << endl;
  cout << "------------------------------------------------------\n";
}

string GetValidPosition(const string &prompt) {
  string position;  // �Է��� ���� ���� ������
  while (true) {
    cout << prompt;
    cin >> position;

    if (position == "����" || position == "�߾�" || position == "����" ||
        position == "��Ű��" || position == "����") {
      break;
    } else {
      cout << "�߸��� �������Դϴ�. ����/�߾�/����/��Ű��/���� �� �ϳ��� "
              "�Է��ϼ���.\n";
    }
  }
  return position;
}
