#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define ll long long
ll n;
ll **a1;
ll **a2;
ll **ans;
void *sum(void*arg)
{
    int row = *(ll *)arg;
    for (ll i = 0; i < n;i++)
    {
        ans[row][i] = a1[row][i] + a2[row][i];
    }
    return NULL;
}
int main()
{
    scanf("%d", &n);
    a1 = (ll **)malloc(n * sizeof(ll *));
    a2 = (ll **)malloc(n * sizeof(ll *));
    ans = (ll **)malloc(n * sizeof(ll *));
    for (ll i = 0; i < n;i++)
    {
        a1[i] = (ll *)malloc(n * sizeof(ll));
        a2[i] = (ll *)malloc(n * sizeof(ll));
        ans[i] = (ll *)malloc(n * sizeof(ll));
    }
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a1[i][j]);
		}
	}
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a2[i][j]);
		}
	}
    pthread_t pt[n];
    ll row[n];
    for (ll i = 0; i < n;i++)
    {
        row[i] = i;
    }
    for (ll i = 0; i < n;i++)
    {
        pthread_create(&pt[i], NULL, sum, &row[i]);
    }
    for (ll i = 0; i < n;i++)
    {
        pthread_join(pt[i], NULL);
    }
    	printf("Resultant array after addition:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", ans[i][j]);
		}
		printf("\n");
	}
    for (ll i = 0; i < n;i++)
    {
        free(a1[i]);
        free(a2[i]);
        free(ans[i]);
    }
    free(a1);
    free(a2);
    free(ans);
}
