/* OM VIGHNHARTAYE NAMO NAMAH : */

#include <bits/stdc++.h>
using namespace std;

#define int long long

void jaiShreeRam() {
  int n;
  cin >> n;
  vector<int> bits[20];
  int arr[n];
  vector<int> done(n + 1, 0);
  int k = 19;
  for (int &x : arr) cin >> x;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k + 1; j++) {
      if (arr[i] & (1LL << j)) bits[j].emplace_back(i);
    }
  }
  while (k >= 0) {
    if (bits[k].size()) {
      int x = bits[k][bits[k].size() - 1];
      bits[k].pop_back();
      if (done[x] or !((1ll << k) & arr[x])) continue;
      done[x] = 1;
      for (int i = 0; i <= k; i++) {
        if (arr[x] & (1ll << i)) continue;

        while (bits[i].size()) {  // u may need to consider for an while
                                  // condition here
          int y = bits[i][bits[i].size() - 1];
          bits[i].pop_back();
          if (done[y] or !(1LL << i & arr[y])) continue;
          int temp = arr[y];
          arr[y] &= arr[x];
          arr[x] |= temp;
          break;
        }
      }
    } else
      k--;
  }
  int ans = 0;
  for (int i : arr) ans += (i * i);
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