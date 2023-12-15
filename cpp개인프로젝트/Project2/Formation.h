#pragma once

class Formation {
 public:
  string formation_name;  // 포메이션 이름
  int defenders;          // 수비수 수
  int midfielders;        // 미드필더 수
  int forwards;           // 공격수 수
  Formation();  // 생성자
  Formation(string formationName, int defenders, int midfielders,
            int forwards);

};
