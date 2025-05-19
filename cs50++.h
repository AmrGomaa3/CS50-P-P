#ifndef CS50PP_H
#define CS50PP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <errno.h>


// Type Definitions
typedef struct node {
    int num;
    struct node *next;
} node;


typedef node *list;

// Function Prototypes
void list_print(node *list);
void list_head(node *list, int num);
void list_tail(node *list, int num);
void list_addresses(node *list);
list list_demo(int num);
list list_generate(int start, int end, int step);
int list_prepend(node **list, int num);
int list_append(node **list, int num);
int list_add_ordered(node **list, int num, bool ascending);
int list_insert(node **list, int num, int index);
int list_count(node *list, int value);
int list_index(node *list, int value);
int list_value(node *list, int index);
int *list_to_array(node *list);
list list_copy(node *list);
int list_max(node *list);
int list_min(node *list);
int list_sum(node *list);
int list_len(node *list);
float list_avg(node *list);
void list_clear(node **list);
int list_remove(node **list, int index);
int list_delete(node **list, int value);
int list_pop(node **list);
int list_remove_duplicates(node **list);
list list_slice(node *list, int start_index, int end_index);
int list_sort(node **list, bool ascending);
list list_merge_sort(node *list, bool ascending);
list list_merge(node *left, node *right, bool ascending);
int list_reverse(node **list);
bool list_leak_check(node *list, int len);
bool list_value_exist(node *list, int value);
bool list_compare(node *list1, node *list2);
int list_unify(node **list1, node *list2);
list list_intersect(node *list1, node *list2);
void list_visualise(node *list);


#endif // CS50PP_H
