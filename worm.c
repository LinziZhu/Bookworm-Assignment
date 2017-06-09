#include <time.h>
#include <stdlib.h>
#include <pthread.h>

#include "worm.h"

size_t g_nthreads = 4;
/*
void queue(**int queue, int currentLength, int id){
	queue[currentLength] = id;
}
*/

// Returns result set containing book with given id.
result_t* find_book(book_t* nodes, size_t count, size_t book_id) {

	/*
	//Casting
	int numBooks = (int) count;

	//Initialise queue
	int* queue = malloc(numBooks * sizeof(int));
	int currentQueueLength = 0;

	//Initialise visited
	int* visited = malloc(numBooks * sizeof(int));
	int currentedVisitedLength;

	*/

	book_t ** element = (book_t**) malloc(sizeof(book_t));
	result_t *result = (result_t*) malloc(sizeof(result_t));
	result->n_elements = 0;

	for(int i = 0; i < count; i++){
		if (nodes[i].id == book_id){
			element[0] = &nodes[i];
			result->n_elements += 1;
			result->elements = element;
			break;
		}
	}


	/*
	free(queue);
	free(visited);
	*/

	return result;
}

// Returns result set containing books by given author.
result_t* find_books_by_author(book_t* nodes, size_t count, size_t author_id) {

	book_t ** booklist = (book_t**) malloc(sizeof(book_t) * count);
	result_t *result = (result_t*) malloc(sizeof(result_t));
	result->n_elements = 0;

	for(int i = 0; i < count; i++){
		if (nodes[i].author_id == author_id){
			booklist[0] = &nodes[i];
			result->n_elements = 1;
			break;
		}
	}

	if(booklist[0]){
		for(int i = 0; i < booklist[0]->n_author_edges; i++){
			booklist[i+1] = &nodes[booklist[0]->b_author_edges[i]];
			result->n_elements = result->n_elements += 1;
		}
	}
	result->elements = booklist;

	return result;
}

// Returns result set containing books that have been reprinted by a different publisher.
result_t* find_books_reprinted(book_t* nodes, size_t count, size_t publisher_id) {

	int* publisherBooklist = (int*) malloc(sizeof(int) * count);
	book_t ** booklist = (book_t**) malloc(sizeof(book_t) * count);
	result_t *result = (result_t*) malloc(sizeof(result_t));
	result->n_elements = 0;

	int publisherBooklistCount = 0;
	int currentBooklist = 0;

	for(int i = 0; i < count; i++){
		if(nodes[i].publisher_id == publisher_id){
			publisherBooklist[publisherBooklistCount] = nodes[i].id;
			publisherBooklistCount += 1;
		}
	}

	if(publisherBooklist[0]){
		for(int i = 0; i < count; i++){
			for(int j = 0; j <= publisherBooklistCount; j++){
				if(nodes[i].publisher_id != publisher_id && nodes[i].id == publisherBooklist[j]){
					booklist[currentBooklist] = &nodes[i];
					result->n_elements = result->n_elements += 1;
					currentBooklist += 1;
				}
			}
		}
	}
	result->elements = booklist;



	free(publisherBooklist);

	return result;
}

// Returns result set containing books that are k distance from given book.
result_t* find_books_k_distance(book_t* nodes, size_t count, size_t book_id, uint16_t k) {

	// TODO
	return NULL;
}

// Returns result set containing books in shortest path between book 1 and 2.
result_t* find_shortest_distance(book_t* nodes, size_t count, size_t b1_id, size_t b2_id) {

	// TODO
	return NULL;
}
