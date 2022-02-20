class Problem1288 {
    public int removeCoveredIntervals(int[][] inter) {
        Arrays.sort(inter, new Comparator<int[]>() {
        public int compare(int[] o1, int[] o2) {
            if (o1[0] != o2[0]) return Integer.compare(o1[0], o2[0]);
            return Integer.compare(o1[1], o2[1]);
        }
        });
        int x = inter[0][0], y = inter[0][1], counter = 1;
        for (int i = 1; i < inter.length; i++){
            if (inter[i][0] > x && inter[i][1] > y) counter++;
            if (inter[i][1] > y){
                x = inter[i][0];
                y = inter[i][1];
            }
        }
        return counter;
    }
}