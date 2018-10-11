#include <stdio.h>

#define MY_CONSTANT 100

enum boolean {FALSE, TRUE};
enum escapes {
    BELL = '\a',
    BACKSPACE = '\b',
    TAB = '\t',
    NEWLINE = '\n',
    VTAB = '\v',
    RETURN = '\r'
};
enum behavior{
    ONE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE
};

long strlen(const char s[]);
short is_leap_year(int year);

int main(){
    int inty = 1234;
    long longy = 123456789L;
    unsigned int uinty = 1234U;
    unsigned long ulongy = 123456789UL;

    double doubly = 123.4;
    float floaty = 123.4F;
    long double ldoubly = 123456.789L;

    unsigned long uocty = 01765; //1013
    unsigned long uhexy = 0x45FE; //17918

    char bell = '\013';
    bell = '\xd';
    putchar(bell);

    char vtab = '\x7';
    vtab = '\007';
    putchar(vtab);

    char cons_expression[MY_CONSTANT + 1];

    "String constant";

    "String constant" " concatenation";

    const int number = 17;
}

short is_leap_year(int year){
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

long strlen(const char s[]){
    long count;
    for(count = 0;s[count] != '\0';++count);
    return count;
}