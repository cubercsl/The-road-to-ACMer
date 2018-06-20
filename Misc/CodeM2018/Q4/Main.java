import java.util.*;
import java.math.BigDecimal;

/**
 * Main
 */
public class Main {
    private class P implements Comparable<P> {
        BigDecimal first;
        int second;

        public int compareTo(P o) {
            if (first.compareTo(o.first) == 0) {
                if (second < o.second)
                    return 1;
                return -1;
            }
            return first.compareTo(o.first);
        }

        P() {}

        P(BigDecimal x, int y) {
            this.first = x;
            this.second = y;
        }
    }

    final int round = 100;
    final BigDecimal eps =
            BigDecimal.valueOf(1).divide(BigDecimal.valueOf(Math.pow(10L, 15)), round, 5);

    int sgn(BigDecimal x) {
        if (x.abs().compareTo(eps) < 0)
            return 0;
        return 1;
    }

    void solve() {
        BigDecimal w[] = new BigDecimal[6];
        int n, m, k, c;
        int cpt[][] = new int[500][6];
        int missi = -1, missj = -1;
        int mxCpt[] = new int[6];
        BigDecimal score[] = new BigDecimal[500];
        BigDecimal missScore[] = new BigDecimal[500];
        int mark[] = new int[500];
        P SCORE[] = new P[500];
        int win[] = new int[500], lose[] = new int[500], unknown[] = new int[500];
        Arrays.fill(score, BigDecimal.ZERO);
        Arrays.fill(missScore, BigDecimal.ZERO);
        Arrays.fill(w, BigDecimal.ZERO);
        Scanner cin = new Scanner(System.in);
        n = cin.nextInt();
        m = cin.nextInt();
        k = cin.nextInt();
        c = cin.nextInt();
        BigDecimal wsm = BigDecimal.ZERO;
        for (int i = 0; i < m; i++) {
            w[i] = cin.nextBigDecimal();
            wsm = wsm.add(w[i]);
        }
        for (int i = 0; i < m; i++) {
            w[i] = w[i].divide(wsm, round, 5);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cpt[i][j] = cin.nextInt();
                if (cpt[i][j] == -1) {
                    missi = i;
                    missj = j;
                }
                mxCpt[j] = Math.max(mxCpt[j], cpt[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                if (j != missj) {
                    if (mxCpt[j] > 0)
                        score[i] = score[i].add(w[j].multiply(BigDecimal.valueOf(cpt[i][j])
                                .divide(BigDecimal.valueOf(mxCpt[j]), round, 5)));
                }
        }
        for (int miss = 0; miss <= c; miss++) {
            double mxs = Math.max(1.0 * mxCpt[missj], 1.0 * miss);
            cpt[missi][missj] = miss;
            for (int i = 0; i < n; i++) {
                if (mxs > 0) {
                    missScore[i] = w[missj].multiply(BigDecimal.valueOf(cpt[i][missj])
                            .divide(BigDecimal.valueOf(mxs), round, 5));
                } else
                    missScore[i] = BigDecimal.ZERO;
            }
            for (int i = 0; i < n; i++) {
                SCORE[i] = new P((score[i].add(missScore[i])).negate(), i);
            }
            Arrays.sort(SCORE, 0, n);
            if (k < n && sgn(SCORE[k - 1].first.add(SCORE[k].first.negate())) == 0) {
                BigDecimal scoreline = SCORE[k - 1].first;
                for (int i = 0; i < n; i++)
                    if (sgn(SCORE[i].first.add(scoreline.negate())) == 0) {
                        unknown[SCORE[i].second]++;
                    }
                for (int i = 0; i < k; i++)
                    if (sgn(SCORE[i].first.add(scoreline.negate())) != 0) {
                        win[SCORE[i].second]++;
                    }
                for (int i = k; i < n; i++)
                    if (sgn(SCORE[i].first.add(scoreline.negate())) != 0) {
                        lose[SCORE[i].second]++;
                    }

            } else {
                for (int i = 0; i < k; i++) {
                    win[SCORE[i].second]++;
                }
                for (int i = k; i < n; i++) {
                    lose[SCORE[i].second]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (unknown[i] > 0 || (win[i] > 0 && lose[i] > 0))
                mark[i] = 3;
            else if (win[i] > 0 && lose[i] == 0)
                mark[i] = 1;
            else if (win[i] == 0 && lose[i] > 0)
                mark[i] = 2;
        }
        for (int i = 0; i < n; i++) {
            System.out.println(mark[i]);
        }
        cin.close();
    }

    public static void main(String[] args) {
        new Main().solve();
    }

}
