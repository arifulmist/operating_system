#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define ll long long
ll **arr;
int main_diag_sum = 0, sec_diag_sum = 0;
int n,m;
void* sum1(void*arg)
{
    for (ll i = 0; i < n;i++)
    {
        main_diag_sum += arr[i][i];
    }
    return NULL;

}
void* sum2(void*arg)
{
    for (ll i = 0; i < n;i++)
    {
        sec_diag_sum += arr[i][m-1-i];
    }
    return NULL;
    
}
int main()
{
    scanf("%d%d", &n,&m);
    arr =(ll **)malloc(n * sizeof(ll *));
    for (ll i = 0; i < n;i++)
    {
        arr[i] = (ll *)malloc(m * sizeof(ll));
    }
    for (ll i = 0; i < n;i++)
    {
        for (ll j = 0; j < m;j+=1)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    pthread_t p1, p2;
    pthread_create(&p1, NULL, sum1, NULL);
    pthread_create(&p2, NULL, sum2, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf(" main: %d\n", main_diag_sum);
    printf("secondary: %d", sec_diag_sum);
}
