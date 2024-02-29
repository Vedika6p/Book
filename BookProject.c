#include<stdio.h>
#include<string.h>
typedef struct book
{
	int id;
	char name[20];
	char author[30];
	double price;
	int rating;
}book;

void store(book*,int);
void display(book*,int);
char* search(int,book*);
void update(book*,int);
void deletebook(book*,int);
int maxprice(book*);
int maxrating(book*);
void toptwoprice(book*);
void toptworating(book*);


int count=0;  //global variable

void main()
{
	book b[20];
	int exit;
	int n=10;
	printf("Show book Details \n");
	//printf("How many book you want to add :: ");
	//scanf("%d",&n);
	store(b,n);
	
	do{
		
		printf("1:Display\n2:Search\n3:Update\n4:Delete\n5:Max(price)\n6:Top 3 (rating)\n");
	
	int choice;
	
	printf("Enter your choice :: \n");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			//Display
			display(b,count);
			break;
			
		case 2:
			//search
			printf("Enter the book id :: ");
			int id;
			scanf("%d",&id);
			search(id,b);
			break;
			
		case 3:
			//Update
			printf("Enter the book id :: ");
			scanf("%d",&id);
			update(b,id);
			break;
			
		case 4:
			//Delete
			printf("Enter the book id if you want to delete\n");
			scanf("%d",&id);
			deletebook(b,id);
			break;
			
		case 5:	
			maxprice(b);
			printf("\n_______________________________________Max Rating_____________________________________\n");
			maxrating(b);
			break;
			
		case 6:
			toptwoprice(b);
			toptworating(b);
			break;
	}
		
		printf("Do you want to continue (0/1)?");
		scanf("%d",&exit);
	}while(exit);
	
	
}

