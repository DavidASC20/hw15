#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

char** parse_args(char *line);

char** parse_args(char *line){
    char **args = calloc(5, sizeof(char *));
    args[0] = strsep(&line, " ");
    int num;
    for(num = 1; num < 5; num++){
        args[num] = strsep(&line, " ");
    if (args[num] == NULL) {
      break;
    }
  }return args;
}

int main(){
    char line[100] = "ls -a -l";
    char **args = parse_args(line);
    int err = execvp(args[0], args);
    if(err != 0){
        printf("Error, Message is: %s\n", strerror(errno));
        return err;
    }
    return 0;
}