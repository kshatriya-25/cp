/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int mod = 1e9 + 7;

inline void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += mod;
}

inline int mul(int a, int b) { return (int)((long long)a * b % mod); }

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= mod;
  if (a < 0) a += mod;
  int b = mod, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a;
    swap(a, b);
    u -= t * v;
    swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += mod;
  return u;
}

void jaiShreeRam() {
  int n, q, k;
  cin >> n >> q >> k;
  int arr[n + 2];
  memset(arr, 0, sizeof(arr));
  while (q--) {
    int a, l, r;
    cin >> a >> l >> r;
    add(arr[l], mul(a, inv(power(k, l))));
    sub(arr[r + 1], mul(a, inv(power(k, l))));
  }
  for (int i = 1; i <= n; i++) {
    add(arr[i], arr[i - 1]);
    cout << mul(arr[i], power(k, i)) << " ";
  }
  cout << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t = 1;
  //   cin >> t;
  while (t-- > 0) {
    jaiShreeRam();
  }
}