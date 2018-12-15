#include <stdio.h>

void strcat_n(char *host,char *guest){
    for(;*host;host++);
    for(;*guest;guest++,host++){
        *host = *guest;
    }
    *host = '\0';
}

short strend_n(char *str,char *end){
    int str_len, end_len;
    str_len = 0;
    end_len = 0;
    for(;*str;str++,str_len++);
    for(;*end;end++,end_len++);
    for(;str_len >= 0 && end_len >= 0 && *str == *end;str--,str_len--,end--,end_len--);
    return end_len < 0;
}

char *strcpy_limit(char *host,char *guest,int amount){
    char *init = host;
    for(int count = 0;count < amount && *guest;++count,++guest,++host)
        *host = *guest;
    *host = '\0';
    return init;
}

char *strcat_limit(char *host,char *guest,int amount){
    char *init = host;
    for(;*host;*host++);
    for(int count = 0;count < amount && *guest;++count,++guest,++host)
        *host = *guest;
    *host = '\0';
    return init;
}

short strcmp_limit(char *left,char* right,int amount){
    int count;
    for(count = 0;count < amount && *right && *left;++count,++right,++left){
        if(*left != *right){
            return 0;
        }
    }
    return count == amount || !*right;
}