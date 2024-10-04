/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

int n;

void jaiShreeRam() {
  cin >> n;
  vector<pair<int, int>> interval;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    interval.push_back({r, l});
  }
  sort(all(interval));
  int last_pt = INT_MIN, pt = 0;
  for (auto i : interval) {
    int l = i.second;
    int r = i.first;
    if (last_pt < l) {
      pt++;
      last_pt = r;
    }
  }
  cout << pt << endl;
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