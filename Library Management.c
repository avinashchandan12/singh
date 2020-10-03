/*
Q Design a program with C and DS to maintain (Stroage, Retrieval, Updation)
  Library Records like Books, Stock, Member Issue/Return etc.

  Create different linked list to maintain Book Records having information
  like BookCode, BookName, Author, Publication, Subject, Type, StockQty etc.

  Linked List to maintain Member Records having information like MemId,MemName,
  DOB, Course, Year, CardNo.

  Linked List to maintain Issue/Return Records like SerialNo, BookCode, MemId,
  DOI,DOR, Fine etc.

  Constraints.......
  Only one book will be issued per member at a time.
  A book is issued for maximum 7 days.
  Fine amount is calculated 1 Rs./day.
  After issue stock qty of a book is decreased by 1 and return it is
    increased by 1.
  Proper Message should display, If constrataints violated.
  
  Please do not copy the whole code for submition, do code by yourself first, look at this code only when you stuck somewhere and not able to solve by yourself..
  good luck, Happy Coding
*/
#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#include<dos.h>
typedef struct book_records
{
	struct book_records *pre;
	long int BookCode;
	char BookName[30];
	char Author[30];
	char Publication[30];
	char Subject[20];
	int StockQty;
	struct book_records *next;
}Book;
typedef struct member_records
{
	struct member_records *pre;
	int Day,Month,Year,year;
	long int MemId;
	char MemName[30];
	char Course[20];
	long int CardNo;
	struct member_records *next;
}Member;
typedef struct Issue_Return_Records
{
	struct Issue_Return_Records *pre;
	int SerialNo;
	long int BookCode;
	long int MemId;
	int Doi,Moi,Yoi;
	struct Issue_Return_Records *next;
}IRR;

Book *BHead=NULL;
Member *MHead=NULL;
IRR *IRHead=NULL;

void loading()
{
	int i;
	printf("\nLoading.");
	for(i=0;i<6;i++)
	{
		printf(".");
		delay(400);
	}
}//loading function closed...

//Menu....
int MainMenu()
{
	int choice;
	clrscr();
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Main Menu");
	printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB\xB2\ 0. Exit the Program.");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2\ 1. Book Record.");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2\ 2. Member Record.");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2\ 3. Issue/Return Book.");
	gotoxy(20,13);
	printf("\n Enter your choice: ");
	gotoxy(20,15);
	scanf("%d",&choice);
	return(choice);
}
int BookMenu()
{
	int choice;
	clrscr();
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Book Record.");
	printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB\xB2\ 0. Back to Menu.");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2\ 1. New Record.");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2\ 2. Display Record.");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2\ 3. Update Record.");
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB\xB2\ 4. Delete Record.");
	gotoxy(20,15);
	printf("\nEnter your choice: ");
	gotoxy(20,17);
	scanf("%d",&choice);
	return(choice);

}
int MemberMenu()
{
	int choice;
	clrscr();
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Member Record.");
	printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB\xB2\ 0 Back to Menu.");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2\ 1 New Member.");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2\ 2 Display Member.");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2\ 3 Update Member.");
	gotoxy(20,13);
	printf("\xDB\xDB\xDB\xDB\xB2\ 4 Delete Member.");
	gotoxy(20,15);
	printf("\nEnter your choice: ");
	gotoxy(20,17);
	scanf("%d",&choice);
	return(choice);
}

int IRMenu()
{
	int choice;
	clrscr();
	gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Issue/Return Book.");
	printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,5);
	printf("\xDB\xDB\xDB\xDB\xB2\ 0. Back to Menu");
	gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2\ 1. Issue Book.");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2\ 2. Return Book.");
	gotoxy(20,11);
	printf("\nEnter your choice: ");
	gotoxy(20,13);
	scanf("%d",&choice);
	return(choice);

}
//end menu.......

