#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll n;
vector<char> ss;
vl temp;
vector<bool> used(10, false);

vl maxans;
vl minans;

void solve(int d) {
  if (n + 1 == d) {
    if (0 == maxans.size() || maxans < temp) {
      maxans = temp;
    }
    if (0 == minans.size() || temp < minans) {
      minans = temp;
    }
    return;
  }

  for (auto i = 0; i <= 9; ++i) {
    if (used[i]) continue;

    if (0 == d) {
      temp.push_back(i);
      used[i] = true;
      solve(d + 1);
      temp.pop_back();
      used[i] = false;
    } else {
      if ('>' == ss[d - 1]) {
        if (i < temp[d - 1]) {
          temp.push_back(i);
          used[i] = true;
          solve(d + 1);
          temp.pop_back();
          used[i] = false;
        }
      } else {
        if (temp[d - 1] < i) {
          temp.push_back(i);
          used[i] = true;
          solve(d + 1);
          temp.pop_back();
          used[i] = false;
        }
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;
  ss = vector<char>(n);
  for (auto&& x : ss) {
    cin >> x;
  }

  solve(0);
  for (const auto& x : maxans) {
    cout << x;
  }
  cout << '\n';
  for (const auto& x : minans) {
    cout << x;
  }

  return 0;
}