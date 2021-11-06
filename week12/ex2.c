#include "stdio.h"
#include "string.h"
#include "linux/input.h"
#include "fcntl.h"
#include "unistd.h"

int main(){
    struct input_event inputEvent;
    ssize_t n;
    int fd;

    fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
    
    FILE* fp = fopen("ex2.txt", "w");
    fclose(fp);

    while (1){
    	fp = fopen("ex2.txt", "a");
    	
        n = read(fd, &inputEvent, sizeof inputEvent);
        printf("\n%i\n", inputEvent.code);
        if (inputEvent.value == 0){
            fprintf(fp, "RELEASED 0x%04x (%i)\n", (int) inputEvent.code, inputEvent.code);
        } else if (inputEvent.value == 1){
            fprintf(fp, "PRESSED 0x%04x (%i)\n", (int) inputEvent.code, inputEvent.code);
        } else if (inputEvent.value == 2){
            fprintf(fp, "REPEATED 0x%04x (%i)\n", (int) inputEvent.code, inputEvent.code);
        }
        
        fclose(fp);
    }
    
    return 0;
}
