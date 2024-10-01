/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void jaiShreeRam() {
  int n;
  cin >> n;
  pair<int, int> monsters[n];
  for (int i = 0; i < n; i++) {
    cin >> monsters[i].first >> monsters[i].second;
  }
  sort(monsters, monsters + n, [&](pair<int, int>& a, pair<int, int>& b) {
    return (a.first - a.second > b.first - b.second);
  });
  int ans = 0, cur = 0;
  for (int i = 0; i < n; i++) {
    ans += max(0LL, monsters[i].first - cur);
    cur = max(1LL * monsters[i].first, cur);
    cur -= monsters[i].second;
  }
  cout << ans << endl;
  return;
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