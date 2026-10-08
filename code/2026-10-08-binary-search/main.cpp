#include "binary_search.hpp"

using namespace std;
// Binary Search 
// Params:
// arr : a sorted array
// target : a target value
// Return:
// the index of the target if it exists - else returns -1.
int binary_search(vector<int>& arr, int target) {
  int lo = 0, hi = arr.size()-1;
  while(lo <= hi) {
    int idx = (lo + hi) / 2;
    if(arr[idx] == target) {
      return idx;
    } else if(arr[idx] < target) {
      lo = idx + 1;
    } else {
      hi = idx - 1;
    }
  }
  return -1;
}

void tests() {
  // Test 1 : empty array
  vector<int> a = {};
  assert(binary_search(a, 0) == -1);
  cout << "Test 1 passed -- empty array\n";

  // Test 2 : Single Element found
  vector<int> b = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  assert(binary_search(b, 23) == 5);
  cout << "Test 2 passed -- single element found\n";

  // Test 3 : Boundary conditions L
  assert(binary_search(b, 2) == 0);
  cout << "Test 3 passed -- Boundary Conditions L\n";

  // Test 4 : Boundary conditions R
  assert(binary_search(b, 91) == 9);
  cout << "Test 4 passed -- Boundary Conditions R\n";

  // Test 5 : Element doesn't exist 
  assert(binary_search(b, 24) == -1);
  cout << "Test 5 passed -- Element doesn't exist\n";
}

int main () {
  tests();
  return 0;
}
