#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
char buffer[1024]="";
pthread_t tid1,tid2,tid3;
pthread_attr_t attr;
void *strcat2(void *p){strcat(buffer,p);}
void *strcat1(void *p){strcat(buffer,p);
					  pthread_create(&tid2,&attr,strcat2,"b");}
int main(int argc, char**argv) {
 pthread_attr_init(&attr);
 pthread_create(&tid1,&attr,&strcat1,"a");
 pthread_join(tid1,NULL);
 pthread_join(tid2,NULL);
 strcat(buffer,"b");
 printf("%s\n",buffer);
 pthread_create(&tid3,&attr,&strcat1,"c");
 pthread_join(tid3,NULL);
 pthread_join(tid2,NULL);
 printf("%s\n",buffer);
}