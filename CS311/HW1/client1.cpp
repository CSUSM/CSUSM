// =========================================================

//HW1P1 stack client
//Your name: Mathias LANG
//Compiler: g++  
//File type: C++ source file (.cpp)

//================================================================

#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

int main()
{
    stack postfixstack;  // integer stack
    string expression;
  
    cout << "type a postfix expression: " ;
    cin >> expression;
  
    int i = 0;  // character position within expression
    char item;
  
    int box1, box2, result; // receive things from pop
  
    while (expression[i] != '\0') {
        try {
            item = expression[i++]; //1.  read an item.
//2. if it is an operand (number), push it (you might get Overflow exception)
            if (item >= '0' && item <= '9')
                postfixstack.push(item - '0');
            //3.  else if it is an operator,
            //    pop the two operands (you might get Underflow exception), and
            //	 apply the operator to the two operands, and
            //    push the result.
            else if ((item == '+') || (item == '-') || (item == '*')
                     || (item == '*') || (item == '*')) {
                postfixstack.pop(box1);
                postfixstack.pop(box2);
                switch (item) {
                case '+':
                    result = box2 + box1;
                    break;
                case '-':
                    result = box2 - box1;
                    break;
                case '*':
                    result = box2 * box1;
                    break;
                case '/':
                    result = box2 / box1;
                    break;
                case '%':
                    result = box2 % box1;
                    break;
                }
                postfixstack.push(result);
            }
            else
                throw "invalid item";
	} // this closes try
      
        // Catch exceptions and report problems and quit the program now. 
        catch (stack::Overflow) {
            std::cerr << "Error: Number of digit is not proportional to "
                "the number of operations (too many numbers)." << std::endl;
            return -1;
        } catch (stack::Underflow) {
            std::cerr << "Error: Number of digit is not proportional to "
                "the number of operations (too few numbers)." << std::endl;
            return -1;
        } catch (char const* errorcode) { // for invalid item
            std::cerr << "Error: " << errorcode << std::endl;
            return -1;
        }
    } // end of while
    postfixstack.pop(result);
    // After the loop successfully completes: 
    // The result will be at the top of the stack. Pop it and show it.
    // If anything is left on the stack, an incomplete expression was found
    // inform the user.
    std::cout << "Result is: " << result << std::endl;
    if (!postfixstack.isEmpty()) {
        std::cerr << "--------------------" << std::endl;
        std::cerr << "------- ERROR ------" << std::endl;
        std::cerr << "--------------------" << std::endl;
        std::cerr << "Some operand were not processed: "
            "Not enough operator provided in the expression" << std::endl;
        std::cerr << "Dump of stack:" << std::endl;
        postfixstack.displayAll();
    }
}
