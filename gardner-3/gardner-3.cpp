// Program Name:	Palindrome 
// Chapter:			Chapter 3  - Linked Lists
// Pg. / Ex.:		64 / 3.9
// Programmer:		Michael A Gardner
// Date:			4 July 2016
// Description:		This program  takes a phrase in and lets the user know if the pharse is a palindrome or not.


#include "stdafx.h"
#include <iostream>

using namespace std;


//  ** Node Structure **
typedef struct node {
	char ch;
	struct node *next;
}Node, *NodePtr;

// ** Function Prototypes **
NodePtr getPhrase();
NodePtr reverse(NodePtr phrase);
void print(NodePtr list);
void strip(NodePtr top);
void palindrone(NodePtr forward, NodePtr reverse);


int main()
{
	cout << "   ** Palendrome Program **   \n\n";
	cout << "Please enter a phrase (Press Enter to Quit): ";

	NodePtr 
		phrase = getPhrase(),
		reversed;

	while (phrase != NULL) {
			
		print(phrase);						// Print the Phrase entered
		strip(phrase);						// Strip the Phrase of Spaces also change upper case to lowercase.
		reversed = reverse(phrase);			// Reverse the Phrase
		palindrone(phrase, reversed);		// Determine if the phrase is a palindrome or not.
		cout << endl << "List 2 =\t"; print(phrase); cout << endl;
		cout << "List 3 =\t"; print(reversed); cout << endl;
		cout << endl << endl;
		cout << "Please enter another phrase (Press Enter to Quit): ";
		phrase = getPhrase();
	}
		
	cout << "Program exit   ";
}

NodePtr getPhrase() {
	NodePtr
		top = NULL,
		last = NULL,
		np;
	char
		c = getchar();

	while (c != '\n') {
		np = (NodePtr)malloc(sizeof(Node));
		np->ch = c;
		np->next = NULL;

		if (top == NULL) {
			top = np;
		}
		else {
			last->next = np;
		}
		last = np;
		c = getchar();
	}
	return top;
}



NodePtr reverse(NodePtr phrase) {
	NodePtr
		rev = NULL,
		np;

	char
		c;

	while (phrase != NULL) {
		c = phrase->ch;
		np = (NodePtr)malloc(sizeof(Node));
		np->ch = tolower(c);
		np->next = rev;
		rev = np;
		phrase = phrase->next;
	}
	return rev;
}

void print(NodePtr list) {
	if (list != NULL) {
		cout << list->ch;
		while (list->next != NULL) {
			list = list->next;
			cout << list->ch;
		}
	}	
}

void strip(NodePtr top) 
{
	/* How to Delete Node C in a singulary linked list:

				THE LINKED LIST
	Node A -> Node B -> Node C -> Node D -> Node E

	* 1. Store Node D in a tempory Node.
	* 2. Copy the data in Node D to Node C.
	* 3. Update Node C to point to Node E.
	* 4. Delete the temparory Node!

			THE LINKED LIST AFTER
	Node A -> Node B -> Node D -> Node E

	YOUTUBE VIDEO:  https://www.youtube.com/watch?v=Cay6RsoIG78
*/
	NodePtr tempNode;
	char c;
	while (top != NULL) {
		c = top->ch;
		top->ch = tolower(c);
		if (isalpha(c) == false) {
			tempNode = (NodePtr)malloc(sizeof(Node));  // make a tempory node.
			tempNode = top->next;  // STEP 1
			top->ch = tempNode->ch;  // STEP 2
			top->next = tempNode->next;  // STEP 3
			free(tempNode);					// STEP 4
		}
		top = top->next;
	}

}


void palindrone(NodePtr forward, NodePtr reverse) {
	bool palindrome = true;

	if (forward == NULL) {
		cout << "*EMPTY LIST*\n";
		palindrome = false;
	}
	else {
		while (forward != NULL) {
			if (forward->ch != reverse->ch) {
				palindrome = false;
				break;
			}
			forward = forward->next;
			reverse = reverse->next;
		}
	}

	if (palindrome) {
		cout << " is a Palindrone!\n";
	}
	else {
		cout << " is not a Palindrone :( \n";
	}
}
