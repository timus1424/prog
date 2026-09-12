#include <stdio.h>

int main()
{
    int n, i, curr_t = 0, count = 0;
    int p_id[20], arrv_t[20], burst_t[20];
    int comp_t[20], turn_ar_t[20], wait_t[20];
    int done[20] = {0};
    int sum_wait = 0, sum_tat = 0;

    printf("Enter number of process: ");
    scanf("%d", &n);
    printf("Enter details:");
    for(i = 0; i < n; i++)
    {
	printf("\nP_id \tArrv_T \tBurst_T:");
	scanf("%d%d%d", &p_id[i], &arrv_t[i], &burst_t[i]);
/*
        p_id[i] = i + 1;

        printf("\nP%d: Arrival=", p_id[i]);
        scanf("%d", &arrv_t[i]);

        printf("P%d: Burst=", p_id[i]);
        scanf("%d", &burst_t[i]);
*/
    }

    while(count < n)
    {
        int min = -1;

        for(i = 0; i < n; i++)
        {
            if(!done[i] && arrv_t[i] <= curr_t)
            {
                if(min == -1 || burst_t[i] < burst_t[min])
                    min = i;
            }
        }

        if(min == -1)
        {
            curr_t++;
            continue;
        }

        comp_t[min] = curr_t + burst_t[min];
        turn_ar_t[min] = comp_t[min] - arrv_t[min];
        wait_t[min] = turn_ar_t[min] - burst_t[min];

        curr_t = comp_t[min];
        done[min] = 1;
        count++;
    }

    printf("\nP_ID\tArrival Time\tBurst Time\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\n",
               p_id[i], arrv_t[i], burst_t[i]);

        sum_wait += wait_t[i];
        sum_tat += turn_ar_t[i];
    }

    printf("\nAverage Turn Around Time = %.2f\n",
           (float)sum_tat / n);

    printf("Average Waiting time = %.2f\n",
           (float)sum_wait / n);

    return 0;
}
