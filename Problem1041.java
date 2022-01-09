class Problem1041 {
    public boolean isRobotBounded(String ins) {
        double dist = 0;
        Pair<int[], Integer> pair = new Pair<>(new int[]{0,0}, 90);
        for (int i = 0; i < 4; i++){
            pair = getCoord(ins, pair.getKey(), pair.getValue());
            dist = Math.max(dist, getDist(pair.getKey()));
        }
        return getDist(getCoord(ins, pair.getKey(), pair.getValue()).getKey()) <= dist;
    }
    public Pair<int[], Integer> getCoord(String ins, int[] coord, int dir){
        for (int i = 0; i < ins.length(); i++){
            if (ins.charAt(i) == 'L') dir = (dir + 90)%360;
            else if (ins.charAt(i) == 'R') dir = (dir+270)%360;
            else{
                switch(dir){
                    case 0: coord[0]++; break;
                    case 90: coord[1]++; break;
                    case 180: coord[0]--; break;
                    case 270: coord[1]--; break;
                }
            }
        }
        return new Pair<>(coord, dir);
    }
    public double getDist(int[]coord){
        return Math.sqrt(coord[0]*coord[0] + coord[1]*coord[1]);
    }
}