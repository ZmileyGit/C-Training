#include <stdio.h>

int main(){
    int chr;
    long lines, blanks, tabs;

    lines = 0;
    blanks = 0;
    tabs = 0;

    chr=getchar();
    while(chr != EOF){
        int out = chr;
        switch(chr){
            case '\n':
                ++lines;
            break;
            case ' ':
                ++blanks;
            break;
            case '\t':
                ++tabs;
            break;
        }
        if(chr == '\b' || chr == '\t' || chr == '\\'){
            putchar('\\');
        }
        switch(chr){
            case '\b':
                out = 'b';
            break;
            case '\t':
                out = 't';
            break;
            case '\\':
                out = '\\';
            break;
        }
        if(chr == ' '){
            while((chr=getchar()) == ' '){
                ++blanks;
            }
        }else{
            chr=getchar();
        }
        putchar(out);
    }

    printf("Found %ld lines, %ld spaces and %ld tabs.\n",lines,blanks,tabs);
}