//WA但不知道為什麼

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
char st[105][125], out[105][125];
char stnum[105][125], outnum[105][125];
int main()
{
    int x = 0, line = 0, lineout = 0;

    while (1)
    {
        scanf("%d", &line);
        getchar();
        if (line == 0) return 0;

        x++;
        printf("Run #%d: ", x);
        memset(st, '@', sizeof(st));
        memset(out, '@', sizeof(out));
        
        for (int i = 0, j, numidx; i < line; i++)
        {
            fgets(st[i], 125, stdin);

            j = 0;
            numidx = 0;
            while (st[i][j] != '@')
            {
                if ('0' <= st[i][j] && st[i][j] <= '9')
                {
                    stnum[i][numidx] = st[i][j];
                    numidx++;
                }
                j++;
            }
        }

        scanf("%d", &lineout);
        getchar();
        if (line != lineout)
        {
            printf("Wrong Answer\n");
            return 0;
        }

        for (int i = 0, j, numidx; i < line; i++)
        {
            fgets(out[i], 125, stdin);
            j = 0;
            numidx = 0;
            while (out[i][j] != '@')
            {
                if ('0' <= out[i][j] && out[i][j] <= '9')
                {
                    outnum[i][numidx] = out[i][j];
                    numidx++;
                }
                j++;
            }
        }

        bool AC = true, PE = true;
        for (int i = 0; i < line; i++)
        {
            if (strcmp(out[i] , st[i]) == 0)
                continue;
            else
            {
                AC = false;

                if (strcmp(outnum[i], stnum[i])) PE = false;
            }
        }
        if (AC)
            printf("Accepted\n");
        else if (PE)
            printf("Presentation Error\n");
        else
            printf("Wrong Answer\n");
    }
    return 0;
}
