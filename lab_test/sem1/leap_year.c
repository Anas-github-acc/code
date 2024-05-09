//Given current date and day find five 5 current 'future friday 13'.
//Input format : 13 3 2018 m == dd mm yy day
//remember for sunday it should be x
#include<stdio.h>
int day31_method(int mm){
    int day31;
    if(mm<8){
        if(mm%2 == 1)
            day31 = 31;
        else
            day31 = 30;
    }else{
        if(mm%2 == 0)
            day31 = 31;
        else
            day31 = 30;
    }
    return day31;
}
int day31_method(int mm );

int main(){
    int dd = 18, mm = 12, yy = 2023;
    char day = 'm'; // for thursday = k & for sunday = x
    char day_known[] = {'m', 't', 'w', 'k', 'f', 's' , 'x'};
    for(int i=0;i<7;++i){
        if(day_known[i] == day){
            (int) day;
            day = i+1;
            break;
        }
    }
    int day31;
    day31 = day31_method(mm);
    int occ = 0;
    while(1){
        dd+=1;
        day+=1;
        if(day > 7){day = 1;}
        if(dd > day31){
            dd = 1;
            mm+=1;
            if(mm > 12){
                mm = 1;
                yy+=1;
            }
            if(mm == 2){
                if(yy%4 == 0)
                    day31 = 29;
                else
                    day31 = 28;
            }
            else{
                day31 = day31_method(mm);
            }
        }
        if( dd == 13 && day == 5 ){
            occ++;
            printf("%d %d %d [ day%d ] is", dd, mm, yy, day);
            yy%4 == 0 ? printf(" a leap year ") : printf(" not a leap year ");
            printf("\n");
            if(occ > 5)
                return 0;
        }
    }
    return 0;
}