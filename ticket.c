/* BUS Ticket Booking */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char r;
void login(){
		{
			printf("\n\nWELCOME TO THE BUS BOOKING SYSTEM. LOGIN SUCCESSFUL\n");
			printf("\n\t\tPress enter to continue........");
			scanf("%c%c",&r,&r);

		}
}
/*struct book{
	char code[20];
	char name[20];
	char date[20];
	int cost;
}b;*/
int seat=80;
void insert_busdetails();
void viewAll();
void find();
void coupon();
void book_ticket();
void old_bookings();
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
void insert_busdetails()
{
	FILE *fp;
	struct book b;
	printf("Enter Bus no :- ");	
	scanf("%s",b.code);
	printf("Enter  name :- ");	
	scanf("%s",b.name);
	printf("Enter Arrival Time:- ");	
	scanf("%s",b.date);
	printf("Enter Cost:- ");	
	scanf("%d",&b.cost);
	fp=fopen("data.txt","a");
	if(fp == NULL)
		printf("FIle not Found");
	else
	{
		fprintf(fp,"%s %s %s %d \n",b.code,b.name,b.date,b.cost);
		printf("Recorded Successfully\n");
	}
	fclose(fp);
	system("clear");
}
void find()
{
	struct book b;
	FILE *fp;
	char ch[20];
	printf("Enter bus number :");
	scanf("%s",ch);
	fp = fopen("data.txt","r");
	if(fp == NULL
	  ){
		printf("File Not Found");
		exit(0);
	}
	else{	
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,ch) == 0)
			{	
				printf("\n Record Found\n");
				printf("\n\t\tbus number :%s",b.code);
				printf("\n\t\tBus Name :%s",b.name);
				printf("\n\t\ttravel Date :%s",b.date);
				printf("\n\t\tPrice of Ticket :%d",b.cost);
			}
		}	
	}
	fclose(fp);
	printf("\n\t\tPress enter to continue........");
	scanf("%c%c",&r,&r);
	system("clear");
}
void coupon()
{
    printf("Hello congrats");
    printf("\n\t\tPress enter to continue........");
	scanf("%c%c",&r,&r);
	system("clear");
}
void viewAll()
{
	char ch;
	FILE *fp;
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("File Not Found");
		exit(0);
	}
	else
	{	
		system("clear");
		while((ch=fgetc(fp))!=EOF)
      			printf("%c",ch);	
	}
	printf("\n\t\tPress enter to continue........");
	scanf("%c%c",&r,&r);
	system("clear");
	fclose(fp);
}
void book_ticket()
{
	struct book b;
	FILE *fp;
	FILE *ufp;
	int total_seat,mobile,total_amount;
	char name[20];
	char ch;
	char bus_code[20];
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file not found !");
		exit(1);
	}
	else
	{	
		system("clear");
		while( ( ch = fgetc(fp) ) != EOF )
      		printf("%c",ch);
	}
	fclose(fp);
	printf("\n For Book ticket Choice(Enter bus Code First Latter Of bus name)\n");
	printf("\n Enter bus number :");
	scanf("%s",bus_code);
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file not found !");
		exit(1);
	}
	else
	{	
		while(getc(fp) != EOF)
		{
			fscanf(fp,"%s %s %s %d",b.code,b.name,b.date,&b.cost);
			if(strcmp(b.code,bus_code) == 0)
			{	
				printf("\n Record Found\n");
				printf("\n\t\tbus number :%s",b.code);
				printf("\n\t\tbus name :%s",b.name);
				printf("\n\t\tdate :%s",b.date);
				printf("\n\t\tPrice of ticket:%d",b.cost);
			}
		}
	}
	printf("\n* Fill Your Details  *");
	printf("\n Your Name :");
	scanf("%s",name);
	printf("\n Mobile Number :");
	scanf("%d",&mobile);
	printf("\n Total number of tickets :");
	scanf("%d",&total_seat);	
	total_amount = b.cost * total_seat;
	printf("\n ENJOY YOUR BUS \n");
	printf("\n\t\tName : %s",name);
	printf("\n\t\tMobile Number : %d",mobile);
	printf("\n\t\tbus name : %s",b.name);
	printf("\n\t\tTotal seats : %d",total_seat);
	printf("\n\t\tCost per ticket : %d",b.cost);
	printf("\n\t\tTotal Amount : %d",total_amount);
	ufp=fopen("oldTransection.txt","a");
	if(ufp == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fprintf(ufp,"%s %d %d %d %s %d \n",name,mobile,total_seat,total_amount,b.name,b.cost);
		printf("\n Record insert Sucessfull to the old record file");
	}
	printf("\n");
	printf("\n\t\tPress enter to continue........");
	scanf("%c%c",&r,&r);	
	fclose(ufp);
	fclose(fp);
}
void old_bookings()
{
	char ch;
	FILE *fp;
	fp = fopen("oldTransection.txt","r");
	if(fp == NULL)
	{
		printf("file not found !");
		exit(1);

	}
	else
	{	
		system("clear");
		while((ch=fgetc(fp))!=EOF)
      		printf("%c",ch);	
	}
	printf("\n\t\tPress enter to continue........");
	scanf("%c%c",&r,&r);
	fclose(fp);
}
