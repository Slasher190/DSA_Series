class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (auto &num: nums){
            s.insert(num);
        }
        int mx_len = 0;
        for (auto &num: nums){
            if (!s.count(num-1)){
                int curr_len = 1;
                while(s.count(num+1)){
                    curr_len++;
                    num++;
                }
                mx_len = max(mx_len, curr_len);
            }
        }
        return mx_len;
    }
};

// https://leetcode.com/problems/longest-consecutive-sequence/
