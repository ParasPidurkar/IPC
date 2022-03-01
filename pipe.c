#include "header.h"
int main(){

    int p[2],ret;
    ret = pipe(p);
    if (ret<0){
        perror("pipe");
        return;
    }
printf("p[0] is %d p[1] is %d \n",p[0],p[1]);
if (fork()==0)
    {
        //child process 
        while(1){
        char b[10];
        printf("this is before read in the child\n");
        read(p[0],b,10);
        printf("after reading in child %s \n",b);
    }
    }
else{
    while(1){
        sleep(1);
//parent process
char a[10];
printf("Enter your name");
scanf("%s",a);
write(p[1],a,strlen(a)+1);
    }
}
}