void store(book* b,int n)
{	
	int i;
	for(i=0;i<n;i++)
	{
		count++;
//		printf("\n****Enter book Details****\n");
//		printf("Enter book id :: ");
//		scanf("%d",&b[i].id);
//		printf("Enter name :: ");
//		scanf("%s",b[i].name);
//		fflush(stdin);
//		printf("Enter author name :: ");
//		scanf("%s",&b[i].author);
//		printf("Enter the price :: ");
//		scanf("%lf",&b[i].price);
//		printf("Enter the rating :: ");
//		scanf("%d",&b[i].rating);
//		printf("____________");
//		printf("\n");
                    b[0].id=1;
                    strcpy(b[0].name, "Wings of fire");
                    strcpy(b[0].author, "A.P.J Abdul Kalam");
                    b[0].price = 172;
                    b[0].rating = 5;
                    
                    b[1].id=2;
                    strcpy(b[1].name, "Believe In Yourself");
                    strcpy(b[1].author, "Napoleon Hill");
                    b[1].price = 350;
                    b[1].rating = 6;
                    
                    b[2].id=3;
                    strcpy(b[2].name, "Agnipankh");
                    strcpy(b[2].author, "A.P.J Abdul Kalam");
                    b[2].price = 180;
                    b[2].rating = 3;
                    
                    b[3].id=4;
                    strcpy(b[3].name, "Ek Hota Karvhar");
                    strcpy(b[3].author, "Veena Gawankar");
                    b[3].price = 200;
                    b[3].rating = 4.6;
                    
                    b[4].id=5;
                    strcpy(b[4].name, "Gita Rahasya");
                    strcpy(b[4].author, "Bal Gangadhar Tilak");
                    b[4].price = 313;
                    b[4].rating = 2;
                    
                    b[5].id=6;
                    strcpy(b[5].name, "Yayati");
                    strcpy(b[5].author, "V.S.Khandekar ");
                    b[5].price = 280;
                    b[5].rating = 4.5;
                    
                    b[6].id=7;
                    strcpy(b[6].name, "The Autobiography of a Yogi");
                    strcpy(b[6].author, "Paramhansa Yogananda");
                    b[6].price = 295;
                    b[6].rating = 4.6;
                    
                    b[7].id=8;
                    strcpy(b[7].name, "Astitva");
                    strcpy(b[7].author, "Sudha Murthy");
                    b[7].price = 110;
                    b[7].rating = 7;
                    
                    b[8].id=9;
                    strcpy(b[8].name, "Computing Fundamentals");
                    strcpy(b[8].author, "E Balguruswami");
                    b[8].price = 601;
                    b[8].rating = 6;
                    
                    b[9].id=10;
                    strcpy(b[9].name, "Gitanjali");
                    strcpy(b[9].author, "Rabindranath Tagore");
                    b[9].price = 149;
                    b[9].rating = 3;
	}
}
void display(book* b,int n)
{
	int i;
	printf("------------------------------------------------------------------------------------------------------\n");
	printf("id  |                   Name                  |            author             |   price   |rating    |\n");
	printf("------------------------------------------------------------------------------------------------------\n");
    
	for(i=0;i<count;i++)
	{
       //printf("%d\n%s\n%s\n%lf\n%d\n",b[i].id,b[i].name,b[i].author,b[i].price,b[i].rating);
    printf("%3d |%40s |%30s |%10lf |%8d  |\n",b[i].id,b[i].name,b[i].author,b[i].price,b[i].rating);
	printf("-------------------------------------------------------------------------------------------------------\n");
	
	}
	
}
char* search(int idno,book* b)
{
	int i,flag=0;
	for(i=0;i<count;i++)
	{
		if(b[i].id==idno)
		{
			flag=1;
			printf("id  |                   Name                  |            author             |   price   |rating     |\n");
	        printf("------------------------------------------------------------------------------------------------------\n");
	        printf("%3d |%40s |%30s |%10lf |%8d  |\n",b[i].id,b[i].name,b[i].author,b[i].price,b[i].rating);
			//printf("id : %d\nname : %s\nauthor :%s\nprice :%lf\nrating :%d\n",b[i].id,b[i].name,b[i].author,b[i].price,b[i].rating);
			return b[i].name;	
		}
	}
	if(flag==0)
		printf("No book found with id no %d",idno);
		
	

}
void update(book* b,int idno)
{
	int i,flag=0;
	for(i=0;i<count;i++)
	{
		if(b[i].id==idno)
		{
			flag=1;
			printf("Enter the price :: ");
			scanf("%lf",&b[i].price);
			printf("Enter the rating ::");
			scanf("%d",&b[i].rating);
			
			
			printf("updated successfully \n");
			printf("id  |                   Name                  |            author             |   price   |rating     |\n");
	        printf("------------------------------------------------------------------------------------------------------\n");
	        printf("%3d |%40s |%30s |%10lf |%8d  |\n",b[i].id,b[i].name,b[i].author,b[i].price,b[i].rating);
			//printf("id\nName\nauthor\nprice\nrating\n");
			//printf("%d\t%s\t\t%d\t\t%d\t%d\\n",b[i].id,b[i].name,b[i].author,b[i].price,b[i].rating);				
			break;
				
		}
	}
	if(flag==0)
		printf("No book found with id no %d\n",idno);
}
void deletebook(book* b,int idno)
{
	int i,flag=0;	
	for(i=0;i<count;i++)
	{
		
	if(b[i].id==idno )
		{
			flag=1;
			b[i]=b[i+1];
		}
		if(flag==1)
		{
			b[i+1]=b[i+2];
		}
     }
	if(flag==0)
		printf("id number not found");

	else if(flag==1)
	{
		printf("Successfully Deleted book\n");
		count=count-1;
		printf("Count is after deleting :: %d\n",count);
	}
	display(b,count);	
}

