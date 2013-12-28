typedef struct iterator{
	int position;
	void* list;
	void* (*next)(struct iterator* itr);
	int (*hasNext)(struct iterator* itr);

} Iterator;