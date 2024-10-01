/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

const int N = 100100;
int arr[N];
int n, m, q;

void jaiShreeRam() {
  cin >> n >> m >> q;
  pair<int, int> a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = 0;
  }
  while (m--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    a[l].second += 1;
    if (r + 1 < n) a[r + 1].second -= 1;
  }
  for (int i = 1; i < n; i++) a[i].second += a[i - 1].second;
  sort(a, a + n);
  pair<int, int> Q[q];
  for (int i = 0; i < q; i++) {
    cin >> Q[i].first;
    Q[i].second = i;
  }
  sort(Q, Q + q);
  int ptr = 0, sum = 0;
  int ans[q];
  for (int i = 0; i < q; i++) {
    int k = Q[i].first;
    while (ptr < n && sum + a[ptr].second < k) {
      sum += a[ptr].second;
      ptr++;
    }
    if (ptr < n)
      ans[Q[i].second] = a[ptr].first;
    else
      ans[Q[i].second] = -1;
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