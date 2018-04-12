#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t a;
int c=5;
int r1,r2,r3;



void *fun2(){
   //sem_wait(&a);
    //printf("\n T2 is running in Function 2");
   
}
void *funa(){
   
 
   sem_wait(&a);
   
   printf("\n Entered...Function A");
     r2=c;
    r2=r2-1;
    sleep(5);
    c=r2;
    //sem_post(&a);
//    printf("\n count = %d",c);
  //printf("\n T2 is running in A");
  printf("\n Function A excuted before Function B");
  
  printf("\n Exiting...Function A");
  printf("\n count = %d",c);
   sem_post(&a);
}
void *func(){
	sem_wait(&a);
	r3=c;
	r3=r3-1;
	c=r3;
   //sem_wait(&a);
   printf("\n Entered...Function C");
   printf("\n Function C excuted after Function B");
   
   printf("\n Exiting...Function C");
   sem_post(&a);
   printf("\n count = %d",c);
}

void *fun1(){

 
  printf("\n T1 is running in Function 1");
   pthread_t T2;
   
 pthread_create(&T2,NULL,fun2,NULL);
  //sem_wait(&a);
 //r1=c;
 //r1=r1+1;
  
   
   pthread_create(&T2,NULL,funa,NULL);
   sleep(5);

 //sem_post(&a);
  //sleep(5);
  //c=r1;
  //printf("\n count = %d",c);
//  pthread_create(&T2,NULL,func,NULL);
   
   
   pthread_join(T2,NULL);
}


void *funb(){
 sem_wait(&a);
  r2=c;
  r2=r2+1;
  printf("\n Entered...Function B");
 
 printf("\n Function B excuted before Function C");
 printf("\n Exiting...B");
 sleep(5); 
  c=r2;
printf("\n count = %d",c);
  
 sem_post(&a);
}


int main(){
	
   sem_init(&a,1,1);


   pthread_t T1,T2;
   pthread_create(&T1,NULL,fun1,NULL);
   sleep(5); 
   pthread_create(&T1,NULL,funb,NULL);
   sleep(5);
   
   pthread_join(T1,NULL);

  pthread_create(&T2,NULL,func,NULL); 
  pthread_join(T2,NULL);
   //sem_destroy(&a);   
   return 0;
  

   

}
