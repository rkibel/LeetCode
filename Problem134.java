public class Problem134 {
    public int canCompleteCircuit(int[] gas, int[] cost) {
        int tot = 0, curr = 0, index = 0;
        for (int i = 0; i < gas.length; i++){
            tot += gas[i]-cost[i];
            curr += gas[i]-cost[i];
            if (curr < 0){
                curr = 0;
                index = i+1;
            }
        }
        return (tot < 0) ? -1 : index;
    }
}
