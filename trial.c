#include "cs50++.h"


int main(void) 
{   
    printf("\n=== 1. List Creation ===\n");
    list demo1 = list_demo(1);
    printf("Created demo1 using list_demo(1)\n");

    list demo2 = list_demo(3);
    printf("Created demo2 using list_demo(3)\n");

    printf("\n=== 2. Basic Operations on demo1 ===\n");
    printf("demo1: ");
    list_print(demo1);
    list_prepend(&demo1, 100);
    printf("Prepend 100 to demo1: ");
    list_print(demo1);

    list_append(&demo1, 999);
    printf("Append 999 to demo1: ");
    list_print(demo1);

    printf("First 3 elements of demo1 using list_head(): ");
    list_head(demo1, 3);
    
    printf("Last 3 elements of demo1 using list_tail(): ");
    list_tail(demo1, 3);

    list_add_ordered(&demo1, 500, true);
    printf("Added 500 to demo1 in ascending order: ");
    list_print(demo1);

    list_insert(&demo1, 250, 3);
    printf("Inserted 250 at index 3 in demo1: ");
    list_print(demo1);

    printf("\n=== 3. Searching and Info Operations on demo2 ===\n");
    printf("demo2: ");
    list_print(demo2);
    printf("demo2 length: %i\n", list_len(demo2));
    printf("demo2 sum: %i\n", list_sum(demo2));
    printf("demo2 average: %f\n", list_avg(demo2));
    printf("demo2 min/max: %i / %i\n", list_min(demo2), list_max(demo2));

    int search_val = 4;
    printf("Count of %i in demo2: %i\n", search_val, list_count(demo2, search_val));
    printf("Index of the first occurrence of %i in demo2: %i\n", search_val, list_index(demo2, search_val));
    printf("Value at index 5 in demo2: %d\n", list_value(demo2, 5));

    printf("Does %i exist in demo2? %s\n", search_val, list_value_exist(demo2, search_val) ? "Yes" : "No");

    printf("\n=== 4. List Manipulation ===\n");
    printf("demo1: ");
    list_print(demo1);
    list reversed = list_copy(demo1);
    list_reverse(&reversed);
    printf("Created 'reversed' as reversed copy of demo1: ");
    list_print(reversed);

    list sliced = list_slice(demo1, 3, 8);
    printf("Created 'sliced' from demo1 (indices 3-8): ");
    list_print(sliced);

    printf("Creating an array from demo2 using list_to_array(demo2)\n");
    int *array = list_to_array(demo2);
    printf("First 5 elements of demo2 as array: ");
    for (int i = 0; i < 5 && i < list_len(demo2); i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
    free(array);

    printf("\n=== 5. Sorting and Duplicates ===\n");
    list to_sort = list_copy(demo2);
    printf("Created 'to_sort' as copy of demo2: ");
    list_print(to_sort);
    
    list_sort(&to_sort, true);
    printf("Sorted 'to_sort' ascending: ");
    list_print(to_sort);
    
    list_sort(&to_sort, false);
    printf("Sorted 'to_sort' descending: ");
    list_print(to_sort);
    
    printf("Before duplicate removal in 'to_sort': ");
    list_print(to_sort);
    list_remove_duplicates(&to_sort);
    printf("After duplicate removal in 'to_sort': ");
    list_print(to_sort);

    printf("\n=== 6. Advanced Operations ===\n");
    list common = list_intersect(demo1, demo2);
    printf("Common elements between demo1 and demo2: ");
    list_print(common);

    printf("Are demo1 and demo2 identical? %s\n", list_compare(demo1, demo2) ? "Yes" : "No");

    printf("Merged demo1 and demo2 into 'merged':\n");
    printf("Original demo1: "); list_head(demo1, 5); printf("...\n");
    printf("Original demo2: "); list_head(demo2, 5); printf("...\n");
    list_unify(&demo1, demo2);
    printf("Merged result: "); list_head(demo1, 5); printf("...\n");

    printf("\n=== 7. Deleting Operations on demo1 ===\n");
    printf("demo1 before operations: ");
    list_print(demo1);

    list_remove(&demo1, 2);
    printf("After removing element at index 2: ");
    list_print(demo1);

    list_delete(&demo1, 500);
    printf("After deleting value 500: ");
    list_print(demo1);

    printf("demo1 before pop: ");
    list_print(demo1);
    printf("Popped value from demo1: %i\n", list_pop(&demo1));
    printf("demo1 after pop: ");
    list_print(demo1);

    printf("Memory check before clearing demo1: ");
    list_leak_check(demo1, list_len(demo1));
    list_clear(&demo1);
    printf("Memory check after clearing demo1: ");
    list_leak_check(demo1, 0);

    printf("\n=== 8. Visualization ===\n");
    list generated = list_generate(10, 50, 10);
    printf("Created 'generated' list using list_generate(10, 50, 10): ");
    list_print(generated);
    printf("Visualizing generated list: ");
    list_visualise(generated);
    printf("View adresses of each node of the list in the memory:\n");
    list_addresses(generated);

    printf("\n=== Cleanup ===\n");
    list_clear(&generated);
    list_clear(&reversed);
    list_clear(&sliced);
    list_clear(&to_sort);
    list_clear(&common);

    printf("All lists cleared successfully.\n");
    return 0;
}
