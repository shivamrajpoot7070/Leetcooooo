class Solution {
public:
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        unordered_map<int,int>mpp;



        vector<pair<int,int>>v;

        for(int x:arr){
            mpp[x]++;
        }

        if(k==0){
            return mpp.size();
        }

        for(auto it:mpp){
            v.push_back({it.second,it.first});
        }

        sort(v.begin(),v.end());

        for(int i=0;i<v.size();i++){

            if(v[i].first<=k){
                int ele=v[i].second;
                int tym=v[i].first;
                mpp.erase(ele);
                k-=tym;
            }
            else{
                k=0;
                int ele=v[i].second;
                mpp[ele]--;

                if(mpp[ele]==0){
                    mpp.erase(ele);
                }
            }

            if(k==0){
                break;
            }
        }

        return mpp.size();
    }
};