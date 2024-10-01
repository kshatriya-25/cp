/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int inf = 1e9;
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

void jaiShreeRam() {
  int n, q;
  cin >> n >> q;
  int A[n + 2];
  int D[n + 2];
  memset(A, 0, sizeof(A));
  memset(D, 0, sizeof(D));

  while (q--) {
    int a, d, l, r;
    cin >> a >> d >> l >> r;
    add(A[l], a);
    sub(A[r + 1], a);
    add(D[l], d);
    sub(D[r + 1], d);
    sub(A[l], mul(l, d));
    add(A[r + 1], mul(l, d));
  }
  for (int i = 1; i <= n; i++) {
    add(A[i], A[i - 1]);
    add(D[i], D[i - 1]);
    // add(A[i], mul(i, D[i]));
    int ans = A[i];
    add(ans, mul(D[i], i));
    cout << ans << " ";
  }
  cout << endl;
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