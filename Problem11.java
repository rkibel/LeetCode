public class Problem11 {
    public int maxArea(int[] height) {
        int m = 0;
        int lefter = 0;
        for (int i = 0; i < height.length; i++){
            if (lefter >= height[i]) continue;
            lefter = height[i];
            for (int j = i+1; j < height.length; j++)
                m = Math.max(m, Math.min(lefter, height[j])*(j-i));
        }
        return m;
    }
}
