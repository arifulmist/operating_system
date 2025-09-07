#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define ll long long

ll n;
ll *arr;
ll *freq;
ll max_val = 0;
pthread_mutex_t mut;

void* freq_array(void* arg) {
    ll start = *(ll*)arg;
    ll end = (start == 0) ? n/2 : n;
    for (ll i = start; i < end; i++) {
        pthread_mutex_lock(&mut);
        freq[arr[i]]++;
        pthread_mutex_unlock(&mut);
    }
    return NULL;
}

int main() {
    printf("Enter array size: ");
    scanf("%lld", &n);
    arr = (ll *)malloc(n * sizeof(ll));
    for (ll i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
        if (arr[i] > max_val) max_val = arr[i];
    }
    freq = (ll*)calloc(max_val + 1, sizeof(ll));

    pthread_t t1, t2;
    ll ind1 = 0, ind2 = n/2;
    pthread_mutex_init(&mut, NULL);
    pthread_create(&t1, NULL, freq_array, &ind1);
    pthread_create(&t2, NULL, freq_array, &ind2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&mut);

    printf("Frequency:\n");
    for (ll i = 0; i <= max_val; i++) {
        if (freq[i] > 0)
            printf("%lld: %lld\n", i, freq[i]);
    }
    free(arr);
    free(freq);
    return 0;
}
