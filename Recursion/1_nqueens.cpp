/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

char board[8][8];
vector<int> placed;
int ans = 0;

void rec(int row) {
  if (row == 8) {
    ans++;
    return;
  }

  for (int col = 0; col < 8; col++) {
    bool ok = 1;
    for (int prevrow = 0; prevrow < row; prevrow++) {
      int prevcol = placed[prevrow];
      if (board[row][col] == '*' || col == prevcol ||
          abs(col - prevcol) == abs(row - prevrow)) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      placed.emplace_back(col);
      rec(row + 1);
      placed.pop_back();
    }
  }
}

void jaiShreeRam() {
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++) cin >> board[i][j];
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