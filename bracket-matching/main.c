#include "bracketMacthing.h"
#include <stdio.h>
int main(int argc, char  *argv[]){
    char* input = argv[1];
    if(breakMatch(input))
    	printf("Bracket Matching");
    else
    	printf("Bracket not Matching");
    return 0;
}