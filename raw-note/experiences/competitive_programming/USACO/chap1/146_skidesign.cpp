/*
ID: gaitzga1
LANG: C++11
PROG: skidesign
*/
#include <algorithm>
#include <climits>
#include <cmath>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

const string PROG_NAME = "skidesign";

int solve(vector<int> hills) {
  int minCost = INT_MAX;

  // O(n)
  int minValue = *(min_element(hills.begin(), hills.end()));
  int maxValue = *(max_element(hills.begin(), hills.end()));

  if (maxValue - minValue <= 17) {
    // no need to change
    return 0;
  }

  // 1 4 20 21 24
  // [1, 18]
  // 2^2 + 3^2 + 6^2 = 4 + 9 + 36 = 49

  // try all the gaps and count the cost
  // n times
  // O(n * n) = O(n^2)
  for (int i = 0; i < maxValue - minValue + 1; i++) {
    pair<int, int> interval = {minValue + i, minValue + i + 17};

    int cost = 0;
    // O(n)
    for (int hillHeight : hills) {
      if (hillHeight < interval.first) {
        cost += pow((interval.first - hillHeight), 2);
      } else if (hillHeight > interval.second) {
        cost += pow((hillHeight - interval.second), 2);
      }
    }

    minCost = min(cost, minCost);
  }

  // return the smallest one
  return minCost;
}

int main() {
  ofstream fout(PROG_NAME + ".out");
  ifstream fin(PROG_NAME + ".in");
  int nHills;
  fin >> nHills;
  vector<int> hills;
  for (int i = 0; i < nHills; i++) {
    int hillHeight;
    fin >> hillHeight;
    hills.push_back(hillHeight);
  }

  fout << solve(hills) << endl;

  return 0;
}

// max n = 1000, max m = 100
// complexity = O (n * m) = 1000*100 = 100,000
// force brute