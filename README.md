# shortC
shortC is a "programming language" for code golfing. Frequently-used C functions/keywords are shortened into capital letters.

Build the "interpreter": `make`.

Compile a shortC program: `./shortC <source >outc && gcc out.c`.

shortC automatically inserts closing quotes, closing double-quotes, final semicolon and closing curly-braces. It also auto-inserts a semicolon before each final closing curly-brace.

[Try it online!](https://tio.run/#shortC)

Here are the conversions that shortC currently performs:

 - `A` -> `int main(int argc, char **argv){`
 - `B` -> `int main(`
 - `C` -> `char `
 - `D` -> `#define `
 - `E` -> ` else `
 - `F` -> `if(`
 - `G` -> `getchar()`
 - `H` -> `switch(`
 - `J` -> `puts(`
 - `L` -> `long `
 - `M` -> `strcmp(`
 - `N` -> `stdin`
 - `O` -> `for(`
 - `P` -> `putchar(`
 - `Q` -> `gets(`
 - `R` -> `printf(`
 - `S` -> `strlen(`
 - `T` -> `return `
 - `U` -> `usleep(`
 - `W` -> `while(`
 - `X` -> `while(1){`
 - `Y` -> `fgets(`
 - `Z` -> `srand(time(0));`
 - `$` -> `system(`
 - `@` -> `argv`
 - `` ` `` -> `rand()`

Remaining characters:

 - `K`
 - `V`
 - `I` (implemented as `int`, but that's useless)
 - `\` (this will never be used in golfing)
 - `#` (`D` already does `#define`)
 - `_` (maybe. not an operator nor used in any standard library functions)
