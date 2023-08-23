class Solution {
public:
    string reorganizeString(string s) 
    {
        unordered_map<char,int>temp;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            temp[s[i]]++;
        }
        int maxi=-1;
        char charmax;
        for(auto it:temp)
        {
            if(maxi<it.second)
            {
                charmax=it.first;
                maxi=it.second;
            }
        }
        int ind=0;
        for(;ind<n;ind+=2)
        {
            s[ind]=charmax;
            maxi--;
            if(!maxi)
            {
                temp.erase(charmax);
                break;
            }
        }
        if(maxi)
            return "";
        for(auto it:temp)
        {
            char cur=it.first;
            char freq=it.second;
            while(freq)
            {
                if(ind+2>=n)
                {
                    ind=1;
                }
                else
                {
                    ind+=2;
                }
                s[ind]=cur;
                freq--;
            }
        }
        return s;
        // string str="";
        // for(int i=0;i<n;i++)
        // {
        //     str+="1";
        // }
        // unordered_map<char,int>::iterator it=temp.begin();
        // for(int i=0;i<n;i+=2)
        // {
        //     // for(auto it:temp)
        //     // {
        //         if(it->second>(n+1)/2)
        //             return "";
        //         if(it->second>0)
        //             str[i]=it->first;
        //         it->second--;
        //     // }
        //     it++;
        // }
        // for(int i=1;i<n;i+=2)
        // {
        //     // for(auto it:temp)
        //     // {
        //         if(it->second>(n+1)/2)
        //             return "";
        //         if(it->second>0)
        //             str[i]=it->first;
        //         it->second--;
        //     // }
        //     it++;
        // }
        // // int r=0;
        // // for(auto it:temp)
        // // {
        // //     int e=0;
        // //     int w=r;
        // //     if(it.second>(n+1)/2)
        // //         return "";
        // //     while(e<it.second)
        // //     {
        // //         str[w]=it.first;
        // //         w+=2;
        // //         e++;
        // //     }
        // //     r++;
        // // }
        // for(int i=1;i<n;i++)
        // {
        //     if(str[i]==str[i-1] || str[i]=='1')
        //     {
        //         return "";
        //     }
        // }
        // return str;
    }
};