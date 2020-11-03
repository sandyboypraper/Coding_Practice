// recurssion and iteration

// recurssion(node)
// 1. if node->next  == NULL
//     assign it to head
//     and return node
// 2. node1 = reverse a list after one node
// 3. node1->next = node
// 4. return node
//Link -> https://www.geeksforgeeks.org/recursively-reversing-a-linked-list-a-simple-implementation/

// iteratively
// by 3 pointers
// 1. a = NULL , b = head , c = head->next;
// assign b->next to a
// a to b
// b to c
// c to c->next
// untill b != NULL