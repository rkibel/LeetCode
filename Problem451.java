public class Problem451 {
    public static void main (String[]args){
        String n = "tree";
        System.out.println(frequencySort(n));

    }
    public static String frequencySort (String s){
        int maxCount = 0;
        char max = ' ';
        int currCount = 0;
        char curr = ' ';
        String output = "";
        while (s.length() > 0){
            for (int i = 0; i < s.length(); i++){
                curr = s.charAt(i);
                
                for (int j = 0; j < s.length(); j++){
                    if (s.charAt(j) == curr)
                        currCount++; 
                }
                
                if (currCount > maxCount){
                    max = curr;
                    maxCount = currCount;
                }   
            }
            System.out.println(max + " " + maxCount);
            for (int x = 0; x < maxCount; x++)
                output += Character.toString(max);
            maxCount = 0;
            currCount = 0;
            for (int x = 0; x < s.length(); x++){
                if (s.charAt(x) == max){
                    if (x == 0)
                        s = s.substring(1);
                    else if (x == s.length()-1)
                        s = s.substring(0, x);
                    else
                        s = s.substring(0, x) + s.substring(x+1);
                }
            }
            System.out.println(s);
        }
        return output;
    }
}
