#include <bits/stdc++.h>
const int MOD = (int) 1e9 + 7;
using namespace std;
int max_digit(int x){
    int mx = 0;
    while(x > 0){
        int p = x%10;
        mx = max(mx,p);
        x /= 10;
    }
    return mx;
}
int main()
{
    int n;
    cin>>n;
    if (n == 0){
        cout<<0<<endl;
        return 0;
    }
    int cnt=1;
    while(n > 0){
        if (n < 10){
            break;
        }
        n = n - max_digit(n); // subtracting max digit from number 
        cnt++;
    }
    cout<<cnt<<endl;
}
