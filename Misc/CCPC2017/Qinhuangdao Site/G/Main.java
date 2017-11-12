import java.util.Scanner;
import java.math.BigInteger;

public class Main {
    private static Scanner cin;
    static BigInteger n, m;
    public static void main(String[] args) {
        cin =  new Scanner(System.in);
        int T;
        T = cin.nextInt();
        while((T--) > 0) {
            n = cin.nextBigInteger();
            m = cin.nextBigInteger();
            int len = 0;
            BigInteger tmp = n;
            while(tmp.compareTo(BigInteger.ZERO) != 0) {
                tmp = tmp.shiftRight(1);
                len++;
            }
            BigInteger ans = BigInteger.ZERO;
            for(int i = len - 1; i >= 0 && n.compareTo(BigInteger.ZERO) > 0; i--) {
                BigInteger cnt = BigInteger.ONE.shiftLeft(i);
                tmp = cnt.subtract(BigInteger.ONE).multiply(m);
                if (tmp.compareTo(n) < 0) {
                    n = n.subtract(cnt.multiply(m.min(n.divide(cnt))));
                    ans = ans.or(cnt);
                }
            }
            System.out.println(ans);
        }
    }
}
