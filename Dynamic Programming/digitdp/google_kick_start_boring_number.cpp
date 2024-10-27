/* OM VIGHNHARTAYE NAMO NAMAH :*/

/* Description: in a given range L to R, fing no of numbers such that even
  posion are even and odd positions are odd also called as bpring numbers*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

int dp[102][2][2][101];

string L, R;
int len;

int rec(int level, int lo, int hi, int firtstnonzero) {
  if (level == len) {
    return 1;
  }

  if (dp[level][lo][hi][firtstnonzero] == -1) {
    int ans = 0;
    int lowlim = 0;
    int hilim = 9;

    // pruning the borders
    if (hi) {
      hilim = R[level] - '0';
    }
    if (lo) {
      lowlim = L[level] - '0';
    }

    if (level < firtstnonzero)
      hi = 0;  // means hi tight has achieved freedom (crct ?)

    for (int i = lowlim; i <= hilim; i++) {
      if (level >= firtstnonzero &&
          ((level - firtstnonzero + 1 - i) % 2) == 1)  // didnt get this
        continue;
      int newhi = hi;
      int newlo = lo;

      if (i != R[level]) newhi = 0;
      if (i != L[level]) newlo = 0;
      ans = ans + rec(level + 1, newlo, newhi, firtstnonzero);
    }
    dp[level][lo][hi][firtstnonzero] = ans;
  }
  return dp[level][lo][hi][firtstnonzero];
}

void jaiShreeRam() {
  cin >> L >> R;
  len = R.length();
  int extra = len - L.length();
  string temp = "";
  while (extra--) temp += '0';
  L = temp + L;
  mset(dp, -1);
  int ans = 0;
  for (int i = 0; i < len; i++) {  // didnt get this
    ans += rec(0, 1, 1, i);
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