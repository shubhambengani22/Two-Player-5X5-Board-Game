#include<stdio.h>
#include<stdlib.h>
int i,j;
void downX(int posX[5],int posO[5],int a[5][5],int n);
void downO(int posX[5],int posO[5],int a[5][5],int n);
void upX(int posX[5],int posO[5],int a[5][5],int n);
void upO(int posX[5],int posO[5],int a[5][5],int n);
void rightX(int posX[5],int posO[5],int a[5][5],int n);
void rightO(int posX[5],int posO[5],int a[5][5],int n);
void leftX(int posX[5],int posO[5],int a[5][5],int n);
void leftO(int posX[5],int posO[5],int a[5][5],int n);
void display(int posX[5],int posO[5],int a[5][5],int x,int o,int cx,int co);
void sort(int arr[],int c);
void isWinner(int cx, int co);
void main()
{
        int posX[5],posO[5],p,n,m,q,k,s,x,o,c1,c2,c3,cx,co,l,done,pn,choice;
        done=0;
        x=0;
        o=0;
        cx=0;
        co=0;
        int b[16][5]= {
                        {1,2,3,0,0},
                        {2,3,4,0,0},
                        {3,4,5,0,0},
                        {7,8,9,0,0},
                        {17,18,19,0,0},
                        {21,22,23,0,0},
                        {22,23,24,0,0},
                        {23,24,25,0,0},
                        {1,6,11,0,0},
                        {6,11,16,0,0},
                        {11,16,21,0,0},
                        {7,12,17,0,0},
                        {9,14,19,0,0},
                        {5,10,15,0,0},
                        {10,15,20,0,0},
                        {15,20,25,0,0}
                      };
        int a[5][5] = {
                        {1,2,3,4,5},
                        {6,7,8,9,10},
                        {11,12,13,14,15},
                        {16,17,18,19,20},
                        {21,22,23,24,25}
                      };
        a:m=0;
        q=0;
        for(p=1;p<=10;p++)
        {
                if(p%2==0)
                {
                        printf("Enter the position of O : ");
                        scanf("%d",&posO[q]);
                        q++;
                }
                else
                {
                        printf("Enter the position of X : ");
                        scanf("%d",&posX[m]);
                        m++;
                }
        }
        for(i=0;i<5;i++)
                {
                        for(j=0;j<5;j++)
                        {
				for(m=0;m<5;m++)
				{
				        for(q=0;q<5;q++)
				        {
				                if(posX[m]==a[i][j] && posO[q]==a[i][j])
				                {
				                        printf("You cannot enter at X and O same positions\n");
							goto a;
						}
					}
				}
				}
				}
	for(i=0;i<5;i++)
	{
	for(j=i+1;j<5;j++)
	{
	if(posX[i]==posX[j])
	{
	printf("You cannot Enter X at same positions\n");
	goto a;
	}
	if(posO[i]==posO[j])
	{
	printf("You cannot Enter O at same positions\n");
	goto a;
	}
	}
	}
        printf("\n");
        for(i=0;i<5;i++)
        {
                if(posX[i]==13 || posO[i]==13)
                {
                        printf("Invalid Position\n");
                        printf("Enter the positions again\n");
                        goto a;
                }
        }
        sort(posX,cx);
        sort(posO,co);
        display(posX,posO,a,x,o,cx,co);
        while(!done)
        {
	for(c1=0;c1<3;c1++)
	{
	for(c2=1;c2<4;c2++)
	{
	for(c3=2;c3<5;c3++)
	{
        for(k=0;k<16;k++)
        {
        if(posX[c1]==b[k][0] && posX[c2]==b[k][1] && posX[c3]==b[k][2] && b[k][3]==0)
                {
                                //printf("i = %d    k = %d",i,k);
                                printf("Enter the number of pawn 'O' to be removed : ");
                                scanf("%d",&n);
                                o=posO[n-1];
                                posO[n-1]=0;
                                if(b[k][3]==0)
                                co++; 
                                b[k][3]=1;
                                sort(posX,cx);
                                sort(posO,co);
                                display(posX,posO,a,x,o,cx,co);
                }
        if(posO[c1]==b[k][0] && posO[c2]==b[k][1] && posO[c3]==b[k][2] && b[k][4]==0)
                {
                                printf("Enter the number of pawn 'X' to be removed : ");
                                scanf("%d",&n);
                                x=posX[n-1];
                                posX[n-1]=0;
                                if(b[k][4]==0)
                                cx++; 
                                b[k][4]=1;
                                sort(posX,cx);
                                sort(posO,co);
                                display(posX,posO,a,x,o,cx,co);
                }
                }
                }
                }
                }
                isWinner(cx,co);
                printf("\n1. Down  2. Up  3. Right  4. Left  5. Exit\n");
                printf("Enter the choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1: printf("Enter the player number to continue : ");
                        scanf("%d",&pn);
                        if(pn==1)
                        {
                                downX(posX,posO,a,n);
                                sort(posX,cx);
                                sort(posO,co);
                                display(posX,posO,a,x,o,cx,co);
                        }
                        if(pn==2)
                        {
                                downO(posX,posO,a,n);
                                sort(posX,cx);
                                sort(posO,co);
                                display(posX,posO,a,x,o,cx,co);        
                        }
                        break;
                case 2: printf("Enter the player number to continue : ");
                        scanf("%d",&pn);
                        if(pn==1)
                        {
                                upX(posX,posO,a,n);
                                sort(posX,cx);
                                sort(posO,co);
                                display(posX,posO,a,x,o,cx,co);
                        }
                        if(pn==2)
                        {
                                upO(posX,posO,a,n);
                                sort(posX,cx);
                                sort(posO,co);
                                display(posX,posO,a,x,o,cx,co);        
                        }
                        break;
                case 3: printf("Enter the player number to continue : ");
                        scanf("%d",&pn);
                        if(pn==1)
                        {
                                rightX(posX,posO,a,n);
                                sort(posX,cx);
                                sort(posO,co);
                                display(posX,posO,a,x,o,cx,co);
                        }
                        if(pn==2)
                        {
                                rightO(posX,posO,a,n);
                                sort(posX,cx);
                                sort(posO,co);
                                display(posX,posO,a,x,o,cx,co);        
                        }
                        break;
                case 4: printf("Enter the player number to continue : ");
                        scanf("%d",&pn);
                        if(pn==1)
                        {
                                leftX(posX,posO,a,n);
                                sort(posX,cx);
                                sort(posO,co);
                                display(posX,posO,a,x,o,cx,co);
                        }
                        if(pn==2)
                        {
                                leftO(posX,posO,a,n);
                                sort(posX,cx);
                                sort(posO,co);
                                display(posX,posO,a,x,o,cx,co);
                        }  
                        break;      
                case 5: done=1;
                        break;
                default:printf("Enter a valid choice\n");
                        break;
                }
        }
        b:return;
}
void downX(int posX[5],int posO[5],int a[5][5],int n)
{
                printf("Enter the number of pawn 'X' to move DOWN : ");
                scanf("%d",&n);
                printf("\n");
                for(i=0;i<5;i++)
                {
                        for(j=0;j<5;j++)
                        {
                                if(posX[n-1]==a[i][j])
                                {
                                        posX[n-1]=a[i+1][j];
                                        goto c;
                                }
                                if(posX[n-1]>=20 && posX[n-1]<=25)
                                {
                                        printf("The Pawn cannot be moved DOWN\n");
                                        goto c;
                                }
                                if(posX[n-1]==2 || posX[n-1]==4 || posX[n-1]==17 || posX[n-1]==19)
                                {
                                        printf("Illegal Move\n");
                                        goto c;
                                }
                                if(posX[n-1]==8)
                                {
                                        printf("The Pawn cannot be shifted to this position\n");
                                        goto c;
                                }
                        }       
                }
                c:return;
}
void downO(int posX[5],int posO[5],int a[5][5],int n)
{
                printf("Enter the number of pawn 'O' to move DOWN : ");
                scanf("%d",&n);
                printf("\n");
                for(i=0;i<5;i++)
                {
                        for(j=0;j<5;j++)
                        {
                                if(posO[n-1]==a[i][j])
                                {
                                        posO[n-1]=a[i+1][j];
                                        goto c;
                                }
                                if(posO[n-1]>=21 && posO[n-1]<=25)
                                {
                                        printf("The Pawn cannot be moved DOWN\n");
                                        goto c;
                                }
                                if(posO[n-1]==2 || posO[n-1]==4 || posO[n-1]==17 || posO[n-1]==19)
                                {
                                        printf("Illegal Move\n");
                                        goto c;
                                }
                                if(posO[n-1]==8)
                                {
                                        printf("The Pawn cannot be shifted to this position\n");
                                        goto c;
                                }
                        }       
                }       ;
        c:return;
}
void upX(int posX[5],int posO[5],int a[5][5],int n)
{
                printf("Enter the number of pawn 'X' to move UP : ");
                scanf("%d",&n);
                printf("\n");
                for(i=0;i<5;i++)
                {
                        for(j=0;j<5;j++)
                        {
                                if(posX[n-1]==a[i][j])
                                {
                                        posX[n-1]=a[i-1][j];
                                        goto c;
                                }
                                else if(posX[n-1]<=5)
                                {
                                        printf("The Pawn cannot be moved UP\n");
                                        goto c;
                                }
                                if(posX[n-1]==7 || posX[n-1]==9 || posX[n-1]==22 || posX[n-1]==24)
                                {
                                        printf("Illegal Move\n");
                                        goto c;
                                }
                                if(posX[n-1]==18)
                                {
                                        printf("The Pawn cannot be shifted to this position\n");
                                        goto c;
                                }
                        }       
                }       
        c:return;
}
void upO(int posX[5],int posO[5],int a[5][5],int n)
{
                printf("Enter the number of pawn 'O' to move UP : ");
                scanf("%d",&n);
                printf("\n");
                for(i=0;i<5;i++)
                {
                        for(j=0;j<5;j++)
                        {
                                if(posO[n-1]==a[i][j])
                                {
                                        posO[n-1]=a[i-1][j];
                                        goto c;
                                }
                                if(posO[n-1]<=5)
                                {
                                        printf("The Pawn cannot be moved UP\n");
                                        goto c;
                                }
                                if(posO[n-1]==7 || posO[n-1]==9 || posO[n-1]==22 || posO[n-1]==24)
                                {
                                        printf("Illegal Move\n");
                                        goto c;
                                }
                                if(posO[n-1]==18)
                                {
                                        printf("The Pawn cannot be shifted to this position\n");
                                        goto c;
                                }
                        }       
                }       
        c:return;
}
void rightX(int posX[5],int posO[5],int a[5][5],int n)
{
                printf("Enter the number of pawn 'X' to move RIGHT : ");
                scanf("%d",&n);
                printf("\n");
                for(i=0;i<5;i++)
                {
                        for(j=0;j<5;j++)
                        {
                                if(posX[n-1]==a[i][j])
                                {
                                        posX[n-1]=a[i][j+1];
                                        goto c;
                                }
                                if(posX[n-1]==5 || posX[n-1]==10 || posX[n-1]==15 || posX[n-1]==20 || posX[n-1]==25)
                                {
                                        printf("The Pawn cannot be moved RIGHT\n");
                                        goto c;
                                }
                                if(posX[n-1]==6 || posX[n-1]==9 || posX[n-1]==16 || posX[n-1]==19)
                                {
                                        printf("Illegal Move\n");
                                        goto c;
                                }
                                if(posX[n-1]==12)
                                {
                                        printf("The Pawn cannot be shifted to this position\n");
                                        goto c;
                                }
                        }       
                }       
        c:return;
}
void rightO(int posX[5],int posO[5],int a[5][5],int n)
{
                printf("Enter the number of pawn 'O' to move RIGHT : ");
                scanf("%d",&n);
                printf("\n");
                for(i=0;i<5;i++)
                {
                        for(j=0;j<5;j++)
                        {
                                if(posO[n-1]==a[i][j])
                                {
                                        posO[n-1]=a[i][j+1];
                                        goto c;
                                }
                                if(posO[n-1]==5 || posO[n-1]==10 || posO[n-1]==15 || posO[n-1]==20 || posO[n-1]==25)
                                {
                                        printf("The Pawn cannot be moved RIGHT\n");
                                        goto c;
                                }
                                if(posO[n-1]==6 || posO[n-1]==9 || posO[n-1]==16 || posO[n-1]==19)
                                {
                                        printf("Illegal Move\n");
                                        goto c;
                                }
                                if(posO[n-1]==12)
                                {
                                        printf("The Pawn cannot be shifted to this position\n");
                                        goto c;
                                }
                        }       
                }       
        c:return;
}
void leftX(int posX[5],int posO[5],int a[5][5],int n)
{
                printf("Enter the number of pawn 'X' to move LEFT : ");
                scanf("%d",&n);
                printf("\n");
                for(i=0;i<5;i++)
                {
                        for(j=0;j<5;j++)
                        {
                                if(posX[n-1]==a[i][j])
                                {
                                        posX[n-1]=a[i][j-1];
                                        goto c;
                                }
                                if(posX[n-1]==1 || posX[n-1]==6 || posX[n-1]==11 || posX[n-1]==16 || posX[n-1]==21)
                                {
                                        printf("The Pawn cannot be moved LEFT\n");
                                        goto c;
                                }
                                if(posX[n-1]==7 || posX[n-1]==10 || posX[n-1]==17 || posX[n-1]==20)
                                {
                                        printf("Illegal Move\n");
                                        goto c;
                                }
                                if(posX[n-1]==14)
                                {
                                        printf("The Pawn cannot be shifted to this position\n");
                                        goto c;
                                }
                        }       
                }       
        c:return;
}
void leftO(int posX[5],int posO[5],int a[5][5],int n)
{
                printf("Enter the number of pawn 'O' to move LEFT : ");
                scanf("%d",&n);
                printf("\n");
                for(i=0;i<5;i++)
                {
                        for(j=0;j<5;j++)
                        {
                                if(posO[n-1]==a[i][j])
                                {
                                        posO[n-1]=a[i][j-1];
                                        goto c;
                                }
                                if(posO[n-1]==1 || posO[n-1]==6 || posO[n-1]==11 || posO[n-1]==16 || posO[n-1]==21)
                                {
                                        printf("The Pawn cannot be moved LEFT\n");
                                        goto c;
                                }
                                if(posO[n-1]==7 || posO[n-1]==10 || posO[n-1]==17 || posO[n-1]==20)
                                {
                                        printf("Illegal Move\n");
                                        goto c;
                                }
                                if(posO[n-1]==14)
                                {
                                        printf("The Pawn cannot be shifted to this position\n");
                                        goto c;
                                }
                        }       
                }       
        c:return;
}
void display(int posX[5],int posO[5],int a[5][5],int x,int o,int cx,int co)
{
                int s,r;
                for(i=0;i<5;i++)
                {
                        for(j=0;j<5;j++)
                        {
				for(s=0;s<5;s++)
				{
				        for(r=0;r<5;r++)
				        {
				                if(posX[s]==a[i][j] && posO[r]==a[i][j])
				                {
				                        printf("You cannot enter at X and O same positions\n");
							;
						}
					}
				}
				}
				}
                s=0;
                r=0;
                for(i=0;i<5;i++)
                {
                        for(j=0;j<5;j++)
                        {
                                if(x==a[i][j])
                                        {
                                                printf("_\t");
                                        }
                                else if(o==a[i][j])
                                        {
                                                printf("_\t");
                                        }
                                else if(posX[s]==a[i][j])
                                        {
                                                printf("X\t");
                                                s++;
                                        }
                                else if(posO[r]==a[i][j])
                                        {       
                                                printf("O\t");
                                                r++;
                                        }
                                else
                                        {
                                                printf("_\t");
                                        }    
                        }
                                printf("\n");
                                printf("\n");
                }
                printf("\n");;
}
void sort(int arr[5],int c)
{
        int i,j,temp;

        for(i=0;i<4;i++)
        {
                for(j=i+1;j<5;j++)
                {
                        if(arr[i]>arr[j])
                        {
                                temp=arr[i];
                                arr[i]=arr[j];
                                arr[j]=temp;
                        }
                }
        }
        for(i=0;i<c;i++)
        {
        for(j=0;j<4;j++)
        {
             arr[j]=arr[j+1];
        }
        arr[j]=0;
        }
}
void isWinner(int cx, int co)
{
	if(cx==3)
	{
		printf("Player 2 Wins !!!\n");
		exit(0);
	}
	else if(co==3)
	{
		printf("Player 1 Wins !!!\n");
		exit(0);
	}
}