void AddBookRecord()
{
	Book *head,*New;
	char ch;
	FILE *fp;
	do
	{
		if(BHead==NULL)
		{
			New=(Book*)malloc(sizeof(Book));
			fflush(stdin);
			clrscr();
			printf("\nEnter Book Code   : ");
			scanf("%ld",&New->BookCode);
			fflush(stdin);
			printf("Enter Book Name   : ");
			gets(New->BookName);
			printf("Enter Author Name : ");
			gets(New->Author);
			printf("Enter Subject Name: ");
			gets(New->Subject);
			printf("Enter Publication : ");
			gets(New->Publication);
			fflush(stdin);
			printf("Enter StockQty    : ");
			scanf("%d",&New->StockQty);
			fflush(stdin);
			BHead=New;
			BHead->next=BHead;
			BHead->pre=BHead;
		}//if close
		else
		{
			head=BHead;
			while(head->next!=BHead)
				head=head->next;//find lasd node.....
			//data entry....
			New=(Book*)malloc(sizeof(Book));
			fflush(stdin);
			clrscr();
			printf("\nEnter Book Code   : ");
			scanf("%ld",&New->BookCode);
			fflush(stdin);
			printf("Enter Book Name   : ");
			gets(New->BookName);
			printf("Enter Author Name : ");
			gets(New->Author);
			printf("Enter Subject Name: ");
			gets(New->Subject);
			printf("Enter Publication : ");
			gets(New->Publication);
			fflush(stdin);
			printf("Enter StockQty    : ");
			scanf("%d",&New->StockQty);
			//set new node in main list...
			head->next=New;
			New->pre=head;
			New->next=BHead;
			BHead->pre=New;
		}
		fflush(stdin); //clear input buffer.
		printf("\nDo you want to insert more Book Record(y/n): ");
		scanf("%c",&ch);
		}while(ch=='y');//while close
	fclose(fp);
	loading();
	printf("\n\tFile Successfully saved.....");
}//AddBookRecord function closed......

void AddMemberRecord()
{
	Member *head,*New;
	char ch;
	do
	{
		if(MHead==NULL)
		{
			clrscr();
			New=(Member*)malloc(sizeof(Member));
			fflush(stdin);
			printf("\nEnter Member Id   : ");
			scanf("%ld",&New->MemId);
			fflush(stdin);
			printf("Enter Member Name : ");
			gets(New->MemName);
			fflush(stdin);
			printf("Enter DOB (DD/MD/YYYY) : ");
			scanf("%d/%d/%d",&New->Day,&New->Month,&New->Year);
			printf("Enter Year\t  : ");
			scanf("%d",&New->year);
			fflush(stdin);
			printf("Enter Course Name : ");
			gets(New->Course);
			fflush(stdin);
			printf("Enter Card No.    : ");
			scanf("%ld",&New->CardNo);
			fflush(stdin);

			MHead=New;
			MHead->next=MHead;
			MHead->pre=MHead;
		}//if close
		else
		{
			head=MHead;
			while(head->next!=MHead)
				head=head->next;//find lasd node.....
			//data entry....
			New=(Member*)malloc(sizeof(Member));
			fflush(stdin);
			clrscr();
			printf("\nEnter Member Id   : ");
			scanf("%ld",&New->MemId);
			fflush(stdin);
			printf("Enter Member Name : ");
			gets(New->MemName);
			fflush(stdin);
			printf("Enter DOB (DD/MM/YYYY) : ");
			scanf("%d/%d/%d",&New->Day,&New->Month,&New->Year);
			printf("Enter Year\t  : ");
			scanf("%d",&New->year);
			fflush(stdin);
			printf("Enter Course Name : ");
			gets(New->Course);
			fflush(stdin);
			printf("Enter Card No     : ");
			scanf("%ld",&New->CardNo);
			fflush(stdin);
			//set new node in main list...
			head->next=New;
			New->pre=head;
			New->next=MHead;
			MHead->pre=New;
		}
		fflush(stdin); //clear input buffer.
		printf("\nDo you want to insert more Member Record(y/n): ");
		scanf("%c",&ch);
	}while(ch=='y');//while close

}//AddMemberRecord function closed......


