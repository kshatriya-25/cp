/* OM VIGHNHARTAYE NAMO NAMAH:*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1000000007;
const int N = 100001;
const int bits = 31;
int poweroftwo[N];

int addmod(int a, int b) {
  a += b;
  if (a > mod) a -= mod;
  return a;
}

int nc2(int x) { return ((x * (x - 1)) / 2) % mod; }

void jaiShreeRam() {
  poweroftwo[0] = 1;
  for (int i = 1; i < N; i++) {
    poweroftwo[i] = addmod(poweroftwo[i - 1], poweroftwo[i - 1]);
  }
  int n;
  cin >> n;
  int a[n];
  for (int &x : a) cin >> x;
  int pairXOR = 0, sbusetXOR = 0, pairAND = 0, sunsetAND = 0;
  for (int i = 0; i < bits; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] & (1 << i)) cnt++;
    }
    pairXOR = addmod(pairXOR, (cnt * (n - cnt)) % mod * (1LL << i) % mod);
    if (cnt) {
      sbusetXOR = addmod(sbusetXOR, poweroftwo[n - 1] % mod * (1LL << i) % mod);
    }
    pairAND = addmod(pairAND, nc2(cnt) * (1LL << i) % mod);
    sunsetAND = addmod(sunsetAND, (poweroftwo[cnt] - 1) * (1LL << i) % mod);
  }
  cout << pairXOR << " " << sbusetXOR << " " << pairAND << " " << sunsetAND
       << "\n";
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