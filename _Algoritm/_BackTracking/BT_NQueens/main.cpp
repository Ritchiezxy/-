
#include <iostream>
#include <cmath>
using namespace std;


void Show(int count, int queens[]) {
  cout << "(";
  for (int i = 1; i <= count; ++i) {
    cout << " " << queens[i];
  }
  cout << " )" << endl;
}
bool Place(int j, int queens[]) {
  for (int i = 1; i < j; ++i) {
    if (queens[i] == queens[j] || abs(queens[i] - queens[j]) == (j - i)) {
      return false;
    }
  }
  return true;
}

void NQueens(int j, int queens[], int queen_count) {
  cout << "\nEnter into queens[" << j << "] >>>>>>>>>>>>>>>>>"  << endl;
  if (j < 1)
    return;
  for (int i = 1; i <= queen_count; ++i) { // queen_count 列
    queens[j] = i;
    if (Place(j, queens)) {
      cout << "place queen " << j << " to column " << i << endl;
      if (j == queen_count) {
        Show(queen_count, queens);
      } else {

        NQueens(j + 1, queens, queen_count);
      }
    }
  }
  cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< back to " << j - 1 << endl << endl;
}

void main(int argc, char* argv[]) {
  const int n = 4;
  int queens[n + 1];
  NQueens(1, queens, n);

}
