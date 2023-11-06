#include <iostream>
using namespace std;
#define n 4
#define wt 8

struct item {
  int weight;
  int profit;
};

item item[4];

void sort(struct item item[]) {
  struct item temp;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (item[i].weight > item[j].weight) {
        temp = item[i];
        item[i] = item[j];
        item[j] = temp;
      }
    }
  }
}

void sortDisplay(struct item item[]) {
  for (int i = 0; i < n; i++) {
    cout << "\n" << item[i].weight << "\t" << item[i].profit;
  }
}

void calculate(int arr[n + 1][wt + 1]) {
  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= wt; w++) {
      if (i == 0 || w == 0) {
        arr[i][w] = 0;
      } else {
        int val = (w - (item[i - 1].weight));
        if (val < 0) {
          arr[i][w] = arr[i - 1][w];
        } else {
          arr[i][w] =
              max(arr[i - 1][w], (arr[i - 1][val] + item[i - 1].profit));
        }
      }
    }
  }
  cout << "\n"
       << "The max profit is:" << arr[n][wt] << "\n";
}

void displayArr(int arr[n + 1][wt + 1]) {
  for (int i = 0; i <= n; i++) {
    for (int w = 0; w <= wt; w++) {
      cout << arr[i][w] << "\t";
    }
    cout << "\n";
  }
}

void backTrack(int arr[n + 1][wt + 1], int x[]) {
  int i = n;
  int w = wt;
  while (i > 0 && w > 0) {
    if (arr[i][w] != arr[i - 1][w]) {
      x[i - 1] = 1;
      i = i - 1;
      w = w - (item[i - 1].weight);
    } else {
      i = i - 1;
    }
  }
}

void printItemArray(int x[]) {
  cout << "\n";
  for (int i = 0; i < n; i++) {
    cout << x[i] << "\t";
  }
}

int main() {
  item[0].profit = 2;
  item[0].weight = 3;
  item[1].profit = 3;
  item[1].weight = 4;
  item[2].profit = 1;
  item[2].weight = 6;
  item[3].profit = 4;
  item[3].weight = 5;

  sort(item);
  sortDisplay(item);

  int arr[n + 1][wt + 1];
  int x[n] = {0};
  calculate(arr);
  cout << "\n";
  displayArr(arr);
  backTrack(arr, x);
  printItemArray(x);
  return 0;
}