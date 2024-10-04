/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

int k;
int fib[50];
void fibo() {
  fib[1] = fib[2] = 1;
  for (int i = 3; i < 50; i++) fib[i] = fib[i - 1] + fib[i - 2];
}

void jaiShreeRam() {
  cin >> k;
  int cnt = 0;
  while (k > 0) {
    int cur = upper_bound(fib, fib + 50, k) - fib;
    k -= cur;
    cnt++;
  }
  cout << cnt << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  fibo();
  while (t-- > 0) {
    jaiShreeRam();
  }
}