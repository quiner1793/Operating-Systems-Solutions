#include "stdio.h"
#include "string.h"
#include "linux/input.h"
#include "fcntl.h"
#include "unistd.h"
#define MAX_LEN_OF_SHORTCUT 6

void check_for_chortcut(FILE* fp, const int* char_history, int cur_indx){
    printf("-----------%i\n", *(char_history+cur_indx));
    if (*(char_history+cur_indx) == 18 && *(char_history+(cur_indx-1)%MAX_LEN_OF_SHORTCUT) == 25){
	fprintf(fp, "I passed the Exam!\n");
    }
    if (*(char_history+cur_indx) == 25 && *(char_history+(cur_indx-1)%MAX_LEN_OF_SHORTCUT) == 30 && *(char_history+(cur_indx-2)%MAX_LEN_OF_SHORTCUT) == 46){
    	fprintf(fp, "Get some cappuccino!\n");
    }
    if (*(char_history+cur_indx) == 17 && *(char_history+(cur_indx-1)%MAX_LEN_OF_SHORTCUT) == 35){
	    fprintf(fp, "Hello World!\n");
    }
}

int main(){
    struct input_event inputEvent;
    ssize_t n;
    int fd;
    
    int char_history[MAX_LEN_OF_SHORTCUT];
    int current_indx = 0;

    for (int i = 0; i < MAX_LEN_OF_SHORTCUT; i++){
        char_history[i] = 0;
    }

    fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    
    FILE* fp = fopen("ex3.txt", "w");
    fclose(fp);

    while (1){
    	fp = fopen("ex3.txt", "a");
    	
        n = read(fd, &inputEvent, sizeof inputEvent);
        printf("\n%i --- this is code\n", inputEvent.code);
	if ((int) inputEvent.code == 0 || (int) inputEvent.code == 4){
	    fclose(fp);
	    continue;
	}
        if (inputEvent.value == 0){
            fprintf(fp, "RELEASED 0x%04x (%i)\n", (int) inputEvent.code, inputEvent.code);
        } else if (inputEvent.value == 1){
            fprintf(fp, "PRESSED 0x%04x (%i)\n", (int) inputEvent.code, inputEvent.code);
            current_indx = (current_indx + 1) % MAX_LEN_OF_SHORTCUT;
            char_history[current_indx] = inputEvent.code;
        } else if (inputEvent.value == 2){
            fprintf(fp, "REPEATED 0x%04x (%i)\n", (int) inputEvent.code, inputEvent.code);
            current_indx = (current_indx + 1) % MAX_LEN_OF_SHORTCUT;
            char_history[current_indx] = inputEvent.code;
        }
        
        check_for_chortcut(fp, char_history, current_indx);
        
        fclose(fp);
    }
    
    return 0;
}
