#include <stdio.h>
#include <string.h>
#include <ctype.h>

#pragma GCC diagnostic ignored "-Wmissing-braces"

/* curly-braces, parenthesis, preprocessor */
int curly, parens, pre;

/* shortened codes */
struct { int c; char *s; } mapping[] = {
'A',"int main(int argc, char **argv){",
'B',"int main(",
'C'," char ",
'D',"#define ",
'E'," else ",
'F'," if(",
'G'," getchar()",
'H'," switch(",
'I'," int ",
'\\'," int (*f)() = \"",
'J'," puts(",
'K'," scanf(",
'L'," long ",
'M'," strcmp(",
'N'," stdin ",
'O'," for(",
'P'," putchar(",
'Q'," gets(",
'R'," printf(",
'S'," strlen(",
'T'," return ",
'U'," usleep(",
'V'," goto*&",
'W'," while(",
'X'," while(1){",
'Y'," fgets(",
'Z'," srand(time(0));",
'$'," system(",
'@'," argv ",
'`'," rand()",
'¡'," != ",
'«'," << ",
'»'," >> ",
'À'," char *a;",
'Á'," int a;",
'×',"*=",
'÷',"/=",
'Ç'," char*",
'ï',"++",
'­',"--",
'¿',"==",
'ÿ'," 42 ",
'µ'," int f(int n){",
'¸',"-=",
'±'," sign(",
'ì'," input()",
'¯'," prime(",
'í'," printf(\"%d\",",
'Ì',"-1 ",
'Í',"+1 ",
'æ',"\"abcdefghijklmnopqrstuvwxyz\"",
'Æ',"\"ABCDEFGHIJKLMNOPQRSTUVWXYZ\"",
'ð'," int i; for (i = 0; i <",
'Ã'," char *s=malloc(1024);memset(s,0,1024);",
'ß',"=strdup(\"",
'©',"\");",
'Þ'," int c;while((c = getchar())!=EOF){",
'Ø'," strcat(",
'¶'," fgets(s,1000,stdin);"
};

/* shortify */
int translate(char c)
{
    int i, match = 0;

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
             match++;
         }
    }

    return match;
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

int main(int argc, char **argv)
{
    if (argv[1] && strchr(argv[1],'h')) {
        printf("Usage: shortc -hn\n"                                 \
               "Flags:         h  | Display help and exit\n"         \
               "                n | No default functions\n"          \
               "short.c, copyright (c) 2017 MD XF Technologies\n");

        return 0;
    }

    if (!argv[1] || !strchr(argv[1],'n')) {
        puts("#include <math.h>\n#include <stdio.h>");
        puts("int sign(int x){return x < 0 ? -1 : x == 0 ? 0 : 1;}");
        puts("int prime(int x){if (x < 2) return 0; int ii; for (ii = sqrt(x); ii > 1; ii--) if (!(x % ii)) return 0; return 1;}");
        puts("int input(void){int x; scanf(\"%d\",&x); return x;}");
    }

    int c, prev, chr, str;
    c = prev = chr = str = curly = parens = pre = 0;
    while ((c = getchar()) != EOF)
    {
        /* if uppercase and not in a string/char, shortify */
        if (!str && !chr)
            if (translate(c))
                continue;
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
        if (c == '\n' && prev != '\\')
            pre = 0;

        /* print closing ' if not present */
        if (chr && prev != '\'' && c != '\'') {
            chr = 0;
            putchar('\'');
        }
        putchar(c);
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
