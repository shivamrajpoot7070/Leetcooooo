class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> answer(cars.size(), -1);  // Collision times ko -1 se initialize karna, iska matlab hai koi collision nahi
        stack<int> st;  // Stack jo cars ke indices ko hold karta hai
        
        // Last car se first car tak iterate karna
        for(int i = cars.size() - 1; i >= 0; --i) {
            // Stack se cars ko remove karna jo slow hain ya same speed wali hain current car se
            while(!st.empty() && cars[st.top()][1] >= cars[i][1]) {
                st.pop();
            }
            
            // Car ke aage wali car ke sath collision time calculate karna
            while(!st.empty()) {
                // Stack ke top par car ke sath potential collision time calculate karna
                double collTime = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);
                
                // Check karna ki collision time valid hai ya nahi
                if(answer[st.top()] == -1 || collTime <= answer[st.top()]) {
                    answer[i] = collTime;  // Current car ke liye collision time update karna
                    break;  // Loop se exit karna kyunki humein valid collision time mil gaya
                }
                st.pop();  // Car ko stack se remove karna agar valid collision nahi hai
            }
            
            st.push(i);  // Current car index ko stack mein push karna
        }
        
        return answer;  // Collision times ka array return karna
    }
};