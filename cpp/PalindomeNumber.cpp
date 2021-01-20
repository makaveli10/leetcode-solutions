class Solution {
public:
    bool isPalindrome(int x) {
        if (x==0)
            return true;
        if ( x < 0)
            return false;
        long rev_num = 0;
        int num = x, remainder;
        while(num > 0){
            remainder = num % 10;
            rev_num = rev_num * 10 + remainder;
            num /= 10;
        }
        // cout << rev_num;
        return x==rev_num;
    }
};
