class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // monotonic stack just means top of the stack is the largest number 
        /*
            goal is for each i we want to tell how many indices in the array until a larger
            num appears

            we push the nums into a stack so long as num < st.top() else we push_back into
            our res array stack.size() then pop and we do so until st.empty() once empty
            we just continue again i think?
        */

        stack<int> st;
        vector<int> res(temperatures.size(), 0);
 
        for (int i{}; i < temperatures.size(); i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                res[st.top()] = i - st.top(); 
                st.pop(); 
            }
            st.push(i);
        }
        return res;
    }
};
