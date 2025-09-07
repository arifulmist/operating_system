#include<stdio.h>
#include<pthread.h>
void * compute(void *n)
{
    int *addsum = (int *)n;
    int sum = 0;
    for (int i = 1; i <=*addsum;i++)
   {
    sum +=i;
   }
printf("%d\n", sum);
return NULL;
}
int main()
{
    pthread_t p1,p2;
    int a, v;
    scanf("%d%d", &a, &v);
    pthread_create(&p1, NULL, compute,(void*)&a);
    pthread_create(&p2, NULL, compute, (void *)&v);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    return 0;
}