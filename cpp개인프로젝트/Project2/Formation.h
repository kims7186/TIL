#pragma once

class Formation {
 public:
  string formation_name;  // �����̼� �̸�
  int defenders;          // ����� ��
  int midfielders;        // �̵��ʴ� ��
  int forwards;           // ���ݼ� ��
  Formation();  // ������
  Formation(string formationName, int defenders, int midfielders,
            int forwards);

};