void DisplayMemberRecord()
{
	Member *head;
	long int id;
	if(MHead==NULL)
	{
		printf("\nSorry:-\n\t Member Record is not available.");
		return;
	}
	head=MHead;
	printf("Enter Member Id : ");
	scanf("%ld",&id);
	do
	{       if(head->MemId==id)
		{
			printf("\n\nMember Id    : %ld",head->MemId);
			printf("\nCard Number : %ld",head->CardNo);
			printf("\nMember Name  : %s",head->MemName);
			printf("\nMember DOB   : %d/%d/%d",head->Day,head->Month,head->Year);
			printf("\nCourse\t     : %s",head->Course);
			printf("\nYear  \t     : %d",head->year);
			return;
		}

		head=head->next;
	}while(head!=MHead);
	printf("\n\nNot Found This Member Record.");
}//DisplayMemberRecord function closed......

void DisplayBookRecord()
{
	Book *head;
	long int id;
	if(BHead==NULL)
	{
		printf("\nSorry:-\n\t Book Record is not available.");
		return;
	}
	head=BHead;
	printf("Enter Book Code : ");
	scanf("%ld",&id);
	do
	{
		if(head->BookCode==id)
		{
			printf("\n\nBook Code   : %ld",head->BookCode);
			printf("\nBook Name   : %s",head->BookName);
			printf("\nAuthor Name : %s",head->Author);
			printf("\nPublication : %s",head->Publication);
			printf("\nBook Subject: %s",head->Subject);
			printf("\nStockQty    : %d",head->StockQty);
			return;
		}
		head=head->next;
	}while(head!=BHead);
	printf("\n\nNot found this Book Record");
}//DisplayBookRecord function closed......


void UpdateBookRecord()
{
	Book *head;
	long int id;
	if(BHead==NULL)
	{
		printf("\nSorry: -\n\t Book Record is not available.");
		return;
	}
	head=BHead;
	printf("Enter Book Code : ");
	scanf("%ld",&id);
	do
	{
		if(head->BookCode==id)
		{
			printf("\nEnter Book Code   : ");
			scanf("%ld",&head->BookCode);
			fflush(stdin);
			printf("Enter Book Nmae   : ");
			gets(head->BookName);
			printf("Enter Author Name : ");
			gets(head->Author);
			printf("Enter Subject Name: ");
			gets(head->Subject);
			fflush(stdin);
			printf("Enter StockQty    : ");
			scanf("%d",&head->StockQty);

			loading();
			printf("\nCongratulation:-\n\t Updation is Successful.");
			return;
		}
		head=head->next;
	}while(head!=BHead);
	printf("\nSoory:- \n\t Not found of Book record.");
}//Update function closed...

void UpdateMemberRecord()
{
	Member *head;
	long int id;
	if(MHead==NULL)
	{
		printf("\nSorry: -\n\t Member Record is not available.");
		return;
	}
	head=MHead;
	printf("Enter Member Id : ");
	scanf("%ld",&id);
	do
	{
		if(head->MemId==id)
		{
			fflush(stdin);
			printf("\nEnter Member Id   : ");
			scanf("%ld",&head->MemId);
			fflush(stdin);
			printf("Enter Member Nmae : ");
			gets(head->MemName);
			fflush(stdin);
			printf("Enter DOB (DD/MM/YYYY) : ");
			scanf("%d/%d/%d",&head->Day,&head->Month,&head->Year);
			printf("Enter Year :");
			scanf("%d",&head->year);
			fflush(stdin);
			printf("Enter Course Name : ");
			gets(head->Course);
			fflush(stdin);
			printf("Enter Card No     : ");
			scanf("%ld",&head->CardNo);

			loading();
			printf("\nCongratulation:-\n\t Updation is Successful.");
			return;
		}
		head=head->next;
	}while(head!=MHead);
	printf("\nSorry:- \n\t Not found of Book record.");
}//UpdateMemberRecord function closed...

