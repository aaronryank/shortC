#include <stdio.h>
#include <string.h>
#include <ctype.h>

void parse_print(char *s);

int chr_eq(int c, char *s)
{
    int i, l = strlen(s);
    for (i = 0; i < l; i++)
        if (s[i] == c)
            return 1;

    return 0;
}

#ifdef DECODE
void parse_print(char *s)
{
    if (!strcmp(s, "I"))
        printf("int");
    else if (!strcmp(s, "C"))
        printf("char");
    else if (!strcmp(s, "V"))
        printf("void");
    else if (!strcmp(s, "E"))
        printf("else");
    else if (!strcmp(s, "F"))
        printf("if");
    else if (!strcmp(s, "R"))
        printf("printf");
    else if (!strcmp(s, "P"))
        printf("putchar");
    else if (!strcmp(s, "G"))
        printf("getchar");
    else if (!strcmp(s, "O"))
        printf("for");
    else if (!strcmp(s, "W"))
        printf("while");
    else if (!strcmp(s, "H"))
        printf("switch");
    else if (!strcmp(s, "M"))
        printf("strcmp");
    else if (!strcmp(s, "D"))
        printf("#define");
    else if (!strcmp(s, "U"))
        printf("usleep");
    else if (!strcmp(s, "L"))
        printf("long");
    else if (!strcmp(s, "S"))
        printf("strlen");
    else if (!strcmp(s, "T"))
        printf("return");
    else if (!strcmp(s, "Q"))
        printf("gets");
    else if (!strcmp(s, "A"))
        printf("main");
    else
        printf("%s",s);
}
#endif

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


#ifdef ENCODE
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
    else if (!strcmp(s, "usleep"))
        putchar('U');
    else if (!strcmp(s, "long"))
        putchar('L');
    else if (!strcmp(s, "strlen"))
        putchar('S');
    else if (!strcmp(s, "return"))
        putchar('T');
    else if (!strcmp(s, "gets"))
        putchar('Q');
    else if (!strcmp(s, "main"))
        putchar('A');
    else
        printf("%s",s);
}
#endif
