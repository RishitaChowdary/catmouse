#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>
void * cs();
void * ms();
int NumBowls[15],num=0 ,arr[15];
int NumCats=0,
NumMice=0;
sem_t nofcats,nofmice;pthread_t t1,t2,t3,t4,t5;
pthread_mutex_t mutex,cmutex,mmutex;
void * ms()
{		NumMice=NumMice+1;
arr[NumMice]=NumMice;
int i=NumMice;
sem_wait(&nofmice);	
if(NumMice==1)
{				pthread_mutex_lock(&mmutex);
}
printf("%d th mice is eating\n",NumMice);
printf("%d th mice is sleeping\n",NumMice);
sleep(2);
if(i!=arr[i])	
{		return;
}
printf("%d th mice woke up and eating \n",NumMice);
sleep(2);
printf("%d th mice left the house\n",NumMice);
pthread_mutex_unlock(&mmutex);
} 
void * cs()
{	pthread_mutex_lock(&mutex);	
NumCats=NumCats+1;
num=num+1;
printf("%d th cat is now in house\n",NumCats);
printf("%d th cat is sleeping\n",NumCats);
sleep(2);
printf("%d th cat is wokeup\n",NumCats);
while(NumMice>0)
{	sem_destroy(&nofmice);
printf("%d th mice died :( \n",NumMice);	
arr[NumMice]=-1;
NumMice=NumMice-1;
}
printf("%d th cat is sleeping\n",NumCats);
sleep(2);
printf("%d th cat wokeup and starts eating\n",NumCats);
NumBowls[num]=num;
printf("%d th cat left the house\n",NumCats);	pthread_mutex_unlock(&mutex);
}
int main()
{ int num=5,x
;	sem_init(&nofcats,0,num);
sem_init(&nofmice,0,num);
pthread_create(&t1,NULL,cs,NULL);	
sleep(2);

pthread_create(&t2,NULL,cs,NULL);
pthread_create(&t3,NULL,cs,NULL);
sleep(2);
pthread_create(&t4,NULL,cs,NULL);
pthread_create(&t5,NULL,ms,NULL);
pthread_join(t1,NULL);
pthread_join(t2,NULL);
pthread_join(t3,NULL);	
pthread_join(t4,NULL);
pthread_join(t5,NULL);
}
