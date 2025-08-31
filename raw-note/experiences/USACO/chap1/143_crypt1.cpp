/*
ID: gaitzga1
LANG: C++11
PROG: crypt1
*/
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;
const string PROG_NAME = "crypt1";

set<int> numberSet;

bool containInNumber(int target) {
  return numberSet.find(target) != numberSet.end();
}

int getDigitSize(int n) {
  n = n < 0 ? -n : n;
  int size = 1;

  while (n > 10) {
    size++;
    n /= 10;
  }

  return size;
}

bool isViablePart(int target, int digitSize) {
  // cout << "is viable part: " << target << " digitSize:" << digitSize << "\n";
  if (getDigitSize(target) != digitSize) {
    // cout << "invalid digit size" << "\n";
    return false;
  }

  if (!containInNumber(target % 10)) return false;
  while (target > 10) {
    target /= 10;
    if (!containInNumber(target % 10)) return false;
  }

  return true;
}

bool isViableSolution(int keys[5]) {
  int a = keys[0];
  int b = keys[1];
  int c = keys[2];
  int d = keys[3];
  int e = keys[4];
  // cout << a << " " << b << " " << c << " " << d << " " << e << "\n";

  // check is x viable
  int x = (a * 100 + b * 10 + c) * e;
  // cout << x << " x is viable?" << isViablePart(x, 3) << "\n";
  if (!isViablePart(x, 3)) return false;

  // check is y viable
  int y = (a * 100 + b * 10 + c) * d;
  // cout << y << " y is viable?" << isViablePart(y, 3) << "\n";
  if (!isViablePart(y, 3)) return false;

  // check product is viable
  int product = x + y * 10;
  // cout << product << " product is viable?" << isViablePart(product, 4) <<
  // "\n";
  if (!isViablePart(product, 4)) return false;

  // cout << "viable solution: " << "\n";
  // cout << a << " " << b << " " << c << " " << d << " " << e << "\n";
  return true;
}

int solve(vector<int> numbers) {
  // a b c
  //   d e
  // x = ae + be + ce -> must three digits
  //         and every digit is in the set
  // y = ad + db + dc -> same
  // x + y * 10 -> must four digits and every digit is in the set

  // brute-force
  // set a counter for solutions
  int counter = 0;
  // loop a, b, c, d, e variables by numbers
  for (int a : numbers) {
    for (int b : numbers) {
      for (int c : numbers) {
        for (int d : numbers) {
          for (int e : numbers) {
            int keys[5]{a, b, c, d, e};
            if (isViableSolution(keys)) {
              counter++;
            }
          }
        }
      }
    }
  }

  return counter;
};

int main() {
  ofstream fout(PROG_NAME + ".out");
  ifstream fin(PROG_NAME + ".in");

  int size;
  vector<int> numbers(0);

  fin >> size;
  for (int i = 0; i < size; i++) {
    int number;
    fin >> number;
    numberSet.insert(number);
    numbers.push_back(number);
  }

  // cout << containInNumber(1) << "\n";

  fout << solve(numbers) << endl;

  return 0;
}