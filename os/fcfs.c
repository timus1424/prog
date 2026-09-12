#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, i, j, curr_t = 0;
    int p_id[20], arrv_t[20], burst_t[20];
    int comp_t[20], turn_ar_t[20], wait_t[20];
    int sum_wait = 0, sum_tat = 0;

    printf("Enter number of process: ");
    scanf("%d", &n);

    printf("Enter process details as asked:\n");

    for(i = 0; i < n; i++)
    {
        printf("\nProcess Id: ");
        scanf("%d", &p_id[i]);

        printf("Arrival time: ");
        scanf("%d", &arrv_t[i]);

        printf("Burst time: ");
        scanf("%d", &burst_t[i]);
    }

    /* Sort according to Arrival Time */
    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(arrv_t[i] > arrv_t[j])
            {
                swap(&arrv_t[i], &arrv_t[j]);
                swap(&burst_t[i], &burst_t[j]);
                swap(&p_id[i], &p_id[j]);
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        if(curr_t < arrv_t[i])
            curr_t = arrv_t[i];

        comp_t[i] = curr_t + burst_t[i];
        turn_ar_t[i] = comp_t[i] - arrv_t[i];
        wait_t[i] = turn_ar_t[i] - burst_t[i];

        curr_t = comp_t[i];
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
