/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

const int N = 100100;
int freq[N];
int arr[N];
int distictCount = 0;

// helper methods
void insert(int x) {
  freq[x]++;
  if (freq[x] == 1) distictCount++;
}

void remove(int x) {
  freq[x]--;
  if (freq[x] == 0) distictCount--;
}

void jaiShreeRam() {
  int n, k;
  cin >> n >> k;
  distictCount = 0;
  for (int i = 0; i < n; i++) cin >> arr[i], freq[arr[i]] = 0;

  // 2 ptr construct
  int tail = 0, head = -1, ans = 0;

  while (tail < n) {
    while (head + 1 < n && ((distictCount < k && freq[arr[head + 1]] == 0) ||
                            (distictCount <= k && freq[arr[head + 1]] > 0))) {
      head++;
      insert(arr[head]);
    }
    // empty window condition
    if (head >= tail) {
      ans += head - tail + 1;
      remove(arr[tail]);
      tail++;
    } else {
      tail++;
      head = tail - 1;
    }
  }
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