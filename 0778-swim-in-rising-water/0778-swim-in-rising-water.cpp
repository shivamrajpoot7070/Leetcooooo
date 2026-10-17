class Solution {
public:
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};

    bool ifposs(int mid,vector<vector<int>>&arr,vector<vector<int>>&vis,int timer){

        if(arr[0][0]>mid) return false;

        queue<tuple<int,int>>q;

        int n=arr.size();
        int m=arr[0].size();
        q.push({0,0});
        vis[0][0]=timer;

        while(q.size()>0){

            auto [i,j]=q.front();
            if(i==n-1 && j==m-1) return true;
            q.pop();

            for(auto [x,y]:dir){

                int ni=x+i;
                int nj=y+j;

                if(ni>=0 && nj>=0 && ni<n && nj<m && vis[ni][nj]!=timer && arr[ni][nj]<=mid){
                    q.push({ni,nj});
                    vis[ni][nj]=timer;
                }
            }

        }

        return false;
    }
    int swimInWater(vector<vector<int>>& arr) {

      int low=0;
      int high=0;
      int n=arr.size();
      int m=arr[0].size();


      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            high=max(high,arr[i][j]);
        }
      }

      vector<vector<int>>vis(n,vector<int>(m,-1));
      int timer=0;
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