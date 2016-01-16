#include <stdio.h>
#include <stdlib.h>
short int cnt=1;
long long int N = 1000000000;
long long int map[50000000];

long long int hashFunction(long long int key) {
    return key/N;
}

void put(long long int key, long long int val) {
    long long int hash = hashFunction(key);
    map[hash]=val;
}

int isPresent(key) {
    return map[key] > 0;
}

long long int get(int key) {
    long long int hash = hashFunction(key);
    return map[hash];
}

long long int byteCoin(long long int n) {
    long long int n2,n3,n4,get2,get3,get4;

    if( n == 0)
        return 0;

    n2 = n/2;
    n3 = n/3;
    n4 = n/4;

    if(n2==0 || n3==0 || n4==0) {
        return n;
    }


    //check if n is already in the map
    int isN = isPresent(n);
    if(!isN) {
        byteCoin(n/2);
    }
    put(n,get2+get3+get4);
    cnt++;
    if(cnt!=1){
        return get2+get3+get4;
    }


    printf("###(%lld,%lld,%lld)\n",get2,get3,get4);
    return get2+get3+get4;
}


int main(void) {


    long long int d;

    scanf("%lld",&d);

    long long int res = byteCoin(d);
    printf("Response:%lld",res);

    return 0;
}
