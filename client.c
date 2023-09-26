#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>

#define PERMS 0644
struct mesg_buffer{
    long mesg_type;
    char mesg_text[100];
};
int main(int argc,char* argv[]){

    int i;
    key_t key;
    int len;
    int msgid;
    if((key=ftok("server.c",'B'))==-1){
        perror("ftok");
        exit(1);
    }
    if((msgid= msgget(key,PERMS))==-1){
        perror("msgget");
        exit(1);
    }
   char greeting[] = "1. Enter 1 to contact the Ping Server\n2. Enter 2 to contact the File Search Server\n3. Enter 3 to contact the File Word Count Server\n4. Enter 4 if this Client wishes to exit\n";
   if(fork()==0){
    int clientID;
     
    printf("Enter Client-ID: ");
    scanf("%d",&clientID);
   

                // while(fgets(buf.mesg_text,sizeof(buf.mesg_text),stdin) !=NULL){
                //     len = strlen(buf.mesg_text);
                //     if(buf.mesg_text[len-1] == '\n') buf.mesg_text[len-1] = '\0';
                
                //}
                
               
                
    while(i!=4){
        struct mesg_buffer buf;
        struct mesg_buffer buf2;
        printf("%s",greeting);
        scanf("%d",&i);
        getchar();
        switch(i){
            case 1:
                    buf.mesg_type=1;
                    strcpy(buf.mesg_text,"Hi\0");
                     if(msgsnd(msgid,&buf,strlen(buf.mesg_text)+1,0)==-1){
                    perror("msgsnd");}
                    if(msgrcv(msgid,&buf2,sizeof(buf2.mesg_text),0,0)==-1){
                        perror("msgrcv");
                        exit(1);
                    }
                    printf("%s\n",buf2.mesg_text);
                    break;
            case 2:
                buf.mesg_type = 2;
                scanf("%[^\n]s",buf.mesg_text);
                if(msgsnd(msgid,&buf,strlen(buf.mesg_text)+1,0)==-1){
                    perror("msgsnd");
                    exit(1);
                }
                if(msgrcv(msgid,&buf2,sizeof(buf2.mesg_text),0,0)==-1){
                    perror("msgrcv");
                    exit(1);
                }
                printf("%s\n",buf2.mesg_text);
                break;
             case 3:
                buf.mesg_type = 3;
                scanf("%[^\n]s",buf.mesg_text);
                if(msgsnd(msgid,&buf,strlen(buf.mesg_text)+1,0)==-1){
                    perror("msgsnd");
                    exit(1);
                }
                if(msgrcv(msgid,&buf2,sizeof(buf2.mesg_text),0,0)==-1){
                    perror("msgrcv");
                    exit(1);
                }
                printf("%s\n",buf2.mesg_text);
             break;
         }
     }
   }else{
     wait(NULL);
    
    }
}