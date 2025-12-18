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
    vector<vector<ll>> c(n);
    vector<pair<ll,ll>> temp;
    for(ll i=0;i<n;i++){
        ll k;
        cin>>k;
        ll mini = -1e7;
        for(ll j=0;j<k;j++){
            ll val;
            cin>>val;
            c[i].push_back(val);
            mini = max((val + 1 - j ), mini);

        }
        //cout<<mini<<" "<<mini+k<<endl;
        temp.push_back({mini , mini+k});
    }

    sort(temp.begin() , temp.end());
    // for(int i=0;i<temp.size();i++){
    //     cout<<temp[i].first<<" "<<temp[i].second<<endl;
    // }
    for(ll i=n-2;i>=0;i--){
        if(temp[i].second<temp[i+1].first){
            int diff = abs(temp[i+1].first - temp[i].second);
            temp[i].first+=diff;
            temp[i].second+=diff;
        }
    }
    // cout<<endl;
    // for(int i=0;i>n;i++){
    //     cout<<temp[i].first<<" "<<temp[i].second<<endl;
    // }
    sort(temp.begin() , temp.end());
    cout<<temp[0].first<<endl;

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


