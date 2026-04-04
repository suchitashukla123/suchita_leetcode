class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        unordered_map<string, vector<int>> memo;
        return solve(expression, memo);
    }

    vector<int> solve(string expr, unordered_map<string, vector<int>>& memo) {
        if (memo.count(expr))
            return memo[expr];

        vector<int> result;

        for (int i = 0; i < expr.size(); i++) {
            char op = expr[i];

            if (op == '+' || op == '-' || op == '*') {
                vector<int> left = solve(expr.substr(0, i), memo);
                vector<int> right = solve(expr.substr(i + 1), memo);

                for (int l : left) {
                    for (int r : right) {
                        if (op == '+')
                            result.push_back(l + r);
                        else if (op == '-')
                            result.push_back(l - r);
                        else if (op == '*')
                            result.push_back(l * r);
                    }
                }
            }
        }

        // Base case: no operator → it's a number
        if (result.empty()) {
            result.push_back(stoi(expr));
        }

        return memo[expr] = result;
    }
};
