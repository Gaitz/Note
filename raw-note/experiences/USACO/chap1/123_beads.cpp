/*
ID: gaitzga1
LANG: C++11
PROG: beads
*/
#include <fstream>
#include <iostream>
#include <stack>
#include <string>

using namespace std;
const string PROG_NAME = "beads";

const char WHITE = 'w';

template <typename stack>
void clearStack(stack target) {
  int originSize = target.size();
  for (int i = 0; i < target.size(); i++) {
    target.pop();
  }
}

// Dynamic Programming
int DanielBundalaSolution(int numb, string beads) {
  int n;
  char tmp[400], s[800];
  // fscanf(in, "%d %s", &n, tmp);

  strcpy(s, tmp);
  strcat(s, tmp);

  int left[800][2], right[800][2];
  left[0][0] = left[0][1] = 0;
  // [0] is 'r', [1] is 'b'

  for (int i = 1; i <= 2 * n; i++) {
    char current = s[i - 1];
    if (current == 'r') {
      left[i][0] = left[i - 1][0] + 1;
      left[i][1] = 0;
    } else if (current == 'b') {
      left[i][1] = left[i - 1][1] + 1;
      left[i][0] = 0;
    } else {
      left[i][0] = left[i - 1][0] + 1;
      left[i][1] = left[i - 1][1] + 1;
    }
  }

  right[2 * n][0] = right[2 * n][1] = 0;
  for (int i = 2 * n - 1; i >= 0; i--) {
    if (s[i] == 'r') {
      right[i][0] = right[i + 1][0] + 1;
      right[i][1] = 0;
    } else if (s[i] == 'b') {
      right[i][1] = right[i + 1][1] + 1;
      right[i][0] = 0;
    } else {
      right[i][0] = right[i + 1][0] + 1;
      right[i][1] = right[i + 1][1] + 1;
    }
  }

  int m = 0;
  for (int i = 0; i < 2 * n; i++)
    m = max(m, max(left[i][0], left[i][1]) + max(right[i][0], right[i][1]));
  m = min(m, n);
  // fprintf(out, "%d\n", m);
}

// a kind of brute force
int HollandFrankSolution(int numb, string beads) {
  int n = numb, max = 0, current, state, i, j;
  string s = beads;
  char c;

  s = s + s;
  for (i = 0; i < n; i++) {
    c = (char)s[i];

    if (c == 'w')
      state = 0;
    else
      state = 1;

    j = i;
    current = 0;
    while (state <= 2) {
      // dont go further in second string than starting position in first string
      while (j < n + i && (s[j] == c || s[j] == 'w')) {
        current++;
        j++;
      }
      state++;
      c = s[j];
    }
    if (current > max) max = current;
  }

  return max;
}

// Three pointers
int mySolution(int numb, string beads) {
  string twice = beads + beads;

  int result = 0;
  int preStart = -1, preEnd = -1;
  int currentIndex = 0;
  char currentLookingFor = twice[0];
  stack<int> whiteStack;

  while (currentIndex < twice.length()) {
    if (twice[currentIndex] == WHITE) {
      whiteStack.push(currentIndex);
      currentIndex++;
      continue;
    }

    if (currentLookingFor != twice[currentIndex]) {
      int previousLength = preEnd - preStart + 1;
      int currentLength = currentIndex - (preEnd + 1);
      result = max(result, previousLength + currentLength);

      preStart = preEnd + 1;
      preEnd = currentIndex - 1;
      // previous ending without White, White should count in current length
      while (!whiteStack.empty() && whiteStack.top() == preEnd) {
        preEnd = whiteStack.top() - 1;
        whiteStack.pop();
      }

      currentLookingFor = twice[currentIndex];
    }

    currentIndex++;
  }

  result = max(result, (preEnd - preStart + 1) + currentIndex - (preEnd + 1));

  if (result > beads.length()) {
    return beads.length();
  }

  return result;
}

int main() {
  ofstream fout(PROG_NAME + ".out");
  ifstream fin(PROG_NAME + ".in");

  int numb = 0;
  string rawBeads;
  fin >> numb >> rawBeads;
  int result = mySolution(numb, rawBeads);
  fout << result << endl;

  return 0;
}