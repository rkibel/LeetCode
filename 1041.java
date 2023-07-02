class Problem1041 {
    int[] coord = {0,0};
    int dir = 90, dist = 0;
    public boolean isRobotBounded(String instructions) {
        for (int i = 0; i < 4; i++) dist = Math.max(dist, loop(instructions));
        return loop(instructions) <= dist;
    }
    public int loop(String ins){
        for (int i = 0; i < ins.length(); i++){
            if (ins.charAt(i) == 'L') dir = (dir+90)%360;
            else if (ins.charAt(i) == 'R') dir = (dir+270)%360;
            else switch(dir){
                case 0: coord[0]++; break;
                case 90: coord[1]++; break;
                case 180: coord[0]--; break;
                case 270: coord[1]--; break;
                default: throw new ArithmeticException("direction not parseable");
            }
        }
        return coord[0]*coord[0] + coord[1]*coord[1];
    }
}