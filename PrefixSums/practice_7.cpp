/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define mod 1000000007

const int N = 1000001;
int powerK[N];
int arr[N];
int prefixSum[N];

int power(int x, int y) {
  int res = 1;
  while (y) {
    if (y & 1) res = (res * x) % mod;
    y = y / 2, x = (x * x) % mod;
  }
  return res % mod;
}

void jaiShreeRam() {
  int n, q, k;
  cin >> n >> q >> k;
  powerK[0] = 1;
  for (int i = 1; i <= n; i++) {
    powerK[i] = (k * powerK[i - 1]) % mod;
  }
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] = (arr[i] * powerK[i]) % mod;
    if (arr[i] < 0) arr[i] += mod;
  }
  prefixSum[0] = 0;
  for (int i = 1; i <= n; i++) {
    prefixSum[i] = (arr[i] + prefixSum[i - 1]) % mod;
  }

  while (q-- > 0) {
    int l, r;
    cin >> l >> r;
    int ans = prefixSum[r] - prefixSum[l - 1];
    if (ans < 0) ans += mod;
    ans = ans * power(powerK[l], mod - 2) % mod;
    cout << ans << endl;
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  //  cin >> t;
  while (t-- > 0) {
    jaiShreeRam();
  }
}