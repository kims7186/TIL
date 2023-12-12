#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Formation {
 public:
  Formation();  // ������
  Formation(std::string formationName, int defenders, int midfielders,
            int forwards);

  // ��ȿ�� �����̼� �Է��� �ޱ� ���� �Լ�
  std::string GetValidFormation(const std::string& prompt);

  // ���� �����̼� ������ ǥ���ϴ� �Լ�
  void DisplayFormation(const vector<Formation>& formations);

 private:
  std::string formationName;           // �����̼� �̸�
  int defenders;                       // ����� ��
  int midfielders;                     // �̵��ʴ� ��
  int forwards;                        // ���ݼ� ��
  std::vector<std::string> positions;  // ���� ��ġ
};
