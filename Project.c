#include<stdio.h>
#include<string.h>
typedef struct player{
	char pname[100];
	int jno;
	int ing;
	int runs;
	int wkt;
	
}player;

int cnt=0;
player p[100];
void nplay(int);
void dplay(int);
void premove(int,int);
int pSearchByName(char*);
int pSearchByJno(int);
void pUpdate(int);
int RunsMin();
int RunsMax();       
int WicketMax();
int WicketMin();
void AddPlayer();
int main()
{
	int ch,a;
	
	do
	{
	printf("\n--------------------------------------------------------------------------");
	printf("\n0.To Exit\n1.Enter Player Details\n2.Print Players ");
	printf("\n3.Enter For Remove Player");
	printf("\n4.To Search Player ");
	printf("\n5.To Update Player Details");
	printf("\n6.To Find Maximum Runs OR Minimum Runs And Maximum Wickets OR Minimum Wickets");
	printf("\nPlease Enter Your Choise :");
	scanf("%d",&ch);
	printf("\n-------------------------------------------------------------------------");
	switch(ch)
	{
		case 1:
			{
				int n,i;
				
				printf("\nEnter No Of Players:");
				scanf("%d",&n);
				int t=cnt+n;
				for(i=cnt;i<t;i++)
				{
					nplay(i);
					cnt++;	
				}
				break;
			}
			
			
		case 2:
			{
				int i;
				for(i=0;i<cnt;i++)
				{
					
					dplay(i);
				}
				break;
			}
		case 3:
			{
				printf("/nEnter Number Of Player To Delete");
				int key;
				scanf("%d",&key);
				premove(cnt,key);
				break;
			}
		
		case 4:
			{
				printf("\n1. To Search Player By Name \n2. To Search Player By Jersy Number");
				int ch1;
				scanf("%d",&ch1);
				if(ch1==1)
				{
					printf("\nEnter Name Of Player To Search :");
					char str1[100];
					scanf("%s",&str1);
					int k=pSearchByName(str1);
					if(k>=0)
					{
	
						printf("\nPlayer Found At %d Position ",k+1);
						
						printf("\n\n1.To See Deatils Of Player %d",k+1);
						printf("\n0.Press Any Key To Continue\n");
						int ch2;
						scanf("%d",&ch2);
						if(ch2==1)
						{
							dplay(k);
						}
					}
					else
					printf("\nPLAYER NOT FOUND");
					
				}
				else if(ch1==2)
				{
					printf("\nEnter Jersy Number To Search :");
					int key;
					scanf("%d",&key);
					int k=pSearchByJno(key);
					if(k>=0)
					{
						printf("\nPlayer Found At %d Position",k+1);
						printf("\n\n1.To See Deatils Of Player %d",k+1);
						printf("\n0.Press Any Key To Continue\n");
						int ch2;
						scanf("%d",&ch2);
						if(ch2==1)
						{
							dplay(k);					
						}
					}
					else
					{
						printf("\nPLAYER NOT FOUND...");
					}
				}
				break;
			}
		case 5:
			{
				int n;
				printf("\nEnter player Number To Update The Data :");
				scanf("%d",&n);
				pUpdate(n);
				break;
			}
		case 6:
			{
				int n,k;
				printf("\n1.Maximum Runs");
				printf("\n2.Minimum Runs");
				printf("\n3.Maximum Wickets");
				printf("\n4.Minimun Wickets");
				scanf("%d",&n);
				if(n==1)
				{
					k=RunMax();
					dplay(k);
				}
				else if(n==2)
				{
					k=RunMin();
					dplay(k);
				}
				else if(n==3)
				{
					k=WicketMax();
					dplay(k);
				}
				else if(n==4)
				{
					k=WicketMin();
					dplay(k);
				}
				else
				printf("\nInvalid Choise..");
				
				break;
			}
		default :
			{
				printf("\nINVALID CHOISE....!");
			}
			
	}
	
}while(ch!=0);
return 0;
}

void nplay(int i)
{

		printf("\nEnter Details Of Player Number --|%d|--",i+1);
		printf("\nEnter Name Of Player :");
		char str[50];
		scanf("%s",&str);
		strcpy(p[cnt].pname,str);
		printf("\nEnter Jersy Number Of Player :");
		scanf("%d",&p[cnt].jno);
		printf("\nEnter innings Of Player :");
		scanf("%d",&p[cnt].ing);
		printf("\nEnter Run Of Player:");
		scanf("%d",&p[cnt].runs);
		printf("\nEnter Wickets Of Player:");
		scanf("%d",&p[cnt].wkt);
		printf("\nPlayer Entered Successfully.....!");
		printf("\n-------------------------------------------------------------------------");
}

void dplay(int i)
{
	
	
		printf("\nDetails Of player Number --|%d|--",i+1);
		printf("\nName Of Player :%s",p[i].pname);
		printf("\nJersy No Of Player:%d",p[i].jno);
		printf("\nNumber Of Innings :%d",p[i].ing);
		printf("\nRuns Of Player :%d",p[i].runs);
		printf("\nWickets Of Player :%d",p[i].wkt);
		printf("\n-------------------------------------------------------------------------");
	
}

void premove(int n,int key)
{
	int i;
	for(i=key-1;i<n;i++)
	{
		p[i]=p[i+1];
	}
	cnt--;
}

int pSearchByName(char*str1)
{
	int i;
	for(i=0;i<cnt;i++)
	{
		int b=strcmp(str1,p[i].pname);
		if(b==0)
		return i;	
	}
	return -1;
}

int pSearchByJno(int a)
{
	int i;
	for(i=0;i<cnt;i++)
	{
		if(a==p[i].jno)
		return i;
	}
	return -1;
}

void pUpdate(int i)
{
	i=i-1;
	printf("\nDetails Of Player :-");
	dplay(i-1);
	printf("\nPlease Enter Data To update:");
	printf("\nEnter Name Of Player :");
	char str[50];
	scanf("%s",&str);
	strcpy(p[i].pname,str);
	printf("\nEnter Jersy Number Of Player :");
	scanf("%d",&p[i].jno);
	printf("\nEnter innings Of Player :");
	scanf("%d",&p[i].ing);
	printf("\nEnter Run Of Player:");
	scanf("%d",&p[i].runs);
	printf("\nEnter Wickets Of Player:");
	scanf("%d",&p[i].wkt);
	printf("\nPlayer updated Successfully.....!");
	printf("\n-------------------------------------------------------------------------");
}

int RunMax()
{
	int temp=p[0].runs;
	int i,k=0;
	for(i=1;i<cnt;i++)
	{
		if(temp<p[i].runs)
		{
			temp=p[i].runs;
			k++;
		}
	}
	return k;
}
int RunMin()
{
	int temp=p[0].runs;
	int i,k=0;
	for(i=1;i<cnt;i++)
	{
		if(temp>p[i].runs)
		{
			temp=p[i].runs;
			k++;
		}
	}
	return k;
}
int WicketMax()
{
	int temp=p[0].wkt;
	int i,k=0;
	for(i=1;i<cnt;i++)
	{
		if(temp<p[i].wkt)
		{
			temp=p[i].wkt;
			k++;
		}
	}
	return k;
}
int WicketMin()
{
	int temp=p[0].wkt;
	int i,k=0;
	for(i=1;i<cnt;i++)
	{
		if(temp>p[i].wkt)
		{
			temp=p[i].wkt;
			k++;
		}
	}
	return k;
}


