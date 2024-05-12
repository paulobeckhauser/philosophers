# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h> 

void* routine(void *i)
{
    printf("Test from threads\n");
    sleep(3);
    printf("Ending thread\n");
}


int main(int argc, char *argv[])
{
    pthread_t t1;
    pthread_t t2;

    if (pthread_create(&t1, NULL, &routine, NULL) != 0)
        return (1);
    if (pthread_create(&t2, NULL, &routine, NULL) != 0)
        return (2);

    if (pthread_join(t1, NULL) != 0)
        return (3);

    if (pthread_join(t2, NULL) != 0)
        return (4);
    
    return (0);
}
