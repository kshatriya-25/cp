/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"
int n, s;

bool check(int mid) {
  int x = 0;
  int temp = mid;
  while (temp > 0) {
    x += (temp % 10);
    temp /= 10;
  }
  return (mid - x) >= s;
}

void jaiShreeRam() {
  cin >> n >> s;
  int lo = 1, hi = n;
  int ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (check(mid)) {
      ans = mid;
      hi = mid - 1;
    } else
      lo = mid + 1;
  }
  if (!ans)
    cout << 0 << endl;
  else
    cout << (n - ans + 1) << endl;
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