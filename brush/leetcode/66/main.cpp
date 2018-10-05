#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; --i) {
            int digit = digits[i];
            int result = (digit + carry) % 10;
            carry = (digit +  carry) / 10;
            digits[i] = result;
        }
        if(carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main() {}
