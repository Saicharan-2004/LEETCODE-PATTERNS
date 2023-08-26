class Solution {
public:
    int distributeCandies(vector<int>& candyType) 
    {
        set<int>temp(candyType.begin(),candyType.end());
        return min(temp.size(),candyType.size()/2);
    }
};