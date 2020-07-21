#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include "list.h"

/*
1) Използвайки имплементирания list от лекции, имплементирайте функции за
 - изтриване на конкретен елемент,
 - изтриване преди конкретен елемент и
 - изтриване след конкретен елемент.

*/

void list_init(list_t *list) {
	pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

	list->head = list->tail = NULL;
	(void)memcpy(&(list->mtx), &mtx, sizeof (mtx));

	return;
}

int add_head(list_t *list, out_types_container_t data) {
	dlist_t *dlist;
	int ret = 0;

	(void)pthread_mutex_lock(&(list->mtx));

	dlist = (dlist_t *)calloc(1lu, sizeof (dlist_t));
	if (!dlist) goto out;
	else ret = 1;

	dlist->data = data;

	if (!list->head) {
		list->head = list->tail = dlist;
	} else {
		dlist->next = list->head;
		list->head->prev = dlist;
		list->head = dlist;
	}

out:	(void)pthread_mutex_unlock(&(list->mtx));

	return ret;
}

int del_head(list_t *list, out_types_container_t *data) {
	dlist_t *dlist;
	int ret = 0;

	(void)pthread_mutex_lock(&(list->mtx));

	if (!list->head) goto out;
	else ret = 1;

	dlist = list->head;
	*data = dlist->data;

	if (!dlist->next) {
		list->head = list->tail = NULL;
	} else {
		dlist->next->prev = NULL;
		list->head = dlist->next;
	}

	free(dlist);

out:	(void)pthread_mutex_unlock(&(list->mtx));

	return ret;
}

int add_tail(list_t *list, out_types_container_t data) {
	dlist_t *dlist;
	int ret = 0;

	(void)pthread_mutex_lock(&(list->mtx));

	dlist = (dlist_t *)calloc(1lu, sizeof (dlist_t));
	if (!dlist) goto out;
	else ret = 1;

	dlist->data = data;

	if (!list->tail) {
		list->head = list->tail = dlist;
	} else {
		dlist->prev = list->tail;
		list->tail->next = dlist;
		list->tail = dlist;
	}

out:	(void)pthread_mutex_unlock(&(list->mtx));

	return ret;
}

int del_tail(list_t *list, out_types_container_t *data) {
	dlist_t *dlist;
	int ret = 0;

	(void)pthread_mutex_lock(&(list->mtx));

	if (!list->tail) goto out;
	else ret = 1;

	dlist = list->tail;
	*data = dlist->data;

	if (!dlist->prev) {
		list->head = list->tail = NULL;
	} else {
		dlist->prev->next = NULL;
		list->tail = dlist->prev;
	}

	free(dlist);

out:	(void)pthread_mutex_unlock(&(list->mtx));

	return ret;
}

void iter_init_head(list_t *list, iter_t *iter) {
	(void)pthread_mutex_lock(&(list->mtx));

	iter->mtx = &(list->mtx);
	iter->iter = list->head;

	return;
}

void iter_init_tail(list_t *list, iter_t *iter) {
	(void)pthread_mutex_lock(&(list->mtx));

	iter->mtx = &(list->mtx);
	iter->iter = list->tail;

	return;
}

void iter_end(iter_t *iter) {
	(void)pthread_mutex_unlock(iter->mtx);

	return;
}

int iter_next(iter_t *iter, out_types_container_t *data) {
	if (!iter->iter) return 0;
	*data = iter->iter->data;
	iter->iter = iter->iter->next;

	return 1;
}

int iter_prev(iter_t *iter, out_types_container_t *data) {
	if (!iter->iter) return 0;
	*data = iter->iter->data;
	iter->iter = iter->iter->prev;

	return 1;
}

int iter_peek(iter_t *iter, out_types_container_t *data) { /* not a good idea in multithreading */
	if (!iter->iter) return 0;
	*data = iter->iter->data;

	return 1;
}

// Del Specific Element from list
int del_element(list_t *list, out_types_container_t *data, iter_t *iter) { // ex del tail
    dlist_t *dlist;
    int ret = 0;

    (void)pthread_mutex_lock(&(list->mtx));

    dlist = list->head;

    // TODO: fix this part	
    while(iter_next(iter, data))
        if( &dlist->data == data) {
            ret=1;
            break;
        }

    if (!dlist->prev) { // This is list tail
        return del_tail(list, data);
    } else if (!dlist->next){ // This is list head
        return del_head(list, data);
    } else if (ret) goto found;

    free(dlist);

out:
    iter_end(iter);
    (void)pthread_mutex_unlock(&(list->mtx));
    return ret;

found:
    dlist->next->prev = dlist->prev;
    dlist->prev->next = dlist->next;
    dlist->prev->next = NULL;

    goto out;
}

// Del the element after the specified element
