class Solution {
  public:
    int getLPSLength(string &s) {
        // code here
        vector<int> lps(s.size(),0);
        int prefix =0 ;
        int suffix =1;
        while(suffix<s.size()){
            if(s[suffix]==s[prefix]){
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
        return lps[s.size()-1];
    }
};