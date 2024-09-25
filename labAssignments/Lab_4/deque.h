#ifndef deque_h
#define deque_h

// Deque class represents a double-ended queue with functionality to add/remove elements from both ends.
// Here is the PROTOTYPE for the Deque class, the definitions live on the deque.cpp file.
class Deque {
private:
  // Node structure represents each element in the deque.
  struct Node {
    Node *previousNode;  // Pointer to the previous node in the deque.
    int val;             // Value stored in the node.
    Node *nextNode;      // Pointer to the next node in the deque.
    
    // Constructor to initialize a node with given previous, value, and next pointers.
    Node(Node* cpreviousNode, int cVal, Node* cnextNode);
  };

  Node *frontTop;  // Pointer to the front element of the deque.
  Node *backTop;   // Pointer to the back element of the deque.

public:
  // Constructor: Initializes an empty deque.
  Deque();

  Node *getfrontTop();
  Node *getBackTop();
  
  void setfrontTop(Node *n);
  void setbackTop(Node *n);

  void push_front(int i);
  void push_back(int i);
  
  int pop_front();
  int pop_back();

  int peak_front();
  int peak_back();

  void removeAll();

  // Destructor: Cleans up all nodes when the deque is destroyed.
  ~Deque();
};

#endif
