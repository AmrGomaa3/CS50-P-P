#include "cs50++.h"


// print elements of a list
void list_print(node *list)
{
    // in case of empty list
    if (list == NULL)
    {
        printf("[]\n");
        return;
    }

    node *ptr = list; // create a pointer to the beginning of the list

    printf("["); // open list bracket

    while (ptr != NULL)
    {
        // in case of last element
        if (ptr->next == NULL)
        {
            printf("%i]\n", ptr->num); // close list bracket
            return;
        }

        printf("%i, ", ptr->num); // print elements separated by a comma

        ptr = ptr->next; // move the pointer to the next node
    }
}


// print the first number of elements in a list
void list_head(node *list, int num)
{
    // in case of empty list
    if (list == NULL)
    {
        printf("[]\n");
        return;
    }

    node *ptr = list; // create a pointer to the beginning of the list

    printf("["); // open list bracket

    for (int i = 0; i < num; i++)
    {
        // in case of last element
        if (ptr->next == NULL || i + 1 >= num)
        {
            printf("%i]\n", ptr->num); // close list bracket
            return;
        }

        printf("%i, ", ptr->num); // print elements separated by a comma

        ptr = ptr->next; // move the pointer to the next node
    }
}


// print the last number of elements from a list
void list_tail(node *list, int num)
{
    // check valid index
    if (num < 0)
    {
        errno = EINVAL;
        return;
    }

    // in case of empty list
    if (list == NULL)
    {
        printf("[]\n");
        return;
    }

    node *ptr = list; // create a pointer to the beginning of the list
    node *end = list; // create pointer that will track the end of the list

    // move the end pointer ahead
    for (int i = 0; i < num; i++)
    {
        if (end != NULL)
        {
            end = end->next;
        }
    }

    // track the end of the list with end pointer while ptr moves to the user defined tail
    while (end != NULL)
    {
        end = end->next;
        ptr = ptr->next;
    }

    printf("["); // open list bracket

    for (int i = 0; i < num; i++)
    {
        // in case of last element
        if (ptr->next == NULL || i + 1 >= num)
        {
            printf("%i]\n", ptr->num); // close list bracket
            return;
        }

        printf("%i, ", ptr->num); // print elements separated by a comma

        ptr = ptr->next; // move the pointer to the next node
    }
}


// print addresses of all nodes in the list
void list_addresses(node *list)
{
    // in case of empty list
    if (list == NULL)
    {
        printf("list -> NULL\n");
        return;
    }

    node *ptr = list; // create a pointer to the beginning of the list

    printf("list -> "); // open list bracket

    while (ptr != NULL)
    {
        // in case of last element
        if (ptr->next == NULL)
        {
            printf("%p-> NULL\n", ptr); // close list bracket
            return;
        }

        printf("%p -> ", ptr); // print elements separated by a comma

        ptr = ptr->next; // move the pointer to the next node
    }
}


// generate a demo list
list list_demo(int num)
{
    list new_list = NULL; // create a new list

    // create a random list based on user choice
    if (num == 1)
    {
        for (int i = 5; i >= 0; i--)
        {
            list_prepend(&new_list, i); // uses prepend with reversed order for better time complexity [O(1) instead of O(n)]
        }
    }
    else if (num == 2)
    {
        for (int i = 0; i <= 5; i++)
        {
            list_prepend(&new_list, i);
        }
    }
    else if (num == 3)
    {
        list_prepend(&new_list, 4);
        list_prepend(&new_list, 0);
        list_prepend(&new_list, 21);
        list_prepend(&new_list, 9);
        list_prepend(&new_list, 4);
        list_prepend(&new_list, 7);
        list_prepend(&new_list, 34);
        list_prepend(&new_list, 0);
        list_prepend(&new_list, 1);
        list_prepend(&new_list, 86);
        list_prepend(&new_list, 11);
        list_prepend(&new_list, 4);
        list_prepend(&new_list, 53);
        list_prepend(&new_list, 3);
        list_prepend(&new_list, 4);
        list_prepend(&new_list, 13);
        list_prepend(&new_list, 91);
        list_prepend(&new_list, 71);
        list_prepend(&new_list, 42);
    }
    else if (num == 4)
    {
        for (int i = 10000; i >= 0; i--)
        {
            list_prepend(&new_list, i);
        }
    }
    else if (num == 5)
    {
        for (int i = INT_MIN; i <= -1; i /= 5)
        {
            list_prepend(&new_list, i);
        }

        for (int i = INT_MAX; i >= 1; i /= 5)
        {
            list_prepend(&new_list, i);
        }
    }
    // in case of invalid number choice
    else
    {
        errno = EINVAL;
        return NULL;
    }

    return new_list;
}


