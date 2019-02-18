
/**
*@Name: 	:Message.c
*
*@Description 	:A file that distinguishes between messages between two messages
*		based on the type of message and passes them to the appropriate function
*
*@date 		:17th February 2019
*
*@Author	:Vignesh Aiyer
*/




#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>



#define		MOTOR		0x80 	/*Message type for motor message*/
#define		DISPLAY		0x34	/*Message type motor display message*/

/*Type definition for a bitfield that encodes the
	message and sends it to the appropriate function*/



typedef struct message_data()
{

	uint8_t packet_id:8;
	uint8_t message_type:8;
	uint16_t message_length:16;
	uint32_t message_data0:32;
	uint32_t message_data1:32;



};


void display_message(message_data mydata);
void update_motor(message_data mydata);


/**
*@Name:		distinguish
*
*@Description:	A file that distinguishes between messages between two messages
*               based on the type of message and passes them to the appropriate function
*
*@param:	The function takes in a uint8_t pointer
*
*@return:	doesnot return a value
*/

void distinguish(uint8_t packet[])
{

	message_data send_data;
	send_data.packet_id=packet[0];
	send_data.message_type=packet[1];
	send_data.message_length=packet[2];
	send_data.message_length|=(packet[3]<<8);//bitwise leftshift by 8 points
	send_data.message_data0=((packet[7]<<24)|(packet[6]<<16)|(packet[5]<<8)|(packet[4]));
	send_data.message_data1=((packet[12]<<24)|(packet[10]<<16)|(packet[9]<<8)|(packet[8]));


	if(send_data.message_type=MOTOR)
	{

		update_motor(send_data);

	}


        if(send_data.message_type=DISPLAY)
        {

                update_motor(send_data);

        }
}

