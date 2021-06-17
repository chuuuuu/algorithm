// 1 + 1 = 10
// 1 + 0 =  1
// 0 + 0 =  0

// 11 + 01 = 100
// 10 + 10
// 100

class Solution {
public:
    int getSum(int a, int b) {
        int x = a ^ b;
        int y = (a & b);
        if((y & 1<<31) == 1<<31){
            y ^= 1<<31;
        }
        y = y << 1;


        while(y!=0){
            int t = x;
            x = t ^ y;
            y = t & y;
            if((y & 1<<31) == 1<<31){
                y ^= 1<<31;
            }
            y = y << 1;
        }
        
        return x;
    }
};