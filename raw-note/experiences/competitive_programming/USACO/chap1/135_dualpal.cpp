/*
ID: gaitzga1
LANG: C++11
PROG: dualpal
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
const string PROG_NAME = "dualpal";

string getPatterInBase(int base, int num) {
  string pattern = "";
  while (num >= base) {
    pattern.insert(0, to_string(num % base));
    num = num / base;
  }
  pattern.insert(0, to_string(num));

  return pattern;
}

bool isPalindrome(int base, int num) {
  string pattern = getPatterInBase(base, num);
  bool judgement = true;

  for (int i = 0; i < pattern.length() / 2; i++) {
    if (pattern[i] != pattern[pattern.length() - 1 - i]) {
      judgement = false;
      break;
    }
  }

  return judgement;
}

void solve(ofstream &print, int n, int s) {
  int numOfAnswers = 0;

  int i = s + 1;
  while (true) {
    int palindromeInBases = 0;

    for (int base = 2; base <= 10; base++) {
      if (isPalindrome(base, i)) {
        palindromeInBases++;
      }

      if (palindromeInBases >= 2) {
        numOfAnswers++;
        print << i << endl;
        break;
      }
    }

    if (numOfAnswers == n) break;

    i++;
  }
}

int main() {
  ofstream fout(PROG_NAME + ".out");
  ifstream fin(PROG_NAME + ".in");
  int n, s;
  fin >> n >> s;
  solve(fout, n, s);
  return 0;
}