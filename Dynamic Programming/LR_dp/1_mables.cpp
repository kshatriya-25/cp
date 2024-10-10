/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

int dp[110][110][100];

int n, arr[550];

int rec(int l, int r, int k) {
  if (l > r) return 0;  // no search space
  if (dp[l][r][k] != -1) return dp[l][r][k];
  int ans = ((k + 1) * (k + 1)) + rec(l + 1, r, 0);  // no club
  for (int i = l + 1; i <= r; i++) {
    if (arr[i] == arr[l]) {
      ans = max(ans, rec(l + 1, i - 1, 0) + rec(i, r, k + 1));  // club with it
    }
  }
  return dp[l][r][k] = ans;
}

void jaiShreeRam() {
  mset(dp, -1);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int ans = rec(0, n - 1, 0);
  cout << ans << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  //   cin >> t;
  while (t-- > 0) {
    jaiShreeRam();
  }
}