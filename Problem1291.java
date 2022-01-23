import java.util.*;
class Problem1291 {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> digits = new ArrayList<>();
        for (int i = Integer.toString(low).length(); i <= Integer.toString(high).length(); i++){
            for (int j = 1; j <= 10-i; j++){
                int num = 0;
                for (int t = j; t < i+j; t++){
                    num *= 10;
                    num += t;
                }
                if (num > high) return digits;
                if (num >= low) digits.add(num);
            }
        }
        return digits;
    }
}