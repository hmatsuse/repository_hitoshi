#include<unistd.h>void p(char c){write(1,&c,1);}void r(int x,int y){int h;int w;h=0;while(h<y){w=0;while(w<x){if(w==0&&(h==0||h==y-1)||w==x-1&&(h==0||h==y-1))p('o');else if(w==0||w==x-1)p('|');else if (h==0||h==y-1)p('-');else p(' ');w++;}p('\n');h++;}}