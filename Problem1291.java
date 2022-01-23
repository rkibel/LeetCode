import java.util.*;

class Problem1291 {
    public List<Integer> sequentialDigits(int low, int high) {
        List<Integer> digits = new ArrayList<>();
        String LOW = Integer.toString(low);
        String HIGH = Integer.toString(high);
        for (int i = LOW.length(); i <= HIGH.length(); i++){
            for (int j = 1; j <= 10-i; j++){
                int dig = createDigit(j, i);
                if (dig > high) return digits;
                if (dig >= low) digits.add(dig);
            }
        }
        return digits;
    }
    public int createDigit(int first, int len){
        String s = "";
        for (int i = first; i < len+first; i++) s += i;
        return Integer.parseInt(s);
    }
}