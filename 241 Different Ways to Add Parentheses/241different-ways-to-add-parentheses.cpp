class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        if (memo.count(expression)) 
            return memo[expression];

        vector<int> results;

        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];

            if (c == '+' || c == '-' || c == '*') {
              
                string leftExpr = expression.substr(0, i);
                string rightExpr = expression.substr(i + 1);

                vector<int> leftResults = diffWaysToCompute(leftExpr);
                vector<int> rightResults = diffWaysToCompute(rightExpr);

                for (int l : leftResults) {
                    for (int r : rightResults) {
                        if (c == '+') results.push_back(l + r);
                        else if (c == '-') results.push_back(l - r);
                        else if (c == '*') results.push_back(l * r);
                    }
                }
            }
        }

        if (results.empty()) {
            results.push_back(stoi(expression));
        }

        memo[expression] = results;
        return results;
    }
};
