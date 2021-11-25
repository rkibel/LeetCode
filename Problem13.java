class Solution {
    private int num = 0;
    public int romanToInt(String s) {
        if (s.equals(""))
            return num;
        char first = s.charAt(0);
        if (s.length() == 1)
            return num + translate(first);
        char second = s.charAt(1);
        if (first == 'I'){
            if (second == 'V'){
                num += 4;
                return romanToInt(s.substring(2));
            }
            else if (second == 'X'){
                num += 9;
                return romanToInt(s.substring(2));
            }
            else{
                num++;
                return romanToInt(s.substring(1));
            }
        }
        else if (first == 'X'){
            if (second == 'L'){
                num += 40;
                return romanToInt(s.substring(2));
            }
            else if (second == 'C'){
                num += 90;
                return romanToInt(s.substring(2));
            }
            else{
                num += 10;
                return romanToInt(s.substring(1));
            }
        }
        else if (first == 'C'){
            if (second == 'D'){
                num += 400;
                return romanToInt(s.substring(2));
            }
            else if (second == 'M'){
                num += 900;
                return romanToInt(s.substring(2));
            }
            else{
                num += 100;
                return romanToInt(s.substring(1));
            }
        }
        else{
            num += translate(first);
            return romanToInt(s.substring(1));
        }
    }
    public Integer translate(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return null;
        }
    }
}