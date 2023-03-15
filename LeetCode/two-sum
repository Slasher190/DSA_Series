class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp;
        int i1=0,j1=0;   
        int i=0,j=nums.size()-1;
        unordered_map<int,int> mp; //storing value and its index
        vector<int> t;
        for(int i=0;i<nums.size();i++){
            if (mp[nums[i]] > 0){
                nums[i]++; 
                target++;
            }
            mp[nums[i]] = i;
        }
        sort(nums.begin(),nums.end()); // sorting in increasing order
        while(i<j){
            int x = nums[i] + nums[j];
            if (x == target){ // if equals to the target break and store the value
                temp.push_back(nums[i]);
                temp.push_back(nums[j]);
                break;
            }
            else if( x < target) i++;
            else j--;
        }
        t.push_back(mp[temp[0]]);t.push_back(mp[temp[1]]); // using map for fetching related index
        return t;
    }
};
// https://leetcode.com/problems/two-sum/
