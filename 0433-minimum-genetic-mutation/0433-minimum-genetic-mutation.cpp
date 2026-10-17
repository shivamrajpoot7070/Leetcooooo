class Solution {
public:
    int minMutation(string strt, string end, vector<string>& bank) {

        unordered_map<string,int>mpp;

        for(string s:bank){
            mpp[s]++;
        }

        queue<tuple<string,int>>q;

        q.push({strt,0});

        while(q.size()>0){

            auto[str,dis]=q.front();
            
            if(str==end) return dis;

            q.pop();

            string temp=str;

            for(int i=0;i<temp.length();i++){
                for(char c='A';c<='Z';c++){

                    temp[i]=c;

                    if(mpp[temp]>0){
                        q.push({temp,dis+1});
                        mpp[temp]--;
                    }
                }
                temp=str;
            }
        }

        return -1;
    }
};