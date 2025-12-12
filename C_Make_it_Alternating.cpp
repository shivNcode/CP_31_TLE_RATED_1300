#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ll long long

ll modd = 998244353;
ll fac(ll n){
    ll ans = 1;
    for(ll i=1;i<=n;i++){
         ans = (ans * i) % modd;
    }
    return ans;
}

int main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        // int n;
        // cin>>n;
        string str;
        cin>>str;
        stack<char> st;
        st.push(str[0]);
        ll cnt = 0;
        vector<ll> temp;
        for(ll i=1;i<str.size();i++){
            if(str[i]!=st.top()){
                st.push(str[i]);
                if(cnt>0) temp.push_back(cnt);
                cnt = 0;
            }
            else{
                cnt++;
            }
        }
        if(cnt>0) temp.push_back(cnt);
        ll ans = 1;
        ll val = 0;
        for(ll i=0;i<temp.size();i++){
            val+=temp[i];
            //cout<<temp[i]<<" ";
            // ans*=cal(temp[i]+1);
            ans*=(temp[i]+1);
            ans = ans%modd;
        }
        ans*=(fac(val));
        ans = ans%modd;
        if(temp.size()==0){
            cout<<0<<" "<<1<<endl;
            continue;
        }
        cout<<val<<" "<<ans<<endl;
        // cout<<endl;
    }

    return 0;
}


