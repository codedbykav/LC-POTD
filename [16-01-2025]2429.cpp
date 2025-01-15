class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0, minXor = 0;

        // Step 1: Count set bits in num2
        for (int i = 0; i < 32; i++) {
            if ((1 << i) & num2) cnt++;
        }

        // Step 2: Align higher bits of num1 with minXor
        for (int i = 31; i >= 0; i--) {
            if (cnt <= 0) break;
            if ((1 << i) & num1) {
                minXor |= (1 << i); // Set bit in minXor
                cnt--;
            }
        }

        // Step 3: Set remaining bits in minXor (minimal value)
        for (int i = 0; i < 32; i++) {
            if (cnt <= 0) break;
            if ((minXor & (1 << i)) == 0) { // If bit is not set
                minXor |= (1 << i); // Set bit in minXor
                cnt--;
            }
        }

        return minXor;
    }
};
