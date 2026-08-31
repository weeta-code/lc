class Solution {
public:
    int maxArea(vector<int>& heights) {
        // more or less just maximizing area no?
        /*
            seems like a window is valid if its like volume is greater than our current volume no? 
        */

        /*
            overall goal here is to maximize volume, definitely isn't if vol > then r++ else l++.  
        */
        int l {}, r = heights.size() - 1;
        int vol = 0;
        while(l < r) {
            vol = max(vol, (r - l) * (min(heights[r], heights[l])));
            if (heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return vol;
    }
};
