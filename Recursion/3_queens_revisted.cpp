/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

vector<int> placed;
int ans = 0;
int n;

bool safe(int pr, int pc, int r, int c) {
  if (pr == r || pc == c) return 0;
  if (abs(pr - r) == abs(pc - c)) return 0;
  if ((abs(r - pr) == 2 && abs(c - pc) == 1) ||
      ((abs(r - pr) == 1) && abs(c - pc) == 2))
    return 0;
  return 1;
}

void rec(int row) {
  if (row == n) {
    ans++;
    return;
  }

  for (int col = 0; col < n; col++) {
    bool ok = 1;
    for (int prevrow = 0; prevrow < row; prevrow++) {
      int prevcol = placed[prevrow];
      if (!safe(prevrow, prevcol, row, col)) ok = 0;
    }
    if (ok) {
      placed.emplace_back(col);
      rec(row + 1);
      placed.pop_back();
    }
  }
}

void jaiShreeRam() {
  cin >> n;
  rec(0);
  cout << ans << endl;
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