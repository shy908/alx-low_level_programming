#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

/* Adding standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listint_s - singly linked list
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 *
 * Description: singly linked list node structure
 */

typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - Singly linked list with an express lane
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: singly linked list node structure with an express lane
 */

typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

/* Prototypes for the project */
/* Linear Search */
int linear_search(int *, size_t, int);

/* Binary Search */
int binary_search(int *, size_t, int);

/* Jump Search */
int jump_search(int *, size_t, int);

/* Interpolation Search */
int interpolation_search(int *, size_t, int);
int get_position(int *, int, size_t, size_t);

/* Exponential Search */
int exponential_search(int *, size_t, int);
