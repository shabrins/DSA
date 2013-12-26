// typedef struct _list_t_ {
//     char *string;
//     struct _list_t_ *next;
// } list_t;

// typedef struct _hash_table_t_ {
//     int size;       /* the size of the table */
//     list_t **table; /* the table elements */
// } hash_table_t;

//Structure
typedef struct Element {
    int key;
    int value;
} Element; /* you had a syntax error here */

typedef struct HashTable {
    int size; /* we will need the size for the traversal */
    Element *table; /* leave it as a pointer */
} HashTable; /* a syntax error here too */
