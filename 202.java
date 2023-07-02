import java.util.*;

class Problem202 {
    List<Integer> list = new ArrayList<>();
    public boolean isHappy(int n) {
        if (list.contains(n)) return false;
        if (n == 1) return true;
        list.add(n);
        int num = 0;
        while (n != 0){
            num += (n%10)*(n%10);
            n /= 10;
        }
        return isHappy(num);
    }
}