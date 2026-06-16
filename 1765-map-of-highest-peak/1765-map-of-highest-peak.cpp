class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& arr) {


        queue<tuple<int,int,int>>q;

        int n=arr.size();
        int m=arr[0].size();


        vector<vector<int>>vis(n,vector<int>(m,-1));
        vector<vector<int>>ans(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(arr[i][j]==1){
                    vis[i][j]=1;
                    ans[i][j]=0;
                    q.push({i,j,0});
                }
            }
        }

        vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};

        while(q.size()>0){

            int nn=q.size();
            queue<tuple<int,int,int>>temp;

            while(nn--){

                auto [i,j,dist]=q.front();

                q.pop();

                for(auto [x,y]:dir){

                    int ni=x+i;
                    int nj=y+j;

                    if(ni>=0 && nj>=0 && ni<n && nj<m && vis[ni][nj]==-1 && arr[ni][nj]==0){
                        q.push({ni,nj,dist+1});
                        ans[ni][nj]=dist+1;
                        vis[ni][nj]=1;
                    }
                }
            }
            //q=temp;
        }

        return ans;
    }
};