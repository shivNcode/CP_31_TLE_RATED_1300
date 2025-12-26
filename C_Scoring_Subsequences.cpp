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
//     int n;
//     cin>>n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     if(arr[0]==1){
//         cout<<1<<" ";
//         int l = 1 , r = 1;
//         while(r<n){
//             //cout<<arr[r]<<endl;
//             if((r-l+1)<=arr[r]){
//                 cout<<r-l+1<<" ";
//                 r++;
//             }
//             else{
//                 cout<<r-l<<" ";
//                 r++;
//                 l++;
//             }
//         }
//     }
//     else{
//         int l = 0 , r = 0;
//         while(r<n){
//             //cout<<arr[r]<<endl;
//             if((r-l+1)<=arr[r]){
//                 cout<<r-l+1<<" ";
//                 r++;
//             }
//             else{
//                 cout<<r-l<<" ";
//                 r++;
//                 l++;
//             }
//         }
//     }
//     cout<<endl;
//     return;
// }

// int main() {
//     fastio;

//     int t;
//     cin >> t;
//     while (t--) {
//         solve();
//     }

//     return 0;
// }


#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    // write solution here
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int nu = arr[0] , de = 1;
    int l = 0 , r = 0;
    vector<int> ans;
    ans.push_back(1);
    cout<<1<<" ";
    while(r+1<n){
        r++;
        //nu*=arr[r];
        //cout<<l<<" "<<r<<endl;
        if(arr[l]<(r-l+1)){
           // cout<<"..";
            l++;
        }
        ans.push_back(r-l+1);
       cout<<r-l+1<<" ";
    }
    cout<<endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}


/*
Notes:

*/

