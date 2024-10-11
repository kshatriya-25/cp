/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

string s;
int n;

int longest;

int rec(int i, int j) {
  if (i == n || j < 0) return 0;  // no more space
  int ans = 0;
  if (s[i] == '(')
    j++;
  else if (s[i] == ')')
    j--;
  if (j == 0 && i) {
    longest = i + 1;
    ans++;
  }
  ans += rec(i + 1, j);
  return ans;
}

void jaiShreeRam() {
  cin >> s;
  n = s.length();
  int ans = rec(0, 0);
  if (!ans) ans++;
  cout << longest << " " << ans << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t-- > 0) {
    longest = 0;
    jaiShreeRam();
  }
}