public class Problem67 {
    public String addBinary(String a, String b) {
        String longer = (a.length() > b.length()) ? a : b;
        String shorter = (a.length() <= b.length()) ? a : b;
        int diff = longer.length() - shorter.length();
        for (int i = 0; i < diff; i++)
            shorter = "0" + shorter;
        
        String res = "";
        int r = 0;
        for (int i = longer.length()-1; i >= 0; i--){
            int valA = longer.charAt(i)-48, valB = shorter.charAt(i)-48;
            switch (valA+valB+r){
                case 0: res = "0" + res; r = 0; break;
                case 1: res = "1" + res; r = 0; break;
                case 2: res = "0" + res; r = 1; break;
                case 3: res = "1" + res; r = 1; break;
                default: return "Error: binary strings not computable";
            }
        }
        if (r == 1) res = "1" + res;
        return res;
    }
}
