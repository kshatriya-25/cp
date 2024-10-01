/* OM VIGHNHARTAYE NAMO NAMAH :*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int solve(vector<int>& A, int l, int r) {
  if (l >= r) return 0;
  if (r - l == 1) {
    if (A[r] < A[l]) {
      swap(A[r], A[l]);
      return 1;
    }
    return 0;
  }
  int mid = (r + l) / 2;
  int ans = solve(A, l, mid) + solve(A, mid + 1, r);
  int ptr = mid + 1;
  for (int i = l; i <= mid; i++) {
    while (ptr <= r && A[ptr] < A[i]) {
      ptr++;
    }
    ans += ptr - mid - 1;
  }
  vector<int> temp;
  for (int i = l; i <= r; i++) temp.push_back(A[i]);
  sort(temp.begin(), temp.end());
  for (int i = l; i <= r; i++) A[i] = temp[i - l];
  return ans;
}

void jaiShreeRam() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  cout << solve(A, 0, n - 1) << endl;
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