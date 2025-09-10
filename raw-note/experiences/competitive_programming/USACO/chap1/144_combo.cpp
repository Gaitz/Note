/*
ID: gaitzga1
LANG: C++11
PROG: combo
*/
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using namespace std;
const string PROG_NAME = "combo";

int getNextNumber(int max, int current, int move) {
  int nextValidNumber;
  if (current + move <= 0) {
    nextValidNumber = (current + move) % max + max;
  } else {
    nextValidNumber = (current + move) % max;
  }
  if (nextValidNumber == 0) nextValidNumber = max;

  // cout << "max: " << max << " current: " << current << " move: " << move << "
  // nextValidNumber: " << nextValidNumber << "\n";

  return nextValidNumber;
}

set<int> getValidKeys(int max, int lockKey) {
  // current +- 2
  set<int> validKeys;
  // cout << "max:" << max << "\n";
  // cout << "current lockKey:" << lockKey << "\n";
  for (int j = 0; j <= 2; j++) {
    validKeys.insert(getNextNumber(max, lockKey, j));
    validKeys.insert(getNextNumber(max, lockKey, -j));
  }
  // cout << validKeys.size() << "\n";

  return validKeys;
}

set<tuple<int, int, int>> possibleLocks;

void addAllPossibleLockToTheSet(int max, vector<int> someoneLock) {
  // get all possible key in farmerLock
  array<set<int>, 3> validLockKeys;
  for (int i = 0; i < 3; i++) {
    validLockKeys[i] = getValidKeys(max, someoneLock[i]);
  }

  // store all combination into possible locks set
  for (int key1 : validLockKeys[0]) {
    for (int key2 : validLockKeys[1]) {
      for (int key3 : validLockKeys[2]) {
        // cout << key1 << " " << key2 << " " << key3 << "\n";
        possibleLocks.insert({key1, key2, key3});

        // for (tuple<int, int, int> lock : possibleLocks)
        // {
        //   int p1, p2, p3;
        //   tie(p1, p2, p3) = lock;
        //   // cout << p1 << " " << p2 << " " << p3 << "\n";
        // }
      }
    }
  }

  // cout << possibleLocks.size() << "\n";
}

int solve(int n, vector<int> farmerLock, vector<int> masterLock) {
  // store all possible key in a set of tuples

  addAllPossibleLockToTheSet(n, farmerLock);
  addAllPossibleLockToTheSet(n, masterLock);

  int count = possibleLocks.size();
  // cout << count << endl;

  return count;
}

int main() {
  ofstream fout(PROG_NAME + ".out");
  ifstream fin(PROG_NAME + ".in");
  int n;
  vector<int> farmerLock(3), masterLock(3);
  fin >> n;
  for (int i = 0; i < 3; i++) {
    fin >> farmerLock[i];
    // cout << farmerLock[i] << "\n";
  }

  for (int i = 0; i < 3; i++) {
    fin >> masterLock[i];
    // cout << masterLock[i] << "\n";
  }

  fout << solve(n, farmerLock, masterLock) << endl;

  // set<tuple<int, int, int>> testSet;
  // testSet.insert({1, 2, 3});
  // testSet.insert({4, 5, 6});
  // for (auto t : testSet)
  // {
  //   int p1, p2, p3;
  //   tie(p1, p2, p3) = t;
  //   cout
  //       << p1 << " " << p2 << " " << p3 << "\n";
  // }
  // cout << testSet.size() << "\n";

  return 0;
}

// case 1
// 50
// 5 6 7
// 5 6 7
// case 2
// 50
// 1 2 3
// 1 2 3
// case 3
// 50
// 1 2 3
// 5 6 7
// case 4
// 1
// 1 1 1
// 1 1 1
// case 5
// 2
// 1 2 2
// 1 2 2
// case 6
// 2
// 1 2 2
// 2 1 1