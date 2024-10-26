/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

int dp[110][110][12];

int board[110][110];
int n, m, k;

void jaiShreeRam() {
  mset(dp, -1);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      board[i][j] = c - '0';
    }
  }
  for (int j = 1; j <= m; j++) {
    int r = board[n][j] % k;
    dp[n][j][r] = board[n][j];
  }

  for (int i = n - 1; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      for (int l = 0; l < k; l++) {
        if (j > 1 && dp[i + 1][j - 1][l] >= 0) {  // valid prev path
          int t = dp[i + 1][j - 1][l] + board[i][j];
          if (dp[i][j][t % k] < t) dp[i][j][t % k] = t;
        }
        if (j < m && dp[i + 1][j + 1][l] >= 0) {
          int t = dp[i + 1][j + 1][l] + board[i][j];
          if (dp[i][j][t % k] < t) dp[i][j][t % k] = t;
        }
      }
    }
  }
  int ans = -1;
  for (int j = 1; j <= m; j++) {
    if (dp[1][j][0] > ans) ans = dp[1][j][0];
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