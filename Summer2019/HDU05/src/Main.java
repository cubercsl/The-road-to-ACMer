import java.math.BigInteger;
import java.util.Scanner;
import java.util.Vector;

public class Main {
    static int N = 2000;
    static int mod = 119 << 23 | 1;
    static long[] fac = new long[N];

    static void init() {
        fac[0] = 1;
        for (int i = 1; i < N; i++) {
            fac[i] = fac[i - 1] * i % mod;
        }
    }

    int[] changeRadix(BigInteger x) {
        int[] =new int[200000];
        BigInteger t = new BigInteger(x);
        while(t.compareTo(BigInteger.ZERO) > 0) {

        }
    }

    static long solve(BigInteger x) {
        
    }

    public static void main(String[] args) {
        init();
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        while (T-- > 0) {
            BigInteger l = in.nextBigInteger();
            BigInteger r = in.nextBigInteger();
            System.out.println((solve(r) - solve(l.subtract(BigInteger.ONE)) + mod) % mod);
        }
    }
}