#include "stdio.h"

// For NUM = 100: #hits: 194, #misses: 806, ration: 0.240695
// For NUM = 50: #hits: 101, #misses: 899, ration: 0.112347
// For NUM = 10: #hits: 20, #misses: 980, ration: 0.020408
#define NUM 10
#define COUNTER_NUMBER_BITS 16

struct page{
    int id;
    int counter;
};

int execute_page(struct page* pages, int page_num){
    int flag = 0;
    int min_page_id = 0;
    int min_page_counter = (1 << COUNTER_NUMBER_BITS) - 1;

    for (int i = 0; i < NUM; i++){
        if (pages[i].id == -1){
            if (flag)
                continue;

            flag = 1;
            pages[i].id = page_num;
            pages[i].counter |= 1 << (COUNTER_NUMBER_BITS - 1);
        } else{
            pages[i].counter >>= 1;
        }

        if (flag)
            continue;

        if (min_page_counter > pages[i].counter){
            min_page_counter = pages[i].counter;
            min_page_id = i;
        }

        if (pages[i].id == page_num){
            flag = 1;
            pages[i].counter |= 1 << (COUNTER_NUMBER_BITS - 1);
        }
    }

    if (flag)
        return 1; // HIT

    pages[min_page_id].id = page_num;
    pages[min_page_id].counter |= 1 << (COUNTER_NUMBER_BITS - 1);
    return 0; // MISS
}

void print_pages(struct page* pages){
    for (int i = 0; i < NUM; i++){
        printf("id: %d\tcounter: %d\n", pages[i].id, pages[i].counter);
    }
}

int main(){
    struct page pages[NUM];

    for (int i = 0; i < NUM; i++){
        pages[i].counter = 0;
        pages[i].id = -1;
    }

    print_pages(pages);

    FILE* file = fopen("Lab_09_input.txt", "r");

    if (file == NULL){
        printf("File does not exist\n");
        return 1;
    }

    int page_num;
    int number_hits = 0;
    int number_misses = 0;

    while (fscanf(file, "%d", &page_num) == 1){
        if (execute_page(pages, page_num))
            number_hits++;
        else
            number_misses++;
        printf("Executing page #%d:\n", page_num);
        print_pages(pages);
        printf("\n\n");
    }

    printf("#hits: %d, #misses: %d, ration: %f\n", number_hits, number_misses, (float) number_hits / (float) number_misses);

    fclose(file);

    return 0;
}