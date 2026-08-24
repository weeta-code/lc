class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
        fixed size window of length s1

        a window is valid iff it contains the same characters as s1 else we continue

        freq each step freq[s[r]]++ and then for 
        */ 

        int l = 0, r = 0;
        vector<int> need(26);
        vector<int> have(26);
        for (auto& c : s1) {
            need[c - 'a']++;
        }

        for (int r{}; r < s2.size();r++) {
            have[s2[r] - 'a']++;

            if ((r - l) + 1 > s1.size()) {
                have[s2[l] - 'a']--;
                l++;
            }

            if (need == have) return true;
        }

        return false;
    }
};
