/*
ID: gaitzga1
LANG: C++11
PROG: milk
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const string PROG_NAME = "milk";

struct FarmerSell {
  int price;
  int available;
};

string solve(int totalNeeds, int numOfFarmers, vector<FarmerSell> farmers) {
  int cost = 0;
  int bought = 0;

  // cout << totalNeeds << " " << numOfFarmers << endl;
  // cout << "farmers" << endl;

  sort(farmers.begin(), farmers.end(),
       [](FarmerSell a, FarmerSell b) { return a.price < b.price; });

  for (int i = 0; i < numOfFarmers; i++) {
    int need = totalNeeds - bought;
    if (need == 0) {
      break;
    }

    if (farmers[i].available <= need) {
      bought += farmers[i].available;
      cost += farmers[i].available * farmers[i].price;
    } else {
      bought += need;
      cost += need * farmers[i].price;
    }

    // cout << farmers[i].available << " in " << farmers[i].price
    //      << " cent per unit" << endl;
  }

  return to_string(cost);
}

int main() {
  ofstream fout(PROG_NAME + ".out");
  ifstream fin(PROG_NAME + ".in");
  int totalNeeds, numOfFarmers;
  vector<FarmerSell> farmers;

  fin >> totalNeeds >> numOfFarmers;
  for (int i = 0; i < numOfFarmers; i++) {
    FarmerSell farmer;
    fin >> farmer.price >> farmer.available;
    farmers.push_back(farmer);
  }

  fout << solve(totalNeeds, numOfFarmers, farmers) << endl;
  return 0;
}