#include "Formation.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// ������ ����
Formation::Formation()
    : formation_name(""), defenders(0), midfielders(0), forwards(0) {}
Formation::Formation(std ::string formationName, int defenders, int midfielders,
                     int forwards) {
  this->formation_name = formationName;
  this->defenders = defenders;
  this->midfielders = midfielders;
  this->forwards = forwards;
}

// ���� �����̼� ������ ǥ���ϴ� �Լ� ����
void Formation::DisplayFormation(const vector<Formation>& formations) {
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

void Formation::InsertFormation(vector<Formation>& formations) {
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
void Formation::EditFormation(vector<Formation>& formations) {
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
void Formation::DeleteFormation(vector<Formation>& formations) {
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


