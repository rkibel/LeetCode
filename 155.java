import java.util.Stack;
public class Problem155 {
    Stack<Integer> s;
    Stack<Integer> min;
    public Problem155() {
    s = new Stack<>();
    min = new Stack<>();
    }
    
    public void push(int val) {
        s.push(val);
        if (min.size() == 0 || (min.size() > 0 && min.peek() > val))
            min.push(val);
        else
            min.push(min.peek());
    }
    
    public void pop() {
        s.pop();
        min.pop();
    }
    
    public int top() {
        return s.peek();
    }
    
    public int getMin() {
        return min.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */