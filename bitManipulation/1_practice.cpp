/* OM VIGHGNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

int prefix[1001001][31];

void jaiShreeRam() {
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 31; j++) {
      prefix[i][j] = 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    int a;
    cin >> a;
    int cnt = 0;
    while (a) {
      prefix[i][cnt] = a % 2;  // check its lsb
      a /= 2;                  // left shift
      cnt++;                   // next bit position
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 31; j++) {
      prefix[i][j] += prefix[i - 1][j];
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    double total = (r - l + 1.0) / 2;  // using double to avaoid truncation
                                       // error
    long long x1 = 0, x2 = 0, x3 = 0;
    for (int j = 0; j < 31; j++) {
      int p = prefix[r][j] - prefix[l - 1][j];
      if (p < total) {  // xor opration
        x1 |= 1LL << j;
      }
      if (p != (r - l + 1)) {
        x2 |= 1LL << j;
      }
      if (p) x3 |= 1LL << j;
    }
    long long sum = x1 + x2 + x3;
    cout << sum << "\n";
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