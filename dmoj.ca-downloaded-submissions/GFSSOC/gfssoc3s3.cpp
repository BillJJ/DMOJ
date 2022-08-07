//user d code lmao testing this wack ass lag
#include <stdio.h>

char a,b,c;
int n, out=1;

int main()
{
    //freopen("data.txt","r",stdin);
    a=getchar();
    b=getchar();
    c=getchar();
    if ((b<'0')||(c<'0')) {
        if (b>='0') n=(a-48)*10+b-48;
        else n=a-48;
        if (n>=18) printf("999999998");
        else if (n&1) {
            n/=2;
            for (int i=0; i<n; i++) out*=10;
            out*=11;
            out+=999999998;
            printf("%d",out%1000000000);
        }
        else {
            n/=2;
            for (int i=0; i<n; i++) out*=10;
            out*=2;
            out+=999999998;
            printf("%d",out%1000000000);
        }
    }
    else printf("999999998");
}