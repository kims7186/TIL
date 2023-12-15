#pragma once

void InsertPlayer(vector<Player> &players);  // 플레이어 추가
void DeletePlayer(vector<Player> &players);  //플레이어 삭제
void EditPlayer(vector<Player> &players);    // 플레이어 수정
void GetInformation(const vector<Player> &players);  // 플레이어 정보 보여주는 함수
string GetValidPosition(const string &prompt);  // 입력된 포지션 유효성 검사 및올바른 입력 반환하는 함수
                                               