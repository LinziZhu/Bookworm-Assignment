#include <time.h>
#include <stdlib.h>
#include <pthread.h>

#include "worm.h"

size_t g_nthreads = 4;

// Returns result set containing book with given id.
result_t* find_book(book_t* nodes, size_t count, size_t book_id) {

	// TODO
	return NULL;
}

// Returns result set containing books by given author.
result_t* find_books_by_author(book_t* nodes, size_t count, size_t author_id) {

	// TODO
	return NULL;
}

// Returns result set containing books that have been reprinted by a different publisher.
result_t* find_books_reprinted(book_t* nodes, size_t count, size_t publisher_id) {

	// TODO
	return NULL;
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

// Returns result set containing books in shortest path of two edges types between author 1 and 2.
result_t* find_shortest_edge_type(book_t* nodes, size_t count, size_t a1_id, size_t a2_id) {

	// TODO
	return NULL;
}

