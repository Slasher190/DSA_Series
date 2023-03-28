#include <bits/stdc++.h>
#define ll long long 
using namespace std;

ll m,n;
const int N = 1e6;
ll tree[N];

bool isWoodEnough(int h){
    ll wood = 0;
    for (int i=0; i<n; ++i){
        if (tree[i] >= h){
            wood += (tree[i] - h);
        }
    }
    return wood >= m;
}

int main()
{
    cin>>n>>m;
    // vector<int> tree(N);
    ll mx_height = -1;
    for (ll i=0; i<n; i++){
        cin>>tree[i];
        mx_height = max(mx_height, tree[i]);
    }
    ll low = 0;
    ll high = mx_height;
    while(high - low > 1){
        int mid = (low + high)/2;
        // T T T T T F F F F 
        if(isWoodEnough(mid)){
            low = mid;
        }
        else{
            high = mid-1;
        }
        
    }
    if (isWoodEnough(high)){
        cout<<high<<endl;
    }
    else{
        cout<<low<<endl;
    }
}
// https://www.spoj.com/problems/EKO/
