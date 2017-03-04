#include<stdio.h>
#include<stdlib.h>
#define size 5

// defining priority queue structure. //
typedef struct node1{
	int element;
	int priority;
	struct node1 *next;  // a self referential pointer to the structure. //
}pq;

// define an instance of pq. //
pq *head = NULL;

void insert( int item, int priority ){
	if( head == NULL ){
		/* if head is null, you cannot enter elements simply,
		You first have to initialise head with a random pq type
		address and then store values on head's data and next. */
		head = ( pq * )malloc( sizeof( pq ) );
		head -> element = item;
		head -> priority = priority;
        head -> next = NULL;
	}
	else{
		/* if head is not null that implies we can add this new element
		on the first node and shift every other node to the right. */
		
		// first initialise a temp variable to store the value of head, //
		// so that we can change head's value. //
		pq *temp;
		temp = head;  // So this is the first element, which will become second after insertion. //
		head = ( pq * )malloc( sizeof( pq ) );
		head -> element = item;
		head -> priority = priority;
		head -> next = temp;
		// element now inserted. //
	}
	printf("Element is inserted successfully.\n");
} // End of insert function. //

void delete(){
	// Now we have to traverse the whole linked list until to get the highest priority. //
	
	pq *temp = head;
	int priority_store = -1;
	
	// Now initialise the while loop to traverse the list. //
	while( temp != NULL ){
		if( temp -> priority > priority_store ){
			priority_store = temp -> priority;
		}
		temp = temp -> next;
	}
	
	/* Now we got the highest priority in the whole list.
	Next task must be to delete those elements with this priority. 
	For that make temp again equal to head. */
	temp = head;
	// Also initialise a prev variable. //
	pq *prev;
	// Again initialise the while loop. //
	while( temp != NULL ){
		if( temp -> priority == priority_store ){
			/* Now if the priority is found at very first element,
			i.e. temp == head */
			if( temp == head ){
				pq *temp1 = head;
				head = head -> next;
				free( temp1 );
			}
			else{
				prev -> next = temp -> next;
				free( temp );
                temp = prev; // Assigning temp just the previous value, else temp -> next will not work. //
			} 
		}
		prev = temp; // This statement will not be affected due to else part also. //
		temp = temp -> next;
	} // End of while //
	printf("Items deleted.\n");
} // End of delete() //

void display(){
	if ( head != NULL ){
		/* This part is very simple.
		You have to just traverse the whole list
		and print each and every element. */
	
		// For that again initialise a temp pointer variable. //
		pq *temp;
        temp = head;
		// Now start the while loop. //
		
		while( temp != NULL ){
			printf("Item = %d with priority = %d. \n", temp -> element, temp -> priority);
			temp = temp -> next;
		} // While ends here. //
	}
	else{
		printf("Empty priority queue.\n");
	}
} // display() ends here. //

void main(){
	/* We will be making a menu driven program. For that we will be initialising
	a ch variable equal to 1. */
	int ch = 1;
	
	while( ch == 1 ){
		printf("Enter 1 to insert.\n");
		printf("Enter 2 to delete.\n");
		printf("Enter 3 to display.\n");
		printf("Enter 4 to exit.\n");
		
		// Initialising a choice variable x. //
		int x;
		printf("Enter your choice: ");
		scanf("%d", &x);
		
		if( x == 1 ){
			// Ask for element and its priority. //
			int item, pr;
			printf("Enter the item: ");
			scanf("%d", &item);
			printf("Enter the priority: ");
			scanf("%d", &pr);
			
			// Make a call to insert() function. //
			insert( item, pr );
		}
		else if( x == 2 ){
			// Here simply make a call to delete() function. //
			delete();
		}
		else if( x == 3 ){
			// Here also simply make a call to display() function. //
			display();
		}
		else if( x == 4 ){
			// Change ch to 0 to halt the while loop. //
			ch = 0;
		}
		else{
			printf("Invalid choice!!\n");
		}
	}
} // End of main() //