void DeleteBookRecord ()
{
	Book *head,*temp;
	long int id;

	if(BHead==NULL)
	{
		printf("\nSorry: -\n\t Book Record is not available.");
		return;
	}
	head=BHead;
	printf("\nEnter target Book Code: ");
	scanf("%ld",&id);

	if(head->BookCode==id&&head->next==BHead)
	{
		temp=BHead;
		BHead=NULL;
		free(temp);
		loading();
		printf("\nCongratulation:-\n\t Deletion is Successful.");
		return;
	}//if closed.

	if(head->BookCode==id)
	{
		temp=head;
		while(head->next!=head)
			head=head->next;
		head->next=temp->next;
		temp->next->pre=head;
		BHead=temp->next;
		free(temp);
		loading();
		printf("\nCongratulation:-\n\t Updation is Successfully.");
		return;
	}//if closed...

	do
	{
		if(head->next->BookCode==id&&head->next->next==head)
		{
			temp=head->next;
			head->next=BHead;
			BHead->pre=head;
			free(temp);
			loading();
			printf("\nCongratulation:-\n\t Updation is Successful.");
			return;
		}
		if(head->next->BookCode==id)
		{
			temp=head->next;
			head->next=temp->next;
			temp->next->pre=head;
			free(temp);
			loading();
			printf("\nCongratulation:-\n\t Updation is Successful.");
			return;
		}
		head=head->next;
	}while(head!=BHead);
	printf("\nSorry:- \n\t Not found of Book Record.");
}//DeleteBookRecord function closed....

void DeleteMemberRecord ()
{
	Member *head,*temp;
	long int id;

	if(MHead==NULL)
	{
		printf("\nSorry: -\n\t Member Record is not available.");
		return;
	}
	head=MHead;
	printf("\nEnter target Member Id: ");
	scanf("%ld",&id);

	if(head->MemId==id&&head->next==MHead)
	{
		temp=MHead;
		MHead=NULL;
		free(temp);
		loading();
		printf("\nCongratulation:-\n\t Deletion is Successful.");
		return;
	}//if closed.

	if(head->MemId==id)
	{
		temp=head;
		while(head->next!=head)
			head=head->next;
		head->next=temp->next;
		temp->next->pre=head;
		MHead=temp->next;
		free(temp);
		loading();
		printf("\nCongratulation:-\n\t Updation is Successfully.");
		return;
	}//if closed...

	do
	{
		if(head->next->MemId==id&&head->next->next==head)
		{
			temp=head->next;
			head->next=MHead;
			MHead->pre=head;
			free(temp);
			loading();
			printf("\nCongratulation:-\n\t Updation is Successful.");
			return;
		}
		if(head->next->MemId==id)
		{
			temp=head->next;
			head->next=temp->next;
			temp->next->pre=head;
			free(temp);
			loading();
			printf("\nCongratulation:-\n\t Updation is Successful.");
			return;
		}
		head=head->next;
	}while(head!=MHead);
	printf("\nSorry:- \n\t Not found of Book Record.");
}//DeleteMemberRecord function closed....

int checkMember(long int Memid)
{
	Member *head;
	if(MHead==NULL)
	{
		return 1;
	}
	else
	{
		head=MHead;
		do
		{
			if(head->MemId==Memid)
				return 0;
			head=head->next;
		}while(head->next!=MHead);
	}
	return 1;
}

int checkBook(long int Bookid)
{
	Book *head;
	if(BHead==NULL)
	{
		return 1;
	}
	else
	{
		head=BHead;
		do
		{
			if(head->BookCode==Bookid&&head->StockQty>0)
			{
				head->StockQty--;
				return 0;
			}
			head=head->next;
		}while(head->next!=BHead);
	}
	return 1;
}//checkBook closed....

int checkMemIRR(long int id)
{
	IRR *head;
	if(IRHead==NULL)
	{
		return 0;
	}
	else
	{
		head=IRHead;
		do
		{
			if(head->MemId==id)
				return 1;
			head=head->next;
		}while(head->next!=IRHead);
	}
	return 0;
}//closed CheckMemIRR function...

