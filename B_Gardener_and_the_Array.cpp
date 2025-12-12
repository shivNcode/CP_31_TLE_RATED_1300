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
    int n;
    cin>>n;
    vector<int> bits(33,0);
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        while(b--){
            int bb;
            cin>>bb;
            bits[bb]++;
        }
    }
    int cnt = 0;
    for(int i=1;i<=32;i++){
        if(bits[i]>=2){
            cnt++;
        }
    }
    if(cnt==n) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
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


