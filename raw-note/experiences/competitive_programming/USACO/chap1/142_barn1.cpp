/*
ID: gaitzga1
LANG: C++11
PROG: barn1
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
const string PROG_NAME = "barn1";

string solve(int maxBoards, int stalls, int numberOfCows,
             int cowsInStall[200]) {
  int blocked = cowsInStall[numberOfCows - 1] - cowsInStall[0] + 1;
  maxBoards--;

  int gap[200];
  int gapIndex = 0;
  int preStallPos = cowsInStall[0];

  for (int i = 1; i < numberOfCows; i++) {
    int currentPos = cowsInStall[i];

    if (currentPos != preStallPos + 1) {
      gap[gapIndex] = (currentPos - preStallPos) - 1;
      gapIndex++;
    }

    preStallPos = currentPos;
  }

  sort(gap, gap + gapIndex, greater<int>());

  for (int i = 0; i < gapIndex; i++) {
    if (maxBoards == 0) break;

    if (maxBoards > 0) {
      blocked -= gap[i];
      maxBoards--;
    }
  }

  return to_string(blocked);
}

int main() {
  ofstream fout(PROG_NAME + ".out");
  ifstream fin(PROG_NAME + ".in");

  int cowsInStall[200];
  int maxBoard, stalls, numberOfCows;

  fin >> maxBoard >> stalls >> numberOfCows;
  for (int i = 0; i < numberOfCows; i++) {
    int numberOfStall;
    fin >> numberOfStall;
    cowsInStall[i] = numberOfStall;
  }

  sort(cowsInStall, cowsInStall + numberOfCows);

  fout << solve(maxBoard, stalls, numberOfCows, cowsInStall) << endl;

  return 0;
}