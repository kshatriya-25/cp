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
  vector<int> c(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    sum += c[i];
  }
  sort(all(c));
  sum -= c[n - 1];
  if (c[n - 1] >= sum)
    cout << c[n - 1] - sum;
  else {
    sum -= c[n - 1];
    cout << sum % 2 << endl;
  }
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