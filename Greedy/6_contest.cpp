/* OM VIGHNHARTYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

int n;

void jaiShreeRam() {
  cin >> n;
  vector<int> ratings(n + 2);
  ratings.push_back(1e18);
  for (int i = 1; i <= n; i++) {
    cin >> ratings[i];
  }
  ratings.push_back(2e18);
  vector<pair<int, int>> indices;
  for (int i = 1; i <= n; i++) indices.push_back({ratings[i], i});
  vector<int> mintutes(n + 2, 0);
  sort(all(indices));
  int ans = 0;
  for (auto i : indices) {
    int idx = i.second;
    int give = 1;
    if (ratings[idx] > ratings[idx - 1])
      give = max(give, mintutes[idx - 1] + 1);
    if (ratings[idx] > ratings[idx + 1])
      give = max(give, mintutes[idx + 1] + 1);
    ans += give;
    mintutes[idx] = give;
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