class Solution {
public:
    // int helper(vector<vector<int>>&pairs,vector<int>prev,int ind)
    // {
        


    //     int nottake=helper(pairs,prev,ind);

    // }
    static bool sortbysec(const vector<int> &a,const vector<int> &b)
    {
        return (a[1] < b[1]);
    }
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),sortbysec);
        int prev=INT_MIN;
        int ans=0;
        for(auto it:pairs)
        {
            // cout<<it[0]<<" "<<it[1]<<" * ";
            if(it[0]>prev)
            {
                prev=it[1];
                ans++;
            }
        }
        cout<<endl;
        return ans;
    }
};