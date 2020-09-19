#include "header.h"
void main()
{
	login();
	int ch;
 	while(1)
	{
		printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");	
		printf("\n\t Book BUS Ticket \n");
		printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
		printf("\nEnter >1< To Insert A Bus\nEnter >2< To View All bus\nEnter >3< To Find A Bus\nEnter >4< To Book A Ticket(s)\nEnter >5< To View All Recent Transactions\nEnter  >6< To view all coupans\nEnter >0< To Exit \nEnter your Choice :");
	   	scanf("%d",&ch);
	   	system("clear");	
	   	switch (ch)
		{
	    		case 1: insert_busdetails();
	   			break;
			case 2: viewAll();
	   			break;    		
			case 3: find();
	   			break;
			case 4: book_ticket();
				break;	
			case 5: old_bookings();
			    break;
			case 6: coupon();
				break;
	    		case 0: exit(0);
	    		default: printf("Enter a valid option.");
	   	}
	 }
}
