#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

#define TO_INT(c) (c - '0')

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int a_ind = 0, b_ind = 0;
        int carry = 0;
        while(a_ind < a.size() && b_ind < b.size()) {
            int digit = (TO_INT(a[a_ind]) + TO_INT(b[b_ind]) + carry) % 2;
            carry = (TO_INT(a[a_ind]) + TO_INT(b[b_ind]) + carry) / 2;
            result += to_string(digit);
            a_ind++;b_ind++;
        }
        while(a_ind == a.size() && b_ind < b.size()) {
            int digit = (TO_INT(b[b_ind]) + carry) % 2;
            carry = (TO_INT(b[b_ind]) + carry) / 2;
            result += to_string(digit);
            b_ind++;
        }
        while(b_ind == b.size() && a_ind < a.size()) {
            int digit = (TO_INT(a[a_ind]) + carry) % 2;
            carry = (TO_INT(a[a_ind]) + carry) / 2;
            result += to_string(digit);
            a_ind++;
        }
        if(carry)
            result += "1";
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    string a = "1011";
    string b = "1010";
    cout << Solution().addBinary(a, b);
}
