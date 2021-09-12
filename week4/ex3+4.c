#include <stdio.h>
#include <stdlib.h>

#include "shl_input.h"
#include "shl_commands.h"

char* get_user_name(){
    char* username = getenv("USERPROFILE");

    int flag = 1;
    int count = 0;
    while (flag){
        if (*username == '\\')
            count++;
        if (count == 2)
            flag = 0;
        username++;
    }

    return username;
}

void init_shell(){
    char* username = get_user_name();
    printf("\nWelcome to my shell, %s\n", username);
}

void shell_loop(){
    char* username = get_user_name();

    int input_status = 1;

    while (input_status){

        char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("DIR: %s\n", cwd);
        }

        printf("%s>>>", username);

        struct ARGS input_args = get_splitted_args();

        input_status = execute_command(input_args);

        free(input_args.args);
        free(input_args.line);
    }
}

int main(){
    init_shell();
    shell_loop();

    return 0;
}
