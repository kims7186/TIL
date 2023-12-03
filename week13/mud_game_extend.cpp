#include <iostream>
#include <string>

#include "user.h"
using namespace std;

const int MAP_X = 5;
const int MAP_Y = 5;

// 사용자 정의 함수
bool CheckXY(int user_x, int map_x, int user_y, int map_y);
void DisplayMap(int map[][MAP_X], int user_x, int user_y);
bool CheckGoal(int map[][MAP_X], int user_x, int user_y);
void CheckState(int map[][MAP_X], int user_x, int user_y, User &my_user);
void PrintMovement(int movement_x, int movement_y);
bool CheckUser(User user);

// 메인  함수
int main() {
  // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
  int map[MAP_Y][MAP_X] = {{0, 1, 2, 0, 4},
                           {1, 0, 0, 2, 0},
                           {0, 0, 0, 0, 0},
                           {0, 2, 3, 0, 0},
                           {3, 0, 0, 0, 2}};

  // 유저의 위치를 저장할 변수
  int user_x = 0;                    // 가로 번호
  int user_y = 0;                    // 세로 번호
  int player1_x = 0, player1_y = 0;  //플레이어1의 좌표 (0,0)
  int player2_x = 3, player2_y = 3;  //플레이어2의 좌표 (3,3)

  int k = 0;  // 차례를 저장하는 변수 0이면 player1,1이면 player2

  //유저의 정보를  저장하는 객체
  User my_user(user_x, user_y, " USER |");
  Magician player1(player1_x, player1_y);
  Warrior player2(player2_x, player2_y);

  //게임 시작 알림과 함께 게임안내, 현재 위치, 맵의 정보를 출력
  cout << endl << ("mud 게임을 시작합니다. ") << endl;
  cout << endl
       << ("상하 좌우로 이동할수 있으며 이동시 체력이 1 깎입니다.") << endl;
  cout << endl << ("적을 만나면 체력이 2 깎입니다.") << endl;
  cout << endl
       << ("보드판을 벗어나거나 비정상 입력인경우 제자리로 돌아옵니다.")
       << endl;
  cout << endl
       << ("지도를 입력하면 현재 위치와 맵상황을 보여주고, 종료를 입력시 "
           "게임이 종료됩니다.")
       << endl;
  cout << endl << ("현재의 맵 상황입니다. 건투를 빕니다. ") << endl << endl;

  DisplayMap(map, user_x, user_y);  // 사용자에게 초기 맵상태를1 회 출력합니다.

  // 게임 시작
  while (1) {  // 사용자에게 계속 입력받기 위해 무한 루프를시행한다.

    switch (k % 1) {
      case 0:
        user_x = player1_x;
        user_y = player1_y;
        break;
      case 1:
        user_x = player2_x;
        user_y = player2_y;
        break;
    }

    // 사용자의 입력을 저장할 변수
    string user_input = "";

    cout << endl
         << "현재의 HP: " << my_user.GetHP()
         << " 명령어를 입력하세요 (상,하,좌,우,지도,종료): ";
    cin >> user_input;  // 사용자 입력 받기

    //사용자의 좌표 이동 처리하기(상,하,좌,우 중 하나인경우 )
    if (user_input == "상" || user_input == "하" || user_input == "좌" ||
        user_input == "우") {
      //사용자의  좌표이동  처리하기
      bool in_map;  //좌표 유효성 검사 결과를 저장하는 변수
      int movement_x = 0,  // x좌표,y좌표의 이동을 임시로 저장하는 변수
          movement_y = 0;  //사용자 입력이 들어올때마다 초기화 된다.

      //사용자의 좌표의 입력을 통해, 각각상황에 맞게  checkXY 함수 호출 및
      // movemntX,movementY변수 초기화
      if (user_input == "상") {
        in_map = CheckXY(user_x, MAP_X, user_y - 1, MAP_Y);
        movement_y--;
      } else if (user_input == "하") {
        in_map = CheckXY(user_x, MAP_X, user_y + 1, MAP_Y);
        movement_y++;
      } else if (user_input == "좌") {
        in_map = CheckXY(user_x - 1, MAP_X, user_y,
                         MAP_Y);  //좌표의 유효성 검사 결과를 inamp 변수에 저장
        movement_x--;
      } else {  // 사용자의 입력이"하 " 인경우
        in_map = CheckXY(user_x + 1, MAP_X, user_y, MAP_Y);
        movement_x++;
      }

      if (in_map ==
          true) {  //사용자의 좌표이동이 유효한 경우에만 아래 과정을 수행한다.

        //사용자의 좌표 이동
        user_x += movement_x;
        user_y += movement_y;
        PrintMovement(movement_x, movement_y);
        my_user.DecreaseHP(1);  //사용자 이동시 체력 1씩 감소
        CheckState(map, user_x, user_y, my_user);
        DisplayMap(map, user_x, user_y);
      } else {  //사용자의 좌표이동이 유효하지 않은경우 출력
        cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
      }
    }

    else if (user_input ==
             "지도") {  // 사용자가 이동이 아닌 "지도"옵션을 선택한경우
      // TODO: 지도 보여주기 함수 호출
      DisplayMap(map, user_x, user_y);
    } else if (user_input == "종료") {  //사용자가 종료를 입력한 경우
      cout << "종료합니다.";
      break;
    } else {  // 입력자체가 옵션에 없는 경우
      cout << "잘못된 입력입니다." << endl;
      continue;
    }

    // 목적지에 도달했는지 체크
    bool finish = CheckGoal(map, user_x, user_y);
    if (finish == true) {  // 목적지에 도달한경우 출력
      cout << "목적지에 도착했습니다! 축하합니다!" << endl;
      cout << "게임을 종료합니다." << endl;
      break;
    }

    // hp가 0 이하가 되면 "실패"를 입력하고 종료
    if (CheckUser(my_user) == false) {
      cout << "HP가 0 이하가 되었습니다. 실패 했습니다" << endl;
      cout << "게임을 종료합니다." << endl;
      break;
    }
  }
  k++;
  return 0;
}

