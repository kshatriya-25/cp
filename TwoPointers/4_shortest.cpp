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
int n;
int cnt_dintnt;

void insert(int x) {
  freq[arr[x]]++;
  if (freq[arr[x]] == 1) cnt_dintnt++;
}

void remove(int x) {
  freq[arr[x]]--;
  if (freq[arr[x]] == 0) cnt_dintnt--;
}

void jaiShreeRam() {
  cin >> n;
  cnt_dintnt = 0;
  unordered_set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    freq[arr[i]] = 0;
    s.insert(arr[i]);
  }

  int distinct = s.size();
  int tail = 0, head = 0, ans = n;

  // Use a sliding window approach
  for (head = 0; head < n; head++) {
    insert(head);

    while (cnt_dintnt == distinct) {
      ans = min(ans, head - tail + 1);  // Update the minimum sub-array length
      remove(tail);
      tail++;
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
