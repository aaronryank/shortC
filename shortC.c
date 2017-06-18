#include <stdio.h>
#include <string.h>
#include <ctype.h>

#pragma GCC diagnostic ignored "-Wmissing-braces"

/* curly-braces, parenthesis, preprocessor */
int curly, parens, pre;

/* shortened codes */
struct { char c, *s; } mapping[] = {
'A',"int main(int argc, char **argv){",
'B',"int main(",
'C',"char ",
'D',"#define ",
'E'," else ",
'F',"if(",
'G',"getchar()",
'H',"switch(",
'J',"puts(",
'I',"int ",
'L',"long ",
'M',"strcmp(",
'N',"stdin",
'O',"for(",
'P',"putchar(",
'Q',"gets(",
'R',"printf(",
'S',"strlen(",
'T',"return ",
'U',"usleep(",
'W',"while(",
'X',"while(1){",
'Y',"fgets(",
'Z',"srand(time(0));",
'$',"system(",
'@',"argv",
'`',"rand()",
};

/* shortify */
void translate(char c)
{
    int i;
    for (i = 0; mapping[i].s; i++) {
         if (mapping[i].c == c) {
             printf("%s",mapping[i].s);
             if (strchr(mapping[i].s,'{'))
                 curly++;
             if (strchr(mapping[i].s,'}'))
                 curly--;
             if (strchr(mapping[i].s,'('))
                 parens++;
             if (strchr(mapping[i].s,')'))
                 parens--;
             if (strchr(mapping[i].s,'#'))
                 pre = 1;
         }
    }
}

/* auto-insert parenthesis and semicolons */
void autoclose(void)
{
    if (parens > 0)
        while (parens--)
            putchar(')');

    if (!--curly)
        putchar(';');
}

int main(void)
{
    int c, prev, chr, str;
    c = prev = chr = str = curly = parens = pre = 0;
    while ((c = getchar()) != EOF)
    {
        /* if uppercase and not in a string/char, shortify */
        if ((isupper(c) || c == '@' || c == '$' || c == '`') && !str && !chr)
            translate(c);
        else {
            /* swap char/string flags */
            if (c == '"' && prev != '\\' && !chr)
                str = !str;
            else if (c == '\'' && prev != '\\' && !str)
                chr = !chr;
            else if (c == '(' && !chr && !str)
                parens++;
            else if (c == ')' && !chr && !str)
                parens--;
            else if (c == '{' && !chr && !str)
                curly++;
            else if (c == '}' && !chr && !str)
                autoclose();

            /* print newline and swap preprocessor flag if preprocessor flag is 1 */
            if (c == '\n') {
                if (pre) {
                    pre = 0;
                    putchar(c);
                }
            }
            else
                putchar(c);
        }
        prev = c;
    }

    /* close quotes */
    if (chr)
        putchar('\'');
    else if (str)
        putchar('\"');

    /* close braces and auto-insert remaining characters */
    if (curly > 0)
        while (curly)  /* autoclose decrements curly */
            autoclose(), putchar('}');

    /* prettiness */
    putchar('\n');

    return 0;
}