// 지도와 사용자 위치 출력하는 함수
void DisplayMap(int map[][MAP_X], int user_x, int user_y) {
  for (int i = 0; i < MAP_Y; i++) {
    //각 행이 바뀔때마다 보드의 테두리를 그린다.
    cout << " --------------------------------- " << endl;
    cout << "|";
    for (int j = 0; j < MAP_X; j++) {
      if (i == user_y && j == user_x) {  //해당좌표에 사용자가 있는경우
        cout << " USER |";               // 양 옆 1칸 공백
      } else {                           //그외 동일하게 출력
        int pos_state = map[i][j];
        switch (pos_state) {
          case 0:
            cout << "      |";  // 6칸 공백
            break;
          case 1:
            cout << "아이템|";
            break;
          case 2:
            cout << "  적  |";  // 양 옆 2칸 공백
            break;
          case 3:
            cout << " 포션 |";  // 양 옆 1칸 공백
            break;
          case 4:
            cout << "목적지|";
            break;
        }
      }
    }
    cout << endl;
  }
  cout << " ---------------------------------- " << endl;
}

// 이동하려는 곳이 유효한 좌표인지 체크하는 함수
bool CheckXY(int user_x, int mapX, int user_y, int mapY) {
  bool check_flag = false;
  if (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY) {
    check_flag = true;
  }
  return check_flag;
}

// 유저의 위치가 목적지인지 체크하는 함수
bool CheckGoal(int map[][MAP_X], int user_x, int user_y) {
  // 목적지 도착하면
  if (map[user_y][user_x] == 4) {
    return true;
  }
  return false;
}

//현재 좌표의 상태를 나타내는 함수
void CheckState(int map[][MAP_X], int user_x, int user_y, User &my_user) {
  int check = map[user_y][user_x];

  switch (check) {
    case 1:
      cout << "아이템이 있습니다" << endl;

      break;
    case 2:
      cout << "  적이 있습니다. HP가 2가 줄어듭니다." << endl;
      my_user.DecreaseHP(2);
      break;
    case 3:
      cout << " 포션이 있습니다. HP가 2 늘어납니다." << endl;
      my_user.IncreaseHP(2);
      break;
  }
}

//좌표이동결과를 출력
void PrintMovement(int movementX, int movementY) {
  switch (10 * movementX + movementY) {
    case (-1):  //상으로 한칸
      cout << "위로 한 칸 올라갑니다." << endl;
      break;
    case (1):  ///하로 한칸
      cout << "밑으로 한 칸 내려갑니다." << endl;
      break;
    case (-10):  //좌로 한칸
      cout << "왼쪽으로 이동합니다." << endl;
      break;
    case (10):  // 우로 한칸
      cout << "오른쪽으로 이동합니다." << endl;
      break;
  }
}

bool CheckUser(User user) {
  bool result;  //반환할 결과
  if (user.GetHP() <= 0)
    result = false;
  else {
    result = true;
  }
  return result;
}
