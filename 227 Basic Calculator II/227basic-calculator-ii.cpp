class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        char op = '+';                 
        stack<long long> st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    st.push(num);
                } else if (op == '-') {
                    st.push(-num);
                } else if (op == '*') {
                    long long top = st.top(); st.pop();
                    st.push(top * num);
                } else if (op == '/') {
                    long long top = st.top(); st.pop();
                    st.push(top / num);   
                }
                op = c;
                num = 0;
            }
        }

        long long result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return (int)result;
    }
};
