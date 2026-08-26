class Solution {
public:
    bool isValid(string s) {
      stack<int> st;
      for (auto& ch: s) {
        if (ch == '}') {
          if (st.top() != '{') return false;
          st.pop();
        } else if (ch == ')') {
          if (st.top() != '(') return false;
          st.pop();
        } else if (ch == ']') {
          if (st.top() != '[') return false;
          st.pop();
        }
        st.push(ch);
      }
      if (!st.empty()) {
        return false;
      }
      return true;
    }
};
