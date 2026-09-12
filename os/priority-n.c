#include <stdio.h>

int main()
{
    int n, i, curr_t = 0, count = 0;
    int p_id[20], arrv_t[20], burst_t[20], priority[20];
    int comp_t[20], turn_ar_t[20], wait_t[20];
    int done[20] = {0};
    int sum_wait = 0, sum_tat = 0;

    printf("Enter number of process: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nP_id: Arrival_T: Burst_T: Priority: ");
        scanf("%d %d %d %d",
              &p_id[i], &arrv_t[i], &burst_t[i], &priority[i]);
    }

    while(count < n)
    {
        int best = -1;

        for(i = 0; i < n; i++)
        {
            if(!done[i] && arrv_t[i] <= curr_t)
            {
                if(best == -1 ||
                   priority[i] < priority[best])
                    best = i;
            }
        }

        if(best == -1)
        {
            curr_t++;
            continue;
        }

        comp_t[best] = curr_t + burst_t[best];
        turn_ar_t[best] = comp_t[best] - arrv_t[best];
        wait_t[best] = turn_ar_t[best] - burst_t[best];

        curr_t = comp_t[best];
        done[best] = 1;
        count++;
    }

    printf("\nP_ID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t\t%d\t%d\t%d\n",
               p_id[i], arrv_t[i], burst_t[i],
               priority[i], comp_t[i],
               turn_ar_t[i], wait_t[i]);

        sum_wait += wait_t[i];
        sum_tat += turn_ar_t[i];
    }

    printf("\nAverage TAT = %.2f\n", (float)sum_tat/n);
    printf("Average WT = %.2f\n", (float)sum_wait/n);

    return 0;
}
