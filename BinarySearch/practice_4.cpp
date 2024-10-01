/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

const int N = 100100;
int arr[N];
unordered_map<int, int> balls;
int n, k;

bool check(int mid) {
  int ans = 0;
  for (auto v : balls) {
    ans += min(v.second, mid);
  }
  return ans >= k * mid;
}

void jaiShreeRam() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    balls[arr[i]]++;
  }
  int lo = 0, hi = n;
  int ans = lo;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (check(mid)) {
      ans = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }
  cout << ans << endl;
  balls.clear();
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