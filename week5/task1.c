//
//  main.c
//  week5-tasks
//
//  Created by Smarty on 5/18/20.
//  Copyright © 2020 Martin Maslyankov. All rights reserved.
//

#include <stdio.h>
#include "list.h"

int main(int argc, const char * argv[]) {
    
    printf("Hello, World!\n");
    
    int j;
    out_types_container_t data;
    list_t l;
    iter_t i;
    
    list_init(&l);
    
    for (j = 0; j < 16; j++) {
        data.type = INT32;
        data.container.i32 = j;
        if (!add_head(&l, data)) printf("cannot add_head %d\n", j);
        else printf("add_head %d\n", j);
    }
    
    for (iter_init_head(&l, &i); iter_next(&i, &data); )
        printf("iter_next %d\n", data.container.i32);
    iter_end(&i);
        
    while (del_head(&l, &data))
        printf("del_head %d\n", data.container.i32);
    
    printf("----------------\n");
    
    // add tail
    for (j = 0; j < 16; j++) {
        data.type = INT32;
        data.container.i32 = j;
        if (!add_tail(&l, data)) printf("cannot add_tail %d\n", j);
        else printf("add_tail %d\n", j);
    }
    
    // Delete element
    out_types_container_t mydata;
    mydata.type = INT32;
    mydata.container.i32 = 5;
    
    if(del_element(&l, &mydata, &i))
        printf("Deleted element %d\n", data.container.i32);
    
    // Iterate
    for (iter_init_tail(&l, &i); iter_prev(&i, &data); )
        printf("iter_prev %d\n", data.container.i32);
    iter_end(&i);
    
    
    
    // clean up
    while (del_tail(&l, &data))
        printf("del_tail %d\n", data.container.i32);
    
    return 0;
}
