class Solution {
public:
    vector<string> result;

    void backtrack(string& num, int target, int pos,
                   long currValue, long prevValue,
                   string& expr) {

        if (pos == num.size()) {
            if (currValue == target)
                result.push_back(expr);
            return;
        }

        long number = 0;
        int len = expr.size();

        for (int i = pos; i < num.size(); i++) {

            if (i > pos && num[pos] == '0') break;

            number = number * 10 + (num[i] - '0');
            string part = num.substr(pos, i - pos + 1);

            if (pos == 0) {
                expr += part;
                backtrack(num, target, i + 1, number, number, expr);
                expr.resize(len);
            } 
            else {
                // +
                expr += "+" + part;
                backtrack(num, target, i + 1,
                          currValue + number,
                          number, expr);
                expr.resize(len);

                // -
                expr += "-" + part;
                backtrack(num, target, i + 1,
                          currValue - number,
                          -number, expr);
                expr.resize(len);

                // *
                expr += "*" + part;
                backtrack(num, target, i + 1,
                          currValue - prevValue + prevValue * number,
                          prevValue * number, expr);
                expr.resize(len);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        result.clear();
        string expr;
        backtrack(num, target, 0, 0, 0, expr);
        return result;
    }
};

