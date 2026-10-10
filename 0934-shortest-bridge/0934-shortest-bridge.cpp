class Solution {
public:
    //typedef pair<pair<int,int>,int>>p;
    int shortestBridge(vector<vector<int>>& arr) {
        
        queue<pair<int,int>>q;

        int n=arr.size();
        int m=arr[0].size();

        queue<pair<pair<int,int>,int>>pq;

        vector<vector<int>>vis(n,vector<int>(m,-1));


        vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        bool flag=false;

        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                if(arr[i][j]==1){
                    q.push({i,j});
                    pq.push({{i,j},0});
                    vis[i][j]=1;
                    flag=true;
                    break;
                }
            }

            if(flag) break;
        }

        while(q.size()>0){

            int i=q.front().first;
            int j=q.front().second;
            q.pop();

            for(auto [x,y]:dir){

                int ni=x+i;
                int nj=y+j;

                if(ni>=0 && nj>=0 && ni<n && nj<m && arr[ni][nj]==1 && vis[ni][nj]==-1){
                    pq.push({{ni,nj},0});
                    q.push({ni,nj});
                    vis[ni][nj]=1;
                }
            }
        }

        //vis.resize(n,vector<int>(m,-1));

        while(pq.size()>0){

            int nn=pq.size();

            while(nn--){

                int i=pq.front().first.first;
                int j=pq.front().first.second;
                vis[i][j]=1;
                int curr=pq.front().second;
                pq.pop();

                for(auto [x,y]:dir){

                    int ni=x+i;
                    int nj=y+j;

                    if(ni>=0 && nj>=0 && ni<n && nj<m && vis[ni][nj]==-1 && arr[ni][nj]==0){
                        vis[ni][nj]=1;
                        pq.push({{ni,nj},curr+1});
                    }

                    if(ni>=0 && nj>=0 && ni<n && nj<m && vis[ni][nj]==-1 && arr[ni][nj]==1){
                        return curr;
                    }
                } 
            }
        }

        return -1;
    }
};