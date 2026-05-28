class Solution {
public:
    bool canJump(vector<int>& arr) {

        int maxi=0;

       // if(arr.size()==1) return true;

        for(int i=0;i<arr.size();i++){

            maxi=max(maxi,i+arr[i]);

            if(arr[i]==0){

                if(maxi>=arr.size()-1) return true;
                
                if(maxi<=i) return false;
            }

            if(maxi>=arr.size()-1) return true;
        }

        return false;
    }
};