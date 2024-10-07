/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

const int N = 100100;
int dp[N][2];  // memotable

string s[N];
string rev[N];
int cost[N];
int n;

int rec(int i, int r) {
  if (i == 0) {
    if (r)
      return cost[i];
    else
      return 0;
  }
  if (dp[i][r] != -1) return dp[i][r];
  int ans = 1e18;
  if (r) {
    if (rev[i] >= rev[i - 1]) ans = min(ans, rec(i - 1, 1) + cost[i]);
    if (rev[i] >= s[i - 1]) ans = min(ans, rec(i - 1, 0) + cost[i]);
  } else {
    if (s[i] >= s[i - 1]) ans = min(ans, rec(i - 1, 0));
    if (s[i] >= rev[i - 1]) ans = min(ans, rec(i - 1, 1));
  }
  return dp[i][r] = ans;
}

void jaiShreeRam() {
  mset(dp, -1);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> cost[i];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    rev[i] = s[i];
    reverse(all(rev[i]));
  }
  int ans = min(rec(n - 1, 0), rec(n - 1, 1));
  if (ans >= 1e18)
    cout << -1 << endl;
  else
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