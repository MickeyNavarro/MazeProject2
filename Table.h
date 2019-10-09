#ifndef TABLE_H
#define TABLE_H

#include "Node.h"
#include<bits/stdc++.h>

class Table
{
	Node* head;
	int row; 
	int col;
public:
    Table(); 
    ~Table(); 
    void setRow(int); 
    void setCol(int); 
    void setValue(int,int,int); 
    int getValue(int,int); 
    void createTable(); 
    void print(); 
    Node* nodeAt(int,int); 
};

#endif