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
    vector<ll> a(n) , b(n) ,d(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
        d[i] = a[i] - b[i];
    }

    ll last = d[n-1];
    for(ll i=0;i<n;i++){
        last  = max(last , d[i]);
    }
    vector<ll> ans;
    for(ll i=0;i<n;i++){
        if(last==d[i]){
            ans.push_back(i+1);
        }
    }
    cout<<ans.size()<<endl;
    for(ll i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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


