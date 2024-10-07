#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the minimum number of changes needed for a substring of
// length K to match a pattern starting with the ith letter of "RGB"
int minChanges(const string &S, int N, int K, const string &pattern) {
  vector<int> changes(N, 0);

  // Precompute the mismatches for each position in S relative to the periodic
  // pattern
  for (int i = 0; i < N; ++i) {
    if (S[i] != pattern[i % 3]) {
      changes[i] = 1;
    }
  }

  // Sliding window to compute the number of mismatches for each substring of
  // length K
  int current_mismatch = 0;
  for (int i = 0; i < K; ++i) {
    current_mismatch += changes[i];
  }

  int min_mismatch = current_mismatch;

  for (int i = K; i < N; ++i) {
    current_mismatch += changes[i] - changes[i - K];
    min_mismatch = min(min_mismatch, current_mismatch);
  }

  return min_mismatch;
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    int N, K;
    string S;
    cin >> N >> K >> S;

    // The three possible RGB patterns to match
    string pattern1 = "RGB";
    string pattern2 = "GBR";
    string pattern3 = "BRG";

    // Calculate the minimum changes for each pattern and take the minimum
    int result =
        min({minChanges(S, N, K, pattern1), minChanges(S, N, K, pattern2),
             minChanges(S, N, K, pattern3)});

    cout << result << endl;
  }

  return 0;
}
