class Solution {
public:
    bool isNStraightHand(vector<int>& arr, int size) {
        

        int n=arr.size();
        
        if(n%size!=0){
            return false;
        }

        int mm=n/size;
        int tym=mm;

        map<int,int>mpp;

        for(int x:arr){
            mpp[x]++;
        }

        int k=size;
        int ans=0;

        while(tym--){

            int prev=-1;
            int ct=1;

            for(auto& it:mpp){

                if(prev==-1){
                    prev=it.first;
                    it.second--;
                    if(it.second==0){
                        mpp.erase(it.first);
                    }
                }
                else{
                    if(it.first-prev!=1){
                        it.second--;
                        if(it.second==0){
                        mpp.erase(it.first);
                        }
                        prev=-1;
                        ct=1;
                    }
                    else{
                        cout<<prev<<"->"<<it.first<<"->"<<" ";
                        ct+=1;
                        prev=it.first;
                        it.second--;
                        if(it.second==0){
                           mpp.erase(it.first);
                        }
                    }
                }

                if(ct==k){
                    prev=-1;
                    cout<<"hi"<<" ";
                    ans+=1;
                    ct=1;
                    break;
                }
            }
        }

        if(ans==mm) return true;
        return false;
    }
};