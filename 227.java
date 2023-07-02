import java.util.Stack;

class Problem227 {
    public int calculate(String s) {
        int num = 0;
        char op = '+';
        Stack<Integer> stack = new Stack<>();
        for(int i=0; i < s.length(); i++){
            char c = s.charAt(i);
            if(Character.isDigit(c)) num = (num * 10) + (c - '0');
            if (!Character.isDigit(c) && c != ' ' || i == s.length()-1){
                if(op == '+') stack.push(num);
                else if(op == '-') stack.push(-num);
                else if(op == '*') stack.push(stack.pop()*num);
                else if(op == '/') stack.push(stack.pop()/num);
                num = 0; 
                op = c;
            }
        }
        while(!stack.isEmpty()) num += stack.pop();
        return num;
    }
}