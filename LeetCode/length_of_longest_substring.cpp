class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        int mx_cnt = 1;
        // int curr_cnt = 0;
        vector<int> v(300, 0);
        int i=0,j=0;
        v[s[0]]++;
        while(i != s.size()-1){
            if (v[s[i+1]] == 0){
                i++;
                v[s[i]] = 1;
                mx_cnt = max(mx_cnt , i-j+1);
            }
            else{
                v[s[j]]--;
                j++;
            }
        }
        return mx_cnt;
    }
};
