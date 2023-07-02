import java.util.*;

class Problem119 {
    public List<Integer> getRow(int rowIndex) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        res.add(new ArrayList<>(Arrays.asList(1)));
        for (int i = 1; i <= rowIndex; i++){
            List<Integer> prev = res.get(i-1);
            List<Integer> adder = new ArrayList<>();
            for (int j = 0; j < i+1; j++){
                int num = 0;
                if (j > 0) num += prev.get(j-1);
                if (j < i) num += prev.get(j);
                adder.add(num);
            }
            res.add(adder);
        }
        return res.get(rowIndex);
    }
}