// generate a list
list list_generate(int start, int end, int step)
{
    node *new_list = NULL; // create a new empty list

    // in case of step = 0
    if (step == 0)
    {
        errno = EINVAL;
        return NULL;
    }

    // in case of negative step
    else if (step < 0)
    {
        if (start < end)
        {
            errno = EINVAL;
            return NULL;
        }

        // append nodes to the list with user specified bounds and step
        for (int i = end; i <= start; i -= step)
        {
            // in case of unsuccessful prepending
            if (list_prepend(&new_list, i) != 0) // uses prepend with reversed order for better time complexity [O(1) instead of O(n)]
            {
                list_clear(&new_list); // clear partially created list
                errno = ENOMEM; // exit with an error
                return NULL;
            }        
        }
    }
    // in case of positive step
    else 
    {
        if (start > end)
        {
        errno = EINVAL;
        return NULL;
        }

        // append nodes to the list with user specified bounds and step
        for (int i = end; i >= start; i -= step)
        {
            // in case of unsuccessful prepending
            if (list_prepend(&new_list, i) != 0) // uses prepend with reversed order for better time complexity [O(1) instead of O(n)]
            {
                list_clear(&new_list); // clear partially created list
                errno = ENOMEM; // exit with an error
                return NULL;
            }
        }
    }

    return new_list;
}


// prepend element to the start of a list
int list_prepend(node **list, int num)
{
    // check valid input
    if (list == NULL)
    {
        errno = EINVAL;
        return -2;
    }

    node *n = malloc(sizeof(node)); // create a node

    // check successful memory allocation
    if (n == NULL)
    {
        errno = ENOMEM;
        return -3;
    }

    n->num = num; // assign node value

    n->next = *list; // link the node to the list

    *list = n; // move the list pointer to the newly added node

    return 0;
}


// append element to the end of the list
int list_append(node **list, int num)
{
    // check valid input
    if (list == NULL)
    {
        errno = EINVAL;
        return -2;
    }

    node *n = malloc(sizeof(node)); // create a node

    // check successful memory allocation
    if (n == NULL)
    {
        errno = ENOMEM;
        return -3;
    }

    n->num = num; // assign node value
    n->next = NULL; // define the node as the last node

    // in case of empty list
    if (*list == NULL)
    {
        *list = n;
        return 0;
    }

    node *ptr = *list; // create a pointer that points at the beggining of the list

    // find the last element of the list
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = n; // link the new node to the list

    return 0;
}


