/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define mod 1000000007
const int N = 1001001;
int a[N];
int b[N];

void jaiShreeRam() {
  int n, q;
  cin >> n >> q;
  a[0] = 0;
  b[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = (i * a[i]) % mod;
  }
  // building inplace prefix sum
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    a[i] %= mod;
    b[i] += b[i - 1];
    b[i] %= mod;
  }
  while (q-- > 0) {
    int l, r;
    cin >> l >> r;
    int ans = (b[r] - b[l - 1]);
    ans -= (l - 1) * (a[r] - a[l - 1]);
    ans = (((ans) % mod) + mod) % mod;
    cout << ans << endl;
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