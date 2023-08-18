class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
        vector<int>degree(n,0);
        set<pair<int,int>>set_;
        for(auto it:roads)
        {
            degree[it[0]]++;
            degree[it[1]]++;
            set_.insert({it[0],it[1]});
            set_.insert({it[1],it[0]});
        }
        int rank=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int ra=degree[i]+degree[j];
                if(set_.find({i,j})!=set_.end())
                {
                    ra--;
                }
                rank=max(rank,ra);
            }
        }
        return rank;
    }
};