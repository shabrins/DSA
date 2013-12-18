#include <stdlib.h>
typedef int (*compare)(void* first, void* second);

void isort(void* base, size_t numberOfElements, size_t elementSize,
			compare comp); 

typedef char String[256];

typedef struct {
	int accountNumber;
	int balance;
	String name;
} Account;

int compareAccountsByAccountNumber(void* first, void* second);
int compareAccountsByBalance(void* first, void* second);
int compareAccountsByName(void* first, void* second);