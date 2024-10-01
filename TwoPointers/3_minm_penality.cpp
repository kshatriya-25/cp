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
int n, d;
int cnt_dintnt = 0;

void insert(int x) {
  freq[arr[x]]++;
  if (freq[arr[x]] == 1) cnt_dintnt++;
}

void remove(int x) {
  freq[arr[x]]--;
  if (freq[arr[x]] == 0) cnt_dintnt--;
}

void jaiShreeRam() {
  cin >> n >> d;
  cnt_dintnt = 0;
  for (int i = 1; i <= n; i++) cin >> arr[i], freq[arr[i]] = 0;
  int tail = 1;
  int head = d;
  for (int i = tail; i <= head; i++) insert(i);
  int ans = cnt_dintnt;
  while (head < n) {
    insert(head + 1);
    remove(tail);
    ans = min(ans, cnt_dintnt);
    head++;
    tail++;
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