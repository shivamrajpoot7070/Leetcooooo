class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& rest) {

        unordered_map<int,int>res;
        
        for(int x:rest){
            res[x]++;
        }

        unordered_map<int,vector<int>>mpp;

        for(int i=0;i<edges.size();i++){

            int u=edges[i][0];
            int v=edges[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);
        }
        
        vector<int>vis(n,-1);


        int ans=0;

        queue<int>q;

        q.push(0);

        vis[0]=1;


        while(q.size()>0){

            int node=q.front();
            q.pop();

            for(auto it:mpp[node]){

                if(vis[it]==-1 && res[it]==0){
                    ans+=1;
                    q.push(it);
                    vis[it]=1;
                }
            }
        }

        return ans+1;
        
    }
};