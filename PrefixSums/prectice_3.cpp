/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define mod 1000000007

void jaiShreeRam() {
  int n, m, q;
  cin >> n >> m >> q;
  int a[n + 1][m + 1];
  memset(a, 0, sizeof(a));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {  // calculating rectangular prefix sum
      a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    }
  }
  while (q-- > 0) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans = a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
    ans %= mod;
    if (ans < 0) ans += mod;
    cout << ans << "\n";
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  //  cin >> t;
  while (t-- > 0) {
    jaiShreeRam();
  }
}