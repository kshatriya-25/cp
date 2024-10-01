/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void jaiShreeRam() {
  int m;
  cin >> m;
  string s[m];
  for (int i = 0; i < m; i++) {
    cin >> s[i];
  }
  int cnt[m][2];
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < m; i++) {
    string x = s[i];
    for (char c : x) {
      if (c == '0')
        cnt[i][0]++;
      else
        cnt[i][1]++;
    }
  }
  vector<int> id(m);
  for (int i = 0; i < m; i++) id[i] = i;
  sort(id.begin(), id.end(), [&](int x, int y) {
    return cnt[x][1] * cnt[y][0] < cnt[x][0] * cnt[y][1];
  });
  int ans = 0, one = 0;

  for (int i : id) {
    for (char c : s[i]) {
      if (c == '0')
        ans += one;
      else
        one++;
    }
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