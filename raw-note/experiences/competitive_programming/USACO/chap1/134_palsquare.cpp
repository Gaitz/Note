/*
ID: gaitzga1
LANG: C++11
PROG: palsquare
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
const string PROG_NAME = "palsquare";

bool isPalindromic(string pattern) {
  for (int i = 0; i < pattern.length() / 2; i++) {
    if (pattern[i] != pattern[pattern.length() - 1 - i]) {
      return false;
    }
  }

  return true;
}

string getString(int numb) {
  if (numb >= 10) {
    return string() + (char)((int)'A' + (numb - 10));
  }
  return to_string(numb);
}

string getPatternInBase(int base, int numb) {
  string pattern = "";

  while (numb >= base) {
    pattern.insert(0, getString(numb % base));
    numb = numb / base;
  }
  pattern.insert(0, getString(numb));

  return pattern;
}

void solve(ofstream &print, int base) {
  for (int i = 0; i < 300; i++) {
    string pattern = getPatternInBase(base, (i + 1) * (i + 1));
    if (isPalindromic(pattern)) {
      print << getPatternInBase(base, i + 1) << " " << pattern << endl;
    }
  }
}

int main() {
  ofstream fout(PROG_NAME + ".out");
  ifstream fin(PROG_NAME + ".in");
  int base;
  fin >> base;
  solve(fout, base);
  return 0;
}