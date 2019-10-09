#include "Table.h"

using namespace std;

Table::Table() { 
    head = NULL; 
}
Table::~Table() { 
    head = NULL; 
}

void Table::setRow(int r) { 
    row = r; 
}
void Table::setCol(int c) { 
    col = c; 
}
void Table::setValue(int r,int c,int val){ 
    //set the head to a temp node
	Node* temp = head; 
	
	//loop through the linkedlist
    for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++){
		    //check if we have accessed the given node coordinates
			if(i == r && j == c) { 
			    //set the node value to the given value
			    temp->value = val; 
			    
			    //cout << "Row: " << r << " Col: " << c << " Val: " << temp->value << endl;  //used to output the node coordinates & its value 
			    return; //end the loop & return to main program
			}
			
		    //check is the this is the first row or one of the even numbered rows
			if (i ==0 || i % 2 == 0){
			    //if yes, move the temp node to the right
			    temp = temp->right; 
			}
			else { 
			    //if no, move the temp node to the left
			    temp = temp->left;
			}
		}
		
		if (temp->down != NULL) {
    		//move the temp node down so it can go through each row
    		temp = temp->down; 
		}
	}
}

int Table::getValue(int r,int c){ 
    //set the head to a temp node
	Node* temp = head; 
	
	//loop through the linkedlist
    for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++){
		    //check if we have accessed the given node coordinates
			if(i == r && j == c) { 
			    //get the node value
			    int val = temp->value; 
			    return val; //end the loop & return to main program
			}
			
		    //check is the this is the first row or one of the even numbered rows
			if (i ==0 || i % 2 == 0){
			    //if yes, move the temp node to the right
			    temp = temp->right; 
			}
			else { 
			    //if no, move the temp node to the left
			    temp = temp->left;
			}
		}
		
		if (temp->down != NULL) {
    		//move the temp node down so it can go through each row
    		temp = temp->down; 
		}
	}
	
	return 0; 
}

void Table::createTable() { 
    Node*** nodeArray; 
    
    //create a new node array for every new row 
    nodeArray = new Node** [row];
    
    //loop through each row and add a new node based on col size
    for(int i=0; i<row; i++) { 
        nodeArray[i] = new Node* [col]; 
    }
    //loop to add a new node at every coordinate of the 2D node array
    for(int i=0; i<row;i++){
        for(int j=0; j<col;j++) { 
            nodeArray[i][j] = new Node();
        }
    }
    
    //loop through the linkedlist
    for(int i=0; i<row;i++){
        for(int j=0; j<col;j++) { 
            //set the pointers 
            nodeArray[i][j]->left = ((i==0)? NULL : nodeArray[i-1][j]);
            nodeArray[i][j]->right = ((i==row-1)? NULL : nodeArray[i+1][j]);
            nodeArray[i][j]->up = ((j==0)? NULL : nodeArray[i][j-1]);
            nodeArray[i][j]->down = ((j==col-1)? NULL : nodeArray[i][j+1]);
            nodeArray[i][j]->value = 0;
        }
    }
    
    //set the head to the first node in the array
    head = nodeArray[0][0]; 
    
    /* Used for checking if the correct size of the table was outputted
    //loop to print out the addresses of each node
    for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << nodeArray[i][j] << "  ";
		cout << endl;
	}
	*/

}

//method to loop to print out the value of each node
void Table::print(){ 
    //set the head to a temp node
	Node* temp = head; 
	
	//loop through the linkedlist
    for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++){
			cout << temp->value << "  ";
			
			//check is the this is the first row or one of the even numbered rows
			if (i ==0 || i % 2 == 0){
			    //if yes, move the temp node to the right
			    temp = temp->right; 
			}
			else { 
			    //if no, move the temp node to the left
			    temp = temp->left;
			}
		}
		//make sure there is a break at the end of each column to get ready for the output of the next row
		cout << endl;
		
		if (temp->down != NULL) {
    		//move the temp node down so it can go through each row
    		temp = temp->down; 
		}
	}
}