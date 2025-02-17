#include <iostream>
#include <algorithm>


void quicksortHelper(std::vector<int>& foo, int ub, int lb, int pivotPos) {
  int n = foo.size();
  int pivotPos = pivotPos;
  int val = foo.at(pivotPos);

  for (int i = ub; i < lb; ++i) {
    int bar = foo.at(i);
    if (bar < val) {

    } else if (bar > val) {

    }
  }

}

void quicksort(std::vector<int> &foo, int pivotPos) {
  quicksortHelper(foo, 0, foo.size() - 1, pivotPos);
}

int main() {
  std::vector<int> foo = {1, 2, 3, 4, 5};
}