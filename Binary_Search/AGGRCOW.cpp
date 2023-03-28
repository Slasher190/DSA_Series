#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll n,cows;
const int N = 1e6;
ll cord[N];

bool canPlace(int minDist){
    ll cnt_cow = cows;
    ll pos = -1;
    for (int i=0; i<n; ++i){
        if (cord[i] - pos >= minDist || pos == -1){
            cnt_cow--;
            pos = cord[i];
        }
        if (cnt_cow == 0) return true;
    }
    return false;
}

int main()
{
    int t; cin>>t;
    while(t--){
        cin>>n>>cows;
        // vector<int> tree(N);
        for (ll i=0; i<n; i++){
            cin>>cord[i];
        }
        sort(cord, cord + n);
        ll low = 0;
        ll high = 1e9;
        while(high - low > 1){
            int mid = (low + high)/2;
            // T T T T T F F F F 
            if(canPlace(mid)){
                low = mid;
            }
            else{
                high = mid-1;
            }
            
        }
        if (canPlace(high)){
            cout<<high<<endl;
        }
        else{
            cout<<low<<endl;
        }
    }
}
// https://www.spoj.com/problems/AGGRCOW/
