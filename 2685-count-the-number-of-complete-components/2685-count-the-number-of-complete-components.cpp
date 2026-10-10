class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&mpp,vector<int>&vis,unordered_map<int,int>&ct,int node,int &nod){

        vis[node]=1;

        for(auto it:mpp[node]){
            int siz=mpp[node].size();
            ct[siz]+=1;

            if(vis[it]==-1){
                nod++;
                dfs(mpp,vis,ct,it,nod);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& arr) {
        
        unordered_map<int,vector<int>>mpp;

        for(int i=0;i<arr.size();i++){

            int u=arr[i][0];
            int v=arr[i][1];

            mpp[u].push_back(v);
            mpp[v].push_back(u);

        }

        int ans=0;

        vector<int>vis(n,-1);

        for(int i=0;i<n;i++){

            if(vis[i]==-1){
                unordered_map<int,int>ct;
                int nod=1;
                dfs(mpp,vis,ct,i,nod);
                cout<<i<<" "<<nod<<" "<<ct.size()<<'\n';
                if(ct.size()==1){
                    for(auto it:ct){
                        if(it.first==nod-1) ans+=1;
                    }
                }
                else if(ct.size()==0) ans+=1;
            }
        }

        return ans;

    }
};