class Solution {
public:
    bool parseBoolExpr(string str) {

        stack<char> s1; 
        stack<char> s2; 

        for (char ch : str) {

            if (ch == 't' || ch == 'f') {
                s1.push(ch);  
            } 
            else if (ch == '!' || ch == '|' || ch == '&') {
                s2.push(ch);  
            } 
            else if (ch == '(') {
                s1.push(ch);  
            } 
            else if (ch == ')') {
                char curOperator = s2.top();
                s2.pop();

                vector<char> operands;

                while (!s1.empty() && s1.top() != '(') {
                    operands.push_back(s1.top());
                    s1.pop();
                }

                s1.pop();

                if (curOperator == '!') {
                    char p = operands[0];
                    s1.push(p == 't' ? 'f' : 't');

                } else if (curOperator == '&') {
                    bool result = true;
                    for (char c : operands) {
                        if (c == 'f') {
                            result = false;
                            break;
                        }
                    }
                    s1.push(result ? 't' : 'f');

                } else if (curOperator == '|') {
                    bool result = false;
                    for (char c : operands) {
                        if (c == 't') {
                            result = true;
                            break;
                        }
                    }
                    s1.push(result ? 't' : 'f');
                }
            }
        }

        return s1.top()=='t';
    }
};
