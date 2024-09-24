#include "deque.h"
#include <iostream>

// Constructor for Node, which initializes the node with a value and links to the previous and next nodes.
Deque::Node::Node(Node *cpreviousNode, int cVal, Node *cnextNode) {
  previousNode = cpreviousNode;  // Link to the previous node
  val = cVal;                    // Value of the node
  nextNode = cnextNode;          // Link to the next node
}

// Constructor for Deque, initializes an empty deque with no elements.
Deque::Deque() {
  frontTop = nullptr;  // No front element in an empty deque
  backTop = nullptr;   // No back element in an empty deque
}

// Getter for the front node in the deque.
Deque::Node *Deque::getfrontTop() { return frontTop; }

// Setter for the front node in the deque.
void Deque::setfrontTop(Node *n) { frontTop = n; }

// Setter for the back node in the deque.
void Deque::setbackTop(Node *n) { backTop = n; }

/* --------------------------------------------------------
 * Function: push_front
 * Usage: push_front(number)
 * --------------------------------------------------------
 * This function inserts a new node at the front of the deque. 
 * If the deque is empty, the new node becomes both front and back; otherwise, it is linked to the current front.
 * ---------------------------------------------------------
 */
void Deque::push_front(int i) {
  // Create a new node with the value i, where nextNode points to the current front.
  Node *newNode = new Node(nullptr, i, frontTop);
  
  // If the deque is empty, the new node becomes both the front and the back.
  if(frontTop == nullptr && backTop == nullptr) { 
        setbackTop(newNode);
        setfrontTop(newNode);
  } else {
        // Otherwise, link the new node to the current front and update frontTop.
        frontTop->previousNode = newNode; 
        setfrontTop(newNode);
  }
}

/* --------------------------------------------------------
 * Function: push_back
 * Usage: push_back(number)
 * --------------------------------------------------------
 * This function inserts a new node at the back of the deque. 
 * If the deque is empty, the new node becomes both front and back; otherwise, it is linked to the current back.
 * ---------------------------------------------------------
 */
void Deque::push_back(int i) {
  // Create a new node with the value i, where previousNode points to the current back.
  Node *newNode = new Node(nullptr, i, backTop);
  
  // If the deque is empty, the new node becomes both the front and the back.
  if(frontTop == nullptr && backTop == nullptr) { 
        setbackTop(newNode);
        setfrontTop(newNode);
  } else {
        // Otherwise, link the new node to the current back and update backTop.
        backTop->nextNode = newNode; 
        setbackTop(newNode);
  }
}

/* --------------------------------------------------------
 * Function: push_back
 * Usage: push_back(number)
 * --------------------------------------------------------
 * This function removes and returns the value from the front of the deque. 
 * If the deque has only one element, both front and back are cleared; otherwise, the front is updated to the next node.
 * ---------------------------------------------------------
 */
int Deque::pop_front() {
  // Check if the deque is not empty.
  if (frontTop != nullptr && backTop != nullptr) {
    int val = frontTop->val;   // Get the value from the front node.
    Node *tempFrontTop = frontTop;  // Temporarily store the front node.
    
    // If there's only one element, clear both front and back.
    if(frontTop == backTop) {
        frontTop = nullptr;
        backTop = nullptr;
    } else {
        // Move the front pointer to the next node and unlink the previous node.
        frontTop = frontTop->nextNode;
        frontTop->previousNode = nullptr;
    }
    delete tempFrontTop;  // Delete the old front node.
    return val;           // Return the value from the front node.
  }
  
  // If the deque is empty, print an error message and return 0.
  std::cout << "Error: Tried popping an empty Deque\n";
  return 0;
}

/* --------------------------------------------------------
 * Function: pop_back
 * Usage: pop_back()
 * --------------------------------------------------------
 * This function removes and returns the value from the back of the deque. 
 * If the deque has only one element, both front and back are cleared; otherwise, the back is updated to the previous node.
 * ---------------------------------------------------------
 */
int Deque::pop_back() {
  // Check if the deque is not empty.
  if (frontTop != nullptr && backTop != nullptr) {
    int val = backTop->val;   // Get the value from the back node.
    Node *tempBackTop = backTop;  // Temporarily store the back node.
    
    // If there's only one element, clear both front and back.
    if(frontTop == backTop) {
        frontTop = nullptr;
        backTop = nullptr;
    } else {
        // Move the back pointer to the previous node and unlink the next node.
        backTop = backTop->previousNode;
        backTop->nextNode = nullptr;
    }
    delete tempBackTop;  // Delete the old back node.
    return val;          // Return the value from the back node.
  }
  std::cout << "Error: Tried popping an empty Deque\n";
  return 0;  // Consider using exceptions for error handling if needed.
}

/* --------------------------------------------------------
 * Function: peak_front
 * Usage: peak_front()
 * --------------------------------------------------------
 * This function returns the value from the front of the deque without removing it. 
 * If the deque is empty, an error message is displayed and 0 is returned.
 * ---------------------------------------------------------
 */
int Deque::peak_front() {
  // Check if the deque is not empty.
  if (frontTop != nullptr) {
    return frontTop->val;  // Return the value from the front node.
  }
  std::cout << "Error: tried peaking an empty Deque\n";
  return 0;
}

/* --------------------------------------------------------
 * Function: peak_back
 * Usage: peak_back()
 * --------------------------------------------------------
 * This function returns the value from the back of the deque without removing it. 
 * If the deque is empty, an error message is displayed and 0 is returned.
 * ---------------------------------------------------------
 */
int Deque::peak_back() {
  // Check if the deque is not empty.
  if (backTop != nullptr) {
    return backTop->val;  // Return the value from the back node.
  }
  std::cout << "Error: tried peaking an empty Deque\n";
  return 0;
}

/* --------------------------------------------------------
 * Function: removeAll
 * Usage: removeAll()
 * --------------------------------------------------------
 * This function removes all elements from the deque by continuously popping elements 
 * from the front until the deque is empty.
 * ---------------------------------------------------------
 */
void Deque::removeAll() {
  // Keep popping elements from the front until the deque is empty.
  while (getfrontTop() != nullptr) {
    int temp = pop_front();
  }
}

// Destructor to clean up any remaining nodes when the deque is destroyed.
Deque::~Deque() { removeAll(); }
