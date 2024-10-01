/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

void jaiShreeRam() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> occurances[26];
  for (int i = 0; i < 26; i++) occurances[i].emplace_back(-1);  // left boundary
  for (int i = 0; i < n; i++) {
    occurances[s[i] - 'a'].emplace_back(i);
  }
  int score = 0;
  for (int i = 0; i < 26; i++) occurances[i].emplace_back(n);  // right boundry
  for (int i = 0; i < 26; i++) {
    for (int j = 1; j < occurances[i].size() - 1; j++) {
      score += (occurances[i][j] - occurances[i][j - 1]) *
               (occurances[i][j + 1] - occurances[i][j]);
    }
  }
  cout << score << endl;
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