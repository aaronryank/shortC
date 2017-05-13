# shortC
shortC is a "programming language" for code golfing. Frequently-used C functions/keywords are shortened into capital letters.

To build the encoder/decoder, type `make`.

To easily turn a C program into a shortC program, type `./convert <CSOURCEFILE.c >SHORTSOURCEFILE.sc`.

To compile a shortC program, type `./shortC <SHORTSOURCEFILE.sc >CSOURCEFILE.c && gcc CSOURCEFILE.c`.

Here are the conversions that shortC currently performs:

 - C <-> **c**har
 - D <-> #**d**efine
 - E <-> **e**lse
 - F <-> i**f**
 - G <-> **g**etchar
 - H <-> switc**h**
 - I <-> **i**nt
 - L <-> **l**ong
 - M <-> strc**m**p
 - O <-> f**o**r
 - P <-> **p**utchar
 - R <-> p**r**intf
 - U <-> **u**sleep
 - V <-> **v**oid
 - W <-> **w**hile
