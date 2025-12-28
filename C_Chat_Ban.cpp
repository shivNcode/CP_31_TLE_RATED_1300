// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <deque>
// #include <random>
// #include <chrono>
// #include <unordered_map>
// #include <map>
// #include <stack>
// using namespace std;

// #define int long long
// #define INF (int)1e18
// #define ed endl
// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

// void Solve() {
//     int  k ,x;
//     cin>>k>>x;
//     int val = (k*(k+1))/2;
//     if(x>val){
//         vector<int> check(k-1 , 0);
//         int v = k-1;
//         for(int i=0;i<k-1;i++){
//             if(i == 0) check[0] = v;
//             else{
//                 check[i] = check[i-1] + v;
//             }
//             //cout<<check[i]<<" ";
//             v--;
//         }
//         int l = 0 , r = k-2;
//         int temp = x - (val);
//         int ans = 0;
//         // cout<<ed;
//         // //cout<<temp<<" ";
//         // cout<<ed;
//         while(l<=r){
//             int mid = (r+l)/2;
//             //cout<<check[mid]<<" ";
//             if(check[mid]==temp){
//                 ans = mid;
//                 break;
//             }
//             if(check[mid]>=temp){
//                 ans = mid;
//                 r = mid - 1;
//             }
//             else{
//                 ans = mid;
//                 l = mid + 1;
//             }
//         }
//         cout<<k+ans+1<<ed;
//     }
//     else{
//         vector<int> check(k , 0);
//         int v = 1;
//         for(int i=0;i<k;i++){
//             if(i==0) check[i] = v;
//             else check[i] = check[i-1] + v;
//             v++;
//             //cout<<check[i]<<" ";
//         }
//         int ans = 0;
//         int l = 0 , r = k-1;
//         while(l<=r){
//             int mid = (r+l)/2;
//             //cout<<check[mid]<<" ";
//             if(check[mid]==x){
//                 ans = mid;
//                 break;
//             }
//             if(check[mid]>=x){
//                 ans = mid;
//                 r = mid - 1;
//             }
//             else{
//                 ans = mid;
//                 l = mid + 1;
//             }
//         }
//         cout<<ans+1<<ed;
//     }
// }

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t = 1;
//     cin >> t;
//     while (t--) {
//         Solve();
//     }

//     return 0;
// }


// /*
// Notes:

// */



#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
#include <stack>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <string>
#include <set>
#include <utility>
#include <cstdint>
using namespace std;
#define int long long

bool ok_inc(int mid, int x) {
    return mid * (mid + 1) / 2 >= x;
}

bool ok_dec(int mid, int k, int rem) {
    // sum of first mid terms of decreasing part
    // (k-1) + (k-2) + ... (k-mid)
    return mid * (2*k - mid - 1) / 2 >= rem;
}

void solve() {
    int k, x;
    cin >> k >> x;

    int incSum = k * (k + 1) / 2;

    // Case 1: Increasing part
    if (x <= incSum) {
        int l = 1, r = k, ans = k;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (ok_inc(mid, x)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }
    // Case 2: Decreasing part
    else {
        int rem = x - incSum;
        int l = 1, r = k-1, ans = k-1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (ok_dec(mid, k, rem)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << k + ans << '\n';
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) solve();
}
