#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Formation.h"
#include "Player.h"
#include "FunctionManager.h"

using namespace std;


// ���� �����̼� ������ ǥ���ϴ� �Լ� ����
void DisplayFormation(const vector<Formation>& formations) {
  // ���� �����̼� ������ ����ϴ� �Լ�
  cout << "��ȣ |�����̼� �̸� | ����� | �̵��ʴ� | ���ݼ�\n";
  cout << "------------------------------------------------\n";

  for (int i = 0; i < formations.size(); i++) {
    cout << setw(4) << i + 1 << " |";
    cout << setw(13) << formations[i].formation_name;
    cout << " | " << setw(6) << formations[i].defenders;
    cout << " | " << setw(8) << formations[i].midfielders;
    cout << " | " << setw(6) << formations[i].forwards << endl;
  }
  cout << endl;
  cout << "------------------------------------------------\n";
}

void InsertFormation(vector<Formation>& formations) {
  string formationName;
  cout << "�߰��� �����̼��� �̸�:\n";
  cin >> formationName;
  int def, mid, forward;
  while (true) {
    cout << "����� ����:\n";
    cin >> def;
    cout << "�̵��ʴ� ����\n";
    cin >> mid;
    cout << "���ݼ� ����\n";
    cin >> forward;
    if (def > 0 && mid > 0 && forward > 0) {
      if (def + mid + forward == 10) {
        formations.push_back(Formation(formationName, def, mid, forward));
        cout << "���ο� �����̼��� �߰��Ǿ����ϴ�.\n";
        break;
      } else {
        cout << "�ʵ� �÷��̾�� 10�� �Դϴ�.�ٽ� �Է����ּ���\n";
        cout << "���� �ʵ� �÷��̾� ���� :" << def + mid + forward << endl;
      }
    } else {
      cout << "�� �������� �÷��̾� ���ڴ� �ּ� �Ѹ��̿��� �մϴ�. �ٽ� "
              "�Է����ּ��� \n";
    }
  }
}
void EditFormation(vector<Formation>& formations) {
  cout << "------------------------------------------------------\n";
  cout << "�����̼� ������ �����մϴ�.\n\n";
  cout << "������ �����̼��� ��ȣ�� �Է����ּ��� \n\n";

  int edit_index;  //������ �÷��̾� ��ȣ

  // ������ �÷��̾� ��ȣ �Է�
  cout << "������ �����̼� ��ȣ: ";
  cin >> edit_index;
  cout << "�̸�: ";
  cin >> formations[edit_index - 1].formation_name;
  int def, mid, forward;
  while (true) {
    cout << "����� ����:\n";
    cin >> def;
    cout << "�̵��ʴ� ����\n";
    cin >> mid;
    cout << "���ݼ� ����\n";
    cin >> forward;
    if (def > 0 && mid > 0 && forward > 0) {
      if (def + mid + forward == 10) {
        formations[edit_index - 1].defenders = def;
        formations[edit_index - 1].midfielders = mid;
        formations[edit_index - 1].forwards = forward;
        cout << "�����̼� ������ �����Ǿ����ϴ�.\n";
        break;
      } else {
        cout << "�ʵ� �÷��̾�� 10�� �Դϴ�.�ٽ� �Է����ּ���\n";
        cout << "���� �ʵ� �÷��̾� ���� :" << def + mid + forward << endl;
      }
    } else {
      cout << "�� �������� �÷��̾� ���ڴ� �ּ� �Ѹ��̿��� �մϴ�. �ٽ� "
              "�Է����ּ��� \n";
    }
  }
}
void DeleteFormation(vector<Formation>& formations) {
  cout << "------------------------------------------------------\n";
  cout << "�����̼��� �����մϴ�.\n\n";
  cout << "������ �����̼��� ��ȣ�� �Է����ּ��� \n\n";

  int delete_index;  // ������ �÷��̾� ��ȣ

  // ������ ��ȣ �Է�
  cout << "��ȣ: ";
  cin >> delete_index;
  formations.erase(formations.begin() + delete_index - 1);

  cout << "�����̼��� ���� �Ǿ����ϴ�.\n";
}

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
