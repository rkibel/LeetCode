import java.util.*;
class Problem452 {
    public int findMinArrowShots(int[][] points) {
        if (points.length == 0) return 0;
        Arrays.sort(points, (a,b)->Integer.compare(a[1], b[1]));
        for (int[] point: points) System.out.println(Arrays.toString(point));
        
        int arrows = 1, last = points[0][1];
        for (int i = 1; i < points.length; i++){
            if (points[i][0] > last){
                arrows++;
                last = points[i][1];
            }
        }
        return arrows;
    }
}