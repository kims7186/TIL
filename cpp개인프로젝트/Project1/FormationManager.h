#pragma once
// 포메이션을 추가하기 위한 함수
void InsertFormation(vector<Formation> &formations);  // 포메이션 추가
void DeleteFormation(vector<Formation> &formations);  //포메이션 삭제
void EditFormation(vector<Formation> &formations);    //포메이션 수정

// 현재 포메이션 정보를 표시하는 함수
void DisplayFormation(const vector<Formation> &formations);