#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include "Table.h"
#include "Node.h"

using namespace std;

//Almicke Navarro 
//CST-201 
//October 2, 2019 
//This is Nasser Tadayon's Maze Project 1 code. The implementation of the LinkedList is my own code. The set up of the Table class & method names were provided by Nasser. 

//This code was created via the https://www.onlinegdb.com/online_c++_compiler# for the language of C++ 17
    //this might be the reason for any unknown errors
void printArray(int** array, int c, int r)
{
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++)
			cout << array[i][j] << "  ";
		cout << endl;
	}

}
int main(){
    
    int row, col;						// Dimension of the Maze
	int start1, start2;					// Index for start point
	int end1, end2;						// Index for end point
	int r, c;							// Used for filling the two dimensioal array
	ifstream input ("input_file.txt");		// Read from the input file
	ofstream output("output_file.txt");	// Store in output file
	string in;							// Read one line at a time and store in string in
	if (!input || !output)				// Check if the file is opened
	{
		cout << "could not open the file." << endl;
		exit(1);
	}
	else
	{
	    getline(input,in);							// Read the first line (dimensions)
		col = stoi(in);								// Read the row
		int find = in.find(',');					// Find the ,
		row = stoi(in.substr(find + 1, in.size()));	// Read the column
		cout << "Row: " << row << endl;
		cout << "Column: "<< col << endl;			// Check the results
		in.erase();									// Clear the in string to read the next line
		getline(input, in);							// Read then next line for indexes of start
		start2 = stoi(in.substr(1, in.size()));		// Read the column index for start
		in = in.substr(in.find(',') + 1, in.size());// Move string in forward
		start1 = stoi(in);							// Read the row index for start
//		cout << start1 << "   " << start2 << endl;		// Checking if it was set correctly
		in.erase();									// Reset string in to empty string for next line
		getline(input, in);							// Read then next line for indexes of end
		end2 = stoi(in.substr(1, in.size()));		// Read the column index for end
		end1 = stoi(in.substr(in.find(',') + 1, in.size()));	// Read the row index for end
//		cout << end1 << "   " << end2 << endl;			// Checking if it was set correctly

		
		Table Table; 
		
		Table.setRow(row); 
		Table.setCol(col); 
		Table.createTable();
		/*
		//Checking if the setValue worked correctly
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++){
			    Table.setValue(i, j, 1); 
			}
		}
		*/
		
		//set the end & start 
		Table.setValue(start1, start2, 2); 
		Table.setValue(end1, end2, 3); 

		while (!input.eof())					// Read the rest of the file
		{
			in.erase();							// empty string in to get the new line from the file
			getline(input,in);					// Get the next line
//			cout << in << endl;					// Checking
			while (in.size() > 3)				// get the coordinates of blocks and set them in array as 1
			{
				c = stoi(in.substr(in.find('(')+1, in.size()));		// Read the row for each block
				//cout << c;											// Check
				r = stoi(in.substr(in.find(',') + 1, in.size()));	// Read the column for each block
				//cout << "  " << r << endl;							// Check
				Table.setValue(r, c, 1);                                // Set LinkedList value to 1 at the given coordinates
				in = in.substr(in.find(')') + 2, in.size());		// Move in string forward to read the next one
				//cout << in << endl;									// check if the in string is correct
			}	
		}
		
		Table.print(); 
		
		/* Start to print the result into output file*/
		
		output << " ";							// Format according to requirement for first row
		for (int i = 0; i < col; i++)
			output << setw(3) <<i ;
		output << endl;
		
		
		for (int i = 0; i < row; i++)			// Go through different rows
		{			
			for (int line = 0; line < 3; line++) {		// For each line there are 3 lines to output
				if (line != 1)
					output << "  ";						// row index
				else
					output << setw(2)<<left << i;

				for (int j = 0; j < col; j++) {			// go through each value in array and write 3 lines for each
					switch (Table.getValue(i,j)) {
						case 0:
							output << "...";
							break;
						case 1:
							output << "XXX";
							break;
						case 2:
							if (line != 1)
								output << "...";
							else
								output << ".S.";
							break;
						case 3:
							if (line != 1)
								output << "...";
							else
								output << ".F.";
							break;
						default:
							break;
					}
				}
				output << endl;
			}			
		}
		input.close();							// Closing the input file
		output.close();							// Closing the output file
	}

}