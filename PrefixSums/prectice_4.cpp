/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void jaiShreeRam() {
  int n, m, q;
  cin >> n >> m >> q;
  int arr[n + 1][m + 1];
  memset(arr, 0, sizeof(arr));
  while (q-- > 0) {
    int x1, y1, x2, y2, c;
    cin >> x1 >> y1 >> x2 >> y2 >> c;
    arr[x1][y1] += c;
    if (x2 < n and y2 < m) arr[x2 + 1][y2 + 1] += c;
    if (y2 < m) arr[x1][y2 + 1] -= c;
    if (x2 < n) arr[x2 + 1][y1] -= c;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {  // calculating rectangular prefix sum
      arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
    }
  }
  int ans = -1e9;
  int c = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (arr[i][j] > ans) {
        ans = arr[i][j], c = 1;
      } else if (arr[i][j] == ans)
        c++;
    }
  }
  cout << ans << " " << c << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  // cin >> t;
  while (t-- > 0) {
    jaiShreeRam();
  }
}