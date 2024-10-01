/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(o) (o).begin(), (o).end()
#define mset(m, v) memset(m, v, sizeof(m))
#define endl "\n"

const int N = 1001001;
int freq[N];
int arr[N];
int n, k;
int cnt_distinct = 0;

void insert(int x) {
  freq[arr[x]]++;
  if (freq[arr[x]] == 1) cnt_distinct++;
}

void remove(int x) {
  freq[arr[x]]--;
  if (freq[arr[x]] == 0) cnt_distinct--;
}

int atmostx(int x) {
  cnt_distinct = 0;
  int head = 0, tail = 0, ans = 0;
  while (head < n) {
    insert(head);
    while (tail <= head and cnt_distinct > x) {
      remove(tail);
      tail++;
    }
    ans += head - tail + 1;
    head++;
  }
  return ans;
}

void jaiShreeRam() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i], freq[arr[i]] = 0;
  int ans = atmostx(k);
  for (int i = 0; i < n; i++) freq[arr[i]] = 0;
  ans -= atmostx(k - 1);
  for (int i = 0; i < n; i++) freq[arr[i]] = 0;
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