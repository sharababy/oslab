#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(void)
{
        int     fd[2], nbytes;
        char    string[] = "Oslab Test !";

        
        pipe(fd);

        dup2(fd[0],0);
		//printf("%s",string);       
        system("wc");
        return(0);
}