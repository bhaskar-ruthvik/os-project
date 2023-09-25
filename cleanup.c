#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
int main(){
    char c;
    while(1){
    	printf("Do you want the server to terminate? Press Y for Yes and N for No.\n");
    	c = getchar();
    	if(c=='Y'){
    		break;
    	}
    }
}
