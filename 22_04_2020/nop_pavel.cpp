#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;

int get(int i, int j) {
    if (i < 0 || j < 0) {
        return 0;
    }
    return dp[i][j];
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    dp.resize(n, vector<int>(m));
    vector<vector<int>> p(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i] == b[j]) {
                dp[i][j] = get(i - 1, j - 1) + 1;
                p[i][j] = 1;
            } else {
                if (get(i - 1, j) > get(i, j - 1)) {
                    dp[i][j] = get(i - 1, j);
                    p[i][j] = 2;
                } else {
                    dp[i][j] = get(i, j - 1);
                    p[i][j] = 3;
                }
            }
        }
    }
    int curx = n - 1, cury = m - 1;
    vector<int> nop;
    while (curx >= 0 && cury >= 0) {
        if (p[curx][cury] == 1) {
            nop.push_back(a[curx]); //b[cury];
            curx--;
            cury--;
        } else if (p[curx][cury] == 2) {
            curx--;
        } else {
            cury--;
        }
    }
    reverse(nop.begin(), nop.end());
    for (int i : nop) {
        cout << i << ' ';
    }
    system("pause");
}


/*
5
2 3 1 4 7
5
3 4 1 5 7
*/