// add element to a list in order
int list_add_ordered(node **list, int num, bool ascending)
{
    // check valid input
    if (list == NULL)
    {
        errno = EINVAL;
        return -2;
    }

    node *n = malloc(sizeof(node)); // create a node

    // check successful memory allocation
    if (n == NULL)
    {
        errno = ENOMEM;
        return -3;
    }

    n->num = num; // assign node value

    // in case of first node
    if (*list == NULL)
    {
        n->next = NULL; // define as last node
        *list = n; // point list pointer at the node
        return 0;
    }

    node *ptr = *list; // create a pointer at the beggining of the list

    // in case of ascending
    if (ascending)
    {
        // in case of one node in the list
        if (ptr->num < num && ptr->next == NULL)
        {
            n->next = NULL; // define as last node
            ptr->next = n; // link new node to the list
            return 0;
        }
        else if (ptr->num > num && ptr->next == NULL)
        {
            n->next = ptr;
            *list = n;
            return 0;
        }
        // in case of many nodes in the list
        else
        {
            // find the proper place for the new node
            while (ptr->next != NULL && ptr->next->num < num)
            {
                ptr = ptr->next;
            }

            n->next = ptr->next; // link the new node to the list from the back
            ptr->next = n; // link the new node to the list from the front
            return 0;
        }
    }
    // in case of descending
    else
    {
        // in case of one node in the list
        if (ptr->num > num && ptr->next == NULL)
        {
            ptr->next = n;
            n->next = NULL;
            return 0;
        }
        else if (ptr->num < num && ptr->next == NULL)
        {
            n->next = ptr;
            *list = n;
            return 0;
        }
        // in case of many nodes in the list
        else
        {
            while (ptr->next != NULL && ptr->next->num > num)
            {
                ptr = ptr->next;
            }

            n->next = ptr->next;
            ptr->next = n;
            return 0;
        }
    }
}


// add element to a list in a specified index
int list_insert(node **list, int num, int index)
{
    // check valid input
    if (list == NULL || index < 0 || list_len(*list) < index)
    {
        errno = EINVAL;
        return -2;
    }

    node *n = malloc(sizeof(node)); // create a node

    // check successful memory allocation
    if (n == NULL)
    {
        errno = ENOMEM;
        return -3;
    }

    n->num = num; // assign node value

    // in case adding at index = 0
    if (index == 0)
    {
        n->next = *list; // link to rest of the list || set end node if list is empty
        *list = n; // link first node to list pointer
        return 0;
    }

    node *ptr = *list;

    // find the node before the desired index
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
    }

    // link the new node
    n->next = ptr->next;
    ptr->next = n;
    return 0;
}


// return the count of the number of instances of a specified value in a list
int list_count(node *list, int value)
{
    int counter = 0;

    // find number of instances of the specified value
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        // increment the counter only if number in the node = specified value
        if (ptr->num == value)
        {
            counter++;
        }
    }

    return counter;
}


// return the index of a specified value in a list
int list_index(node *list, int value)
{
    // check valid input
    if (list == NULL)
    {
        errno = EINVAL;
        return -2;
    }

    int counter = 0;

    // find the specified value
    for (node *ptr = list; ptr->num != value; ptr = ptr->next)
    {
        // check if the value does not exist
        if (ptr->next == NULL)
        {
            errno = 0;
            return -1;
        }

        counter++;
    }

    return counter;
}


// return the value of a specified index
int list_value(node *list, int index)
{
    // Check input is valid
    if (list == NULL || index < 0)
    {
        errno = EINVAL;
        return INT_MIN;
    }

    if (list_len(list) < index + 1)
    {
        errno = 0;
        return INT_MIN;
    }

    node *ptr = list; // create a pointer that points at the start of the list

    // find the value of the specified index
    for (int i = 0; i < index; i++)
    {
        ptr = ptr->next;
    }

    return ptr->num;
}


// converts the linked list into an array
int *list_to_array(node *list)
{
    // check valid input
    if (list == NULL)
    {
        errno = EINVAL;
        return NULL;
    }

    int len = list_len(list); // determine the length of the linked list

    int *array = malloc(len * sizeof(int)); // declaring an array with the same length as the linked list

    if (array == NULL)
    {
        errno = ENOMEM;
        return NULL;
    }

    node *ptr = list; // create a pointer at the start of the list

    for (int i = 0; i < len; i++)
    {
        array[i] = ptr->num; // copy each value into the array
        ptr = ptr->next; // move to next node
    }

    return array;
}


