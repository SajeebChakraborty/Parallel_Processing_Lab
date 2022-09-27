
#include <stdio.h>
#include <pthread.h>

#define MAX 16

#define MAX_THREAD 4


int a[MAX];
int sum[4] = { 0 };
int part = 0;

void* sum_array(void* arg)
{
    // Each thread computes sum of 1/4th of array


    for (int i = part * (MAX / 4); i < (part + 1) * (MAX / 4); i++)
        sum[part]= sum[part] + a[i];
        part++;
}
// Driver Code
int main()
{
    pthread_t threads[MAX_THREAD];

    for (int i = 0; i < MAX; i++)
    {
        a[i] = i;
    }
    // Creating 4 threads
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_create(&threads[i], NULL, sum_array, (void*)NULL);

    // joining 4 threads i.e. waiting for all 4 threads to complete
    for (int i = 0; i < MAX_THREAD; i++)
        pthread_join(threads[i], NULL);

    // adding sum of all 4 parts
    int total_sum = 0;
    for (int i = 0; i < MAX_THREAD; i++)
        total_sum += sum[i];

    printf("sum is %d\n",total_sum);

    return 0;
}
