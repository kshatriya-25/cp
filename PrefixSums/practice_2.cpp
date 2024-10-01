/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
const int N = 1000001;
void jaiShreeRam() {
  int n, k, q;
  vector<int> a(N, 0);
  cin >> n >> k >> q;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    a[l] += 1;
    a[r + 1] -= 1;
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];  // partial sum concept
  }
  for (int i = 1; i <= n; i++) {
    a[i] = (a[i] >= k);
  }
  int prefix[N];
  prefix[0] = 0;
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + a[i];
  }
  while (q-- > 0) {
    int l, r;
    cin >> l >> r;
    cout << prefix[r] - prefix[l - 1] << endl;
    ;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t-- > 0) {
    jaiShreeRam();
  }
}