// return a copy of the list
list list_copy(node *list)
{
    if (list == NULL)
    {
        return NULL;
    }

    node *new_list = NULL; // create new list pointer
    node *temp = NULL; // set temporary pointer

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        // in case of unsuccessful prepending
        if (list_prepend(&new_list, ptr->num) != 0) // uses prepend with reversed order for better time complexity [O(1) instead of O(n)]
        {
            list_clear(&new_list); // clear partially created list
            errno = ENOMEM; // exit with an error
            return NULL;
        }
    }

    list_reverse(&new_list); // reverse the list to maintain order

    return new_list;
}


// return the maximum value in a list
int list_max(node *list)
{
    // check if list is empty
    if (list == NULL)
    {
        return INT_MIN;
    }

    node *ptr = list; // create a pointer that points at the list start

    int max = ptr->num; // initialise a counter

    while (ptr != NULL)
    {
        if (ptr->num > max)
        {
            max = ptr->num;
        }

        ptr = ptr->next; // move to next node
    }

    return max;
}


// return the minimum value in a list
int list_min(node *list)
{
    // check if list is empty
    if (list == NULL)
    {
        return INT_MAX;
    }

    node *ptr = list; // create a pointer that points at the list start

    int min = ptr->num; // initialise a counter

    while (ptr != NULL)
    {
        if (ptr->num < min)
        {
            min = ptr->num;
        }

        ptr = ptr->next; // move to next node
    }

    return min;
}


// return the sum of list values
int list_sum(node *list)
{
    // check if list is empty
    if (list == NULL)
    {
        return 0;
    }

    node *ptr = list; // create a pointer that points at the list start

    int sum = 0; // initialise a counter

    while (ptr != NULL)
    {
        sum += ptr->num; // increment the counter
        ptr = ptr->next; // move to next node
    }

    return sum;
}


// return the length of a list
int list_len(node *list)
{
    node *ptr = list; // create a pointer that points at the list start

    int counter = 0; // initialise a counter

    while (ptr != NULL)
    {
        counter++; // increment the counter
        ptr = ptr->next; // move to next node
    }

    return counter;
}


// return the average of list values
float list_avg(node *list)
{
    // ensure no division by 0
    if (list == NULL)
    {
        return 0;
    }

    return (list_sum(list))/(float)(list_len(list));
}


// clear all elements of a list
void list_clear(node **list)
{
    // check valid input
    if (list == NULL)
    {
        errno = EINVAL;
        return;
    }

    node *ptr = *list; // create a pointer to the beginning of the list

    while (ptr != NULL)
    {
        *list = ptr->next; // move the list to the next node
        free(ptr); // free the current node
        ptr = *list; // move the pointer to the next node
    }
}


// remove element from a list by its index
int list_remove(node **list, int index)
{
    // Check input is valid
    if (list == NULL)
    {
        errno = EINVAL;
        return -2;
    }

    if (list_len(*list) < index + 1)
    {
        errno = 0;
        return -1;
    }

    node *ptr = *list; // create a pointer that points at the start of the list

    // in case of removing index = 0
    if (index == 0)
    {
        // in case the list has just one node
        if (ptr->next == NULL)
        {
            free(ptr); // remove the node
            *list = NULL; // set the list to empty
            return 0;
        }
        else
        {
            *list = ptr->next; // move list start to second element
            free(ptr); // remove the node
            return 0;
        }
    }

    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next; // stop one node before the specified index
    }

    node *temp = ptr->next; // pointer at desired index
    ptr->next = ptr->next->next; // link the list elements around the removed node
    free(temp); // remove desired node
    return 0;
}


