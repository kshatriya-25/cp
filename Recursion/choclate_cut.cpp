/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

int dp[1001][1001][101];

int rec(int i, int j, int needed) {
  if (needed == 0) return 0;
  if (i * j < needed) return 1e18;
  if (i == j && needed == 1) return 0;
  if (dp[i][j][needed] != -1) return dp[i][j][needed];
  int ans = 1e18;
  // row wise cut
  for (int row = 1; row < i; row++) {
    for (int k = 0; k <= needed; k++) {
      ans = min(ans, rec(row, j, k) + rec(i - row, j, needed - k) + j * j);
    }
  }
  // cut col wise
  for (int col = 1; col < j; col++) {
    for (int k = 0; k <= needed; k++) {
      ans = min(ans, rec(i, col, k) + rec(i, j - col, needed - k) + i * i);
    }
  }
  return dp[i][j][needed] = ans;
}

void jaiShreeRam() {
  int n, m, k;
  cin >> n >> m >> k;
  mset(dp, -1);
  cout << rec(n, m, k) << endl;
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