/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

int m, d, mod = 1e9 + 7;

string a, b;
int len;

int dp[2020][2][2][10];

int rec(int level, int lo, int hi, int rem) {
  if (level == len) {
    if (rem == 0)
      return 1;
    else
      return 0;
  }

  if (dp[level][lo][hi][rem] == -1) {
    int ans = 0;

    int lowlimit = 0;
    int hilimit = 9;

    // pruning boundaries
    if (lo) {
      lowlimit = a[level] - '0';
    }

    if (hi) hilimit = b[level] - '0';

    for (int i = lowlimit; i <= hilimit; i++) {
      // making one based index and checking if current position is odd or even
      // and currnet number is d
      if ((level % 2 == 1 && i == d) || (level % 2 == 0 && i != d)) {
        int newlo = lo;
        int newhi = hi;

        if (i != a[level] - '0') newlo = 0;
        if (i != b[level] - '0') newhi = 0;

        int newrem = (rem * 10 + i) % m;
        ans = (ans + rec(level + 1, newlo, newhi, newrem)) % mod;
      }
    }
    dp[level][lo][hi][rem] = ans;
  }
  return dp[level][lo][hi][rem];
}

void jaiShreeRam() {
  mset(dp, -1);
  cin >> m >> d >> a >> b;
  len = a.length();
  // given a,b are of same length so need for padding
  cout << (rec(0, 1, 1, 0)) << endl;  //-1 coz level zero will be added
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