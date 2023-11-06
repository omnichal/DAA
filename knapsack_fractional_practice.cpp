#include <iostream>
using namespace std;
#define W 15

struct item {
  int p;
  int w;
  float pw;
};

item it[10];

void calculate(item it[10], int n) {
  for (int i = 0; i < n; i++) {
    it[i].pw = ((float)it[i].p) / it[i].w;
  }
}

void input(item it[10], int n) {
  for (int i = 0; i < n; i++) {
    cout << "\n Enter the profit of the object: \n";
    cin >> it[i].p;
    cout << "\n Enter the weight of the object: \n";
    cin >> it[i].w;
  }
}

void sortPW(item it[10], int n) {
  item temp;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (it[i].pw < it[j].pw) {
        temp = it[i];
        it[i] = it[j];
        it[j] = temp;
      }
    }
  }
}

void pwDisplay(item it[10], int n) {
  cout << "\n"
       << "Profit\tWeight\tP/W"
       << "\n";
  for (int i = 0; i < n; i++) {
    cout << it[i].p << "\t" << it[i].w << "\t" << it[i].pw;
    cout << "\n";
  }
}

void knapsack(item it[10], int n) {
  float curr_cpty = 0;
  float totalProfit = 0;
  cout << "\n"
       << "Items added to the bag:"
       << "\n";
  for (int i = 0; i < n; i++) {
    if (curr_cpty <= W) {
      if ((curr_cpty + it[i].w) <= W) {
        cout << "\n" << it[i].w << "\n";
        curr_cpty = curr_cpty + it[i].w;
        totalProfit = totalProfit + it[i].p;
      } else {
        int val = W - curr_cpty;
        float wt = (float)val / it[i].w;
        cout << wt << "\n";
        curr_cpty = curr_cpty + (wt);
        totalProfit = totalProfit + (wt * it[i].p);
      }
    } else {
      break;
    }
  }
  cout << "\n"
       << "Total Profit obtained is:"
       << "\n";
  cout << totalProfit;
}

int main() {
  int n;
  cout << "\n Enter the number of objects: \n";
  cin >> n;
  input(it, n);
  calculate(it, n);
  sortPW(it, n);
  pwDisplay(it, n);
  knapsack(it, n);
  return 0;
}