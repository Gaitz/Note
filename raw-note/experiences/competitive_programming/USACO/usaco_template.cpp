/*
ID: gaitzga1
LANG: C++11
PROG: ride
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const string PROG_NAME = "ride";

string solve(string a, string b) { return a; }

int main() {
  ofstream fout(PROG_NAME + ".out");
  ifstream fin(PROG_NAME + ".in");
  string a, b;
  fin >> a >> b;
  fout << solve(a, b) << endl;
  return 0;
}