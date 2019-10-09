#ifndef NODE_H
#define NODE_H

#include<bits/stdc++.h>

class Node
{
public:
	int value;
	Node* right;
	Node* left; 
	Node* up; 
	Node* down; 
	Node(){ 
	    value = 0; 
	    right = NULL;
	    left = NULL; 
	    up = NULL; 
	    down = NULL; 
	}
};

#endif