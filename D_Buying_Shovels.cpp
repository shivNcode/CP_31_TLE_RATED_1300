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

int largestProperFactor(int n) {
    if (n <= 1) return 1;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return n / i;   // first divisor ⇒ smallest
        }
    }
    return 1; // n is prime
}
vector<int> getAllFactorsSorted(int n) {
    vector<int> factors;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i)
                factors.push_back(n / i);
        }
    }

    sort(factors.begin(), factors.end());
    return factors;
}


void solve() {
    int n , k;
    cin>>n>>k;
    if(k>=n){
        cout<<1<<endl;
    }
    else{
       vector<int> fac = getAllFactorsSorted(n);
       for(int i = fac.size()-1;i>=0;i--){
        if(fac[i]<=k){
            cout<<n/fac[i]<<endl;
            return;
        }
       }
    }
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) solve();
}


/*
Notes:

*/




