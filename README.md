# CS50++

---

### Video Demo: https://youtu.be/UdhWuBaEuFA

### **Table of Contents**
1. [Description](#description)
2. [Usage](#usage)
   - [Installation](#installation)
   - [Example Usage](#example-usage)
3. [Error Codes](#error-codes)
4. [Function Reference](#function-reference)
5. [Design Decisions](#design-decisions)
6. [Library Functions](#library-functions)
   - [Important Note](#important-note)
   - [`list_print`](#list_print)
   - [`list_head`](#list_head)
   - [`list_tail`](#list_tail)
   - [`list_addresses`](#list_addresses)
   - [`list_demo`](#list_demo)
   - [`list_generate`](#list_generate)
   - [`list_prepend`](#list_prepend)
   - [`list_append`](#list_append)
   - [`list_add_ordered`](#list_add_ordered)
   - [`list_insert`](#list_insert)
   - [`list_count`](#list_count)
   - [`list_index`](#list_index)
   - [`list_value`](#list_value)
   - [`list_to_array`](#list_to_array)
   - [`list_copy`](#list_copy)
   - [`list_max`](#list_max)
   - [`list_min`](#list_min)
   - [`list_sum`](#list_sum)
   - [`list_len`](#list_len)
   - [`list_avg`](#list_avg)
   - [`list_clear`](#list_clear)
   - [`list_remove`](#list_remove)
   - [`list_delete`](#list_delete)
   - [`list_pop`](#list_pop)
   - [`list_remove_duplicates`](#list_remove_duplicates)
   - [`list_slice`](#list_slice)
   - [`list_sort`](#list_sort)
   - [`list_reverse`](#list_reverse)
   - [`list_leak_check`](#list_leak_check)
   - [`list_value_exist`](#list_value_exist)
   - [`list_compare`](#list_compare)
   - [`list_unify`](#list_unify)
   - [`list_intersect`](#list_intersect)
   - [`list_visualise`](#list_visualise)
7. [Future Enhancements](#future-enhancements)  

---

## Description

CS50++ is a custom C library designed to provide Python-like list functionality to C programmers, especially CS50 students. It’s the tool I wish I had while solving the problem sets, particularly before Week 5, and a response to the moments where Professor Malan waved his hands past implementation details I was itching to explore.

This library abstracts away the low-level complexity of working with linked lists in C by offering clean, user-friendly functions for list creation, insertion, deletion, slicing, searching, sorting, visualization, and more. On the surface, these lists behave much like Python lists or arrays with extended features. But under the hood, they still involve all the pointer manipulation and memory management typical of C, just packaged in a way that doesn’t frustrate beginners.

> **Note**: CS50++ is currently designed to work with `int` data only.

### The focus of this library is to:

- Serve as a guide for students who are new to linked lists
- Motivate curious learners to later reimplement these functions with improved performance
- Save time for students using linked lists in larger projects
- Help students *see* and *feel* how linked lists work, using visual tools like `list_visualise` and `list_addresses`
- Act as a debugging companion via helpers like `list_print` and `list_visualise`
- Reinforce key C concepts like initializing pointers with `NULL`, using `&` for memory addresses, and freeing memory explicitly with `list_clear`

---

## Usage

### Installation

1. Copy `cs50++.o` and `cs50++.h` into your project directory.

2. Include it in your project file:

```c
#include "cs50++.h"
```

3. Declare a list:

```c
list my_list = NULL; // must be declared as NULL to avoid unpredictable behaviour
```
> **Important note**: Lists must use `list` data type to initialise and be initialised to `NULL`.

4. Use any available function. For example:

```c
list_append(&my_list, 5);
list_sort(&my_list, true);
list_print(my_list);
```

5. Compile the file using C compiler

Example with GCC:
```c
gcc -o file_name file_name.c cs50++.o
```
Example with CLang:
```c
clang -o file_name file_name.c cs50++.o
```

### Example usage

```c
#include "cs50++.h"  // Include the library header

int main(void) {
    // Always initialize lists as NULL
    list my_list = NULL;
    
    // Example operations
    list_append(&my_list, 5);
    list_sort(&my_list, true);
    list_print(my_list);
    
    // Clean up when done
    list_clear(&my_list);
    return 0;
}
```
> **Important note** :Always call `list_clear` when done with a list. The library does not automatically free memory.

---

## Error Codes

Functions in CS50++ that return `int` or `int`-like values use standardized error signaling.

### For functions that return an `int` status:
- `0` — Success
- `-1` — Not found
- `-2` — Invalid input
- `-3` — Memory allocation failure

### For functions that return an actual `int` value (e.g., `list_value`, `list_index`):
- `INT_MIN` — Used to indicate an error (e.g., invalid index, empty list, allocation failure)

### For functions that return a `list`-type (e.g., `list_demo`, `list_copy`):
- `NULL` — Used to indicate an error (e.g., invalid index, empty list, allocation failure)

> **Note**: When a function returns an actual `int` (like `list_pop()` or `list_value()`), `INT_MIN` is used as a sentinel error value instead of negative codes, to avoid ambiguity with valid negative numbers.

---

## Function Reference

All list operations use the `list` data type, defined as:

```c
typedef struct node {
    int num;
    struct node *next;
} node;

typedef node* list; // for an easier type call
```

---

## Design Decisions

CS50++ is meant to be beginner-friendly, educational, and practical. Design decisions include:
- Descriptive function names and return values
- Explicit memory management for learning clarity
- Safety checks and errno usage
- Visual tools to reinforce abstract concepts

It was designed as a tool that is reusable, not just a project to be put on the shelf once it is submitted. It is a companion and helper to all future CS50 students or anyone learning C.

---

## Library Functions

### Important note:

Read-only functions do not modify the input and require just the name of the list `list_name`, while Writing functions modify the input and require the address of the list `$list_name`.

Example Usage:

```c
list_print(my_list); // Read-only function
list_prepend(&my_list); // Write function
```

### `list_print`

**Description:**
Prints all elements of the linked list in a formatted array-like style.

**Syntax:**

```c
void list_print(node *list);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = NULL;
list_prepend(&mylist, 3);
list_prepend(&mylist, 2);
list_prepend(&mylist, 1);
list_print(mylist);
```

**Expected Output:**

```
[1, 2, 3]
```

---

### `list_head`

**Description:**
Prints the first `num` elements of the list.

**Syntax:**

```c
void list_head(node *list, int num);
```

**Type:** Read-only

**Time Complexity:** O(1)

**Usage:**

```c
list mylist = list_generate(1, 10, 1);
list_head(mylist, 3);
```

**Expected Output:**

```
[1, 2, 3]
```

---

### `list_tail`

**Description:**
Prints the last `num` elements of the list.

**Syntax:**

```c
void list_tail(node *list, int num);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 10, 1);
list_tail(mylist, 3);
```

**Expected Output:**

```
[8, 9, 10]
```

---

### `list_addresses`

**Description:**
Prints the memory addresses of each node in the list.

**Syntax:**

```c
void list_addresses(node *list);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = NULL;
list_append(&mylist, 42);
list_append(&mylist, 84);
list_addresses(mylist);
```

**Expected Output (example):**

```
list -> 0x564b8a2d8f40 -> 0x564b8a2d8f70 -> NULL
```

---

### `list_demo`

**Description:**
Generates a sample list based on a predefined configuration. 
AVailable demos: 1, 2, 3, 4, 5.
demo 1 = [0, 1, 2, 3, 4, 5]
demo 2 = [5, 4, 3, 2, 1, 0]
demo 3 = [42, 71, 91, 13, 4, 3, 53, 4, 11, 86, 1, 0, 34, 7, 4, 9, 21, 0, 4]
demo 4 = numbers from 0 to 10000.
demo 5 = random large and small numbers both positive and negative

**Syntax:**

```c
list list_demo(int num);
```

**Time Complexity:** O(k), where k depends on the selected demo.
> uses prepend with reversed order for better time complexity [O(1) instead of O(n)]

**Usage:**

```c
list mylist = list_demo(1);
list_print(mylist);
```

**Expected Output (example for demo 1):**

```
[0, 1, 2, 3, 4, 5]
```

---

### `list_generate`

**Description:**
Generates a list of integers from `start` to `end` (inclusive) with a given step. Negative steps are allowed.

**Syntax:**

```c
list list_generate(int start, int end, int step);
```

**Time Complexity:** O(k), where k = |(end - start)/step|
> uses prepend with reversed order for better time complexity [O(1) instead of O(n)]

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
list_print(mylist);
```

**Expected Output:**

```
[1, 2, 3, 4, 5]
```

---

### `list_prepend`

**Description:**
Adds a new element to the beginning of the list.

**Syntax:**

```c
int list_prepend(node **list, int num);
```

**Type:** Writing

**Time Complexity:** O(1)

**Usage:**

```c
list mylist = NULL;
list_prepend(&mylist, 1);
list_prepend(&mylist, 2);
list_prepend(&mylist, 3);
list_print(mylist);
```

**Expected Output:**

```
[3, 2, 1]
```

---

### `list_append`

**Description:**
Adds a new element to the end of the list.

**Syntax:**

```c
int list_append(node **list, int num);
```

**Type:** Writing

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = NULL;
list_append(&mylist, 1);
list_append(&mylist, 2);
list_append(&mylist, 3);
list_print(mylist);
```

**Expected Output:**

```
[1, 2, 3]
```

---

### `list_add_ordered`

**Description:**
Adds an element to the list in sorted order, either ascending or descending.

**Syntax:**

```c
int list_add_ordered(node **list, int num, bool ascending);
```

**Type:** Writing

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = NULL;
list_add_ordered(&mylist, 5, true);
list_add_ordered(&mylist, 2, true);
list_add_ordered(&mylist, 3, true);
list_print(mylist);
```

**Expected Output:**

```
[2, 3, 5]
```

---

### `list_insert`

**Description:**
Inserts a new element at the specified index. Index starts at 0.

**Syntax:**

```c
int list_insert(node **list, int num, int index);
```

**Type:** Writing

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_demo(1);
list_insert(&mylist, 99, 3);
list_print(mylist);
```

**Expected Output:**

```
[0, 1, 2, 99, 3, 4, 5]
```

---

### `list_count`

**Description:**
Returns the number of times a specific value appears in the list.

**Syntax:**

```c
int list_count(node *list, int value);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
list_append(&mylist, 3);
list_append(&mylist, 3);
int count = list_count(mylist, 3);
printf("%d\n", count);
```

**Expected Output:**

```
3
```

---

### `list_index`

**Description:**
Returns the index of the first occurrence of a specified value in the list. Returns `-1` if not found, or `-2` for invalid input.

**Syntax:**

```c
int list_index(node *list, int value);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
int index = list_index(mylist, 4);
printf("%d\n", index);
```

**Expected Output:**

```
3
```

---

### `list_value`

**Description:**
Returns the value at the specified index in the list. Returns `INT_MIN` if the index is invalid or out of bounds.

**Syntax:**

```c
int list_value(node *list, int index);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
int value = list_value(mylist, 2);
printf("%d\n", value);
```

**Expected Output:**

```
3
```

---

### `list_to_array`

**Description:**
Converts the linked list into a dynamically allocated array. The user is responsible for freeing the returned array.

**Syntax:**

```c
int *list_to_array(node *list);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
int *array = list_to_array(mylist);

for (int i = 0; i < list_len(mylist); i++)
{
    printf("%d ", array[i]);
}
free(array);
```
> **Note:** Should free the array at the end to avoid memory leaks.

**Expected Output:**

```
1 2 3 4 5
```

---

### `list_copy`

**Description:**
Creates and returns a new list that is a deep copy of the original.

**Syntax:**

```c
list list_copy(node *list);
```

**Type:** Read-only

**Time Complexity:** O(n)
> uses prepend with reversed order for better time complexity [O(1) instead of O(n)]

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
list newlist = list_copy(mylist);
list_print(newlist);
```

**Expected Output:**

```
[1, 2, 3, 4, 5]
```

---

### `list_max`

**Description:**
Returns the maximum value stored in the list. Returns `INT_MIN` if the list is empty.

**Syntax:**

```c
int list_max(node *list);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
printf("%d", list_max(mylist));
```

**Expected Output:**

```
5
```

---

### `list_min`

**Description:**
Returns the minimum value stored in the list. Returns `INT_MAX` if the list is empty.

**Syntax:**

```c
int list_min(node *list);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
printf("%d", list_min(mylist));
```

**Expected Output:**

```
1
```

---

### `list_sum`

**Description:**
Returns the sum of all values in the list. Returns `0` if the list is empty.

**Syntax:**

```c
int list_sum(node *list);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
printf("%d", list_sum(mylist));
```

**Expected Output:**

```
15
```

---

### `list_len`

**Description:**
Returns the number of elements in the list.

**Syntax:**

```c
int list_len(node *list);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
printf("%d", list_len(mylist));
```

**Expected Output:**

```
5
```

---

### `list_avg`

**Description:**
Returns the average of all values in the list as a float. Returns `0` if the list is empty.

**Syntax:**

```c
float list_avg(node *list);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
printf("%.2f", list_avg(mylist));
```

**Expected Output:**

```
3.00
```

---

### `list_clear`

**Description:**
Frees all nodes in the list and sets the list to `NULL`. This is the correct way to fully delete a list and avoid memory leaks.

**Syntax:**

```c
void list_clear(node **list);
```

**Type:** Writing

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
list_clear(&mylist);
list_print(mylist);
```

**Expected Output:**

```
[]
```

---

### `list_remove`

**Description:**
Removes an element at the specified index. Returns `-1` if index is out of bounds, `-2` if input is invalid.

**Syntax:**

```c
int list_remove(node **list, int index);
```

**Type:** Writing

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
list_remove(&mylist, 2);
list_print(mylist);
```

**Expected Output:**

```
[1, 2, 4, 5]
```

---

### `list_delete`

**Description:**
Deletes the first occurrence of a value in the list. Returns `-1` if value not found, `-2` for invalid input.

**Syntax:**

```c
int list_delete(node **list, int value);
```

**Type:** Writing

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
list_delete(&mylist, 3);
list_print(mylist);
```

**Expected Output:**

```
[1, 2, 4, 5]
```

---

### `list_pop`

**Description:**
Removes and returns the last element of the list. Returns `INT_MIN` if the list is empty or input is invalid.

**Syntax:**

```c
int list_pop(node **list);
```

**Type:** Writing

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
int val = list_pop(&mylist);
list_print(mylist);
printf("Popped: %d\\n", val);
```

**Expected Output:**

```
[1, 2, 3, 4]
Popped: 5
```

---

### `list_remove_duplicates`

**Description:**
Removes all duplicate values in the list, keeping only one occurrence of each value.

**Syntax:**

```c
int list_remove_duplicates(node **list);
```

**Type:** Writing

**Time Complexity:** O(n²)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
list_append(&mylist, 3);
list_append(&mylist, 3);
list_remove_duplicates(&mylist);
list_print(mylist);
```

**Expected Output:**

```
[1, 2, 3, 4, 5]
```

---

### `list_slice`

**Description:**
Returns a new list that is a slice from the `start_index` to `end_index` (exclusive). If the indices are invalid, returns `NULL`.

**Syntax:**

```c
list list_slice(node *list, int start_index, int end_index);
```

**Type:** Read-only

**Time Complexity:** O(k), where k = `end_index - start_index`
> uses prepend with reversed order for better time complexity [O(1) instead of O(n)]

**Usage:**

```c
list mylist = list_generate(1, 10, 1);
list sliced = list_slice(mylist, 2, 5);
list_print(sliced);
```

**Expected Output:**

```
[3, 4, 5]
```

---

### `list_sort`

**Description:**
Sorts the list in-place in ascending or descending order using merge sort.

**Syntax:**

```c
int list_sort(node **list, bool ascending);
```

**Type:** Writing

**Time Complexity:** O(n log n)
> Uses merge sort implementation optimized for singly linked lists.

**Usage:**

```c
list mylist = list_generate(5, 1, -1);
list_sort(&mylist, true);
list_print(mylist);
```

**Expected Output:**

```
[1, 2, 3, 4, 5]
```

---

### `list_reverse`

**Description:**
Reverses the order of the list in place.

**Syntax:**

```c
int list_reverse(node **list);
```

**Type:** Writing

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
list_reverse(&mylist);
list_print(mylist);
```

**Expected Output:**

```
[5, 4, 3, 2, 1]
```

---

### `list_leak_check`

**Description:**
Checks if the list has the expected number of nodes. Useful for debugging and ensuring memory integrity. Prints result to console.

**Syntax:**

```c
bool list_leak_check(node *list, int expected_length);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
list_leak_check(mylist, 5);
```

**Expected Output:**

```
Check completed: No leaks found!
```

---

### `list_value_exist`

**Description:**
Checks if a given value exists in the list.

**Syntax:**

```c
bool list_value_exist(node *list, int value);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 5, 1);
bool exists = list_value_exist(mylist, 3);
printf("%s\\n", exists ? "true" : "false");
```

**Expected Output:**

```
true
```

---

### `list_compare`

**Description:**
Compares two lists for equality. Returns true if all elements match in the same order and both lists are the same length. Returns false otherwise.

**Syntax:**

```c
bool list_compare(node *list1, node *list2);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list a = list_generate(1, 5, 1);
list b = list_generate(1, 5, 1);
bool same = list_compare(a, b);
printf("%s\\n", same ? "true" : "false");
```

**Expected Output:**

```
true
```

---

### `list_unify`

**Description:**
Appends the second list to the end of the first. If either list is empty, the function completes with no error.

**Important Note: The function links the first list to the second list for better memory use. The second list remains unchanged but the first list is chnaged to the unified two lists. Freeing the second list will affect the unified list, while freeing the unified list will automatically free the second list. avoid dealing with the second list unless you wish for the changes to be reflected in the unified list. If you wish to maintain the original lists, you may copy them before use using `list_copy`.**

**Syntax:**

```c
int list_unify(node **list1, node *list2);
```

**Type:** Writing for the first list, Read-only for the second list.

**Time Complexity:** O(n) where n is the length of the first list.

**Usage:**

```c
list a = list_generate(1, 3, 1);
list b = list_generate(4, 6, 1);
list_unify(&a, b);
list_print(a);
```

**Expected Output:**

```
[1, 2, 3, 4, 5, 6]
```

---

### `list_intersect`

**Description:**
Returns a new list containing the common values that appear in both lists, without duplicates.

**Syntax:**

```c
list list_intersect(node *list1, node *list2);
```

**Type:** Writing

**Time Complexity:** O(n²)

**Usage:**

```c
list a = list_generate(1, 5, 1);       // [1, 2, 3, 4, 5]
list b = list_generate(3, 7, 1);       // [3, 4, 5, 6, 7]
list c = list_intersect(a, b);
list_print(c);
```

**Expected Output:**

```
[3, 4, 5]
```

---

### `list_visualise`

**Description:**
Displays the linked list as a vertical ASCII diagram showing each node's value and pointer structure. Useful for educational and debugging purposes.

**Syntax:**

```c
void list_visualise(node *list);
```

**Type:** Read-only

**Time Complexity:** O(n)

**Usage:**

```c
list mylist = list_generate(1, 3, 1);
list_visualise(mylist);
```

**Expected Output:**

```
   list
    |
    v
+--------+
| num: 1 |
+--------+
| next:--+-|
+--------+ |
           v
+--------+
| num: 2 |
+--------+
| next:--+-|
+--------+ |
           v
+--------+
| num: 3 |
+--------+
| next:--+-|
+--------+ |
           v
         NULL
```

---

## License

This release includes only the compiled object file `cs50++.o` and header file `cs50++.h` for usage.
The source code is not included in compliance with CS50's academic policy.
The project is licensed under the MIT License.

---

