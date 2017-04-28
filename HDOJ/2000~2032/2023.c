#include <stdio.h>

int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        int a[50][5];
        double student[50];
        double subject[5];
        int sum;
        //数据输入
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);

        //学生平均
        for (int i = 0; i < n; i++)
        {
            sum = 0;
            for (int j = 0; j < m; j++)
                sum += a[i][j];
            student[i] = sum * 1.0 / m;
        }

        //各科平均
        for (int j = 0; j < m; j++)
        {
            sum = 0;
            for (int i = 0; i < n; i++)
                sum += a[i][j];
            subject[j] = sum * 1.0 / n;
        }

        for (int i = 0; i < n - 1; i++)
            printf("%.2f ", student[i]);
        printf("%.2f\n", student[n - 1]);
        for (int i = 0; i < m - 1; i++)
            printf("%.2f ", subject[i]);
        printf("%.2f\n", subject[m - 1]);

        //统计人数
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int flag = 1;
            for (int j = 0; j < m; j++)
                if (a[i][j] * 1.0 < subject[j])
                {
                    flag = 0;
                    break;
                }
            if (flag)
                count++;
        }
        printf("%d\n\n", count);
    }
    return 0;
}
