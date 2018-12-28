#include <stdio.h>

static char days_per_month[2][12] = {
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}
};

void month_day(int year,int yearday,int *month,int *day);
int year_day(int year,int month,int day);

int main(){
    printf("%d\n",year_day(1988,2,29));
    printf("%d\n",year_day(1989,12,29));
    printf("%d\n",year_day(1988,3,1));
    printf("%d\n",year_day(1989,3,1));
    printf("%d\n",year_day(1989,30,1));
    printf("%d\n",year_day(1989,-3,1));
    printf("%d\n",year_day(1989,12,-1));
    printf("%d\n",year_day(1989,12,100));
    printf("%d\n",year_day(-1989,12,100));

    int day = -1,month = -1;
    month_day(1988,60,&month,&day);
    printf("%d/%d\n",month,day);
    month_day(1989,60,&month,&day);
    printf("%d/%d\n",month,day);
    month_day(1988,366,&month,&day);
    printf("%d/%d\n",month,day);
    month_day(1989,366,&month,&day);
    printf("%d/%d\n",month,day);
    month_day(-1989,366,&month,&day);
    printf("%d/%d\n",month,day);
    month_day(1989,-366,&month,&day);
    printf("%d/%d\n",month,day);
    return 0;
}

int year_day(int year,int month,int day){
    int leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if(year < 1 || month < 1 || month > 12 || day < 1 || day > days_per_month[leap][month - 1]){
        return -1;
    }
    for(int count = 0; count < (month - 1);++count){
        day += days_per_month[leap][count];
    }
    return day;
}

void month_day(int year,int yearday,int *month,int *day){
    int leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    if(year < 1 || yearday < 1 || leap && yearday > 366 || !leap && yearday > 365){
        *month = -1;
        *day = -1;
        return;
    }
    for(*month = 0; yearday > days_per_month[leap][*month];++(*month)){
        yearday-=days_per_month[leap][*month];
    }
    (*month)++;
    *day = yearday;
}
