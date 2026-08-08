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
                prefix=lps[prefix-1];
            }
        }
    }
}
int KMP_MATCH(string haystack, string needle){
    vector<int>lps(needle.size(),0);
    lpsfind(lps,needle);
    int first=0;
    int second=0;
    while(first<haystack.size()&&second<needle.size()){
        if(haystack[first]==needle[second]){
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
            return 1;
        }
    }
    return 0;
}
    int repeatedStringMatch(string a, string b) {
        if(a==b){
            return 1;
        }
        int repeat = 1;
        string temp = a;
        while(temp.size()<b.size()){
            temp+=a;
            repeat++;
        }

        // KMP SEARCH
        if(KMP_MATCH(temp,b)==1){
            return repeat;
        }
        // temp+a KMP SEARCH
        if(KMP_MATCH(temp+a,b)==1){
            return repeat+1;
        }

        // otherwise
        return -1;

    }
};