void BookIssue()
{
	IRR *head,*New;
	if(BHead==NULL)
	{
		printf("\nSorry:- \n\t Book Stock is empty");
		return;
	}
	if(IRHead==NULL)
	{
		New=(IRR*)malloc(sizeof(IRR));
		fflush(stdin);
		printf("\nEnter Serial No: ");
		scanf("%d",&New->SerialNo);
		printf("Enter Member Id: ");
		scanf("%ld",&New->MemId);
		if(checkMember(New->MemId)) //Member not available
		{
			printf("\nFirst of all Join Membership");
			getch();
			return;
		}
		printf("Enter Book Code: ");
		scanf("%ld",&New->BookCode);
		if(checkBook(New->BookCode)) // retutn false
		{
			printf("\n This Book is not available");
			getch();
			return;
		}
		printf("Enter Date of issue(DD/MM/YYYY): ");
		scanf("%d/%d/%d",&New->Doi,&New->Moi,&New->Yoi);
		IRHead=New;
		New->next=IRHead;
		New->pre=IRHead;
	}//If closed...
	else
	{
		head=IRHead;
		while(head->next!=IRHead)
			head=head->next;

		New=(IRR*)malloc(sizeof(IRR));
		fflush(stdin);
		printf("\nEnter Serial No: ");
		scanf("%d",&New->SerialNo);
		printf("Enter Member Id: ");
		scanf("%ld",&New->MemId);
		if(checkMember(New->MemId)) //return false
		{
			printf("\nFirst of all Join Membership");
			getch();
			return;
		}
		if(checkMemIRR(New->MemId))
		{
			printf("\nYou are allready Issue any Book");
			getch();
			return;
		}
		printf("Enter Book Code: ");
		scanf("%ld",&New->BookCode);
		if(checkBook(New->BookCode)) // retutn false
		{
			printf("\n This Book is not available");
			getch();
			return;
		}
		printf("Enter Date of issue(DD/MM/YYYY): ");
		scanf("%d/%d/%d",&New->Doi,&New->Moi,&New->Yoi);

		head->next=New;
		New->pre=head;
		New->next=IRHead;
		IRHead->pre=New;
	}//else closed;
	loading();
	printf("\nCongratulation:-\n\t Book issue is Successful.");
}//BookIssue function closed

void BookQty(long int id)
{
	Book *head;
	if(BHead==NULL)
	{
		printf("\nSorry:- \n\t Book stock is empty");
		return;
	}
	head=BHead;
	do
	{
		if(head->BookCode==id)
		{
			head->StockQty++;
			return;
		}
		head=head->next;
	}while(head->next!=BHead);
	printf("\nThis Book is not issue.");
	getch();
}//BookQty function is closed...

void BookReturn()
{
	IRR *head,*temp;
	int Sn,D,M,Y,fine=0;

	if(IRHead==NULL)
	{
		printf("\nSorry: -\n\t Here no any Book issue.");
		return;
	}
	head=IRHead;
	printf("Enter Serial No. : ");
	scanf("%d",&Sn);
	printf("Enter Date of return(DD/MM/YYYY): ");
	scanf("%d/%d/%d",&D,&M,&Y);

	if(head->SerialNo==Sn&&head->next==IRHead)
	{
		temp=IRHead;
		IRHead=NULL;
		BookQty(temp->BookCode);   //for incremeant
		fine=(D-temp->Doi)-7;
		free(temp);
		loading();
		printf("\nCongratulation:-\n\t Book Return is Successful.");
		if(fine>=1)
			printf("\nfine = %d",fine);
		else
			printf("\nfine = 0");
		return;
	}//if closed.

	if(head->SerialNo==Sn)
	{
		temp=head;
		while(head->next!=head)
			head=head->next;
		head->next=temp->next;
		temp->next->pre=head;
		IRHead=temp->next;
		BookQty(temp->BookCode);//for incremeant
		fine=(D-temp->Doi)-7;
		free(temp);
		loading();
		printf("\nCongratulation:-\n\t Book Return is Successful.");
		if(fine>=1)
			printf("\nfine = %d",fine);
		else
			printf("\nfine = 0");
		return;
	}//if closed...

	do
	{
		if(head->next->SerialNo==Sn&&head->next->next==head)
		{
			temp=head->next;
			head->next=IRHead;
			IRHead->pre=head;
			BookQty(temp->BookCode);
			fine=(D-temp->Doi)-7;
			free(temp);
			loading();
			printf("\nCongratulation:-\n\t Book Return is Successful.");
			if(fine>=1)
				printf("\nfine = %d",fine);
			else
				printf("\nfine = 0");
			return;
		}
		if(head->next->SerialNo==Sn)
		{
			temp=head->next;
			head->next=temp->next;
			temp->next->pre=head;
			BookQty(temp->BookCode);
			fine=(D-temp->Doi)-7;
			free(temp);
			loading();
			printf("\nCongratulation:-\n\t Book Return is Successful.");
			if(fine>=1)
				printf("\nfine = %d",fine);
			else
				printf("\nfine = 0");
			return;
		}
		head=head->next;
	}while(head!=IRHead);
	printf("\nSorry:- \n\t Not found of Book Record.");
}//BookReturn function is closed....

