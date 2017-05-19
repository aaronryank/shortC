#include <stdio.h>
#include <string.h>

int curly, parens;

struct {
    char c, *s;
} mapping[] = {
'A',"int main(int argc, char **argv){",
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
'O',"for(",
'P',"putchar(",
'Q',"gets(",
'R',"printf(",
'S',"strlen(",
'T',"return ",
'U',"usleep(",
'W',"while(",
'X',"while(1){"
};

void translate(char c)
{
    int i;
    for (i = 0; mapping[i].s; i++) {
         if (mapping[i].c == c) {
             printf("%s",mapping[i].s);
             if (strchr(mapping[i].s,'{'))
                 curly++;
             else if (strchr(mapping[i].s,'}'))
                 curly--;
             else if (strchr(mapping[i].s,'('))
                 parens++;
             else if (strchr(mapping[i].s,')'))
                 parens--;
         }
    }
}

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
    c = prev = chr = str = curly = parens = 0;
    while ((c = getchar()) != EOF)
    {
        if (isupper(c) && !str && !chr)
            translate(c);
        else {
            if (c == '"' && prev != '\\' && !chr)
                str = !str;
            else if (c == '\'' && prev != '\\' && !str)
                chr = !chr;
            else if (c == '(')
                parens++;
            else if (c == ')')
                parens--;
            else if (c == '{')
                curly++;
            else if (c == '}')
                autoclose();

            if (c != '\n')
               putchar(c);
        }
        prev = c;
    }

    if (chr)
        putchar('\'');
    else if (str)
        putchar('\"');

    if (curly > 0)
        while (curly)
            autoclose(), putchar('}');
}
