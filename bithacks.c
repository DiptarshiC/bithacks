
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

/**
*1.Parity of a number refers to whether it contains an odd or even number of 1-bits. 
*  The number has “odd parity”, if it contains odd number of 1-bits 
*  and is “even parity” if it contains even number of 1-bits.
*  Main idea of the below solution is – Loop while n is not 0 and in 
*  loop unset one of the set bits and invert parity.
*
*/



#define 	MASK_0(x)		(x&0x0001)	/*Mask helps to find out the zeroth bit*/
#define		LEFT_SHIFT(x)	(x>>1)		/*Macro shifts the number to the left by 1*/


/**
*@function: parity 
*
*@description: function returns 1 if it has even parity and one if it has odd parity
*
*@param: uint32_t
*
*@return: uint8_t
*
*/

uint8_t parity(uint32_t x)
{
	uint8_t count=0;
	while(x>0)
	{
		if(MASK_0(x))
			count++;
		
		x=LEFT_SHIFT(x);
	
	}

	if(count&0x0001)
		return 0;
	else
		return 1;
	
}

/**
*2.Given an array of positive integers. All numbers occur even number of times 
*  except one number which occurs odd number of times. 
*  Find the number in O(n) time & constant space.
*
*/


/**
*@function: odd_number_of_times 
*
*@description: Finds the number that occurs odd no, of times
*
*@param: uint8_t*
*
*@return: uint8_t
*
*/

uint8_t odd_number_of_times(uint8_t *x, uint8_t len)
{
		uint8_t XOR=0;
		uint8_t i=0;

		while(i<len)     
        	{
        		XOR = XOR ^ *(x+i);
        		i++;
        	} 
		
		return XOR;
	
}

/**
*3.The given number swaps the odd and the even bits
*/

#define 	ODD_DIGIT(x)	x&0x55		/*A number which stores the bits at odd positions*/
#define		EVEN_DIGIT(x)	x&0xAA		/*A number which stores the bits at even positions*/
#define		SHIFT_LEFT(x)	x>>1		/*Macro shifts the number to the left by 1*/
#define		SHIFT_RIGHT(x)	x<<1		/*Macro shifts the number to the right by 1*/

/**
*@function: swap_odd_even_bits 
*
*@description: swaps odd and even bits
*
*@param: uint8_t
*
*@return: uint8_t
*
*/

uint8_t swap_odd_even_bits(uint8_t x)
{
		

	return ((ODD_DIGIT(x)<<1)|(EVEN_DIGIT(x)>>1));
}

/**
*4. A function to multiply without * operator
*
*/

/**
*@function: mul 
*
*@description: multiplies two numbers
*
*@param: uint8_t, uint8_t
*
*@return: uint8_t
*
*/

uint32_t mul(uint8_t a, uint8_t b)
{
	uint8_t MASK=0x01;
	uint8_t count=0;
	uint32_t prod=0;
	while(a)
	{
		if(MASK&a)
		{
			prod=prod+(b<<count);
		}
		count++;
		a=a>>1;

	}
	return prod;

}


/**
*5. A function to count the set bits in an given integer.
*   It uses Brian Kernighams algorithm wherein the loop runs
*	till there are set bits in the number
*/

/**
*@function: count_set 
*
*@description: finds the number of set bits
*
*@param: uint32_t
*
*@return: uint8_t
*
*/

uint8_t count_set(uint32_t a)
{

	uint8_t count=0;
	while(a)
	{
		a&=(a-1);
		count++;
		

	}
	return count;

}

/**
*6. A function that detects if two numbers have opposite signs
*	does not use arithmetic operators 
*/


/**
*@function: detect_opp_sign 
*
*@description: A function that detects if two numbers have opposite signs
*				does not use arithmetic operators. Return 1 if signs are
*				opposite, 0 if signs are the same
*@param: uint32_t
*
*@return: uint8_t
*
*/

#define		MASK_31(x)			(x&0x80000000)	
#define		SHIFT_LEFT_31(x)	(x>>31)


uint8_t detect_opp_sign(int32_t a, int32_t b)
{

	return (SHIFT_LEFT_31(MASK_31(a)) ^ SHIFT_LEFT_31(MASK_31(b)) );
	

}

/**
*7.We need not to do anything if a number is positive. 
*We want to change only negative numbers. Since negative 
*numbers are stored in 2’s complement form, 
*to get the absolute value of a negative number we have to 
*toggle bits of the number and add 1 to the result.
*/


/**
*@function: abs_val 
*
*@description: A function that returns absolute val
*
*@param: int32_t
*
*@return: int32_t
*
*/

#define CHECK_SIGN(x)	SHIFT_LEFT_31(MASK_31(x))



int32_t abs_val(int32_t x)
{

	return (CHECK_SIGN(x)?((~x)+1):x);
	

}

/**
*8.Given a string, find the first non-repeating character in it. 
*For example, if the input string is “GeeksforGeeks”, then output should 
*be ‘f’ and if input string is “GeeksQuiz”, then output should be ‘G’
*/


/**
*@function: first_non_r 
*
*@description: A function that returns absolute val
*
*@param: uint8_t*
*
*@return: uint8_t(Returns the first non-repeating element or -1)
*
*/






uint8_t first_non_r(uint8_t arr[], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        int j; 
        for (j = 0; j < n; j++) 
            if (i != j && arr[i] == arr[j]) 
                break; 
        if (j == n) 
            return arr[i]; 
    } 
    return -1; 
} 

/**
*9.Given two numbers ‘a’ and b’. Write a program to count 
*number of bits needed to be flipped to convert ‘a’ to ‘b’.
*/


/**
*@function: flip_no 
*
*@description: A function that returns the number of bits needed to be flipped
*
*@param: uint8_t
*
*@return: uint8_t,uint8_t
*
*/

#define		SEP(a,b)		(a^b)

uint8_t flip_no(uint8_t a, uint8_t b)
{
	uint8_t x=SEP(a,b);
	uint8_t count=0;
	while(x)
	{
		x=x&(x-1);
		count++;
	}
	return count;
}

/**
*10. A program to find out whether a number is
*	big endian or little endian
*/


/**
*@function: endian 
*
*@description: A function to find out whether a number is
*				big endian or little endian
*
*@param: void
*
*@return: uint8_t
*
*/



uint8_t endian()
{
	uint32_t  x;
	x=0x00000001;

	uint8_t *y=(uint8_t*)&x;

	

	return  ((*y) ? 1:0) ;

	
}

/**
*11. A program to determine word size of the machine
*	
*/


/**
*@function: word_size 
*
*@description: A program to determine word size of a machine
*
*@param: void
*
*@return: uint8_t( Will return the number of bytes)
*
*/



uint8_t word_size()
{
	
	

	return(sizeof(size_t));

	
}


/**
*12. A program to insert a key in a BST
*	
*/

typedef struct node
{
	int key;
	struct node * right;
	struct node * left;
}Node;


/**
*@function: newNode 
*
*@description: A program to create a new node
*
*@param: int 
*
*@return: Node *
*
*/

Node * newNode(int item)
{
	Node * temp = (Node*)malloc(sizeof(Node));
	temp->key= item;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

/**
*@function: preorder 
*
*@description: A program to print the elements pre order
*
*@param: int 
*
*@return: Node *
*
*/

void preorder(Node * root)
{
	if(root!=NULL)
	{
		printf("key : %d\n",(root->key));
		preorder(root->left);
		preorder(root->right);
	}
}

/**
*@function: printinorder 
*
*@description: A program to print the elements in order
*
*@param: int 
*
*@return: Node *
*
*/

void printinorder(Node * root)
{
	if(root!=NULL)
	{
		printinorder(root->left);
		printf("key : %d\n",(root->key));
		printinorder(root->right);
	}
}

/**
*@function: postorder 
*
*@description: A program to print the elements post order
*
*@param: int 
*
*@return: Node *
*
*/

void postorder(Node * root)
{
	if(root!=NULL)
	{
		preorder(root->left);
		preorder(root->right);
		printf("key : %d\n",(root->key));
	}
}

/**
*@function: insertNode 
*
*@description: A program to insert a given key in a BST
*
*@param: int 
*
*@return: Node *
*
*/

Node * insertNode(Node * root,int item)
{
	if(root==NULL)
	{
		return newNode(item);
	}

	if (item < root->key) 
        root->left  = insertNode(root->left, item);

    else if(item>root->key)
    {
    	root->right  = insertNode(root->right, item);
    }

    return root;
}


/**
*13. A program to find index of protocol header
*	
*/
/**
*@function: index 
*
*@description: A program to find index of protocol header
*
*@param: uint8_t ,  uint8_t,uint8_t,uint8_t
*
*@return: int8_t
*
*/

int8_t  myindex(int8_t buffer[],int8_t bufferlength,int8_t protocolheader[],int8_t protocolheaderlength)
{
	if(bufferlength < protocolheaderlength)
	{
		return -1;
	}
	else
	{
		int index;
		int flag=0;
		for(int i=0;i<bufferlength-protocolheaderlength;i++)
		{
			for(int j=0;j<protocolheaderlength;j++)
			{

				if(protocolheader[j]!=buffer[i+j])
					{flag=1;}
			}

			if (flag==0)
			{
				index=i;
				break;
			}
			flag=0;
		}
		return index;
	}

	
}

/**
*14. A program to insert elements in a BST when they are in preorder in an array
*	
*/
/**
*@function: insert_preorder 
*
*@description: A program to insert elements in a BST when they are in preorder in an array
*
*@param: uint8_t array,array_length 
*
*@return: Node*
*
*/

void  insert_preorder(Node * current, uint8_t val)
{
	
	Node * mynode = newNode(val);
	

	if( (current->left==NULL) && (current->right ==NULL) ) 
	{

		if(current->key > val)
		{
			Node * left = newNode(val);
			current->left=left;
		}

		else if(current->key < val)
		{
			Node * right = newNode(val);
			current->right=right;
		}
	}

	else
	{
		if( current->key > val)
		{
			if(  current->left==NULL )
			{
				current->left=newNode(val);
			}
			else 
			{
				insert_preorder(current->left,val);
			}
		}


		else if(current->key < val)
		{
			if(  current->right==NULL )
			{
				current->right=newNode(val);
			}
			else
			{
				insert_preorder(current->right,val);
			}
		}

	}
	
}





/**
*Questions and Answers
*
*Q1. What is a realtime operating system?
*Ans: A Real time system is a system which has to provide output within a given
*	time frame. The time before which it has to provide the correct/desirable output
*	is called the deadline. Failing to do so would be dangerous to the nearby
*	environment. Any operating system that responds within real time are called realtime
*	systems. Operating systems that schedule tasks for a real time response are called
*	real time operating systems.
*
*Q2. What are the features of a real time operating system? 
*Ans: The features of a real time operating system are as follows:
*	1.It has to be deterministic.The scheduler should be able to schedule all
*		the tasks accurately.Deadlines should not be missed.
*	2.It has a very low context switch latency.Contexts can be switched fast.
*	3.Scalability. It has a scheduler,timers,tasks,drivers,file management systems
*	4.Light weight and deterministic.It should have minimal code and have faster performance
*
*Q3. What is a hypervisor?
*Ans : A Hypervisor or a virtual machine is a system that creates and runs virtual machines.
*	   The hypervisor presents the guest operating systems with a virtual operating platform 
*	   and manages the execution of the guest operating systems.  
*
*Q4.  
*
*
*
*
*/	

/**
*Driver function
*/


//live:865b13342ce219b4
int main()
{
	int n=6;
	uint8_t x[]={2,3,5,4,5,2,4,3,5,2,4,4,2};
	uint8_t a=3;
	uint8_t b=3;
	int32_t x1=-100;
	int32_t x2=100;
	int32_t x3=-400;
	uint8_t z=10;
	uint8_t y=20;
	uint32_t c=0xFFFFFFFF;
	uint8_t string[]="GeeksQuiz";
	printf("\nParity of no = %s\n",(parity(n)? "even": "odd"));	
	printf("Unique digit from the array is: %d\n",odd_number_of_times(&x[0],13));
	printf("swap(0x55) is :0X%X\n",swap_odd_even_bits(0x55));
	printf("The product of two numbers is: %d\n",mul(4,3));
	printf("The number of set bits in 0xFFFFFFFF is: %d\n",count_set(0xFFFFFFFF));
	printf("The signs of the two numbers are: %s\n",(detect_opp_sign(x1,x2)? "different":"same"));
	printf("The absolute value of %d is : %d\n",x3,abs_val(x3));
	printf("The fist non-repeating character is:%c\n",first_non_r(string, strlen(string)));
	printf("The number of bits that need to be shifted are:%d\n",flip_no(z,y));
	printf("The endianess of the given machine is %s\n",endian()? "little":"big");
	printf("The word size of the given integer is %d bytes\n",word_size());

	Node *root = NULL;
	Node *root1;
	root1=root;

	root=insertNode(root, 50); 
    insertNode(root, 30); 
    insertNode(root, 20); 
    insertNode(root, 40); 
    insertNode(root, 70); 
    insertNode(root, 60); 
    insertNode(root, 80);
    printf("\nIn order thraversal \n");
    printinorder(root);
    
    printf("\nPre order thraversal \n");
    preorder(root);

    printf("\nPost order thraversal \n");
    postorder(root);

    int8_t buffer[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int8_t protocolheader[]={10,11,12,13};
     printf("The index of the protocol header is:%d\n",myindex(buffer,21,protocolheader,4));

     printf("\n Now I shall demonstrate a program to insert elements in a BST in preorder traversal\n");
     
     uint8_t array[]={10, 5, 1, 7, 40, 50};

     Node * new= newNode(array[0]);
     for(uint8_t i=1;i<6;i++)
     {
     		insert_preorder(new, array[i]);
     }

     printf("\nThe inorder traversal of the tree is: %d\n");

    printinorder(new);

    uint8_t myarray[]={40,30,35,80,100};

    printf("\nHappy\n");

    preorder_postorder(myarray[0],0,myarray,0);



	return 0;

}