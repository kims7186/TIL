#include "Formation.h"

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// ������ ����
Formation::Formation()
    : formation_name(""), defenders(0), midfielders(0), forwards(0) {}
Formation::Formation(string formationName, int defenders, int midfielders,
                     int forwards) {
  this->formation_name = formationName;
  this->defenders = defenders;
  this->midfielders = midfielders;
  this->forwards = forwards;
}
