class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0;
        int j=numbers.size()-1;
        int x,y;
        while(i<j){
            if(numbers[i]+numbers[j]==target){
                x = i+1;
                y = j+1;
                break;
            }
            else if(numbers[i]+numbers[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        return {x,y};
    }
};