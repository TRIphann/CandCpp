#include <stdio.h >
void main() {
char * s;
s = ”chao cac ban”;
strcpy( & s[5], & s[9]);
printf(“ % s”, s);
};
