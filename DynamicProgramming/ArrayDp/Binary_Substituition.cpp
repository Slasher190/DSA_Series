#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll int t;
	cin>>t;
	while(t--)
	{
		string s; cin>>s;
		vector<int> dp(s.size()+1,0);
		dp[0] = 1;
		dp[1] = 1;
		for(int i=2; i<=s.size(); i++){
		    if (s[i-1] != s[i-2]){
		        dp[i] = dp[i-1]%mod + dp[i-2]%mod;
		    }
		    else{
		        dp[i] = dp[i-1]%mod;
		    }
		}
		cout<<dp[s.size()]%mod<<endl;
	}
}

// https://www.codechef.com/OCT221D/problems/BINARYSUB
