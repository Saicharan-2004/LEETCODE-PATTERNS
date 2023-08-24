// class Solution {
// public:
//     string justifyContentSpaceBetween(string &str,int &maxi)
//     {
//         int n=str.length();
//         string f=str.substr(0,n-1);
//         int countSpaces=0;
//         for(char it:f)
//         {
//             if(it==' ')
//             {
//                 countSpaces++;
//             }
//         }
//         countSpaces+=(maxi-str.length());
//         int countWords=countSpaces+1;
//         // for(int i=0;i<str.size();i++)
//         // {
//         //     if(countWords==0)
//         //     {
//         //         for(int j=i;j<str.size();i++)
//         //         {
//         //             if(str[j]!=' ')
//         //             {
//         //                 ans+=str[j];
//         //             }
//         //             else
//         //             {
//         //                 break;
//         //             }
//         //         }
//         //         break;
//         //     }
//         //     if(str[i]!=' ')
//         //     {
//         //         ans+=str[i];
//         //     }
//         //     else
//         //     {
//         //         int dec=countSpaces%countWords;
//         //         int y=countSpaces/countWords;
//         //         if(dec!=0)
//         //             y++;
//         //         for(int i=0;i<y;i++)
//         //         {
//         //             ans+=' ';
//         //         }
//         //         countSpaces-=y;
//         //         countWords--;
//         //         while(i<str.size())
//         //         {
//         //             if(str[i]==' ')
//         //             {
//         //                 i++;
//         //             }
//         //             else
//         //             {
//         //                 i--;
//         //                 break;
//         //             }
//         //         }
//         //     }
//         // }
//         // while(ans.length()!=maxi)
//         // {
//         //     ans+=' ';
//         // }
//         if(countSpaces==0)
//         {
//             while(f.length()!=maxi)
//             {
//                 f+=' ';
//             }
//             return f;
//         }
//         int actualWordSpace=n-countSpaces+1;
//         int reqAdditionalSpace=maxi-actualWordSpace-countSpaces;
//         reqAdditionalSpace=max(reqAdditionalSpace,0);
//         int reqindividualadditionalspace;
//         int someadditionalspacereq=0;
//         if(countSpaces!=0 && reqAdditionalSpace % countSpaces==0)
//         {
//             reqindividualadditionalspace=(reqAdditionalSpace)/countSpaces;
//         }
//         else if(countSpaces!=0)
//         {
//             someadditionalspacereq=(reqAdditionalSpace%countSpaces);
//             reqindividualadditionalspace=(reqAdditionalSpace)/countSpaces;
//         }
//         string ans="";
//         int j=someadditionalspacereq;
//         for(int i=0;i<n-1;i++)
//         {
//             ans+=f[i];
//             if(f[i]==' ')
//             {
//                 int ctr=0;
//                 ans+=f[i];
//                 while(ctr<reqindividualadditionalspace)
//                 {
//                     ans+=' ';
//                     ctr++;
//                 }
//             }
//         }
//         // while(ans.length()!=maxi)
//         // {
//         //     ans+=' ';
//         // }
//         return ans;
//     }
//     vector<string> fullJustify(vector<string>& words, int maxWidth) 
//     {
//         int len=0;
//         for(auto it:words)
//         {
//             len+=it.length();
//         }
//         vector<string>ans;
//         int i=0;
//         string temp="";
//         for(auto it:words)
//         {
//             if(temp.length()+it.length()>maxWidth)
//             {
//                 string anstempstring=justifyContentSpaceBetween(temp,maxWidth);
//                 ans.push_back(anstempstring);
//                 temp.erase();
//                 temp+=(it+" ");
//             }
//             else
//             {
//                 temp+=(it+" ");
//             }
//         }
//         while(temp.length()!=maxWidth)
//         {
//             temp+=' ';
//         }
//         ans.push_back(temp);
//         return ans;
//         // vector<string> ans;
//         // string tempans;
//         // tempans--->length === maxWidth;
//     }
// };
class Solution {
public:
    void justifier(string& temp,int& maxWidth){
        float words = 0;
        float spaces = 0;
        int flag = false;
        for (int i=0;i<temp.size();i++){
            if (flag){
                if (temp[i]==' '){
                    flag = false;
                    words++;
                    spaces++;
                }
            }
            else{
                if (temp[i]==' ')
                    spaces++;
                else
                {
                    flag = true;
                }
            }
        }
        if (flag)
            words++;
        spaces += (maxWidth - temp.size());
        words--;
        string t;
        // cout << words << " " << spaces << endl;
        for (int i=0;i<temp.size();i++){
            if (words==0)
            {
                for (int j=i;j<temp.size();j++){
                    if (temp[j]!=' ')
                        t+= temp[j];
                    else
                        break;
                }
                break;
            }
            if (temp[i]!= ' ')
                t += temp[i];
            else{
                float x = spaces/words;
                int y = spaces/words;
                // cout << x << " " << y << endl;
                if (x>y){
                    y++;
                }
                for (int i=0;i<y;i++){
                        t += ' ';
                    }
                spaces -= y;
                words--;
                while (i<temp.size()){
                    if (temp[i]== ' ')
                        i++;
                    else
                        {i--;
                        break;}
                }
            }
        }
        while (t.size()!=maxWidth){
            t = t+ ' ';
        }
        // cout << t << endl;
        temp = t;
    }
    void justifier2(string& temp,int& maxWidth){
        while (temp.size()!=maxWidth){
            temp = temp + ' ';
        }
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0;
        int n = words.size();
        while (i<n){
            string temp;
            while (i<n){
                if (temp.size()+words[i].size()<maxWidth)
                {
                    temp = temp+words[i];
                    temp = temp + " ";
                    i++;
                }
            else if (temp.size()+words[i].size()==maxWidth)
                {
                    temp = temp+words[i];
                    i++;
                }
                else{
                    break;
                }    
            }
            // cout << i << endl;
            // cout << temp << endl;
            if (i==n)
                justifier2(temp,maxWidth);
            else 
                justifier(temp,maxWidth);
            res.push_back(temp);
        }
        return res;
    }
};