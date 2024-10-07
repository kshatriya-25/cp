/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

const int N = 550;
const int MOD = 1e9 + 7;

int dp[N][N][N];

int b, n, m;
int arr[N];

int rec(int i, int lines, int bugs) {
  // success ful plan
  if (lines == 0 && bugs <= b) return 1;
  // not psbl
  if (i == 0 || lines < 0 || bugs < 0) return 0;

  if (dp[i][lines][bugs] != -1) return dp[i][lines][bugs];

  // transition
  int ans = 0;
  // skip current coder
  ans = (ans + rec(i - 1, lines, bugs)) % MOD;
  // have him for another oppertunity
  if (bugs >= arr[i]) {
    ans = (ans + rec(i, lines - 1, bugs - arr[i])) % MOD;
  }

  return dp[i][lines][bugs] = ans;
}

void jaiShreeRam() {
  mset(dp, -1);
  cin >> b >> n >> m;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int ans = rec(n, m, b);
  cout << ans << endl;
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
