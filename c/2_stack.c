#include<stdio.h>
int main()
{
int n, c, val;
printf("Enter size of array:");
scanf("%d",&n);
int top1=-1, top2=n, stack[n];
do{
	printf("\n1.PUSH in S! 2.PUSH in S2 3.POP in S1 4.POP in S2 5.DISPLAY 6.EXIT \n");
	scanf("%d",&c);
	switch(c)
	{
	case 1:
		if (top1 + 1 == top2)	/*here s1 can take up the whole array if 
it needs, which does not fulfill our cause. hence: if (top1 == n/2 - 1) */
			printf("Overflow! \n");
		else
		{
			printf("Enter Value:");
			scanf("%d", &val);
			stack[++top1]=val;
		}
		break;
	case 2:
		if (top1 + 1 == top2)	//similarly: if(top2==n/2)
			printf("Overflow! \n");
		else
		{
			printf("Enter Value:");
			scanf("%d",&val);
			stack[--top2]=val;
		}
		break;
	case 3:
		if(top1==-1)
			printf("Underflow! \n");
		else
		{
			printf("%d popped. \n", stack[top1]);
			stack[top1--]=0;
		}
		break;
	case 4:
                if(top2==n)
                        printf("Underflow! \n");
                else
                {
                        printf("%d popped. \n", stack[top2]);
                        stack[top2++]=0;
                }
                break;
	case 5:
		printf("Stack:");
		for(int i=0; i<n;i++)
			printf("%d, ", stack[i]);
		printf("\n");
		break;
	case 6:
		printf("Exiting...\n");
		break;
	default:
		printf("Invalid Choice!\n");
	}
} while (c!=6);
return 0;
}
