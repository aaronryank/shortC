#include <stdio.h>
#include <string.h>
#include <ctype.h>

int chr_eq(int c, char *s)
{
    int i, l = strlen(s);
    for (i = 0; i < l; i++)
        if (s[i] == c)
            return 1;

    return 0;
}

void parse_print(char *s)
{
    if (!strcmp(s, "int"))
        putchar('I');
    else if (!strcmp(s, "char"))
        putchar('C');
    else if (!strcmp(s, "void"))
        putchar('V');
    else if (!strcmp(s, "else"))
        putchar('E');
    else if (!strcmp(s, "if"))
        putchar('F');
    else if (!strcmp(s, "printf"))
        putchar('R');
    else if (!strcmp(s, "putchar"))
        putchar('P');
    else if (!strcmp(s, "getchar"))
        putchar('G');
    else if (!strcmp(s, "for"))
        putchar('O');
    else if (!strcmp(s, "while"))
        putchar('W');
    else if (!strcmp(s, "switch"))
        putchar('H');
    else if (!strcmp(s, "strcmp"))
        putchar('M');
    else if (!strcmp(s, "#define"))
        putchar('D');
    else
        printf("%s",s);
}

int main(void)
{
    char token[100] = {0};
    int i = 0, c = 0;

    while ((c = getchar()) != EOF) {
        if (isalnum(c) || c == '_' || c == '#' || c == '"' || c == '\'') {
            token[i++] = c;
        }
        else {
            i = 0;
            if (strlen(token))
                parse_print(token);
            putchar(c);
            memset(token,0,100);
        }
    }

    return 0;
}
