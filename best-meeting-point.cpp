#include "util.h"

// Given an NxN grid, and K participant locations, what would be the best
// meeting point for the participants?
//
// The best meeting point minimizes the sum of manhattan distances of the
// participants from their locations to that point.

typedef pair<int,int> pii;
pii solve(const vector<pii>& l, int N) {
  vector<pii> locs = l;
  // O(K log K), but can be made O(K) using quick-select.
  // Sort by first dim
  sort(locs.begin(), locs.end(), [](const pii& a, const pii& b) {
    if (a.first < b.first) return true;
    if (a.first > b.first) return false;
    return a.second < b.second;
  });

  int xPivot = locs[locs.size()/2].first;
  // Sort by second dim
  sort(locs.begin(), locs.end(), [](const pii& a, const pii& b) {
    if (a.second < b.second) return true;
    if (a.second > b.second) return false;
    return a.first < b.first;
  });
  return make_pair(xPivot, locs[locs.size()/2].second);
}

int main() {
  assert(pii({2,2}) == solve({{0,0},{2,0},{0,2},{2,2}}, 3));
  assert(pii({0,2}) == solve({{0,0},{0,1},{0,2},{0,3},{0,4}}, 3));
  assert(pii({1,0}) == solve({{0,0},{1,2},{4,0}},5));
  return 0;
}
