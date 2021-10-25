#include <stdio.h>
#include "dirent.h"
#include <sys/stat.h>
#include <string.h>

#define MAX_SIZE_ARRAY 30
#define MAX_FILE_NAME 40

struct folder_entry{
    int hard_links_num;
    int i_node_num;
    char file_name[MAX_FILE_NAME];
};

int main(){
    struct folder_entry folder_entries[MAX_SIZE_ARRAY];
    int arr_size = 0;

    DIR *folder = opendir(".");
    struct dirent *entry;
    struct stat file_stat;

    if(folder == NULL){
        perror("Unable to read directory");
        return(1);
    }

    while( (entry=readdir(folder)) ){
        if (stat(entry->d_name, &file_stat) < 0){
            perror("Unable to get file stat");
            return(1);
        }
        folder_entries[arr_size].hard_links_num = file_stat.st_nlink;
        folder_entries[arr_size].i_node_num = file_stat.st_ino;
        strcpy(folder_entries[arr_size].file_name, entry->d_name);

        arr_size++;
    }

    for (int i = 0; i < arr_size; i++){
        if (folder_entries[i].hard_links_num > 1){
            int cur_i_node = folder_entries[i].i_node_num;
            printf("%s --- ", folder_entries[i].file_name);
            for (int j = 0; j < arr_size; j++){
                if(folder_entries[j].i_node_num == cur_i_node){
                    printf("%s  ", folder_entries[j].file_name);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
