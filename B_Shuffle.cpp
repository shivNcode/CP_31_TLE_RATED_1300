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
    ll n , x , m;
    cin>>n>>x>>m;
    pair<ll,ll> ans = {x , x};
    ll l , r;

    for(ll i=0;i<m;i++){
        cin>>l>>r;
        if(ans.first>r || ans.second<l){
            continue;
        }
        else{
            ans.first = min(ans.first , l);
            ans.second = max(ans.second , r);
        }
    }
    cout<<ans.second - ans.first + 1<<endl;
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

/*
Notes:

*/

