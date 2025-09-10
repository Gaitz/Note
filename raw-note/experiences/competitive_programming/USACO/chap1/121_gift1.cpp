/*
ID: gaitzga1
LANG: C++11
PROG: gift1
*/
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

const string PROG_NAME = "gift1";

class Giver {
 public:
  string name = "";
  int amount = 0;
  map<string, Giver> receivers;

  Giver() {}
  Giver(string name) { this->name = name; }
};

int main() {
  ofstream fout(PROG_NAME + ".out");
  ifstream fin(PROG_NAME + ".in");

  int p = 0;
  fin >> p;

  string names[p];
  map<string, Giver> givers;
  for (int i = 0; i < p; i++) {
    string name;
    fin >> name;
    names[i] = name;
    givers[name] = Giver(name);
  }

  for (int i = 0; i < p; i++) {
    string giverName;
    fin >> giverName;
    Giver* giver = &givers[giverName];

    int cash = 0;
    int numberOfReceiver = 0;
    fin >> cash >> numberOfReceiver;
    int eachGift = (numberOfReceiver > 0 ? cash / numberOfReceiver : 0);
    int remain = (numberOfReceiver > 0 ? cash % numberOfReceiver : 0);
    giver->amount += -cash + remain;

    for (int j = 0; j < numberOfReceiver; j++) {
      string receiverName;
      fin >> receiverName;
      Giver* receiver = &givers[receiverName];
      receiver->amount += eachGift;
    }
  }

  for (string name : names) {
    Giver* giver = &givers[name];
    fout << giver->name << " " << giver->amount << endl;
  }

  return 0;
}