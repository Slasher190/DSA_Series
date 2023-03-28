class Solution {
public:
    int N = 1e5+10;
    void dfs1(vector<int>* graph1, int src, vector<bool> &visited, stack<int> &st){
        visited[src] = true;
        for (auto child:graph1[src]){
            if (!visited[child]){
                dfs1(graph1, child, visited, st);
            }
        }
        st.push(src);
    }
    int cnt=0;
    void dfs2(vector<int>* graph2, int src, vector<bool> &visited){
        visited[src] = true;
        cnt++;
        for(auto child:graph2[src]){
            if (!visited[child]){
                dfs2(graph2, child, visited);
            }
        }
    }
    int longestCycle(vector<int>& edges) {
        // int x = *max_element(edges.begin(), edges.end());
        vector<int> graph1[N];
        vector<int> graph2[N];
        for (int i=0; i<edges.size(); i++){
            graph1[i+1].push_back(edges[i]+1);
            graph2[edges[i]+1].push_back(i+1);
        }      
        vector<bool> v1(N,false);
        vector<bool> v2(N,false);
        stack<int> st;
        for(int i=0; i<=edges.size(); i++){
            if (!v1[i]){
                dfs1(graph1, i, v1, st);
            }
        }
        int mx = 0;
        while(!st.empty()){
            int v = st.top();
            st.pop();
            cnt=0;
            if (!v2[v]){
                dfs2(graph2, v, v2);
                mx = max(cnt,mx);
            }
        }
        if (mx <= 1){
            return -1;
        }
        else{
            return mx; 
        }
    }
};
// https://leetcode.com/problems/longest-cycle-in-a-graph/
