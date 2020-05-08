#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> dp(n + 1, INF);
    dp[0] = -INF;
    for (int i = 0; i < n; ++i) {// в одну строчку
        dp[lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin()] = a[i];
    }
    for (int i = n; i > -1; --i) {
        if (dp[i] != INF) {
            cout << i << endl;
            break;
        }
    }
}
