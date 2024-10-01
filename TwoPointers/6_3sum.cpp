/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

const int N = 1101;
int n, target;
int arr[N];
void jaiShreeRam() {
  cin >> n >> target;
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  int best = arr[0] + arr[1] + arr[2];
  for (int j = 1; j < n - 1; j++) {
    int lo = 0, hi = n - 1;
    while (1) {
      if (abs(arr[lo] + arr[hi] + arr[j] - target) < abs(target - best)) {
        best = arr[lo] + arr[hi] + arr[j];
      }
      if (arr[lo] + arr[hi] + arr[j] > target) {
        hi--;
      } else
        lo++;
      if (j == lo || j == hi) break;
    }
  }
  cout << abs(best - target) << endl;
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