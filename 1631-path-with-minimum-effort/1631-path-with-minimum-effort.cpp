class Solution {
public:
    int n;
    int m;
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};

    bool ifposs(int tym,vector<vector<int>>& arr,vector<vector<int>>& vis,int timer){

       queue<tuple<int,int>>q;
       q.push({0,0});

       vis[0][0]=timer;


       while(q.size()>0){

          auto [i,j]=q.front();

          if(i==n-1 && j==m-1) return true;

          q.pop();

          for(auto [x,y]:dir){

            int ni=x+i;
            int nj=y+j;

            if(ni>=0 && nj>=0 && ni<n && nj<m && vis[ni][nj]!=timer && abs(arr[i][j]-arr[ni][nj])<=tym){
                vis[ni][nj]=timer;
                q.push({ni,nj});
            }
          }
       }

       return false;

    }

    int minimumEffortPath(vector<vector<int>>& arr) {

        n=arr.size();
        m=arr[0].size();

        


        vector<vector<int>>vis(n,vector<int>(m,-1));

        int timer=0;

        int low=0;

        int high=10000000;

        int ans=-1;

        while(low<=high){
            int mid=(low+high)/2;

            bool x=ifposs(mid,arr,vis,timer);
            timer++;

            if(x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
        
    }
};