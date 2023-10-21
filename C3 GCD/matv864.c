/*
это самый быстрый и простой шаблон
это по Евклиду 
принцип пояснять долго, но я его понимаю и он будет работать
но если заливаете на кэтс, постарайтесь понять принцип
*/

#include <stdio.h>
#define ll long long int
ll gcd(ll a, ll b){
    if (a == 0){
        return b;
    }
    return gcd(b % a, a);
}
int main(){
    ll a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);
    printf("%lld %lld %lld", gcd(a, b), gcd(a, c), gcd(b, c));
    return 0;
}
