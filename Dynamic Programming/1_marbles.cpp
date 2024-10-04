/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

int n1, n2, k1, k2;

int dp[110][110][20][20];

int rec(int g, int r, int mg, int mr) {
  // base
  if (mg > k1 || mr > k2) return 0;  // no way
  if (g == 0 && r == 0) return 1;    // successful way
  if (dp[g][r][mg][mr] != -1) return dp[g][r][mg][mr];
  int ans = 0;
  if (g > 0) ans = rec(g - 1, r, mg + 1, 0);   // place green
  if (r > 0) ans += rec(g, r - 1, 0, mr + 1);  // palce red
  return dp[g][r][mg][mr] = ans;
}

void jaiShreeRam() {
  cin >> n1 >> n2 >> k1 >> k2;
  mset(dp, -1);
  int ways = rec(n1, n2, 0, 0);
  cout << ways << endl;
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