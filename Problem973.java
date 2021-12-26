import java.util.*;

class Problem973 {
    public int[][] kClosest(int[][] points, int k) {
        int[][] res = new int[k][2];
        List<int[]> list = new ArrayList<>();
        for (int i = 0; i < points.length; i++) 
            list.add(new int[]{dist(points[i][0], points[i][1]), i});
        Collections.sort(list, (a,b)->Integer.compare(a[0], b[0]));
        for (int i = 0; i < k; i++) 
            res[i] = points[list.get(i)[1]];
        return res;
    }
    public int dist(int x, int y){
        return x*x + y*y;
    }
}