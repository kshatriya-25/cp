/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

int n;

void jaiShreeRam() {
  cin >> n;
  int a[n];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) {
      if (a[i] < a[i - 1]) ans += a[i - 1] - a[i];
    }
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