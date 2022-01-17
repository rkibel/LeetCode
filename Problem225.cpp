#include <queue>
using namespace std;
class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
        q = queue<int>();
    }
    
    void push(int x) {
        queue<int> temp;
        temp.push(x);
        while(!q.empty()) temp.push(q.front()), q.pop();
        q = temp;
        temp = queue<int>();
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */