/* File: char_stack.cpp

  Implementation of functions for basic simple array-based implementation of a stack.

*/
#include "char_stack.h"// contains the declarations of the variables and functions.

// Fill this in.
char_stack::char_stack(){//constructor
	top_index = -1; //empty stack
}

void char_stack::push(char item){
	top_index = top_index + 1;
	A[top_index] = item;
}

char char_stack::top(){
	return A[top_index];
}

char char_stack::pop(){
	top_index = top_index - 1;
	return A[top_index + 1];
}

bool char_stack::empty(){
	return top_index == -1;
}

int char_stack::size(){
	int top = 0;
	if(top_index == -1){
		return 0;
	}else{
		top = top_index + 1;
		return top;
	}
}