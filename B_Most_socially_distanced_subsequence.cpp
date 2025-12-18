#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define int long long

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, bool> check;
    for (int i = 0; i < n; i++) {
        check[arr[i]] = true;
    }

    int r = 0;
    for (int i = 1; i < n - 1; i++) {
        if ((arr[i] <= arr[i + 1] && arr[i] >= arr[i - 1]) ||
            (arr[i - 1] >= arr[i] && arr[i] >= arr[i + 1])) {
            if (check[arr[i]]) {
                check[arr[i]] = false;
                r++;
            }
        }
    }

    cout << n - r << endl;
    for (int i = 0; i < n; i++) {
        if (check[arr[i]]) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int32_t main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*
Notes:

*/

