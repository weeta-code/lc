class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        /*
        goal is to calculate the expression

        if we use a stack and push back the first example tokens we get this:
        stack = [-, 4, *, 3, +, 2, 1]

        if the top is an operand we know to look for two operands in front of us

        or what if we push things onto the stack, and once we get to an op
        we take whats on the stack as our operands?

        so like iterating thru tokens : stack = [1] then = [2,1] then tok = + so int tmp = 
        stack.top() then stack.pop() and then evaluate if tok == + then
        ans += tmp + stack.top() and we'll add a check after stack.pop() if stack.empty()
        then ans tok= tmp

        this iterates thru the whole thing i think?
        */

        stack<int> st;
        for (auto& tok : tokens) {
            if (tok != "+" && tok != "*" && tok != "/" && tok != "-") {
                st.push(stoi(tok));
                continue;
            }
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();

            switch (tok[0]) {
                case '+':
                    st.push(left + right);
                    break;
                case '-':
                    st.push(left - right);
                    break;
                case '*':
                    st.push(left * right);
                    
                    break;
                case '/':
                    st.push(left / right);
                    break;
            }
        }

        return st.top();
    }
};
