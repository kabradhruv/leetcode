#include <stdio.h>

int romanToInt(char * s){
    int res = 0;//for storing result
    while (*s)
    {
        if(*s=='I' && (*(s+1)=='V' || *(s+1)=='X')){
            res+=*(s+1)=='V'?4:9;
            s++;}
        else if(*s=='X' && (*(s+1)=='L' || *(s+1)=='C')){
            res+=*(s+1)=='L'?40:90;
            s++;}
        else if(*s=='C' && (*(s+1)=='D' || *(s+1)=='M')){
            res+=*(s+1)=='D'?400:900;
            s++;}
        else if(*s=='I'){res+=1;}
        else if(*s=='V'){res+=5;}
        else if(*s=='X'){res+=10;}
        else if(*s=='L'){res+=50;}
        else if(*s=='C'){res+=100;}
        else if(*s=='D'){res+=500;}
        else if(*s=='M'){res+=1000;}
        s++;
    }
    return res;
}

int main()
{
    char *s="XCIII";
    printf("result is = %d\n",romanToInt(s));

 return 0;
}