// delete element from a list by its value
int list_delete(node **list, int value)
{
    // check valid input
    if (list == NULL || *list == NULL)
    {
        errno = EINVAL;
        return -2;
    }

    node *ptr = *list; // create a pointer that points at the start of the list

    // in case of a single node list
    if (ptr->next == NULL)
    {
        // if value exists
        if (ptr->num == value)
        {
            free(ptr); // remove the value
            *list = NULL; // set list to empty
            return 0;
        }

        errno = EINVAL;
        return -1;
    }

    // in case of removing the first element in a multi-node list
    if (ptr->num == value)
    {
        *list = ptr->next; // set new list start
        free(ptr); // remove desired node
        return 0;
    }

    // find node with desired value
    while (ptr->next->num != value)
    {
        // check if value does not exist in list
        if (ptr->next->next == NULL)
        {
            errno = EINVAL;
            return -1;
        }

        ptr = ptr->next;
    }

    node *temp = ptr->next; // pointer at desired index
    ptr->next = ptr->next->next; // link the list elements around the removed node
    free(temp); // remove desired node
    return 0;
}


// remove and return the last element of a list
int list_pop(node **list)
{
    // check input is valid
    if (list == NULL || *list == NULL)
    {
        errno = EINVAL;
        return INT_MIN;
    }

    node *ptr = *list; // create a pointer that points at the start of the list

    // in case of one node
    if (ptr->next == NULL)
    {
        int num = ptr->num; // get the value of the last element
        free(ptr); // remove last element
        *list = NULL;
        return num;
    }

    // stop at second to last element
    while (ptr->next->next != NULL)
    {
        ptr = ptr->next;
    }

    int num = ptr->next->num; // get the value of the last element
    free(ptr->next); // remove last element
    ptr->next = NULL; // set the new last element
    return num;
}


// remove duplicate values in a list
int list_remove_duplicates(node **list)
{
    // check valid input
    if (list == NULL)
    {
        errno = EINVAL;
        return -2;
    }

    // find duplicate values
    for (node *ptr1 = *list; ptr1 != NULL; ptr1 = ptr1->next)
    {
        bool match = false; // check if the item has found itself in the list
        node *temp = ptr1; // temp pointer to keep track of the node before the match

        for (node *ptr2 = ptr1; ptr2 != NULL; ptr2 = ptr2->next)
        {
            // check if a match is found
            if (ptr2->num == ptr1->num)
            {
                // in case the element already found itself
                if (match)
                {
                    temp->next = ptr2->next; // link the values around the duplicate value
                    free(ptr2); // remove the duplicate value
                    ptr2 = temp; // reset the second pointer
                }
                // in case the element did not find itself yet
                else
                {
                    match = true;
                }
            }
            else
            {
                temp = temp->next; // does not move temp pointer when initial match is found to stay one node behind
            }
        }
    }

    return 0;
}


// get a slice of a list
list list_slice(node *list, int start_index, int end_index)
{
    // check valid input
    if (list == NULL || start_index > end_index)
    {
        errno = EINVAL;
        return NULL;
    }

    // check that start_index and end_index are inbounds
    if (start_index < 0)
    {
        errno = 0;
        return NULL;
    }

    node *new_list = NULL; // craete a new empty list
    node *ptr = list; // create a pointer that points at the start of the user chosen list

    // move the pointer to specified start index
    for (int i = 0; i < start_index; i++)
    {
        ptr = ptr->next;
    }

    for (int i = start_index; i < end_index; i++)
    {
        // check if end index is out of bounds
        if (ptr == NULL)
        {
            list_clear(&new_list);
            errno = 0;
            return NULL;
        }

        // in case of unsuccessful prepending
        if (list_prepend(&new_list, ptr->num) != 0) // uses prepend with reversed order for better time complexity [O(1) instead of O(n)]
        {
            list_clear(&new_list); // clear partially created list
            errno = ENOMEM; // exit with an error
            return NULL;
        }

        ptr = ptr->next; // move pointer to new node in the user chosen list
    }

    list_reverse(&new_list);

    return new_list;
}


