import java.math.BigDecimal;
import java.util.*;

public class B {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        while (T-- > 0) {
            BigDecimal x1, y1, x2, y2, x3, y3, x, y;
            x1 = cin.nextBigDecimal();
            y1 = cin.nextBigDecimal();
            x2 = cin.nextBigDecimal();
            y2 = cin.nextBigDecimal();
            x3 = cin.nextBigDecimal();
            y3 = cin.nextBigDecimal();
            x = cin.nextBigDecimal();
            y = cin.nextBigDecimal();
            BigDecimal a = x1.subtract(x2);
            BigDecimal b = y1.subtract(y2);
            BigDecimal c = x1.subtract(x3);
            BigDecimal d = y1.subtract(y3);
            BigDecimal e = (x1.multiply(x1).subtract(x2.multiply(x2)).subtract(y2.multiply(y2)).add(y1.multiply(y1)))
                    .multiply(BigDecimal.valueOf(0.5));
            BigDecimal f = (x1.multiply(x1).subtract(x3.multiply(x3)).subtract(y3.multiply(y3)).add(y1.multiply(y1)))
                    .multiply(BigDecimal.valueOf(0.5));
            BigDecimal x0 = b.multiply(f).subtract(d.multiply(e)).divide(b.multiply(c).subtract(a.multiply(d)));
            BigDecimal y0 = c.multiply(e).subtract(a.multiply(f)).divide(b.multiply(c).subtract(a.multiply(d)));
            BigDecimal R_f = x1.subtract(x0).multiply(x1.subtract(x0)).add(y1.subtract(y0).multiply(y1.subtract(y0)));
            BigDecimal R_x = x.subtract(x0).multiply(x.subtract(x0)).add(y.subtract(y0).multiply(y.subtract(y0)));
            if (R_x.compareTo(R_f) == 1)
                System.out.println("Accepted");
            else
                System.out.println("Rejected");
        }
    }
}