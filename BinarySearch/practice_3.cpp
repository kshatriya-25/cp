/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

const int N = 1001001;
int arr[N];
int n, k;
bool check(int mid) {
  int pts = 0;
  for (int i = 1; i < n; i++) {
    int diff = arr[i] - arr[i - 1];
    pts += ((diff + mid - 1) / mid) - 1;  // taken ciel
  }
  return pts <= k;
}

void jaiShreeRam() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int lo = 1, hi = 1e18;
  int ans = 1e19;

  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (check(mid)) {
      ans = mid;
      hi = mid - 1;
    } else {
      lo = mid + 1;
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