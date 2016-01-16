#include <stdio.h>
#include <stdlib.h>
#define MAX 100000000;

int x[1001];
int y[1001];
int main()
{
        int n,t,minx,miny,cntx,cnty,sx,sy,i;

        scanf("%d",&t);

        while(t){
                scanf("%d",&n);
                sx=0;
                sy=0;
                minx=miny=MAX;
                for(i=1;i<=n;i++){
                    scanf("%d%d",&x[i],&y[i]);
                    sx=sx+x[i];
                    sy=sy+y[i];
                    if(x[i]<minx)
                        minx=x[i];
                    if(y[i]<miny)
                        miny=y[i];
                }
                if(sx%n==n/2){
                        if(minx<0)
                            cntx=2*(sx/n+minx);
                        else
                            cntx=2*(sx/n-minx);
                }
                else
                    cntx=1;

                if(sy%n==n/2){
                    if(miny<0)
                            cnty=2*(sy/n+miny);
                        else
                            cnty=2*(sy/n-miny);
                }
                else
                    cnty=1;

                printf("%d\n",cntx*cnty);

            t--;
        }


    return 0;
}
