class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) 
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        long long sum = 0;
        long long ans = 0;
        for(int i = 0; i < k; i++){
            mp[nums[i]]++;
            sum += nums[i];
        }
        if(mp.size() >= m) ans = max(ans, sum);

        for(int i = 1, j = k; i < n, j < n; i++, j++)
        {
            mp[nums[i-1]]--;
            if(mp[nums[i-1]] == 0) mp.erase(nums[i-1]);
            mp[nums[j]]++;
            sum -= nums[i-1];
            sum += nums[j];
            if(mp.size() >= m) ans = max(ans, sum);
        }
        return ans;
    }
};