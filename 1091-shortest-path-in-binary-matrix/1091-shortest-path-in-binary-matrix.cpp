class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& arr) {

        int n=arr.size();
        int m=arr[0].size();

        if(arr[0][0]==1 || arr[n-1][m-1]==1) return -1;

        vector<vector<int>>vis(n,vector<int>(m,0));

        vis[0][0]=1;

        queue<pair<int,pair<int,int>>>q;

        vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,1},{1,-1}};

        q.push({0,{0,0}});


        while(q.size()>0){

            int dist=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;


            q.pop();
            if(i==n-1 && j==m-1) return dist+1;

            for(auto[x,y]:dir){

                int ni=x+i;
                int nj=y+j;

                if(ni>=0 && nj>=0 && ni<n && nj<m && vis[ni][nj]==0 && arr[ni][nj]==0){
                    q.push({dist+1,{ni,nj}});
                    vis[ni][nj]=1;
                }
            }
        }


        return -1;
    }
};