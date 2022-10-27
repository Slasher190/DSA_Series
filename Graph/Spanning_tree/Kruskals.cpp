// kruskals Algorithm Greedy Approach
// Using DSU
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 1e5+10;
int parent[N];
int size[N];

struct Edge{
    int u,v,weight;
    bool operator<(Edge const & e1){
        return weight < e1.weight;
    }
};

void make(int v){
    parent[v] = v;
    size[v] = 1;
}

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);  // compression function
}

void Unions(int a, int b){
    a = find(a);
    b = find(b);
    if (a != b){
        if (size[a] < size[b]){
            swap(a,b);
        }
        parent[b] = a; 
        size[a] += size[b];
    }
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int vert, edge;
    cin>>vert>>edge;
    vector<Edge> edges;
    for (int i=0; i<vert; i++){
        make(i);
    }
    for(int i=0; i<edge; i++){
        int a,b,c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    sort(edges.begin(), edges.end()); //sort edges by distance
    vector<Edge> result;
    int cost = 0;
    for (auto& edge : edges){
        if (find(edge.u) != find(edge.v)){
            cost += edge.weight;
            result.push_back(edge);
            Unions(edge.u, edge.v);
        }
    }
    cout<<cost<<endl;
    for (auto &res : result){
        cout<< res.u << " " << res.v << endl;
    }
}
