class Solution {
public:
    int minimumOperations(string num) 
    {
        bool checkfive=false;
        bool checkzero=false;
        int n=num.length();
        for(int i=n-1;i>=0;i--)
        {
            if(checkzero && (num[i]=='5' || num[i]=='0'))
            {
                return n-i-2;
            }
            else if(checkfive && (num[i]=='2' || num[i]=='7'))
            {
                return n-i-2;
            }
            else if(num[i] == '5')
            {
                checkfive=true;
            }
            else if(num[i] == '0')
            {
                checkzero=true;
            }
        }
        if(checkzero)
        {
            return n-1;
        }
        return n;
        // int n=num.length();
        // unordered_set<string>temp;
        // temp.insert("00");
        // temp.insert("25");
        // temp.insert("75");
        // temp.insert("50");
        // if(n==2)
        // {
        //     if(temp.find(num)!=temp.end())
        //     {
        //         return 0;
        //     }
        //     if(num[0]=='0' || num[1]== '0')
        //     {
        //         return 1;
        //     }
        //     return 2;
        // }
        // int occurZero_end=-1;
        // int occurFive_end=-1;
        // for(int i=n-1;i>=0;i--)
        // {
        //     if(num[i]=='0')
        //     {
        //         occurZero_end=i;
        //         break;
        //     }
        // }
        // for(int i=n-1;i>=0;i--)
        // {
        //     if(num[i]=='5')
        //     {
        //         occurFive_end=i;
        //         break;
        //     }
        // }
        // int ans=0;
        // int checker2=max(occurZero_end,occurFive_end);
        // if(checker2==-1)
        // {
        //     return n;
        // }
        // ans=n-checker2-1;
        // int occurZero_begin=INT_MAX;
        // int occurTwo_begin=INT_MAX;
        // int occurSeven_begin=INT_MAX;
        // int occurFive_begin=INT_MAX;
        // for(int i=0;i<n;i++)
        // {
        //     if(num[i]=='0')
        //     {
        //         occurZero_begin=i;
        //         break;
        //     }
        // }
        // for(int i=0;i<n;i++)
        // {
        //     if(num[i]=='2')
        //     {
        //         occurTwo_begin=i;
        //         break;
        //     }
        // }
        // for(int i=0;i<n;i++)
        // {
        //     if(num[i]=='5')
        //     {
        //         occurFive_begin=i;
        //         break;
        //     }
        // }
        // for(int i=0;i<n;i++)
        // {
        //     if(num[i]=='7')
        //     {
        //         occurSeven_begin=i;
        //         break;
        //     }
        // }
        // int checker1=min(min(occurZero_begin,occurTwo_begin),min(occurFive_begin,occurSeven_begin));
        // ans+=checker1-checker2;
    }
};