/*
ID: gaitzga1
LANG: C++11
PROG: transform
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
const string PROG_NAME = "transform";

bool isEqual(int numb, char a[10][10], char b[10][10]) {
  for (int i = 0; i < numb; i++) {
    for (int j = 0; j < numb; j++) {
      if (a[i][j] != b[i][j]) return false;
    }
  }
  return true;
}

void copy(int numb, char origin[10][10], char target[10][10]) {
  for (int i = 0; i < numb; i++) {
    for (int j = 0; j < numb; j++) {
      target[i][j] = origin[i][j];
    }
  }
}

void ninetyT(int numb, char origin[10][10], char target[10][10]) {
  char copiedOrigin[10][10];
  copy(numb, origin, copiedOrigin);

  for (int i = 0; i < numb; i++) {
    for (int j = 0; j < numb; j++) {
      target[i][j] = copiedOrigin[numb - 1 - j][i];
    }
  }
}

void reflection(int numb, char origin[10][10], char target[10][10]) {
  char copiedOrigin[10][10];
  copy(numb, origin, copiedOrigin);

  for (int i = 0; i < numb; i++) {
    for (int j = 0; j < numb; j++) {
      target[i][j] = copiedOrigin[i][numb - 1 - j];
    }
  }
}

string solve(int numb, char a[10][10], char b[10][10]) {
  char transformed[10][10];
  copy(numb, a, transformed);

  // 90 deg
  ninetyT(numb, a, transformed);
  if (isEqual(numb, transformed, b)) {
    return "1";
  }
  // 180 deg
  ninetyT(numb, transformed, transformed);
  if (isEqual(numb, transformed, b)) {
    return "2";
  }
  // 270 deg
  ninetyT(numb, transformed, transformed);
  if (isEqual(numb, transformed, b)) {
    return "3";
  }

  // reflection horizontally
  reflection(numb, a, transformed);
  if (isEqual(numb, transformed, b)) {
    return "4";
  }

  // reflection + 90 deg
  ninetyT(numb, transformed, transformed);
  if (isEqual(numb, transformed, b)) {
    return "5";
  }

  // reflection + 180 deg
  ninetyT(numb, transformed, transformed);
  if (isEqual(numb, transformed, b)) {
    return "5";
  }

  // reflection + 270 deg
  ninetyT(numb, transformed, transformed);
  if (isEqual(numb, transformed, b)) {
    return "5";
  }

  // no change
  if (isEqual(numb, a, b)) {
    return "6";
  }

  // invalid transformation
  return "7";
}

int main() {
  ofstream fout(PROG_NAME + ".out");
  ifstream fin(PROG_NAME + ".in");
  int n;
  fin >> n;
  char a[10][10], b[10][10];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      fin >> b[i][j];
    }
  }

  fout << solve(n, a, b) << endl;
  return 0;
}