// sort the list in ascending order
int list_sort(node **list, bool ascending)
{
    // check valid input
    if (list == NULL || *list == NULL)
    {
        errno = EINVAL;
        return -2;
    }

    *list = list_merge_sort(*list, ascending);
    return 0;
}


// recursive merge sort function
list list_merge_sort(node *list, bool ascending)
{
    // check base case
    if (list == NULL || list->next == NULL)
    {
        return list;
    }

    // creating three pointers to point at the start of the list
    node *end = list; // will point at the end of the list
    node *right = list; // will point at the start of the right half of the list
    node *prev = list; // will point at the end of the left half of the list

    bool temp = false; // create a helper boolean

    // move the end pointer to the end of the list
    while (end != NULL)
    {
        end = end->next;

        // move the right pointer at half speed to get to the middle of the list
        if (temp)
        {
            // ensure the prev pointer is one node behind the right pointer
            if (prev != right)
            {
                prev = prev->next;
            }

            right = right->next;

            temp = false;
        }
        else
        {
            temp = true;
        }
    }

    // set left list
    node *left = list;
    prev->next = NULL; // separate the two lists

    right = list_merge_sort(right, ascending);
    left = list_merge_sort(left, ascending);

    return list_merge(left, right, ascending);
}


// merge sorted halves
list list_merge(node *left, node *right, bool ascending)
{
    // check valid input
    if (left == NULL)
    {
        return right;
    }

    if (right == NULL)
    {
        return left;
    }

    node *new_list = NULL; // create a new empty list
    node *temp = new_list; // create a new list pointer

    // pointers to traverse left and right halves
    node *ptr1 = left;
    node *ptr2 = right;

    // link the first node to the new list
    if (ptr1->num < ptr2->num)
    {
        if (ascending)
        {
            new_list = ptr1;
            temp = new_list;
            ptr1 = ptr1->next;
        }
        else
        {
            new_list = ptr2;
            temp = new_list;
            ptr2 = ptr2->next;
        }
    }
    else
    {
        if (ascending)
        {
            new_list = ptr2;
            temp = new_list;
            ptr2 = ptr2->next;
        }
        else
        {
            new_list = ptr1;
            temp = new_list;
            ptr1 = ptr1->next;
        }
    }

    // add the other nodes in order
    if (ascending)
    {
        while (ptr1 != NULL && ptr2 != NULL)
        {
            if (ptr1->num < ptr2->num)
            {
                temp->next = ptr1;
                temp = temp->next;
                ptr1 = ptr1->next;
            }
            else
            {
                temp->next = ptr2;
                temp = temp->next;
                ptr2 = ptr2->next;
            }
        }
    }
    else
    {
        while (ptr1 != NULL && ptr2 != NULL)
        {
            if (ptr1->num > ptr2->num)
            {
                temp->next = ptr1;
                temp = temp->next;
                ptr1 = ptr1->next;
            }
            else
            {
                temp->next = ptr2;
                temp = temp->next;
                ptr2 = ptr2->next;
            }
        }
    }

    // link any remaining nodes
    while (ptr1 != NULL)
    {
        temp->next = ptr1;
        temp = temp->next;
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL)
    {
        temp->next = ptr2;
        temp = temp->next;
        ptr2 = ptr2->next;
    }

    temp->next = NULL; // set end node

    return new_list;
}


// reverse the order of the list
int list_reverse(node **list) // Used AI for cleaning and optimization of time complexity
{
    // check valid input
    if (list == NULL)
    {
        errno = EINVAL;
        return -2;
    }

    // create three helper pointers
    node *prev = NULL; 
    node *current = *list;
    node *next = NULL;

    // connect the nodes back to the list in reversed order
    while (current != NULL)
    {
        next = current->next;  // Save next node
        current->next = prev;  // Reverse the link
        prev = current;        // Move pointers forward
        current = next;
    }

    *list = prev; // reset the start of the list

    return 0;
}


