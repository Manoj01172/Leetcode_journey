class Solution {
  public:
    int findSubString(string& str) {
        // code here
        vector<int> count(256,0);
        int diff=0,first=0,second=0;
        int len = str.size();
        // sbse phle unique element kitne hai voh find out kar liye diff hai unique element
        while(first<str.size()){
            if(count[str[first]]==0){
                diff++;
            }
            count[str[first]]++;
            first++;
        }
        // count ko firse 0 bnaya aur first ko bi 0 kiya
        for(int i=0;i<256;i++){
            count[i]=0;
        }
        first=0;
        
        while(second<str.size()){
            // first sbhi unique element window mein lene hai
            while(diff&&second<str.size()){
                if(count[str[second]]==0){
                    diff--;
                }
                count[str[second]]++;
                second++;
            }
            len = min(len,second-first);
            
            // abb left side mtlb start se decrease krna suru karenge, diff increase hoga 
            // aur count kam hoga
            // diff ki value 1 nhi banni chaiye
            while(diff!=1){
                len = min(len,second-first);
                count[str[first]]--;
                if(count[str[first]]==0){
                    diff++;
                }
                first++;
            }
        }
        return len;
    }
};