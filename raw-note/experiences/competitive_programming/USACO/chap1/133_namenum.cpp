/*
ID: gaitzga1
LANG: C++11
PROG: namenum
*/
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
const string PROG_NAME = "namenum";

string solve(unordered_map<char, array<char, 3>> keypad,
             unordered_set<string> possibleNames, string serial) {
  vector<string> validNames;

  short permutationIndex[serial.length()];
  for (int i = 0; i < serial.length(); i++) {
    permutationIndex[i] = 0;
  }

  while (true) {
    string name = "";

    for (int i = 0; i < serial.length(); i++) {
      char digit = serial[i];
      name += ((keypad[digit][permutationIndex[i]]));
    }

    bool isValidName = possibleNames.find(name) != possibleNames.end();
    if (isValidName) validNames.push_back(name);

    int j = serial.length() - 1;
    while (j != -1) {
      permutationIndex[j]++;
      if (permutationIndex[j] < 3) {
        break;
      }
      permutationIndex[j] = 0;
      j--;
    }

    if (j == -1) {
      break;
    }
  }

  if (validNames.size() == 0) return "NONE";

  string result = "";

  for (int i = 0; i < validNames.size(); i++) {
    string name = validNames[i];
    result += name + "\n";
  }
  result.pop_back();

  return result;
}

int main() {
  ofstream fout(PROG_NAME + ".out");
  ifstream fin(PROG_NAME + ".in");
  ifstream dictFin("dict.txt");

  string serial;
  fin >> serial;
  fin.close();

  string name;
  unordered_set<string> possibleNames;
  while (getline(dictFin, name)) {
    possibleNames.insert(name);
  }
  dictFin.close();

  unordered_map<char, array<char, 3>> keypad = {
      {'2', {'A', 'B', 'C'}}, {'3', {'D', 'E', 'F'}}, {'4', {'G', 'H', 'I'}},
      {'5', {'J', 'K', 'L'}}, {'6', {'M', 'N', 'O'}}, {'7', {'P', 'R', 'S'}},
      {'8', {'T', 'U', 'V'}}, {'9', {'W', 'X', 'Y'}}};

  fout << solve(keypad, possibleNames, serial) << endl;
  return 0;
}