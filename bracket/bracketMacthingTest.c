#include "testUtils.h"
#include <stdio.h>
#include "bracketMacthing.h"


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_for_brackets_that_are_not_matching(){
	String str = "[([]";
	ASSERT(breakMatch(str) == 0);
}

void test_for_same_type_of_bracket_for_extra_closing_brace(){
	String str = "[]]]]]";
	ASSERT(breakMatch(str) == 0);
}
void test_for_diff_type_of_bracket_for_extra_closing_brace(){
	String str = "[]})}";
	ASSERT(breakMatch(str) == 0);
}

void test_for_matching_brackets(){
	String str = "([{}])";
	ASSERT(breakMatch(str) == 1);
}
void test_for_matching_backets(){
	String str = "{([])}";
	ASSERT(breakMatch(str) == 1);
}