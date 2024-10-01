/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"
#define double long double
const int N = 10010;
int n, k;
int a[N];
int b[N];

bool check(double mid) {
  priority_queue<double, vector<double>, greater<double>> pq;  // min heap
  for (int i = 0; i < n; i++) {
    pq.push(a[i] - mid * b[i]);
    if (pq.size() > k) pq.pop();
  }
  double ans = 0.0;
  while (pq.size()) {
    ans += pq.top();
    pq.pop();
  }
  return ans >= 0;
}

void jaiShreeRam() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  double lo = 0.0, hi = 1e8, ans = 0.0;
  while (hi - lo >= 1e-9) {
    double mid = (hi + lo) / 2.0;
    if (check(mid)) {
      ans = mid;
      lo = mid;
    } else
      hi = mid;
  }
  cout << fixed << setprecision(6) << ans << endl;
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