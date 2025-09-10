/*
ID: gaitzga1
LANG: C++11
PROG: milk2
*/
#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const string PROG_NAME = "milk2";

string solve(vector<array<int, 2>> milkT) {
  sort(milkT.begin(), milkT.end(),
       [](array<int, 2> a, array<int, 2> b) { return b[0] > a[0]; });

  for (int i = 0; i < milkT.size(); i++) {
    for (int j = i + 1; j < milkT.size(); j++) {
      if (milkT[i][1] >= milkT[j][0]) {
        milkT[i] = {min(milkT[i][0], milkT[j][0]),
                    max(milkT[i][1], milkT[j][1])};
        milkT.erase(milkT.begin() + j);
        j--;
      }
    }
  }

  int continuous = 0;
  for (int i = 0; i < milkT.size(); i++) {
    continuous = max(continuous, milkT[i][1] - milkT[i][0]);
  }

  int idle = 0, prevEnd = milkT[0][1];
  for (int i = 1; i < milkT.size(); i++) {
    idle = max(idle, milkT[i][0] - prevEnd);
    prevEnd = milkT[i][1];
  }

  return to_string(continuous) + " " + to_string(idle);
}

int main() {
  ofstream fout(PROG_NAME + ".out");
  ifstream fin(PROG_NAME + ".in");
  int numb;
  vector<array<int, 2>> milkT;

  fin >> numb;
  for (int i = 0; i < numb; i++) {
    int start, end;
    fin >> start >> end;
    milkT.push_back({start, end});
  }

  fout << solve(milkT) << endl;
  return 0;
}