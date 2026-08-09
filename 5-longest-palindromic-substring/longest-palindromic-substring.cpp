class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxi = 1;
        for(int i=0;i<s.size();i++){
            // odd
            int left = i-1;
            int right = i+1;
            while(left>=0&&right<s.size()&&s[left]==s[right]){
                int len = right-left+1;
                if(len>maxi){
                maxi = max(maxi,len);
                start = left; 
                }
                left--;
                right++;
            }
            // even
            left = i;
            right = i+1;
            while(left>=0&&right<s.size()&&s[left]==s[right]){
                int len = right-left+1;
                if(len>maxi){
                maxi = max(maxi,len);
                start = left; 
                }
                left--;
                right++;
            }
        }
        return s.substr(start,maxi);
    }
};