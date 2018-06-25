import java.math.BigInteger;
import java.util.Scanner;

public class I {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        int kase = 0;
        String buf = cin.nextLine();
        while (T-- > 0) {
            ++kase;
            String s = cin.nextLine();
            System.out.println("Case #" + kase + ":");
            if (s.equals("10")) {
                System.out.println(2);
                System.out.println(8);
                System.out.println(2);
                continue;
            }
            BigInteger ans[] = new BigInteger[50];
            int cnt = 0;
            BigInteger S = new BigInteger(s);
            while (S.compareTo(BigInteger.TEN) == 1) {
                s = S.toString();
                int m = s.length();
                StringBuffer a = new StringBuffer(s.substring(0, (m + 1) / 2));
                StringBuffer b = new StringBuffer(s.substring(0, (m + 1) / 2));
                b.reverse();
                if ((m & 1) == 0) {
                    a.append(b);
                } else {
                    a.deleteCharAt(a.length() - 1);
                    a.append(b);
                }
                BigInteger A = new BigInteger(a.toString());
                if (A.compareTo(S) == 1) {
                    BigInteger B = new BigInteger(s.substring(0, (m + 1) / 2));
                    B = B.subtract(BigInteger.ONE);
                    StringBuffer c = new StringBuffer(B.toString());
                    StringBuffer d = new StringBuffer(B.toString());
                    d.reverse();
                    if ((m & 1) == 0) {
                        c.append(d);
                    } else {
                        c.deleteCharAt(c.length() - 1);
                        c.append(d);
                    }
                    A = new BigInteger(c.toString());
                }
                if (A.compareTo(BigInteger.ZERO) != 0)
                    ans[cnt++] = A;
                S = S.subtract(A);
            }
            if (S.compareTo(BigInteger.ZERO) != 0)
                ans[cnt++] = S;
            System.out.println(cnt);
            for (int i = 0; i < cnt; i++)
                System.out.println(ans[i]);
        }
    }
}