void WriteBookRecord()
{
	Book *head;
	char ch='y';
	FILE *fp;
	if(BHead==NULL)
	{
		printf("\nSorry:-\n\t Book Record is not available.");
		return;
	}
	head=BHead;
	fp=fopen("B_records.txt","w");
	do
	{
		fprintf(fp,"\n%ld ",head->BookCode);
		fprintf(fp,"%s ",head->BookName);
		fprintf(fp,"%s ",head->Author);
		fprintf(fp,"%s ",head->Publication);
		fprintf(fp,"%s ",head->Subject);
		fprintf(fp,"%d ",head->StockQty);
		if(head->next!=BHead)
			fprintf(fp,"%c ",ch);
		else
		{
			ch='n';
			fprintf(fp,"%c ",ch);
		}
		head=head->next;
	}while(head!=BHead);
	fclose(fp);
}//WriteBookRecord function closed......

void WriteMemberRecord()
{
	Member *head;
	FILE *fp;
	char ch='y';
	if(MHead==NULL)
	{
		printf("\nSorry:-\n\t Member Record is not available.");
		return;
	}
	head=MHead;
	fp=fopen("M_record.txt","w");
	do
	{
		fprintf(fp,"\n%ld ",head->MemId);
		fprintf(fp,"%ld ",head->CardNo);
		fprintf(fp,"%s ",head->MemName);
		fprintf(fp,"%d %d %d",head->Day,head->Month,head->Year);
		fprintf(fp,"%s ",head->Course);
		fprintf(fp,"%d ",head->year);
		if(head->next!=MHead)
			fprintf(fp,"%c ",ch);
		else
		{
			ch='n';
			fprintf(fp,"%c ",ch);
		}
		head=head->next;

	}while(head!=MHead);
	fclose(fp);
}//WriteMemberRecord function closed......

void WriteIssueRecord()
{
	IRR *head;
	FILE *fp;
	char ch='y';
	if(IRHead==NULL)
	{
		printf("\nSorry:-\n\t Member Record is not available.");
		return;
	}
	head=IRHead;
	fp=fopen("I_record.txt","w");
	do
	{
		fprintf(fp,"\n%d ",head->SerialNo);
		fprintf(fp,"%ld ",head->MemId);
		fprintf(fp,"%ld ",head->BookCode);
		fprintf(fp,"%d %d %d ",head->Doi,head->Moi,head->Yoi);
		if(head->next!=IRHead)
			fprintf(fp,"%c ",ch);
		else
		{
			ch='n';
			fprintf(fp,"%c ",ch);
		}
		head=head->next;

	}while(head!=IRHead);
	fclose(fp);
}//WriteIssueRecord function closed......

void accBookList()
{
	Book *head,*New;
	char ch;
	FILE *fp;
	fp=fopen("B_records.txt","r"); 			      //
	do
	{
		if(BHead==NULL)
		{
			New=(Book*)malloc(sizeof(Book));
			fflush(stdin);
			clrscr();

			fscanf(fp,"%ld %s %s %s %s %d %c",&New->BookCode,&New->BookName,&New->Author,&New->Subject,&New->Publication,&New->StockQty,&ch);

			BHead=New;
			BHead->next=BHead;
			BHead->pre=BHead;
		}//if close
		else
		{
			head=BHead;
			while(head->next!=BHead)
				head=head->next;//find lasd node.....
			//data entry....
			New=(Book*)malloc(sizeof(Book));
			fflush(stdin);

			fscanf(fp,"%ld %s %s %s %s %d %c",&New->BookCode,&New->BookName,&New->Author,&New->Subject,&New->Publication,&New->StockQty,&ch);

			//set new node in main list...
			head->next=New;
			New->pre=head;
			New->next=BHead;
			BHead->pre=New;
		}
       }while(ch=='y'||ch=='Y');//while close
	fclose(fp);

}//accBookList function closed...

