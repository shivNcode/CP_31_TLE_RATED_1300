#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <map>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ll long long


void solve() {
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=2;i<=n;i++){
        cin>>arr[i];
    }
    string col = " " , s ;
    cin>>s;
    col+=s;
    vector<pair<int, int>> mpp(n+1,{0,0});
    for(int i=1;i<=n;i++){
        //cout<<col[i]<<endl;
        if(col[i]=='B'){
            mpp[i].first++;
        }
        else{
            mpp[i].second++;
        }
    }

    for(int i = n;i>=1;i--){
        mpp[arr[i]].first+=mpp[i].first;
        mpp[arr[i]].second+=mpp[i].second;
    }
    int ans =0;
    for(int i=1;i<=n;i++){
        //cout<<i<<" "<<mpp[i].first<<" "<<mpp[i].second<<endl;
        if(mpp[i].first==mpp[i].second) ans++;
    }
    cout<<ans<<endl;

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


