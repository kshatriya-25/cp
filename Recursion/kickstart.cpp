/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

int s;
int allowed[101][101];

inline bool check(int x, int y) {
  if ((x >= 1) && (y >= 1) && (x <= s) && (y <= 2 * x - 1) && allowed[x][y]) {
    return 1;
  }
  return 0;
}

// returns diff betwn score of player 1 and 2
int getbest(int a, int b, int x, int y) {
  // enumerating the steps
  vector<pair<int, int>> move1, move2;

  // player 1
  if (check(a, b - 1)) {
    move1.emplace_back(make_pair(a, b - 1));
  }
  if (check(a, b + 1)) {
    move1.emplace_back(make_pair(a, b + 1));
  }
  if (b % 2) {
    if (check(a + 1, b + 1))
      move1.emplace_back(make_pair(a + 1, b + 1));  // Check down-right
  } else {
    if (check(a - 1, b - 1))
      move1.emplace_back(make_pair(a - 1, b - 1));  // Check down-left
  }

  // PLAYER 2
  // if (check(x, y - 1)) {
  //   move2.emplace_back(make_pair(x, y - 1));  // Check left
  // }
  // if (check(x, y + 1)) {
  //   move2.emplace_back(make_pair(x, y + 1));  // Check right
  // }
  // if (y % 2) {
  //   if (check(x + 1, y + 1))
  //     move2.emplace_back(make_pair(x + 1, y + 1));  // Check down-right
  // } else {
  //   if (check(x - 1, y - 1))
  //     move2.emplace_back(make_pair(x - 1, y - 1));  // Check down-left
  // }

  // base case
  if (move1.empty() && move2.empty())
    return 0;
  else if (!move1.empty()) {
    int best = -1000;
    for (auto &v : move1) {
      // make the move
      allowed[v.first][v.second] = 0;
      // the next player makes his move
      best = max(best, 1 - getbest(x, y, v.first, v.second));
      // undo the move
      allowed[v.first][v.second] = 1;
      // return best for the current player
    }
    return best;
  } else {
    // the first palyer makes no score he gets 0 and calls the other guy
    return -getbest(x, y, a, b);
  }
}

void jaiShreeRam() {
  mset(allowed, 1);
  int a, b, x, y, c;
  cin >> s >> a >> b >> x >> y >> c;
  while (c--) {
    int k, l;
    cin >> k >> l;
    allowed[k][l] = 0;
  }
  allowed[a][b] = 0;
  allowed[x][y] = 0;
  cout << getbest(a, b, x, y) << endl;
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