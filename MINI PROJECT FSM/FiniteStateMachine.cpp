#include <iostream>
#include <fstream>
#include <string.h>
#include <bits/stdc++.h>
#include <vector>
#include <stdio.h>

using namespace std;

struct FSM // declare struct for state, input and nextstate
{
	string state; //declaration for state
	char input; //declaration for input
	string nextstate; //declaration of the next state 
};

int main()
{
	FSM INFO[6]; // declaration of the struct array
	int i = 0;
	
	ifstream myfile;
	myfile.open("C:\\Users\\Sarah Sofiya\\Desktop\\DEGREE\\SEMESTER 3\\CSC510 NOTES\\MINI PROJECT FSM\\CSC510 Project\\CSC510 Project\\project.txt");
	// to open the textfile, you need to fill in your file path.
	
	// if the textfile can be open, it will enter this section and read all the information inside the textfile
	if (myfile.is_open())
	{
		while (myfile >> INFO[i].state >> INFO[i].input >> INFO[i].nextstate)
		{
			i++;
		}
	}
	// if the textfile cannot be open it will enter this section
	else
	{
		cout << "ERROR: input file cannot be opened!" << endl;
	}
	
	//Welcome Screen on the Compiler
	cout<< "===================================================================\n";
	cout<< "==============WELCOME TO FINITE STATE MACHINE======================\n";
	cout<< "===================================================================\n\n";
	cout<< "=========Table of String Finite State Machine Constructed==========\n";
	
	cout<< "====	       State          Input         Next State	===========\n\n";
	
	//will display output of table of String FSM Constructed that has been read from the textfile
	for(int i=0; i<6 ; i++)
	{
		cout<<"		" << INFO[i].state<<"		"<< INFO[i].input<< "		"<< INFO[i].nextstate << endl;
	}	
	cout<< "===================================================================\n";
	cout<<endl<<endl;
	
	// to know either the FSM is NDFA or DFA	
	bool statement = false;

	for (int i=0; i<5; i++)
	{
		if (INFO[i].state == INFO[i+1].state)
		{
			if (INFO[i].input == INFO[i+1].input)
			{
				statement = true;
			}
		}
	}
	
	//if the checking return true value, it will display information below.
	if ( statement = true ){
		cout << "The Finite State Machine is Non-Deterministic Finite Automata\n\n";
	}
	//else, it will display the information below.
	else if ( statement == false ){
		cout<< "The Finite State Machine is Deterministic Finite State Automata\n\n";
	}
	
	//To search if the input insert are rejected or accepted
	string search; //declaration for input for search
	char YorN = 'Y'; 
	
	while ( (YorN != 'N') )
	{
		cout << "Please enter the input to search: ";
		cin >> search;
		
		int size = search.length();
		
		char string_search[size];
		strcpy(string_search, search.c_str());
		
		string output[size];
		output[0] = INFO[0].state;
		
		for (int k = 0 ; k < size ; k++)
		{
			for (int r = 0; r < 6 ; r++ )
			{
				if ((INFO[r].state == output[k]) && (INFO[r].input == string_search[k]))
				{
					output[k+1] = INFO[r].nextstate; // assign the current state to the output array
					
				}
			}
		}
		
		cout << ">> Output : " ;
		for (int k = 0; k < size; k++)
		{
			if (k == size - 1)
			{
				cout << output[k];
				cout << endl;
				cout << endl;
				
				if (INFO[5].state == (output[k]))
				{
					cout << "The string is accepted" << endl; // check current state = the final state	
 				}
 				else
 				{
 					cout << "The string is rejected" << endl;
 				}
				
			}
			else
			{
				cout << output[k] << " > ";
			}
		}
		
		cout << endl;
		
		//enter capital Y if want to continue with the process and enter capital N to exit.
		cout << "Do you want to continue with the process? (Y | N): ";
		cin >> YorN;
	}
	
	cout << endl << endl;
	
	//close the opened textfile.
	myfile.close();
	system ("pause");
	return 0;
	
}
