#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
 
struct entry_s {
 char *key;
 char *value;
 struct entry_s *next;
};
typedef struct entry_s entry_t;
struct hashtable_s {
 int size;
 struct entry_s **table;	
};
typedef struct hashtable_s hashtable_t;

hashtable_t *ht_create( int size ) {
	hashtable_t *hashtable = NULL;
	int i;
 	if( size < 1 ) return NULL;
	if((hashtable = malloc( sizeof( hashtable_t ) ) ) == NULL ) 
		return NULL;
	if( ( hashtable->table = malloc( sizeof( entry_t * ) * size ) ) == NULL ) 
		return NULL;
	for( i = 0; i < size; i++ ) 
		hashtable->table[i] = NULL;
 	hashtable->size = size;
 	return hashtable;	
}
int ht_hash( hashtable_t *hashtable, char *key ) {
 	unsigned long int hashval;
	int i = 0;
 
	while( hashval < ULONG_MAX && i < strlen( key ) ) {
		hashval = hashval << 8;
		hashval += key[i];
		i++;
	}
	return hashval % hashtable->size;
}
entry_t *ht_newpair( char *key, char *value ) {
	entry_t *newpair;
	if( ( newpair = malloc( sizeof( entry_t ) ) ) == NULL ) 
		return NULL;
	 
	if( ( newpair->key = strdup( key ) ) == NULL ) 
		return NULL;
	 
	if( ( newpair->value = strdup( value ) ) == NULL ) 
		return NULL;
	newpair->next = NULL;
	return newpair;
}
 
void ht_set( hashtable_t *hashtable, char *key, char *value ) {
	int bin = 0;
	entry_t *newpair = NULL;
	entry_t *next = NULL;
	entry_t *last = NULL;
	bin = ht_hash( hashtable, key );
	next = hashtable->table[ bin ];
	while( next != NULL && next->key != NULL && strcmp( key, next->key ) > 0 ) {
		last = next;
		next = next->next;
	}
	if( next != NULL && next->key != NULL && strcmp( key, next->key ) == 0 ) {
	 	free( next->value );
		next->value = strdup( value );
	} 
	else {
		newpair = ht_newpair( key, value );
		if( next == hashtable->table[ bin ] ) {
			newpair->next = next;
			hashtable->table[ bin ] = newpair;
		}
		else if ( next == NULL ) {
			last->next = newpair;
		} 
		else {
			newpair->next = next;
			last->next = newpair;
		}
	}
}
 
char *ht_get( hashtable_t *hashtable, char *key ) {
	int bin = 0;
	entry_t *pair;
	bin = ht_hash( hashtable, key );
	 
	pair = hashtable->table[ bin ];
	while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) 
		pair = pair->next;
	if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) 
		return NULL;
	else 
		return pair->value;
}
 2
int main( int argc, char **argv ) {
 	hashtable_t *hashtable = ht_create( 65536 );
	ht_set( hashtable, "key1", "inky");
	ht_set( hashtable, "key2", "pinky");
	ht_set( hashtable, "key3", "blinky");
	ht_set( hashtable, "key4", "floyd");
	ht_set( hashtable, "key5", "raj");

	printf( "%s\n", ht_get( hashtable, "key1" ) );
	printf( "%s\n", ht_get( hashtable, "key2" ) );
	printf( "%s\n", ht_get( hashtable, "key3" ) );
	printf( "%s\n", ht_get( hashtable, "key4" ) );
	printf("%s\n",ht_get(hashtable, "key5") );
	return 0;
}