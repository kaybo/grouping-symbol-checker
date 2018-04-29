/* File: char_stack.h       

  Header file for a very basic array-based implementation of a stack.

*/
class char_stack
{
  public:
    char_stack();
    void push( char item );
    char pop(); 
    char top();
    bool empty();
    int size();

  private:
    // fill this in.
    static const int capacity = 250000; //array size 250words * 100lines
    int A[capacity];//array
    int top_index; //index top of the stack
};