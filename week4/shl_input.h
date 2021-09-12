#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024
#define TOKENS_SIZE 32
#define DELIMITERS " \t\n"

struct ARGS{
    int number;
    char* line;
    char** args;
};

char* get_input_line(){
    int buffer_size = BUF_SIZE;
    char* input_buffer = malloc(sizeof(char) * BUF_SIZE);

    int input_flag = 1;
    int index = 0;
    int ch;

    while (input_flag){
        ch = getchar();

        if (ch == EOF || ch == '\n'){
            input_flag = 0;
            input_buffer[index] = '\0';
        } else {
            input_buffer[index] = ch;
            index++;

            if (index >= buffer_size){
                buffer_size *= 2;
                input_buffer = realloc(input_buffer, sizeof(char) * buffer_size);
            }
        }
    }

    return input_buffer;
}

struct ARGS get_splitted_args(){
    char* input_line = get_input_line();

    int tokens_size = TOKENS_SIZE;
    char** splitted_line = malloc(TOKENS_SIZE * sizeof(char*));

    int index = 0;

    char* split_arg = strtok(input_line, DELIMITERS);
    while (split_arg != NULL){
        splitted_line[index] = split_arg;
        index++;

        if (index >= tokens_size){
            tokens_size *= 2;
            splitted_line = realloc(splitted_line, tokens_size * sizeof(char*));
        }

        split_arg = strtok(NULL, DELIMITERS);
    }

    struct ARGS args;
    args.args = splitted_line;
    args.number = index;
    args.line = input_line;

    return args;
}