

/**
*@filename 	: struct_trans.c
*
*@description 	: A file containing a simple implementation of a linked list.
*		Functions will be used to add, delete node and to count elements
*		in the given linked list.
*
*@author	: Diptarshi Chakraborty
*
*@date		:6th February 2019
*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


	struct LIST{



	uint8_t data;

	struct  LIST *NEXT;

	};

	typedef struct LIST MY_LIST;



typedef enum {
		N=0, 		// The error code that will be retruned when the pointetr passed is NULL

		success=1, 	// The error code when the function successfully does what it is supposed to do

		failure = 2	// The error code  when there is failure in the operation

	}error;

/**
*@function      : initialize
*
*@description   : A function that initalize a given linked list on being given
*		the correct pointer.
*
*
*@param         :MY_LIST pointer, uint8_t data
*
*@return        :error
*/

error initialize( MY_LIST* head, uint8_t my_data)
{



	head->data=my_data;
	head->NEXT=NULL;
	return success;



}

/**
*@function      : add_node_at_start
*
*@description   : A function that adds a node beforethe first node.
*
*
*
*@param         :MY_LIST pointer, uint8_t data
*
*@return        :error
*/


MY_LIST* add_node_at_start( MY_LIST* head, uint8_t my_data)
{

	if(head==NULL)
	{

		return N;
	}

	else
	{
		MY_LIST *new_node = malloc(sizeof(MY_LIST));

		new_node->data=my_data;
		new_node->NEXT=head;
		head->NEXT=NULL;
		return new_node;


	}



}

/**
*@function      : add_node_at_end
*
*@description   : A function that adds a node after the last node.
*
*
*
*@param         :MY_LIST pointer, uint8_t data
*
*@return        :error
*/


error add_node_at_end( MY_LIST* head, uint8_t my_data)
{


	if(head==NULL)
	{

		return N;

	}

	else
	{


		while(pointer->NEXT!=NULL)
		{

			p=p->NEXT;

		}

		MY_LIST *new_node = malloc(sizeof(MY_LIST));

		p->NEXT=new_node;
		new_node->data=data;
		new_node->NEXT=NULL;
	}
}

void main()
{
	printf("\n Hello world \n");

	int c;
	c=0;
	MY_LIST * p= malloc(sizeof(MY_LIST));
	c=initialize(p,8);
	if(c==0)
	{

		printf("\nThere was an error \n !");
	}

	else
	{

		printf("The initialization of the linked list is successful");

	}

	p=add_node_at_start(p,10);


	if(c==0)
	{

		printf("\n There was an error \n");

	}

	else
	{

		printf("\n Successfully added a node at the start \n");

	}



	printf("Now let us traverse through the list");

	printf("\n data is : %d\n",p->data);

	p=p->NEXT;

	printf("data is : %d\n",p->data);


}

