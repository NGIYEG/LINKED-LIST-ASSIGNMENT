The program uses  The Floyd's cycle Algorithm to detect a loop.It uses two pointers ,fast(f) and slow(s).The base cases of the algorithm is if:
-If the fast pointer reaches nullptr,that is at the end of the list
-If the slow and fast pointers meet at somepoint.

The time complexity of Floyd's Algorithm is 
O(n), where 
n is the number of nodes in the linked list.
Since;
The algorithm uses two pointers, slow(s) and fast(f), to traverse the linked list:
The slow(s) pointer moves one node at a time.
The fast(f) pointer moves two nodes at a time.

