class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            int j = i+1;
            while(j<arr.size()){
                if(arr[j]==2*arr[i]||arr[i]==2*arr[j]){
                    return 1;
                }
                j++;
            }
        }
        return 0;
    }
};