#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[]){
   int fid = fork();
   if(fid==-1) return -1;
   
    if(fid==0){
       execlp("wc","wc","a.txt",NULL);
    }else{
        wait(NULL);
       
    }
}
