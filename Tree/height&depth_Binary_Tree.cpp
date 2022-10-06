#include <bits/stdc++.h>
#define int N = 1e5 + 10
using namespace std;

vetor<int> graph[N];
int depth[N],height[N];
void dfs(int vertex, int par=0){
    for (int child:graph[vertex]){
        if (child == par) continue;
        depth[child] = 1+depth[vertex]; //going to down side
        dfs(chid,vertex);
        height[vertex] = max(height[vertex], 1+height[child]); //going back to upper side
    }
}
int main(){
    int n; cin>>n;
    for(int i=0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1);
}
