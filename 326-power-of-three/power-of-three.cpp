class Solution {
public:
    bool powerOfThree(long long val, long long n) {
        if (val == n) return true;
        if (val > n) return false;

        if (val > LLONG_MAX / 3) return false;

        return powerOfThree(val * 3, n);
    }

    bool isPowerOfThree(long long n) {
        if (n <= 0) return false;
        
        return powerOfThree(1, n);
    }
};