#include  <stdio.h>
#include  <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

FILE *history;
int ghc;


void parse(char *line, char **argv)
{
     while (*line != '\0') {       /* if not the end of line ....... */ 
          while (*line == ' ' || *line == '\t' || *line == '\n')
               *line++ = '\0';     /* replace white spaces with 0    */
          *argv++ = line;          /* save the argument position     */
          while (*line != '\0' && *line != ' ' && 
                 *line != '\t' && *line != '\n') 
               line++;             /* skip the argument until ...    */
     }
     *argv = '\0';                 /* mark the end of argument list  */
}




void execute(char **argv)
{
     pid_t  pid;
     int status,correct=0;

     if ((pid = fork()) < 0) {     /* fork a child process           */
          printf("*** ERROR: forking child process failed\n");
          exit(1);
     }
     else if (pid == 0) {          /* for the child process:         */
          if (execvp(*argv, argv) < 0) {     /* execute the command  */
               printf("*** ERROR: exec failed\n");
               exit(1);
          }
     }
     else {                                  /* for the parent:      */
          while (wait(&status) != pid)       /* wait for completion  */
               ;
          
          fprintf(history, "%s\n", *argv);
          ghc++;
          
          
     }
}

void  main(void)
{
    char  line[1024];             /* the input line                 */
    char  *argv[64];
    ghc = 0;              /* the command line argument      */
	history = fopen("history.shara", "w+");

    while (1) {                   /* repeat until done ....         */
      printf("sharabups -> ");     /*   display a prompt             */
      gets(line);              /*   read in the command line     */
      
      printf("\n");
      parse(line, argv);       /*   parse the line               */
      if (strcmp(argv[0], "exit") == 0)  /* is it an "exit"?     */
      {     exit(0); fclose(history); }            /*   exit if it is                */
      execute(argv);           /* otherwise, execute the command */
    }

    fclose(history);
}