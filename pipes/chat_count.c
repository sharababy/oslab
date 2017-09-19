#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>


void count(char* s){

    int wc=0,i=0,lc=0,cc=0;
    for (i = 0;s[i] != '\0';i++)
    {

        if (s[i] == ' ')
            wc++;    
        else if (s[i] == '\n')
        {
            lc++;
        }
        else if (s[i] != ' ' || s[i] == '\n')
        {
            cc++;
        }
    }
    wc++;
    lc++;
    printf("\n\nWord count: %d\n",wc );
    printf("\n\nCharacter count: %d\n",cc );
    printf("\n\nSentence count: %d\n",lc );
}



int main(void)
{
        int     fd[2], nbytes;
        pid_t   childpid;
        char    string[] = "This is a test for Oslab Test\nLine 2 here";
        char    readbuffer[80];

        pipe(fd);

        if((childpid = fork()) == -1)
        {
                perror("fork");
                exit(1);
        }

        if(childpid == 0)
        {
                
               close(fd[0]);

               printf("\nSending String : ' %s '\n",string);
                
                write(fd[1], string, (strlen(string)+1));
                exit(0);
        }
        else
        {
                close(fd[1]);

                nbytes = read(fd[0], readbuffer, sizeof(readbuffer));

                count(readbuffer);
                
                printf("\nReceived string: %s\n", readbuffer);
        }

        return(0);
}


