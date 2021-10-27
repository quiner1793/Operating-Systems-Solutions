#include <stdio.h>
#include <dirent.h>

int main(void) {
    struct dirent *entry;
    DIR *folder = opendir("/");
    FILE* f = fopen("ex2.txt", "a");
    fprintf(f, "Content of root directory:\n");

    while( (entry=readdir(folder)) ){
        fprintf(f, "%s\n", entry->d_name);
    }

    return 0;
}