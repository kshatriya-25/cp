/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

const int mod = 1e9 + 7;
int fact[100100];

int pw(int a, int b, int p) {
  if (b == 0) return 1;
  int t = pw(a, b / 2, p);
  t = (t * t) % p;
  if (b % 2) return (a * t) % p;
  return t;
}

void jaiShreeRam() {
  fact[0] = 1;
  for (int i = 1; i <= 100000; i++) fact[i] = (fact[i - 1] * i) % mod;
  int n, c1, c2, c3;
  cin >> n >> c1 >> c2 >> c3;
  int ans = fact[n];
  ans = (ans * pw(fact[c1], mod - 2, mod)) % mod;
  ans = (ans * pw(fact[c2], mod - 2, mod)) % mod;
  ans = (ans * pw(fact[c3], mod - 2, mod)) % mod;
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