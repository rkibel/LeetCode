class Problem258 {
public:
    int addDigits(int num) {
        int n = 0;
        while(num) n += (num % 10), num /= 10;
        return (n > 9) ? addDigits(n) : n;
    }
};