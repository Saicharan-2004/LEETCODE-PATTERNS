class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        // unordered_set<char>checker;
        // checker.insert('A');
        // char a='A';
        // for(int i=1;i<26;i++)
        // {
        //     checker.insert(a+1);
        //     a++;
        // }
        int n=columnNumber;
        int rem=0;
        string ans="";
        // int temp=1;
        while(n!=0)
        {
            n-=1;
            ans+='A'+n%26;
            n=n/26;
            // temp++;
        }
        reverse(ans.begin(),ans.end());
        // cout<<701%26<<" ";
        return ans;
    }
};