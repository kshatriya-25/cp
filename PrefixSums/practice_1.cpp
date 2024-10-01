/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
const int mod = 1000000007;
const int N = 1000001;
int arr[N];

void jaiShreeRam() {
  int n, q;
  cin >> n >> q;

  arr[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= n; i++) {
    arr[i] += arr[i - 1];  // prefix sum
    if (arr[i] < 0) arr[i] += mod;
    if (arr[i] >= mod) arr[i] -= mod;
  }
  while (q-- > 0) {
    int l, r;
    cin >> l >> r;

    int ans = arr[r] - arr[l - 1];
    if (ans < 0) ans += mod;
    if (ans >= mod) ans -= mod;
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