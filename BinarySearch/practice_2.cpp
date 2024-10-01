/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

const int N = 100100;
int arr[N];

bool check(int mid) { return arr[mid] > arr[mid - 1]; }

void jaiShreeRam() {
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int lo = 1, hi = n;
  int peak = 0;
  arr[0] = -1e18;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (check(mid)) {
      peak = mid;
      lo = mid + 1;
    } else
      hi = mid - 1;
  }

  while (q-- > 0) {
    int k;
    cin >> k;
    vector<int> ans;
    int lo = 1;
    int hi = peak - 1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (arr[mid] == k) {
        ans.emplace_back(mid);
        break;
      } else if (arr[mid] < k)
        lo = mid + 1;  // done opp
      else
        hi = mid - 1;
    }
    lo = peak;
    hi = n;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (arr[mid] == k) {
        ans.emplace_back(mid);
        break;
      } else if (arr[mid] < k) {
        hi = mid - 1;
      } else
        lo = mid + 1;
    }
    for (auto v : ans) cout << v << " ";
    cout << endl;
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