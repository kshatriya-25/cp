/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"
int n;
int median(vector<int> &a) {
  sort(all(a));
  return a[(n - 1) / 2];
}

void jaiShreeRam() {
  cin >> n;
  vector<int> X, Y;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    X.push_back(x), Y.push_back(y);
  }
  int a = median(X);
  int b = median(Y);
  int cost = 0;
  for (int i = 0; i < n; i++) {
    cost += abs(a - X[i]);
    cost += abs(b - Y[i]);
  }
  cout << cost << endl;
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