class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";

        string result = "1";
        
        for (int i = 2; i <= n; i++) {
            string temp = "";
            int count = 1;

            for (int j = 1; j < result.size(); j++) {
                if (result[j] == result[j - 1]) {
                    count++;  // same digit -> increment count
                } else {
                    temp += to_string(count) + result[j - 1];
                    count = 1;
                }
            }

            // append the last counted group
            temp += to_string(count) + result.back();

            result = temp;
        }

        return result;
    }
};
