// Dining Philosopher's problem

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t threads[5];
int semaphore[5];

void wait(int *sem){
    while(*sem<=0);
    *sem = *sem -1;
}

void ignal(int *sem){
    *sem = *sem + 1;
}

void eat(int i){
    int next = (i+1)%5;
    while(!semaphore[i] || !semaphore[next]);
    wait(&semaphore[i]);
    wait(&semaphore[next]);
    printf("Philosopher %d is eating\n",i+1);
    sleep(5);
    ignal(&semaphore[i]);
    ignal(&semaphore[next]);
    printf("Philosopher %d starts thinking\n",i+1);
    pthread_join(threads[i],NULL);
}

void main(){
    for(int i=0;i<5;i++){
        semaphore[i] = 1;
    }
    int n_hung,hungry[5];
    printf("Enter the number of philosophers who are hungry\n");
    scanf("%d",&n_hung);
    for(int i=0;i<n_hung;i++){
        printf("\nEnter the hungry philosopher[%d] number:",i+1);
        scanf("%d",&hungry[i]);
    }
    for(int i=0;i<n_hung;i++){
        pthread_create(&threads[hungry[i]-1],NULL,(void*)eat,(void*)hungry[i]-1);
    }
    for(int i=0;i<5;i++){
        pthread_join(threads[i],NULL);
    }
}