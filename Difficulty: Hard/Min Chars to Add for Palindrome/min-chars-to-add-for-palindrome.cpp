class Solution {
  public:
    int minChar(string &s) {
        // code here
        int n = s.size();
        string rev = s;
        reverse(rev.begin(),rev.end());
        s+="&";
        s+=rev;
        vector<int> lps(s.size(),0);
        int prefix=0;
        int suffix=1;
        while(suffix<s.size()){
            if(s[suffix]==s[prefix]){
                lps[suffix]=prefix+1;
                suffix++;
                prefix++;
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
        return n-lps[s.size()-1];
    }
};
