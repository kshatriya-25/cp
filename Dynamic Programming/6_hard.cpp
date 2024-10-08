/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"
const int N = 100100;
int dp[4];
int n, c[N];
string s;

void jaiShreeRam() {
  cin >> n >> s;
  mset(dp, 0);
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) {
    if (s[i] == 'h')
      dp[0] += c[i];
    else if (s[i] == 'a')
      dp[1] = min(dp[0], dp[1] + c[i]);
    else if (s[i] == 'r')
      dp[2] = min(dp[1], dp[2] + c[i]);
    else
      dp[3] = min(dp[2], (dp[3] + c[i]));
  }
  cout << dp[3] << endl;
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