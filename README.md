# shortC
shortC is a "programming language" for code golfing. Frequently-used C functions/keywords are shortened into capital letters.

Command to build the "interpreter": `make`.

Command to compile a shortC program: `./shortC <SHORTSOURCEFILE.sc >CSOURCEFILE.c && gcc CSOURCEFILE.c`.

shortC automatically inserts closing quotes, closing double-quotes, final semicolon and closing curly-braces. It also auto-inserts a semicolon before each final closing curly-brace.

Here are the conversions that shortC currently performs:

 - `A` -> `int main(int argc, char **argv){`
 - `C` -> `char `
 - `D` -> `#define `
 - `E` -> ` else `
 - `F` -> `if(`
 - `G` -> `getchar()`
 - `H` -> `switch(`
 - `I` -> `int `
 - `J` -> `puts(`
 - `L` -> `long `
 - `M` -> `strcmp(`
 - `O` -> `for(`
 - `P` -> `putchar(`
 - `Q` -> `gets(`
 - `R` -> `printf(`
 - `S` -> `strlen(`
 - `T` -> `return `
 - `U` -> `usleep(`
 - `W` -> `while(`
 - `X` -> `while(1){`
 - `$` -> `system(`

To suggest conversions, email rkcoder2002+shortC@gmail.com or ping me `@MDXF` on [PPCG SE](//codegolf.stackexchange.com).
