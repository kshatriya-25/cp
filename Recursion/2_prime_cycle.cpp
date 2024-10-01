/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

vector<int> prime = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37, 41,
                     43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

const int N = 100;
bool is_Prime[N];
bool marked[N];
int ans = 0;

void recurse(int m, int n, int par, int prev) {
  // base
  if (!m) {
    if (is_Prime[prev + 1]) ans++;  // maintaing the cyclic nature
    return;
  }

  for (int i = 1 + par; i <= n; i++) {
    if (!marked[i] && is_Prime[i + prev]) {
      marked[i] = true;
      recurse(m - 1, n, 1 - par, i);
      marked[i] = false;
    }
  }
  return;
}

void jaiShreeRam() {
  mset(is_Prime, false);
  for (int v : prime) is_Prime[v] = true;
  mset(marked, false);
  marked[1] = true;
  int n;
  cin >> n;
  recurse(n - 1, n, 1, 1);
  cout << ans;
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