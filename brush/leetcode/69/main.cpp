class Solution {
public:
    int sqrt(int x) {
        if(x < 0) throw "assume input non negative";
        if(x == 0) return 0; // fast path
        if(x < 4) return 1; // fast path
        if(x == 4) return 2; // fast path
        int low = 1;
        int high = x >> 1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(x / mid == mid) return mid;
            else if(x / mid < mid) high = mid - 1;
            else low = mid + 1;
        }
        return high;
    }
};

int main() {}
