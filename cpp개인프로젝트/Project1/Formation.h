#pragma once

class Formation {
 public:
  Formation();  // ������
  Formation(string formationName, int defenders, int midfielders,
            int forwards);
  string formation_name;           // �����̼� �̸�
  int defenders;                       // ����� ��
  int midfielders;                     // �̵��ʴ� ��
  int forwards;                        // ���ݼ� ��
};
