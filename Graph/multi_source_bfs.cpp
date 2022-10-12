/*
    Multi source BFS :- putting all sources simultaneously in a queue then do bfs traversal.
*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> xm = {0,1,1,1,0,-1,-1,-1}; // all possible 8 positions
vector<int> ym = {-1,-1,0,1,1,1,0,-1};
// int mx = 0;
bool isValid(int i, int j, int n, int m){  
    return i>=0 && j>=0 && i<n && j<m; 
}
class Pair{ // storing x,y and its level coordinates
    public:
    int x;
    int y;
    int lvl;
    Pair(int x, int y, int lvl){
        this->x = x;
        this->y = y;
        this->lvl = lvl;
    }
};
int bfs(vector<vector<int>> &grid, int n, int m, int mx){
    vector<vector<bool>> visited(n+1, vector<bool>(m+1,0));
    queue<Pair> q;
    for (int i=0; i<n; i++){
        for(int j=0; j<m; j++){
		    if (grid[i][j] == mx){
		        q.push({i,j,0}); //putting all sources in the queue
		        visited[i][j] = true; // and visit them true
		    }
        }
	}
	int ans=0;
	while(!q.empty()){
	    Pair par = q.front();
	    q.pop();
	    int par_x = par.x;
	    int par_y = par.y;
	    int par_lvl = par.lvl;
	    for (int i=0;i<8;i++){
	        int child_x = par_x + xm[i];
	        int child_y = par_y + ym[i];
	        if (!isValid(child_x,child_y,n,m)) continue;   //if not valid 
	        if (visited[child_x][child_y]) continue;   // if visited
	        visited[child_x][child_y] = true;  // if not visited
	        int lev = par_lvl+1; 
	        q.push({child_x,child_y,lev}); // storing child axis with parent level +1;
	        ans = max(ans,par_lvl+1); // return max level
	    }
	}
    mx=0;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll int t;
	cin>>t;
	while(t--)
	{
	    int n=0,m=0; 
		cin>>n>>m;
		int mx =0;
		vector<vector<int>> grid(n+1, vector<int>(m+1,0));
		for (int i=0; i<n; i++){
		    for(int j=0; j<m; j++){
		        cin>>grid[i][j];
		        mx = max(mx, grid[i][j]);
		    }
		}
// 		cout<<mx<<endl;
		cout<<bfs(grid, n, m, mx)<<endl;
	}
}
// https://www.codechef.com/LP3TO401/problems/SNSOCIAL
