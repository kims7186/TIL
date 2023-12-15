


#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "FormationManager.h"
#include "Formation.h"
using namespace std;

// 현재 포메이션 정보를 표시하는 함수 구현
void DisplayFormation(const vector<Formation>& formations) {
  // 현재 포메이션 정보를 출력하는 함수
  cout << "번호 |포메이션 이름 | 수비수 | 미드필더 | 공격수\n";
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
  cout << "추가할 포메이션의 이름:\n";
  cin >> formationName;
  int def, mid, forward;
  while (true) {
    cout << "수비수 숫자:\n";
    cin >> def;
    cout << "미드필더 숫자\n";
    cin >> mid;
    cout << "공격수 숫자\n";
    cin >> forward;
    if (def > 0 && mid > 0 && forward > 0) {
      if (def + mid + forward == 10) {
        formations.push_back(Formation(formationName, def, mid, forward));
        cout << "새로운 포메이션이 추가되었습니다.\n";
        break;
      } else {
        cout << "필드 플레이어는 10명 입니다.다시 입력해주세요\n";
        cout << "현재 필드 플레이어 숫자 :" << def + mid + forward << endl;
      }
    } else {
      cout << "각 포지션의 플레이어 숫자는 최소 한명이여야 합니다. 다시 "
              "입력해주세요 \n";
    }
  }
}
void EditFormation(vector<Formation>& formations) {
  cout << "------------------------------------------------------\n";
  cout << "포메이션 정보를 수정합니다.\n\n";
  cout << "수정할 포메이션의 번호를 입력해주세요 \n\n";

  int edit_index;  //수정할 플레이어 번호

  // 수정할 플레이어 번호 입력
  cout << "수정할 포메이션 번호: ";
  cin >> edit_index;
  cout << "이름: ";
  cin >> formations[edit_index - 1].formation_name;
  int def, mid, forward;
  while (true) {
    cout << "수비수 숫자:\n";
    cin >> def;
    cout << "미드필더 숫자\n";
    cin >> mid;
    cout << "공격수 숫자\n";
    cin >> forward;
    if (def > 0 && mid > 0 && forward > 0) {
      if (def + mid + forward == 10) {
        formations[edit_index - 1].defenders = def;
        formations[edit_index - 1].midfielders = mid;
        formations[edit_index - 1].forwards = forward;
        cout << "포메이션 정보가 수정되었습니다.\n";
        break;
      } else {
        cout << "필드 플레이어는 10명 입니다.다시 입력해주세요\n";
        cout << "현재 필드 플레이어 숫자 :" << def + mid + forward << endl;
      }
    } else {
      cout << "각 포지션의 플레이어 숫자는 최소 한명이여야 합니다. 다시 "
              "입력해주세요 \n";
    }
  }
}
void DeleteFormation(vector<Formation>& formations) {
  cout << "------------------------------------------------------\n";
  cout << "포메이션을 삭제합니다.\n\n";
  cout << "삭제할 포메이션의 번호를 입력해주세요 \n\n";

  int delete_index;  // 삭제할 플레이어 번호

  // 삭제할 번호 입력
  cout << "번호: ";
  cin >> delete_index;
  formations.erase(formations.begin() + delete_index - 1);

  cout << "포메이션이 삭제 되었습니다.\n";
}
