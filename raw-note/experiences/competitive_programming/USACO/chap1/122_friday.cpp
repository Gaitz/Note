/*
ID: gaitzga1
LANG: C++11
PROG: friday
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
const string PROG_NAME = "friday";

void addWeekFrequency(int* weekFrequency, int dayOfWeek) {
  // 0 (Sun), 1, 2, 3, 4, 5, 6 (Sat)
  // Output: Sat i: 0, Sun i: 1, Mon, ..., Fri i: 6
  weekFrequency[(dayOfWeek + 1) % 7]++;
}

void countThirteenth(int* weekFrequency, int& accDays) {
  addWeekFrequency(weekFrequency, accDays % 7);
}

int daysOfMonth(int year, int month) {
  switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
    case 2:
      if (year % 100 == 0 && year % 400 != 0) {
        return 28;
      } else if (year % 4 == 0) {
        return 29;
      } else {
        return 28;
      }
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
    default:
      cerr << "error month of days of month";
      return 0;
  }
}

string solve(int n) {
  // every month has one 13
  // 1900.1.1 Mon then 13 will be ? 13 % 7 = 6, (Sat)
  // next month, 1900.1.31 will be 31 % 7 = 3 (Wed), 1900.2.1 (Thu)
  // 1900.2.13 will be 13 % 7 = 6, 8 Thu, 9 Fri, 10 Sat, 11 Sun, 12 Mon, 13
  // (Tue) 13+31 = 44, 44 % 7 = 2
  // 1
  // 13, +31, +28, +31, +30, +31, +30, +31, +31, +30, +31, +30, +31
  // 1 13,
  // 2 +31, 44,
  // 3 +28 72,
  // 4 +31 103,
  // 5 +30 133,
  // 6 +31 164,
  // 7 +30 194,
  // 8 +31 225,
  // 9 +31 256,
  // 10 +30 286,
  // 11 +31 317,
  // 12 +30 347,
  // next 1 +31 378,
  // % 7
  int weekFrequency[7] = {0};

  int accDays = 13;
  for (int i = 0; i < n; i++) {
    int year = 1900 + i;
    for (int month = 1; month <= 12; month++) {
      countThirteenth(weekFrequency, accDays);
      accDays += daysOfMonth(year, month);
    }
  }

  string result = "";
  for (auto frequency : weekFrequency) {
    result += to_string(frequency) + " ";
  }
  result.pop_back();
  return result;
}

int main() {
  ofstream fout(PROG_NAME + ".out");
  ifstream fin(PROG_NAME + ".in");
  int n;
  fin >> n;
  fout << solve(n) << endl;
  return 0;
}