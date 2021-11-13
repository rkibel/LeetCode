class Problem739 {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] output = new int[temperatures.length];
        for (int i = 0; i < temperatures.length; i++){
            int counter = 0;
            int temp = temperatures[i];
            for (int j = i+1; j < temperatures.length; j++){
                if (j == temperatures.length-1 && temperatures[j] <= temp){
                    counter = 0;
                    break;
                }
                counter++;
                if (temperatures[j] > temp)
                    break;
            }
            output[i] = counter;
        }
        return output;
    }
}