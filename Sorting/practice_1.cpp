/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void jaiShreeRam() {
  int n;
  cin >> n;
  int v[n], w[n];
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  sort(v, v + n);
  sort(w, w + n);
  int ans = 0;
  for (int i = 0, j = n - 1; i < n; i++, j--) {
    ans += v[i] * w[j];
  }
  cout << ans << endl;
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