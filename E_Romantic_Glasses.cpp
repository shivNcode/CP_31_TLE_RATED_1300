
/*
8
1 2 3 4 5 6 7 8
1 2 11 4 1 5 1 2
yes
even = 2 4 5 2
preeven = 2 6 11 13
odd = 1 11 1 1
preodd = 1 12 13 14


for any two index if the sum the difference if the preeven and preodd is same then it is one of
and also when the diff any preeven and preodd is zero then the there subarray
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;

void solve(){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    vector<ll> peven(n) , podd(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(i&1){
            if(i==1){
                peven[i] = arr[i];
                podd[i] = podd[i-1];
            }
            else{
                peven[i]+=(peven[i-1] + arr[i]);
                podd[i] = podd[i-1];
            }
        }
        else{
            if(i==0){
                podd[0] = arr[i];
            }
            else{
                podd[i]+=(podd[i-1] + arr[i]);
                peven[i] = peven[i-1];
            }

        }
    }
    map<ll , ll> mpp;
    for(ll i=0;i<n;i++){
        ll diff = peven[i] - podd[i];
        mpp[diff]++;
    }
    for(auto& it:mpp){
        if(it.second>=2 || it.first==0){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
    return;


}



int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}