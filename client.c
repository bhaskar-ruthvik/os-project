#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc,char* argv[]){
   
   char message[] = "1. Enter 1 to contact the Ping Server\n2. Enter 2 to contact the File Search Server\n3. Enter 3 to contact the File Word Count Server\n4. Enter 4 if this Client wishes to exit\n";
   if(fork()==0){
    int clientID;
    printf("Enter Client-ID: ");
    scanf("%d",&clientID);
    printf("The Client ID is: %d\n",clientID);
    int i;
    while(i!=4){
        printf("%s",message);
        scanf("%d",&i);
        switch(i){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
        }
    }
   }else{
    wait(NULL);
   }
}