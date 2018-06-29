import java.util.Scanner;
import java.math.BigDecimal;

public class B {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String s = cin.nextBigDecimal().stripTrailingZeros().toPlainString();
        System.out.println(s);
    }
}