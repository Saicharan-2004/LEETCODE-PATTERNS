class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) 
    {
        unordered_map<int,int>temp;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            if(temp.count(target-arr[i])>0)
            {
                return {temp[target-arr[i]],i};
            }
            temp[arr[i]]=i;
        }
        return {-1,-1};
    }
};