import java.util.*;

class Problem84 {
    public int largestRectangleArea(int[] heights) {
        int len = heights.length;
        int[] left = new int[len];
        int[] right = new int[len];
        Stack<Integer> stack = new Stack<>();
        
        for (int i = 0; i < len; i++){
            if (stack.isEmpty()){
                stack.push(i);
                left[i] = 0;
            }
            else{
                while(!stack.isEmpty() && heights[stack.peek()] >= heights[i]) stack.pop();
                left[i] = stack.isEmpty() ? 0 : stack.peek()+1;
                stack.push(i);
            }
        }
        
        while (!stack.isEmpty()) stack.pop();
        
        for (int i = len-1; i >= 0; i--){
            if (stack.isEmpty()){
                stack.push(i);
                right[i] = len-1;
            }
            else{
                while (!stack.isEmpty() && heights[stack.peek()] >= heights[i]) stack.pop();
                right[i] = stack.isEmpty() ? len-1 : stack.peek()-1;
                stack.push(i);
            }
        }
        
        int maxArea = Integer.MIN_VALUE;
        for (int i = 0; i < len; i++){
            System.out.println("i = " + i + ": " + left[i] + " " + right[i]);
            maxArea = Math.max(maxArea, (right[i] - left[i] + 1) * heights[i]);
        }
        return maxArea;
    }
}