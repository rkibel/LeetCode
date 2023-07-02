public class Problem476 {
    public int findComplement(int num) {
        int x = num, y = 0;
        while(x != 0){
            x >>= 1;
            y <<= 1;
            y++;
        }
        return y ^ num;
        /*
        ***one-liner using complement
        return ~num & (Integer.highestOneBit(num)-1);
        */
    }
}
