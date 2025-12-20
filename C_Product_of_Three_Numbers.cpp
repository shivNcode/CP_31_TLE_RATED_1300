#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <set>
#include <chrono>
using namespace std;

#define int long long
#define INF (int)1e18
#define output(arr) for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


vector<pair<int,int>> f(int n){
    vector<pair<int,int>> prr;

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            int cnt = 0;
            while(n % i == 0){
                cnt++;
                n /= i;
            }
            prr.push_back({i, cnt});
        }
    }

    if(n > 1){
        prr.push_back({n, 1});
    }

    return prr;
}



void Solve() {
    int n;
    cin>>n;
    vector<pair<int,int>> arr = f(n);
    // for(int i=0;i<arr.size();i++){
    //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
    // }
    if(arr.size()>=3){

        int v = 1;
        cout<<"YES"<<endl;
        for(int i=0;i<arr[0].second;i++){
            v*=arr[0].first;
        }
        cout<<v<<" ";
        v = 1;
        for(int i=0;i<arr[1].second;i++){
            v*=arr[1].first;
        }
        cout<<v<<" ";
        v = 1;
        for(int i=0;i<arr[2].second;i++){
            v*=arr[2].first;
        }
        if(arr.size()>3){
            for(int i=3;i<arr.size();i++){

                for(int j = 0;j<arr[i].second;j++){
                    v*=arr[i].first;
                }
            }
        }
        cout<<v<<" ";
        cout<<"\n";

    }
    else if(arr.size()==2){
        // cout<<"2"<<" ";
        if(arr[0].second + arr[1].second >=4){
            cout<<"YES"<<endl;
            cout<<arr[0].first<<" ";
            arr[0].second--;
            cout<<arr[1].first<<" ";
            arr[1].second--;
             int v = 1;
            for(int i=0;i<arr.size();i++){

                for(int j = 0;j<arr[i].second;j++){
                    v*=arr[i].first;
                }

            }
             if(v!=1) cout<<v<<" ";
            cout<<"\n";
        }
        else cout<<"NO"<<endl;
    }
    else if (arr.size()==1){
        // cout<<"3"<<" ";
        if(arr[0].second>5){
            cout<<"YES"<<endl;
            cout<<arr[0].first<<" ";
            arr[0].second--;
            cout<<arr[0].first*arr[0].first<<" ";
            arr[0].second-=2;
            int v = 1;
            for(int i=0;i<arr.size();i++){

                for(int j = 0;j<arr[i].second;j++){
                    v*=arr[i].first;
                }

            }
             if(v!=1) cout<<v<<" ";
            cout<<"\n";
        }
        else cout<<"NO"<<endl;
    }
    else  cout<<"NO"<<endl;
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

