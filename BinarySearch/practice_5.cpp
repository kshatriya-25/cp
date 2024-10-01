/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

const int N = 1001001;
int arr[N], brr[N];
int n, m, k;

bool check(int mid) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += upper_bound(brr, brr + m, mid - arr[i]) - brr;
  }
  return ans >= k;
}

void jaiShreeRam() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < m; i++) cin >> brr[i];
  if (n > m) {
    swap(arr, brr);
    swap(n, m);
  }
  sort(arr, arr + n);
  sort(brr, brr + n);
  int lo = arr[0] + brr[0];
  int hi = arr[n - 1] + brr[m - 1];
  int ans = lo;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (check(mid)) {
      ans = mid;
      hi = mid - 1;
    } else
      lo = mid + 1;
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
  return 0;
}
