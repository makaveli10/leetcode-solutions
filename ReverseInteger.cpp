class Solution {
public:
    int reverse(int x) {
        std::vector<int> num;
        while(x != 0){
            num.push_back(x % 10);
            x /= 10;
        }
        long long int result = 0;
        long long int mul = pow(10, (int)num.size()-1);
        // std::cout << mul << std::endl;
        for (size_t i = 0; i < num.size(); i++){
            if (i==0 && num[i]==0){
                mul /= 10;
                continue;
            }
            result += (mul * num[i]);
            // std::cout << result << std::endl;
            mul /= 10;
        }
        int min = -pow(2, 31);
        int max = pow(2, 31) - 1;
        if (result < min || result > max)
            return 0;
        return result;
    }
};
