#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int **arr;
int n;
int sum = 0;
pthread_mutex_t mut;
void *summ(void *arg)
{
    int row = *(int *)arg;
    int localsum = 0;
    for (int i = 0; i < n; i++) {
        localsum += arr[row][i];
    }
    pthread_mutex_lock(&mut);
    sum += localsum;
    pthread_mutex_unlock(&mut);
    return NULL;
}
int main()
{

    scanf("%d", &n);
    arr = (int **)malloc(n * sizeof(int*));
    for (int i = 0; i < n;i++)
    {
        arr[i] = (int *)malloc(n * sizeof(int));
    }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
    pthread_t pt[n];
    int row[n];
    pthread_mutex_init(&mut, NULL);
    for (int i = 0; i < n;i++)
    {
        row[i] = i;
    }
    for ( int i = 0; i<n;i++)
    {
        pthread_create(&pt[i], NULL, summ, &row[i]);
    }
    	for (int i = 0; i < n; i++) {
		pthread_join(pt[i], NULL);
	}
	pthread_mutex_destroy(&mut);

	printf("Sum of all elements: %d\n", sum);
   for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    return 0;
}
