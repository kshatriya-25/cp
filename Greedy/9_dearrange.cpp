/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

int n;
unordered_map<int, int> a;
void jaiShreeRam() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    a[j]++;
  }
  int m = -1;
  for (auto x : a) {
    m = max(m, x.second);
  }
  if (m >= (n + 1) / 2)
    cout << (n - m) * 2 << endl;
  else
    cout << n << endl;
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