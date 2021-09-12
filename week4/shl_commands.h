#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <dirent.h>

struct ARGS;

int change_dir(struct ARGS args){
    if (args.number != 2 || args.args[1] == NULL){
        fprintf(stderr, "Invalid arguments for cd\n");
        return 1;
    }
    if (chdir(args.args[1]) != 0) {
        fprintf(stderr, "Error changing directory: %s\n", strerror(errno));
        return 1;
    }
    return 1;
}

int make_dir(struct ARGS args){
    if (args.number != 2 || args.args[1] == NULL) {
        fprintf(stderr, "Invalid arguments for mkdir\n");
        return 1;
    }
    if (mkdir(args.args[1]) != 0) {
        fprintf(stderr, "Error creating directory: %s\n", strerror(errno));
        return 1;
    }
    return 1;
}

int get_current_directory_name(){
	char cwd[PATH_MAX];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("DIR: %s\n", cwd);
        }
    return 1;
}

// Functions by themself can execute parameter calls
int execute_command(struct ARGS args){
    if (args.number == 0)
        return 1;

    int pid = 0;

    if (strcmp(args.args[0], "fork") == 0 && args.number > 1){
        struct ARGS forkArgs;
        forkArgs.args = args.args + 1;
        forkArgs.number = args.number - 1;
        forkArgs.line = args.line;

        pid = fork();
    }

    if (pid > 0)
        return pid;

    int status = 0;

    if (strcmp(args.args[0], "cd") == 0)
        status = change_dir(args);
    else if (strcmp(args.args[0], "mkdir") == 0)
        status = make_dir(args);
    else if (strcmp(args.args[0], "pwd") == 0)
        status = get_current_directory_name();

    return status;
}