void accMemList()
{
	Member *head,*New;
	char ch;
	FILE *fp;
	fp=fopen("M_records.txt","r"); 			      //
	do
	{
		if(MHead==NULL)
		{
			New=(Member*)malloc(sizeof(Member));
			fflush(stdin);

			fscanf(fp,"%d %ld %s %d %d %d %s %d %c",&New->MemId,&New->CardNo,&New->MemName,&New->Day,&New->Month,&New->Year,&New->Course,&New->year,&ch);

			MHead=New;
			MHead->next=MHead;
			MHead->pre=MHead;
		}//if close
		else
		{
			head=MHead;
			while(head->next!=MHead)
				head=head->next;//find last node.....
			//data entry....
			New=(Member*)malloc(sizeof(Member));
			fflush(stdin);

			fscanf(fp,"%d %ld %s %d %d %d %s %d %c",&New->MemId,&New->CardNo,&New->MemName,&New->Day,&New->Month,&New->Year,&New->Course,&New->year,&ch);

			//set new node in main list...
			head->next=New;
			New->pre=head;
			New->next=MHead;
			MHead->pre=New;
		}
       }while(ch=='y'||ch=='Y');//while close
	fclose(fp);

}//accMemList function closed...

void accIssueList()
{
	IRR *head,*New;
	char ch;
	FILE *fp;
	fp=fopen("I_records.txt","r"); 			      //
	do
	{
		if(IRHead==NULL)
		{
			New=(IRR*)malloc(sizeof(IRR));
			fflush(stdin);

			fscanf(fp,"%d %ld %ld %d %d %d %c",&New->SerialNo,&New->MemId,&New->BookCode,&New->Doi,&New->Moi,&New->Yoi,&ch);

			IRHead=New;
			IRHead->next=IRHead;
			IRHead->pre=IRHead;
		}//if close
		else
		{
			head=IRHead;
			while(head->next!=IRHead)
				head=head->next;//find lasd node.....
			//data entry....
			New=(IRR*)malloc(sizeof(IRR));
			fflush(stdin);

			fscanf(fp,"%d %ld %ld %d %d %d %c",&New->SerialNo,&New->MemId,&New->BookCode,&New->Doi,&New->Moi,&New->Yoi,&ch);

			//set new node in main list...
			head->next=New;
			New->pre=head;
			New->next=IRHead;
			IRHead->pre=New;
		}
       }while(ch=='y'||ch=='Y');//while close
	fclose(fp);

}//accIssueList function closed...


void main()
{
	while(1)
	{
		clrscr();
		accBookList();
		accMemList();
		accIssueList();
		switch(MainMenu())
		{
		case 0:
			WriteBookRecord();
			WriteMemberRecord();
			WriteIssueRecord();
			exit(0);
		case 1:
			switch(BookMenu())
			{
			case 0:
				MainMenu();
				break;
			case 1:
				AddBookRecord();
				break;
			case 2:
				DisplayBookRecord();
				break;
			case 3:
				UpdateBookRecord();
				break;
			case 4:
				DeleteBookRecord();
				break;
			default:
				printf("Wrong input");
			}
			break;
		case 2:
			switch(MemberMenu())
			{
			case 0:
				MainMenu();
				break;
			case 1:
				AddMemberRecord();
				break;
			case 2:
				DisplayMemberRecord();
				break;
			case 3:
				UpdateMemberRecord();
				break;
			case 4:
				DeleteMemberRecord();
				break;
			default:
				printf("Wrong input");
			}
			break;
		case 3:
			switch(IRMenu())
			{
			case 0:
				MainMenu();
				break;
			case 1:
				BookIssue();
				break;
			case 2:
				BookReturn();
				break;
			default:
				printf("Wrong input");
			}
			break;
		default:
			printf("Wrong input");
		}
		getch();
	}//while closed...

}//main closed....
