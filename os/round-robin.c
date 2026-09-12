#include <stdio.h>

int main()
{
    int n, tq, i, time = 0, done = 0;
    int p_id[20], arrv_t[20], burst_t[20];
    int rem[20], comp_t[20], turn_ar_t[20], wait_t[20];
    int queue[100], front = 0, rear = 0;
    int added[20] = {0};
    int sum_wait = 0, sum_tat = 0;

    printf("Enter number of process: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nP_id: Arrival_T: Burst_T: ");
        scanf("%d %d %d",
              &p_id[i], &arrv_t[i], &burst_t[i]);

        rem[i] = burst_t[i];
    }

    printf("\nEnter Time Quantum: ");
    scanf("%d", &tq);

    /* Add processes arriving at time 0 */
    for(i = 0; i < n; i++)
    {
        if(arrv_t[i] == 0)
        {
            queue[rear++] = i;
            added[i] = 1;
        }
    }

    while(done < n)
    {
        if(front == rear)
        {
            time++;

            for(i = 0; i < n; i++)
            {
                if(!added[i] && arrv_t[i] <= time)
                {
                    queue[rear++] = i;
                    added[i] = 1;
                }
            }

            continue;
        }

        i = queue[front++];

        if(rem[i] > tq)
        {
            time += tq;
            rem[i] -= tq;
        }
        else
        {
            time += rem[i];
            rem[i] = 0;

            comp_t[i] = time;
            done++;
        }

        /* Add newly arrived processes */
        for(int j = 0; j < n; j++)
        {
            if(!added[j] && arrv_t[j] <= time)
            {
                queue[rear++] = j;
                added[j] = 1;
            }
        }

        /* Put unfinished process back */
        if(rem[i] > 0)
            queue[rear++] = i;
    }

    for(i = 0; i < n; i++)
    {
        turn_ar_t[i] = comp_t[i] - arrv_t[i];
        wait_t[i] = turn_ar_t[i] - burst_t[i];

        sum_wait += wait_t[i];
        sum_tat += turn_ar_t[i];
    }

    printf("\nP_ID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p_id[i], arrv_t[i], burst_t[i],
               comp_t[i], turn_ar_t[i], wait_t[i]);
    }

    printf("\nAverage TAT = %.2f\n", (float)sum_tat/n);
    printf("Average WT = %.2f\n", (float)sum_wait/n);

    return 0;
}
