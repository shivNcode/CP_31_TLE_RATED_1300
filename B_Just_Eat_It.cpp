#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
using namespace std;

#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    // write solution here
    int n;
    cin>>n;
    vector<int> arr(n);
    int tsum = 0;
    vector<int> prr(n);
    int neg  = 0;
    int z = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        tsum+=arr[i];
        if(i==0) prr[i] = arr[i];
        else prr[i]+=(prr[i-1] + arr[i]);
        if(arr[i]<0) neg++;
        if(arr[i]==0) z++;
    }
    if(z==n){ cout<<"NO"<<endl;return;}
    //vector<int> srr(n);
    if(neg==0){
        cout<<"YES"<<endl;
        return;
    }
    else if(neg==n){
        cout<<"NO"<<endl;
        return;
    }
    // for(int i=n-1;i>=0;i--){
    //     if(i==n-1) srr[i] = arr[i];
    //     else srr[i] = arr[i] + prr[i+1];
    // }
    int l = 0 , r = 0;
    int sum = prr[r] - prr[l] + arr[l];
    int ans = sum;
    //cout<<sum<<" ";
    for(int i=0;i<n-1;i++){
        if(r<n-2 && sum<0){
            r++;
            l = r;
        }
        else if(r<n-2) r++;
        sum = prr[r] - prr[l] + arr[l];
        //cout<<sum<<" ";
        ans = max(sum , ans);
    }
    l = 1 , r = 1;
    prr[0] = 0;
    sum = arr[l];
    //cout<<sum<<" ";
    for(int i=0;i<n;i++){
        if(r<n-1 && sum<0){
            r++;
            l = r;
        }
        else if(r<n-1) r++;
        sum = prr[r] - prr[l] + arr[l];
       //cout<<sum<<" ";
        ans = max(sum , ans);
    }
    //cout<<ans<<endl;
    if(ans>=tsum){
        cout<<"NO"<<endl;
        return;
    }
    else cout<<"YES"<<endl;


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

