/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

int n;
string s;

void jaiShreeRam() {
  int prev[26];
  cin >> n >> s;
  int ans = 26 * ((n * (n + 1)) / 2);
  for (int i = 0; i < 26; i++) prev[i] = -1;
  for (int i = 0; i < n; i++) {
    int lenNotWithChar = i - prev[s[i] - 'a'] - 1;
    ans -= (lenNotWithChar * (lenNotWithChar + 1)) / 2;
    prev[s[i] - 'a'] = i;
  }
  for (int i = 0; i < 26; i++) {
    int lenNotWithChar = n - prev[i] - 1;
    ans -= (lenNotWithChar * (lenNotWithChar + 1)) / 2;
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