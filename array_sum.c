#include <stdio.h>
#include <pthread.h>
#include<stdlib.h>
#define ll long long
ll n;
ll *arr;
ll sum = 0;
pthread_mutex_t mut;

void* arraysum(void*arg)
{
     ll start = *(ll *)arg;
     ll mid = (n + 1) / 2;
    ll end  = (start == 0) ? mid : n;
    ll localsum = 0;
    for (ll i = start; i < end;i+=1)
    {
        localsum += arr[i];
    }
        pthread_mutex_lock(&mut);
        sum += localsum;
        pthread_mutex_unlock(&mut);
        return NULL;
    }

int main()
{
    printf("enter your array size: ");
    scanf("%lld", &n);
    arr = (ll *)malloc(n * sizeof(ll));
    for ( ll i = 0; i < n;i++)
    {
        scanf("%lld", &arr[i]);
    }
    pthread_t t1, t2;
    ll ind1 = 0;
    ll ind2 = (n + 1) / 2; 
    pthread_mutex_init(&mut, NULL);
    pthread_create(&t1, NULL, arraysum, &ind1);
    pthread_create(&t2, NULL, arraysum, &ind2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&mut);
    printf("%lld", sum);
    free(arr);
    return 0;
}
