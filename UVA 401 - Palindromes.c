//WAWA大哭
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char mirror[36] = "A000300HIL0JM0O0002TUVMXY51SE0Z0080";
int main()
{
    char s[25];
    memset(s, '@', sizeof(s));
    int len = 0;

    while (gets(s))
    {
        while (s[len] != '\0')
            len++;
        bool pal = true;
        bool mir = true;

        for (int i = 0; i < len / 2; i++)
        {
            if (s[i] != s[len - 1 - i])
                pal = false;
            if (('A' <= s[len - 1 - i]) && (s[len - 1 - i] <= 'Z'))
            {
                if (s[i] != mirror[s[len - 1 - i] - 'A'])
                    mir = false;
            }
            else
            {
                if (s[i] != mirror[s[len - 1 - i] - '1' + 26])
                    mir = false;
            }
        }
        for (int i = 0; i < len; i++)
            printf("%c", s[i]);
        if (pal && mir)
            printf(" -- is a mirrored palindrome.\n\n");
        else if (pal)
            printf(" -- is a regular palindrome.\n\n");
        else if (mir)
            printf(" -- is a mirrored string.\n\n");
        else
            printf(" -- is not a palindrome.\n\n");
        memset(s, '@', sizeof(s));
        len = 0;
    }
    return 0;
}
