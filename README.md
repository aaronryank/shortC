# shortC
shortC is a "programming language" for code golfing. Frequently-used C functions/keywords are shortened into capital letters.

To build the encoder/decoder, type `make`.

To easily turn a C program into a shortC program, type `./convert <CSOURCEFILE.c >SHORTSOURCEFILE.sc`.

To compile a shortC program, type `./shortC <SHORTSOURCEFILE.sc >CSOURCEFILE.c && gcc CSOURCEFILE.c`.

Here are the conversions that shortC currently performs:

 - I <-> **i**nt
 - C <-> **c**har
 - V <-> **v**oid
 - E <-> **e**lse
 - F <-> i**f**
 - P <-> **p**utchar
 - R <-> p**r**intf
 - G <-> **g**etchar
 - O <-> f**o**r
 - W <-> **w**hile
 - H <-> switc**h**
 - M <-> strc**m**p
 - D <-> #**d**efine
