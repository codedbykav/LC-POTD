class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // Helper function to check if a character is a vowel
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int n = words.size();
        vector<int> prefixSum(n, 0);

        // Compute the prefix sum array
        for (int i = 0; i < n; ++i) {
            bool startsWithVowel = isVowel(words[i][0]);
            bool endsWithVowel = isVowel(words[i].back());
            prefixSum[i] = (startsWithVowel && endsWithVowel) ? 1 : 0;
            if (i > 0) {
                prefixSum[i] += prefixSum[i - 1];
            }
        }

        // Answer the queries
        vector<int> result;
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            int count = prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0);
            result.push_back(count);
        }

        return result;
    }
};
