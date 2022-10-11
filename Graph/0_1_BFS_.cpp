/*
    consept = 0/1 BFS traversal
    shortest path traversal; Using BFS;
    reversing the edges with magnitude of 1 and count those value having min sum 
    then return;
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const int N = 1e5 + 10;
const int INF = 1e9+10;
int n,m;

vector<pair<int,int> > graph[N];
vector<int> lvl(N, INF);

int bfs(){
    deque<int> q;
    lvl[1] = 0;
    q.push_back(1);
    while(!q.empty()){
        int par = q.front();
        q.pop_front();
        for(auto child : graph[par]){
            int child_v = child.first;
            int child_wt = child.second;
            if (lvl[par] + child_wt < lvl[child_v]){   //comparing the path from parents to child
                lvl[child_v] = lvl[par]+child_wt;
                if (child_wt == 1){
                    q.push_back(child_v);
                }
                else{
                    q.push_front(child_v);
                }
            }
        }
    }
    return lvl[n] == INF ? -1 : lvl[n];
}
int main() {
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int x,y; cin>>x>>y;
        if (x == y) continue;
        graph[x].push_back({y,0});
        graph[y].push_back({x,1});
    }
    cout<<bfs()<<endl;
    return 0;
}

// https://www.codechef.com/submit/REVERSE
