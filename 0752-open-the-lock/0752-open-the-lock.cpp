class Solution {
public:
    int openLock(vector<string>& arr, string target) {

        unordered_map<string,int>vis;
        unordered_map<string,int>mpp;

        for(string x:arr){
            mpp[x]++;
        }

        if(mpp["0000"]>=1) return -1;

        vis["0000"]=1;

        queue<pair<string,int>>q;

        q.push({"0000",0});


        while(q.size()>0){

            string curr=q.front().first;
            int dis=q.front().second;
            q.pop();

            if(curr==target) return dis;

            string temp=curr;

            for(int i=0;i<curr.length();i++){

                char c=curr[i];

                if(c=='0'){
                    char ne=c;
                    char pre=c;
                    ne++;
                    pre='9';
                    curr[i]=ne;
                    
                    if(vis[curr]==0 && mpp[curr]==0){
                        vis[curr]=1;
                        q.push({curr,dis+1});
                    }
                    curr[i]=c;
                    curr[i]=pre;
                    if(vis[curr]==0 && mpp[curr]==0){
                        vis[curr]=1;
                       q.push({curr,dis+1});
                    }
                    curr[i]=c;
                }
                else if(c=='9'){
                    char ne=c;
                    char pre=c;
                    ne='0';
                    pre--;
                    curr[i]=ne;
                    if(vis[curr]==0 && mpp[curr]==0){
                        vis[curr]=1;
                        q.push({curr,dis+1});
                    }
                    curr[i]=c;
                    curr[i]=pre;
                    if(vis[curr]==0 && mpp[curr]==0){
                        vis[curr]=1;
                       q.push({curr,dis+1});
                    }
                    curr[i]=c;
                }
                else{

                    char ne=c;
                    char pre=c;
                    ne++;

                    curr[i]=ne;

                    if(vis[curr]==0 && mpp[curr]==0){
                        vis[curr]=1;
                        q.push({curr,dis+1});
                    }
                    curr[i]=c;
                    pre--;
                    curr[i]=pre;

                    if(vis[curr]==0 && mpp[curr]==0){
                        vis[curr]=1;
                        q.push({curr,dis+1});
                    }
                    curr[i]=c;
                }
                curr[i]=c;
            }
        }


        return -1;
    
    }
};