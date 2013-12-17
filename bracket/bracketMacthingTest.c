#include "testUtils.h"
#include <stdio.h>
#include "bracketMacthing.h"


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_for_bracket_not_matching(){
	String str = "[([]";
	ASSERT(breakMatch(str) == 0);
}

void test_for_bracket_not_matching_for_same_extra_closing_brace(){
	String str = "[]]]]]";
	ASSERT(breakMatch(str) == 0);
}
void test_for_bracket_not_matching_for_diff_extra_closing_brace(){
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