int maxprice(book* b)
{
	int i,index;
	int max = 0;
	for(i=0;i<count;i++)
	{
		if(max<b[i].price)
		{
			max=b[i].price;
			index=i;
		}
	}
	
	printf("id  |                   Name                  |            author             |   price   |rating     |\n");
	printf("------------------------------------------------------------------------------------------------------\n");
	printf("%3d |%40s |%30s |%10lf |%8d  |\n",b[index].id,b[index].name,b[index].author,b[index].price,b[index].rating);
	//printf("id\nName\n\nauthor\nprice\nrating\n");
	//printf("%d\n%s\n\n%s\n\n%lf\n%d\n",b[index].id,b[index].name,b[index].author,b[index].price,b[index].rating);
	return b[index].id;
	
	
}
int maxrating(book* b)
{
	int i,index;
	int max = 0;//b[0].rating;
	for(i=0;i<count;i++)
	{
		if(max<b[i].rating)
		{
			max=b[i].rating;
			index=i;
		}
	}
	    
	    printf("id  |                   Name                  |            author             |   price   |rating     |\n");
	    printf("------------------------------------------------------------------------------------------------------\n");
	    printf("%3d |%40s |%30s |%10lf |%8d  |\n",b[index].id,b[index].name,b[index].author,b[index].price,b[index].rating);
	    //printf("id\nName\n\nauthor\nprice\nrating\n");
	    //printf("%d\n%s\n\n%d\n\n%d\n%d\n",b[index].id,b[index].name,b[index].author,b[index].price,b[index].rating);
	        	
	return b[index].id;
}
void toptwoprice(book* b)
{
	int i,index;
    int max=0;
	for(i=0;i<count;i++)
	{
		if(max<b[i].price)
		{
			max=b[i].price;
			index=i;
		}
	}
	printf("______________________________________top book by price are___________________________________________\n");
	printf("id  |                   Name                  |            author             |   price   |rating     |\n");
	printf("------------------------------------------------------------------------------------------------------\n");
	printf("%3d |%40s |%30s |%10lf |%8d  |\n",b[index].id,b[index].name,b[index].author,b[index].price,b[index].rating);
	//printf("id\tName\t\tauthor\tprice\trating\n");
	//printf("%d\t%s\t\t%s\t\t%lf\t%d\n",b[index].id,b[index].name,b[index].author,b[index].price,b[index].rating);
	
	int max2 =0;
	for(i=0;i<count;i++)
	{
	
		if(max2<b[i].price&&b[i].price!=max)
		{
			max2=b[i].price;
			index=i;
		
		}
	}
	//printf("id  |                   Name                  |            author             |   price   |rating     |\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("%3d |%40s |%30s |%10lf |%8d  |\n",b[index].id,b[index].name,b[index].author,b[index].price,b[index].rating);
	//printf("%d\t%s\t\t%s\t\t%lf\t%d\n",b[index].id,b[index].name,b[index].author,b[index].price,b[index].rating);
	printf("_______________________________________________________________________________________________________\n");
}

void toptworating(book* b)
{
	printf("Count in toptworating is :: %d\n",count);
	int i,index,index2;
	int top = 0;
	for(i=0;i<count;i++)
	{

		if(top<b[i].rating)
		{
			top = b[i].rating;
			index=i;	
		}
	}
	
	printf("__________________________________________Top books by rating are______________________________________\n");
    printf("id  |                   Name                  |            author             |   price   |rating     |\n");
    printf("------------------------------------------------------------------------------------------------------\n");
	printf("%3d |%40s |%30s |%10lf |%8d  |\n",b[index].id,b[index].name,b[index].author,b[index].price,b[index].rating);
    //printf("id\tname\t\tauthor\tprice\trating\n");
	//printf("%d\t%s\t\t%s\t\t%lf\t%d\n",b[index].id,b[index].name,b[index].author,b[index].price,b[index].rating);
	int top2 = 0;
	for(i=0;i<count;i++)
	{
	
		if(b[i].rating>top2&&b[i].rating!=top)
		{
			top2=b[i].rating;
			index2=i;
		}
	}
	
    printf("------------------------------------------------------------------------------------------------------\n");
	printf("%3d |%40s |%30s |%10lf |%8d  |\n",b[index2].id,b[index2].name,b[index2].author,b[index2].price,b[index2].rating);
    //	printf("%d\t%s\t\t%s\t\t%lf\t%d\n",b[index2].id,b[index2].name,b[index2].author,b[index2].price,b[index2].rating);
	printf("________________________________________________________________________________________________________\n");
}



