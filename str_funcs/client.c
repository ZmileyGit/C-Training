#include <stdio.h>
#include "str.h"

#define BUFFER_SIZE 100

int main(){
    char host[BUFFER_SIZE] = "Hola ";
    char guest[] = "Mundo";
    printf("Host: '%s'\nGuest: '%s'\n",host,guest);
    strcat_n(host,guest);
    printf("Host: '%s'\nGuest: '%s'\n",host,guest);
    printf("Answer: %d\n",strend_n(host,guest));
    printf("Answer: %d\n",strend_n(host,"do"));
    printf("Answer: %d\n",strend_n("Lucina","cina"));
    char fe[]="Lucina, Marth, Chrom & Roy";
    printf("Host: '%s'\nGuest: '%s'\n",strcpy_limit(host,fe,7),fe);
    printf("Host: '%s'\nGuest: '%s'\n",strcpy_limit(host,fe,100),fe);
    printf("Host: '%s'\nGuest: '%s'\n",strcat_limit(host,fe,10),fe);
    printf("Host: '%s'\nGuest: '%s'\n",strcat_limit(host,fe,100),fe);
    printf("Answer: %d\n",strcmp_limit(host,fe,10));
    printf("Answer: %d\n",strcmp_limit(host,fe,100));
    printf("Answer: %d\n",strcmp_limit(fe,host,100));
    return 0;
}