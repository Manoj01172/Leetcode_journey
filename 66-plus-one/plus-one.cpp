class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int carry =1;
      int size = digits.size()-1;
      while(carry&&size>=0){
        if(digits[size]+carry<=9){
            digits[size]+=carry;
            carry=0;
        }
        else{
            digits[size]=0;
            carry=1;
            size--;
        }
      }
      if(carry){
        digits.insert(digits.begin(), carry);
      }
      return digits;
    }
};