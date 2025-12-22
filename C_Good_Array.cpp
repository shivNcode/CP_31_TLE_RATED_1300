#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
using namespace std;

#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    // write solution here
    int n;
    cin>>n;
    vector<int> arr(n);
    unordered_map<int, int> check;
    vector<int> p(n) , s(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        check[arr[i]]++;
        if(i==0) p[i] = arr[i];
        else p[i]+=(arr[i] + p[i-1]);
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1) s[i]=arr[i];
        else s[i]+=(arr[i]+s[i+1]);
    }
    vector<int> ans;
    for(int i=0;i<n;i++){
        int sum = p[i] + s[i] - (2*arr[i]);
        if(sum%2==0 && check[sum/2] && (arr[i]!=sum/2 ||(arr[i]==sum/2 &&  check[arr[i]]>1))){
            ans.push_back(i+1);
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}


/*
Notes:

*/

