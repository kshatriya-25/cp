/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void jaiShreeRam() {
  int n, m, Q;
  cin >> n >> m >> Q;
  pair<int, int> a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = 0;
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    a[l].second += 1;
    if (r + 1 < n) a[r + 1].second -= 1;
  }
  for (int i = 1; i <= n; i++) a[i].second += a[i - 1].second;
  sort(a, a + n);
  pair<int, int> q[Q];
  int ans[Q];
  for (int i = 0; i < Q; i++) {
    cin >> q[i].first;
    q[i].second = i;
  }
  sort(q, q + Q);
  int sum = 0, ptr = 0;
  for (int i = 0; i < Q; i++) {
    int x = q[i].first;
    while (sum + a[ptr].second < x) {
      sum += a[ptr].second;
      ptr++;
    }
    if (ptr < n)
      ans[q[i].second] = a[ptr].first;
    else
      ans[q[i].second] = -1;
  }
  for (int i : ans) cout << i << " ";
  cout << endl;
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