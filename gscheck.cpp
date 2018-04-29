#include <iostream>
#include <cstdio>
#include "char_stack.h"
using namespace std;

int main(){
	int inc = 0; //incrementor
	int s_size = 0;
	int line = 0;//counting up lines
	char_stack s_words;
	//stack var
	char compare;
	int test = 0;
	char opposite;


	while(inc != EOF){
		char stringline [250];//max characters each line
		cin.getline (stringline, 250,'\n');
		s_size = cin.gcount();
		inc = cin.peek();
		if(inc != EOF){//if newline dectected, subtracts off cin.gcount
			s_size--;
		}
		//input the algorithm here

		for(int i = 0 ; i < s_size ; i++){
			if( (stringline[i] == '(') || (stringline[i] == '{') ||  (stringline[i] == '[') ){
				s_words.push(stringline[i]);
			}else if( (stringline[i] == ')') || (stringline[i] == '}') || (stringline[i] == ']') ){
				if(s_words.empty()){
					cout << "Error on line " << line + 1 << ": Too many " << stringline[i] << endl;
					for(int j = 0 ; j <= i ; j ++){
						cout << stringline[j];
						test++;
					}
					if(test != s_size){
						cout << endl;
						for(int j = 0 ; j <= i ; j ++){
							if(stringline[j] == '\t'){
								cout << '\t';
							}else{
								cout << " ";
							}

						}
						for(i = i + 1; i < s_size ; i ++){
							cout << stringline[i];
						}
						cout << endl;
					}
					return 1;
				}
				compare = s_words.pop();
				if(
				    (compare == '(' && stringline[i] == '}') ||
				    (compare == '(' && stringline[i] == ']') ||
				    (compare == '[' && stringline[i] == ')') ||
				    (compare == '[' && stringline[i] == '}') ||
				    (compare == '{' && stringline[i] == ')') ||
				    (compare == '{' && stringline[i] == ']') 
				    ) {

					if(compare == '('){
						opposite = ')';
					}else if (compare == '['){
						opposite = ']';
					}else if(compare == '{'){
						opposite = '}';
					}

					cout << "Error on line " << line + 1 << ": Read " << stringline[i] << ", expected "  << opposite<< endl;
					for(int j = 0 ; j <= i ; j ++){
						cout << stringline[j];
						test++;
					}
					if(test != s_size){
						cout << endl;
						for(int j = 0 ; j <= i ; j ++){
							if(stringline[j] == '\t'){
								cout << '\t';
							}else{
								cout << " ";
							}

						}
						for(i = i + 1; i < s_size ; i ++){
							cout << stringline[i];
						}
						cout << endl;
					}else{
						cout << endl;
					}
					return 1;
				}
			}

		}

		
		line++;
	}
	if(!s_words.empty()){
		compare = s_words.pop();

		cout << "Error at end of file: Too many " << compare << endl;
		return 1;
	}

	cout << "No Errors Found" << endl;
	return 0;
}