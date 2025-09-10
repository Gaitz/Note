/*
ID: gaitzga1
LANG: C++11
PROG: wormhole
*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string PROG_NAME = "wormhole";

const int NotExists = -1;

// bool cycle_exists(void) {
//   for (int start = 1; start <= N; start++) {
//     // does there exist a cylce starting from start
//     int pos = start;
//     for (int count = 0; count < N; count++) pos =
//     next_on_right[partner[pos]]; if (pos != 0) return true;
//   }
//   return false;
// }

bool isCycleExists(vector<int> wormholesX, vector<int> wormholesY,
                   vector<int> nextOnRight, vector<int> linkedMap) {
  // for (int i = 0; i < linkedMap.size(); i++) {
  //   cout << "linked: " << i << " -> " << linkedMap[i] << "\n";
  // }
  // cout << "\n";

  bool isCycle = false;

  for (int start = 0; start < wormholesX.size(); start++) {
    int pos = start;
    // cout << "start: " << start << " ";

    for (int moves = 0; moves < wormholesX.size(); moves++) {
      if (pos == NotExists) {
        isCycle = false;
        // cout << "the end" << "\n";
        break;
      }
      pos = nextOnRight[linkedMap[pos]];
    }
    // cout << "end pos: " << pos << "\n";

    if (pos != NotExists) {
      isCycle = true;
      // cout << "isCycle: " << isCycle << "\n";
      return isCycle;
    }
  }

  return isCycle;
}

// loop all combiantion by iterative algorithm
// loop all combination by recursive with global variables

int loopAndCheck(vector<int> wormholesX, vector<int> wormholesY,
                 vector<int> nextOnRight, vector<int> linkedMap,
                 vector<int> unlinkedIndices) {
  // loop all combination by recursive with passing variables
  // 0, 1, 2, 3, nextOnRight, linked
  // [0, 1], [2, 3]
  // [0, 2], [1, 3]
  // [0, 3], [1, 2]
  int sum = 0;

  if (unlinkedIndices.size() == 0) {
    // all linked
    // check and sum
    // 3 2
    // 0 1

    bool isContainCycle =
        isCycleExists(wormholesX, wormholesY, nextOnRight, linkedMap);

    // if (isContainCycle) {
    //   cout << wormholesX.size() << "\n";
    //   for (int i = 0; i < wormholesX.size(); i++) {
    //     cout << linkedMap[i] << " ";
    //   }
    //   cout << "\n";
    // }

    if (isContainCycle) return 1;

    return 0;
  }

  // cout << "before, unlinkedIndices: ";
  // for (auto index : unlinkedIndices) {
  //   cout << index << " ";
  // }

  // TRUST, find green box, find base case

  // ! the index has bugs, using another way to implement this !
  int unlinkedStart = unlinkedIndices[0];
  for (int i = 1; i < unlinkedIndices.size(); i++) {
    int unlinkedEnd = unlinkedIndices[i];

    // link
    linkedMap[unlinkedStart] = unlinkedEnd;
    linkedMap[unlinkedEnd] = unlinkedStart;

    // setup remained
    vector<int> remainedUnlinkedIndcies;
    for (int point : unlinkedIndices) {
      if (point != unlinkedStart && point != unlinkedEnd)
        remainedUnlinkedIndcies.push_back(point);
    }

    // cout << "\n";
    // for (int i = 0; i < linkedMap.size(); i++) {
    //   cout << "linked: " << i << " -> " << linkedMap[i] << "\n";
    // }
    // cout << "remained: ";
    // for (auto remain : remainedUnlinkedIndcies) {
    //   cout << remain << " ";
    // }
    // cout << "\n";
    // cout << "\n";

    sum += loopAndCheck(wormholesX, wormholesY, nextOnRight, linkedMap,
                        remainedUnlinkedIndcies);

    // cout << "sum: " << sum << '\n';
  }

  // cout << "sum " << sum << endl;

  return sum;
}

int main() {
  ofstream fout(PROG_NAME + ".out");
  ifstream fin(PROG_NAME + ".in");

  vector<int> wormholesX;
  vector<int> wormholesY;
  vector<int> nextOnRight;
  int n;

  fin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    fin >> x >> y;
    wormholesX.push_back(x);
    wormholesY.push_back(y);
    // cout << wormholesX[i] << ", " << wormholesY[i] << "\n";
  }

  for (int i = 0; i < n; i++) {
    nextOnRight.push_back(NotExists);

    for (int j = 0; j < wormholesX.size(); j++) {
      if (wormholesY[i] == wormholesY[j] && wormholesX[i] < wormholesX[j]) {
        if (nextOnRight[i] == NotExists) {
          nextOnRight[i] = j;
        } else {
          nextOnRight[i] =
              wormholesX[j] < wormholesX[nextOnRight[i]] ? j : nextOnRight[i];
        }
      }
    }

    // cout << i << " next is: " << nextOnRight[i] << "\n";
  }

  vector<int> linked(n, NotExists);
  vector<int> unlinked;
  for (int i = 0; i < n; i++) {
    unlinked.push_back(i);
  }

  fout << loopAndCheck(wormholesX, wormholesY, nextOnRight, linked, unlinked)
       << endl;
  fin.close();
  fout.close();

  return 0;
}