#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ll long long


void solve() {
    ll n;
    cin>>n;
    for(ll k = 2;k<=1e3;k++){
        ll val = k*k;
        ll sum = k + (k*k);
        for(ll i=1;i<=32;i++){
            if(sum==n-1){
                cout<<"YES"<<endl;
                return;
            }
            val*=k;
            sum+=val;
        }
    }
    cout<<"NO"<<endl;
    return;
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
         solve();
    }

    return 0;
}


