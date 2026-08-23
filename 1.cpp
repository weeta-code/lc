class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // we just care about previously seen indices using a hash map of the characters. we use l and r pointers and just measure difference between them to see our max and at the end of our loop just return the raw size difference between l and r.
        unordered_map<char, int> frq;
        int l {}, r {};
        int mx = 0;
        while (r < s.size()) {
            if (frq.contains(s[r])) {
                l = max(l, frq[s[r]] + 1);
            } 
            frq[s[r]] = r;
            mx = max(mx, r - l + 1);
            r++;
        }

        return mx;
    }
};
