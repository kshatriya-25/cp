/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

void jaiShreeRam() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int& x : a) cin >> x;
  int ans = 0;
  for (int i = 29; i >= 0; i--) {
    vector<int> elementswithbits;
    for (int x : a) {
      if (x & (1LL << i)) elementswithbits.emplace_back(x);
    }
    if (elementswithbits.size() >= x) {
      ans += (1LL << i);
      a = elementswithbits;
    }
  }
  cout << ans << "\n";
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    jaiShreeRam();
  }
}