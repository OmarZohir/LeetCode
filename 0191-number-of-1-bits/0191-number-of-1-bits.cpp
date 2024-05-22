class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n > 0){
            // ANDing the number with n-1 removes the most right-hand side one of the number
            n &= (n-1);
            
            count++;
        }
        return count;
    }
};