class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oddSum = n * (2 * 1 + (n - 1) * 2) / 2;
        int evenSum = n * (2 * 2 + (n - 1) * 2) / 2;
        return __gcd(oddSum,evenSum);
    }
};