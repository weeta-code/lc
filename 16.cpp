#include <stack>

using namespace std;

class MinStack {
private:
  stack<int> cont;
  stack<int> minCont;

public:
    MinStack() {
    }
    
    void push(int val) {
      cont.push(val);

      if (minCont.empty() || minCont.top() > val) {
        minCont.push(val);
      }
    }
    
    void pop() {
      cont.pop();
    }
    
    int top() {
      return cont.top();
    }
    
    int getMin() {
      return minCont.top();
    }
};
