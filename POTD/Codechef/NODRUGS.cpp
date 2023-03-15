#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t; cin>>t;
    while(t--){
        int n,k,l;
        cin>>n>>k>>l;
        vector<int> v;
        int mx = -1;
        for (int i=0; i<n; i++){
            int a; cin>>a;
            mx = max(mx, a);
            v.push_back(a);
        }
        int cnt = 0;
        for (int i=0; i<n; i++){
            if (v[i] == mx){
                cnt++;
            }
        }
        if (cnt == 1 && v[n - 1] == mx){
            cout<<"Yes"<<endl;
        }
        else{
            if (k < 0){
                cout<<"No"<<endl;
            } 
            else{
                int x = l/k + l%k;
                int ans = (l-1)*k + v[n-1];
                if (ans > mx){
                    cout<<"Yes"<<endl;
                }
                else{
                    cout<<"No"<<endl;
                }
            }
        }
    }
}
