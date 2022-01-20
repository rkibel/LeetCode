class Problem30 {
    public List<Integer> findSubstring(String s, String[] words) {
        int len = words[0].length();
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < words.length; i++){
            int index = 0;
            while(s.substring(index).indexOf(words[i]) != -1){
                index += s.substring(index).indexOf(words[i]);
                if (map.containsKey(index)) map.get(index).add(i);
                else map.put(index, new ArrayList<>(Arrays.asList(i)));
                index += len;
            }
        }
        System.out.println(map);

        
        int[] beg = new int[words.length + 2];
        Queue<int[]> q = new LinkedList<>();
        q.add(beg);
        List<Integer> res = new ArrayList<>();
        
        while(!q.isEmpty()){
            int[] curr = q.poll();
            boolean full = true;
            for (int j = 2; j < curr.length; j++){
                if (curr[j] == 0) full = false;
            }
            if (full) res.add(curr[0]);
            if (curr[1] < s.length() && map.containsKey(curr[1]+1)){
                int[] blank = new int[words.length+2];
                blank[0] = curr[1]+1;
                blank[1] = curr[1]+1;
                q.add(blank);
            }
            
            if (map.containsKey(curr[1])){
                for (Integer i: map.get(curr[1])){
                    if (curr[i+2] == 0){
                        int[] copy = curr.clone();
                        copy[i+2] = 1;
                        copy[1] += len;
                        q.add(copy);
                    }
                }
            }
        }        
        return res;
        
    }
}