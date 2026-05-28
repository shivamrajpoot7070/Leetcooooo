class Solution {
public:
    int jump(vector<int>& arr) {
        
        if(arr.size()==1) return 0;

        int ct=1;


        int curr=arr[0];

        int maxi=arr[0];

        for(int i=1;i<arr.size();i++){

            maxi=max(maxi,i+arr[i]);

            if(curr>=arr.size()-1) return ct;

            if(i==curr){
                ct++;
                curr=maxi;
            }
        }

        return 0;
    }
};