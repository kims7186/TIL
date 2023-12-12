#include "Formation.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// ������ ����
Formation::Formation()
    : formationName(""), defenders(0), midfielders(0), forwards(0) {}
Formation::Formation(std ::string formationName, int defenders, int midfielders,
                     int forwards) {
  this->formationName = formationName;
  this->defenders = defenders;
  this->midfielders = midfielders;
  this->forwards = forwards;
}

// ��ȿ�� �����̼� �Է��� �ޱ� ���� �Լ� ����
std::string Formation::GetValidFormation(const std::string& prompt) {
  std::string formation;
  while (true) {
    std::cout << prompt;
    std::cin >> formation;

    if (formation == "343" || formation == "352" || formation == "433" ||
        formation == "4231" || formation == "442" || formation == "541" ||
        formation == "523") {
      break;
    } else {
      std::cout << "��ȿ���� ���� �����̼��Դϴ�. ��ȿ�� ���� �Է����ּ���.\n";
    }
  }
  return formation;
}

// ���� �����̼� ������ ǥ���ϴ� �Լ� ����
void Formation::DisplayFormation(const vector<Formation>& formations) {
  // ���� �����̼� ������ ����ϴ� �Լ�
  cout << "�����̼� �̸� | ����� | �̵��ʴ� | ���ݼ�\n";
  cout << "------------------------------------------\n";

  for (int i = 0; i < formations.size(); i++) {
    cout << setw(13) << formations[i].formationName;
    cout << " | " << setw(6) << formations[i].defenders;
    cout << " | " << setw(8) << formations[i].midfielders;
    cout << " | " << setw(6) << formations[i].forwards << endl;
  }
  cout << endl;
  cout << "------------------------------------------\n";
}