// check if there are any leaks in the list
bool list_leak_check(node *list, int expected_length)
{
    // check if list is empty
    if (list == NULL)
    {
        // check if list is supposed to be empty
        if (expected_length == 0)
        {
            printf("Check completed: No leaks found!\n");
            return false;
        }

        printf("Memory leak found!: expected %i nodes and found none\n", list_len(list));
        return true;
    }

    int actual_length = list_len(list);

    // check if length of the list matches the expected length
    if (actual_length == expected_length)
    {
        printf("Check completed: No leaks found!\n");
        return false;
    }
    else
    {
        printf("Memory leak found!: expected %i nodes found %i\n", expected_length, actual_length);
        return true;
    }
}


// check if a value exists in a list
bool list_value_exist(node *list, int value)
{
    // check all elements of the list
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        // in case a match is found
        if (ptr->num == value)
        {
            return true;
        }
    }

    return false;
}


// compare two lists
bool list_compare(node *list1, node *list2)
{
    // check input is valid
    if (list1 == NULL || list2 == NULL)
    {
        if (list1 == NULL && list2 == NULL)
        {
            return true;
        }

        errno = EINVAL;
        return false;
    }

    // compare the two list element by element
    node *ptr1 = list1; // create a pointer that points at the start of first list
    node *ptr2 = list2; // create a pointer that points at the start of second list
    
    while (ptr1 != NULL && ptr2 != NULL)
    {
        // check if the numbers of each node matches
        if (ptr1->num != ptr2->num)
        {
            return false;
        }

        // move to the next node
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return ptr2 == ptr1; // true if both reached NULL in the loop
}


// unify two lists
int list_unify(node **list1, node *list2)
{
    // check valid input
    if (list1 == NULL)
    {
        errno = EINVAL;
        return -2;
    }

    // in case list1 is empty
    if (*list1 == NULL)
    {
        *list1 = list2;
        return 0;
    }

    // in case list2 is empty
    // not neccessary but significantly improves time complexity of the function in case of empty list2
    if (list2 == NULL)
    {
        return 0;
    }

    node *ptr1 = *list1; // create a pointer that points at the start of first list

    // get ptr1 at the last node of the first list to start appending
    while (ptr1->next != NULL)
    {
        ptr1 = ptr1->next;
    }

    ptr1->next = list2; // append the second list to the first list

    return 0;
}


// get the intersecting nodes of two lists
list list_intersect(node *list1, node *list2)
{
    // check if either list is empty
    if (list1 == NULL || list2 == NULL)
    {
        return NULL;
    }

    list new_list = NULL; // create a new list
    node *temp = new_list; // create a pointer that points at the start of the new list

    // check each value of list1
    for (node *ptr = list1; ptr != NULL; ptr = ptr->next)
    {
        if (!list_value_exist(new_list, ptr->num))
        {
            // check if a match exists with list2
            if (list_value_exist(list2, ptr->num))
            {
                // in case of unsuccessful prepending
                if (list_prepend(&new_list, ptr->num) != 0) // uses prepend with reversed order for better time complexity [O(1) instead of O(n)]
                {
                    list_clear(&new_list); // clear partially created list
                    errno = ENOMEM; // return with an error
                    return NULL;
                }
            }
        }
    }

    list_reverse(&new_list);

    return new_list;
}


// visualise linked list
void list_visualise(node *list) // Used AI for the ASCII art
{
    node *ptr = list;
    
    printf("\n   list\n");
    printf("    |\n");
    printf("    v\n");

    if (list == NULL)
    {
        printf("   NULL\n");
        return;
    }

    while (ptr != NULL) 
    {
        printf("+--------+\n");
        printf("| num: %i |\n", ptr->num);
        printf("+--------+\n");
        printf("| next:--+-|\n");
        printf("+--------+ |\n");
        printf("           v\n");
        
        ptr = ptr->next;
        
        if (ptr == NULL) {
            printf("         NULL\n");
        }
    }
}
