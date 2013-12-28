#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed


int areNodesEqualInt(void* ID, void* data){
        return (*(int*)ID == *(int*)data);
}

Tree tree;
int SUCCESS = 1;
int FAILURE = 0;

void setup(){
	tree = createTree(areNodesEqualInt);
}

void test_to_insert_root(){
	int elements[] = {1,2,3,4,5,6,7,8,9,10};
	int result = insertNode(&tree, NULL, &elements[0]);
	ASSERT(SUCCESS == result);
}

void test_to_insert_nodes_under_root_node(){
	int elements[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 2;
	Iterator it;
	result = insertNode(&tree, NULL, &elements[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &elements[0], &elements[1]);
	insertNode(&tree, &elements[0], &elements[2]);
	it = getChild(&tree, &elements[0]);
	while(it.hasNext(&it)){
		ASSERT(elements[count] == *(int*)(it.next(&it)));
		count--;
	}
}

void test_to_insert_multiple_nodes_at_root_node(){
	int elements[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 3;
	Iterator it;
	result = insertNode(&tree, NULL, &elements[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &elements[0], &elements[1]);
	insertNode(&tree, &elements[0], &elements[2]);
	insertNode(&tree, &elements[0], &elements[3]);
	it = getChild(&tree, &elements[0]);
	while(it.hasNext(&it)){
		ASSERT(elements[count] == *(int*)(it.next(&it)));
		count--;
	}
}

void test_to_insert_child_at_of_root(){
	int elements[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 3;
	Iterator it;
	result = insertNode(&tree, NULL, &elements[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &elements[0], &elements[1]);
	insertNode(&tree, &elements[0], &elements[2]);
	insertNode(&tree, &elements[0], &elements[3]);
	result = insertNode(&tree, &elements[1], &elements[4]);	
	ASSERT(result == SUCCESS);
	it = getChild(&tree, &elements[1]);
	while(it.hasNext(&it)){
		ASSERT(5 == *(int*)(it.next(&it)));
		count++;
	}
}

void test_to_insert_child_at_3rd_layer(){
	int elements[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 3;
	Iterator it;
	result = insertNode(&tree, NULL, &elements[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &elements[0], &elements[1]);
	insertNode(&tree, &elements[1], &elements[2]);
	insertNode(&tree, &elements[2], &elements[3]);
	it = getChild(&tree, &elements[2]);
	while(it.hasNext(&it)){
		ASSERT(4 == *(int*)(it.next(&it)));
		count++;
	}
}

void test_to_check_child_of_a_leaf_node(){
	int elements[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 3;
	Iterator it;
	result = insertNode(&tree, NULL, &elements[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &elements[0], &elements[1]);
	insertNode(&tree, &elements[0], &elements[2]);
	insertNode(&tree, &elements[0], &elements[3]);
	it = getChild(&tree, &elements[1]);
	ASSERT(0 == it.hasNext(&it));
	it = getChild(&tree, &elements[2]);
	ASSERT(0 == it.hasNext(&it));
	it = getChild(&tree, &elements[3]);
	ASSERT(0 == it.hasNext(&it));
}

void test_to_delete_a_node_under_root_node(){
	int elements[] = {1,2,3,4,5,6,7,8,9,10};
	int result ;
	int count = 1;
	Iterator it;
	result = insertNode(&tree, NULL, &elements[0]);
	ASSERT(SUCCESS == result);
	insertNode(&tree, &elements[0], &elements[1]);
	it = getChild(&tree, &elements[0]);
	while(it.hasNext(&it)){
		ASSERT(elements[count] == *(int*)(it.next(&it)));
		count--;
	}
	deleteNode(&tree, &elements[1]);
}