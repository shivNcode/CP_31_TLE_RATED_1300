// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <deque>
// using namespace std;

// #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()
// #define rep(i, a, b) for (int i = a; i < b; i++)
// #define ll long long


// void solve() {

// }

// int main() {
//     fastio;

//     int t;
//     cin >> t;
//     while (t--) {
//         int n , x , y;
//         cin>>n>>x>>y;
//         vector<int> arr(n);
//         deque<int> dq;
//         int one = 0 , two = 0;
//         vector<int> z , h;
//         for(int i=0;i<n;i++){
//             cin>>arr[i];
//             // cout<<arr[i]%x<<" ";
//             if(arr[i]%x==0){
//                 z.push_back(arr[i]);
//                 one++;
//                 continue;
//             }
//             if(x%2==0 && arr[i]%x==x/2){
//                 h.push_back(arr[i]);
//                 two++;
//                 continue;
//             }
//             dq.push_back(arr[i]);
//         }


//         int cnt = 0;
//         while(!dq.empty()){
//             int v = dq.front();
//             dq.pop_front();
//             int j = 0;
//             while(j<dq.size()){
//                 int curr = dq.front();
//                 dq.pop_front();
//                 int mv = v%x;
//                 int mcurr = curr%x;
//                 if((mv+mcurr)%x==0 && (abs(v-curr)%y==0)){
//                     cout<<v<<" "<<curr<<endl;
//                     cnt++;

//                     continue;
//                 }
//                 dq.push_back(curr);
//                 j++;
//             }
//         }
//         cout<<one<<" "<<two<<endl;
//         int ans = cnt;
//         ans+=((one*(one-1))/2);
//         if(x%y==0) ans+=((two*(two-1))/2);
//         cout<<ans<<endl;
//     }

//     return 0;
// }

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
    ll n , x , y;
    cin>>n>>x>>y;
    vector<ll> arr(n);
    map<ll , vector<ll>> mpp;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        mpp[arr[i]%y].push_back(arr[i]);
    }
    ll ans = 0;
    for(auto it:mpp){
        vector<ll> v = it.second;
        map<ll , long long> mp;
        for(ll i=0;i<v.size();i++){
            mp[v[i]%x]++;
        }
        for(auto itr:mp){
            //cout<<itr.first<<endl;
            if(itr.first==0 || (itr.first==x/2 && x%2==0)){
                ll cnt = itr.second;
                ans+=((cnt)*(cnt-1))/2;
                mp[itr.first] = 0;
            }
            else{
                ll c1 = itr.second;
                ll c2 = mp[x-itr.first];
                ans+=(c1*c2);
                mp[itr.first] = 0;
                mp[x-itr.first] = 0;
            }

        }
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


