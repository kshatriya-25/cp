/* OM VIGHNHARTAYE NAMO NAMAH :*/

// since low is fixed we will have just one tight paramere for upper tight 0
// will represent lower tight

#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

int dp[10002][2][101];
int d;
string s;

int rec(int level, int hi, int rem) {
  if (level == s.length()) {
    if (rem == 0)
      return 1;
    else
      return 0;
  }
  if (dp[level][hi][rem] == -1) {
    int ans = 0;
    int lolimit = 0;
    int hilimit = 9;

    if (hi == 1) {               // if we are tight on hi
      hilimit = s[level] - '0';  // coz its prev was also respecting boundry
    }
    for (int i = lolimit; i <= hilimit; i++) {
      int newhi = hi;
      if (i != s[level] - '0') {
        newhi = 0;
      }
      int newrem = (rem + i) % d;
      ans = (ans + (rec(level + 1, newhi, newrem))) % mod;
    }
    dp[level][hi][rem] = ans;
  }
  return dp[level][hi][rem];
}

void jaiShreeRam() {
  cin >> s >> d;
  mset(dp, -1);
  cout << (rec(0, 1, 0) - 1 + mod) % mod << endl;
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