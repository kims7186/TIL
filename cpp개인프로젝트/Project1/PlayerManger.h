#pragma once

void InsertPlayer(vector<Player> &players);  // �÷��̾� �߰�
void DeletePlayer(vector<Player> &players);  //�÷��̾� ����
void EditPlayer(vector<Player> &players);    // �÷��̾� ����
void GetInformation(const vector<Player> &players);  // �÷��̾� ���� �����ִ� �Լ�
string GetValidPosition(const string &prompt);  // �Էµ� ������ ��ȿ�� �˻� �׿ùٸ� �Է� ��ȯ�ϴ� �Լ�
                                               