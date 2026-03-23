#include "ArrayStack.hpp"
#include <iostream>

using namespace std;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

double gRec(unsigned);
double gStack(unsigned);

struct Frame {  // because funny
    unsigned i;
    bool done;
};

/*******************************************************************************
 * Description:
 * Starting point of the program. Calls two functions in two different ways:
 * recursive and iterative. The outputs for both function calls should match
 * exactly.
 * 
 * Input:
 * N/A
 * 
 * Output:
 * An integer to signal to the OS the exit code.
*******************************************************************************/

int main() {
    unsigned startValue = 0;

    cout << "Enter the starting value for i: ";
    cin  >> startValue;

    cout << "\nRecursive:\n";
    cout << gRec(startValue) << endl;

    cout << "\nIterative:\n";
    cout << gStack(startValue) << endl;

    return 0;
}

/*******************************************************************************
 * Description:
 * Recursive function that calculates a result. Displays a message when a base
 * case is reached.
 * 
 * Input:
 * i - an unsigned value that determines whether or not this is a base case
 * 
 * Output:
 * The result of 1.1n + 3.2, where n is the depth of recursion
*******************************************************************************/

double gRec(unsigned i) {
    if (i == 0) {
        cout << "Base case!\n";
        return 3.2;
    }
    
    return gRec(i - 1) + 1.1;
}

/*******************************************************************************
 * Description:
 * Iterative function that simulates recursion using a stack. Calculates a
 * result. Displays a message when a base case is reached.
 * 
 * Input:
 * i - an unsigned value that determines whether or not this is a base case
 * 
 * Output:
 * The result of 1.1n + 3.2, where n is the depth of recursion
*******************************************************************************/
// this way felt boring

// double gStack(unsigned i) {
//     ArrayStack<unsigned> recStack;

//     while (i > 0) {
//         recStack.push(i);
//         --i;
//     }    

//     double result = 3.2;
//     cout << "Base case!\n";

//     while (!recStack.isEmpty()) {
//         recStack.pop();
//         result += 1.1;
//     }

//     return result;
//     // TODO
// }

double gStack(unsigned i) {
    ArrayStack<Frame> frameStack;  // it's a stack of frames....a stack frame even :D

    frameStack.push({i, false});

    double result = 0.0;

    while (!frameStack.isEmpty()) {  // build up "frame" stack in descending i value and then pop it away 
        Frame top = frameStack.peek();
        frameStack.pop();

        if (top.i == 0) {  //base case
            result += 3.2;
        } else if (!top.done) { // not base case and we haven't processed frame, starts at largest i
            top.done = true;
            frameStack.push(top); // haven't reached 0, so push i value on top for now
            frameStack.push({top.i-1, false});  // dec i and push on top 
        } else {
            result += 1.1;  // stack will have multiple frames with i's in ascending order, and all have been processed
        }
    }
    return result;
}