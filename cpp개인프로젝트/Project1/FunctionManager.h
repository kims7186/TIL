#include <vector>
#include "Player.h"
#include <string>
#include "Formation.h"

using namespace std;
void InsertPlayer(vector<Player> &players);  // �÷��̾� �߰�
void DeletePlayer(vector<Player> &players);  //�÷��̾� ����
void EditPlayer(vector<Player> &players);    // �÷��̾� ����
void GetInformation(const vector<Player> &players);  // �÷��̾� ���� �����ִ� �Լ�
string GetValidPosition(const string &prompt);  // �Էµ� ������ ��ȿ�� �˻� �� �ùٸ� �Է� ��ȯ�ϴ� �Լ�

												// �����̼��� �߰��ϱ� ���� �Լ�
void InsertFormation(vector<Formation> &formations);  // �����̼� �߰�
void DeleteFormation(vector<Formation> &formations);  //�����̼� ����
void EditFormation(vector<Formation> &formations);    //�����̼� ����

// ���� �����̼� ������ ǥ���ϴ� �Լ�
void DisplayFormation(const vector<Formation> &formations);
