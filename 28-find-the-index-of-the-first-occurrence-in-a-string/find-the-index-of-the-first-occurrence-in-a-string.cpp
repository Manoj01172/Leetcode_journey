class Solution {
public:
void lpsfind(vector<int>&lps, string needle){
    int prefix=0;
    int suffix=1;
    while(suffix<needle.size()){
        if(needle[suffix]==needle[prefix]){
            lps[suffix]=prefix+1;
            prefix++;
            suffix++;
        }
        else{
            if(prefix==0){
                lps[suffix]=0;
                suffix++;
            }
            else{
                prefix = lps[prefix-1];
            }
        }
    }
}
    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(),0);
        lpsfind(lps,needle);
        int first = 0;
        int second = 0;
        while(second<needle.size()&&first<haystack.size()){
            if(needle[second]==haystack[first]){
                first++;
                second++;
            }
            else{
                if(second==0){
                    first++;
                }
                else{
                    second=lps[second-1];
                }
            }
            if(second==needle.size()){
                return first-second;
            }
        }
        return -1;
    }
};