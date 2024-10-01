/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

// #define int long long

/* q :take all summation of all pair xor for the array*/

void jaiShreeRam() {
  int n;
  cin >> n;
  int cnt[31];  // we can just keep trak of the bits itself instead of numbers
                // directly
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < 31; j++) {
      if ((x >> j) & 1)
        cnt[j]++;  // we are cnting in the jth bit how-many 1s are present
    }
  }
  long long ans = 0;
  for (int j = 0; j < 31; j++) {
    long long temp = 1ll * cnt[j] * (n - cnt[j]) * (1 << j);
    ans += temp;
  }
  cout << ans << '\n';
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
