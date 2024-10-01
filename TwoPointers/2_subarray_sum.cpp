/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

const int N = 100100;
int arr[N];
int currSum = 0;
int n, k;

void jaiShreeRam() {
  cin >> n >> k;
  currSum = 0;
  for (int i = 0; i < n; i++) cin >> arr[i];
  int ans = 0;
  int head = -1, tail = 0;

  while (tail < n) {
    while (head + 1 < n && (currSum + arr[head + 1] <= k)) {
      head++;
      currSum += arr[head];
    }
    if (head >= tail) {
      ans += head - tail + 1;
      currSum -= arr[tail];
      tail++;
    } else {
      tail++;
      head = tail - 1;
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