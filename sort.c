#include <stdio.h>


int main()
{
    int sort[10] = {32, 14, 59, 23, 75, 10, 23, 48, 36, 39};
    int tree[10] = {0};
    for (int i=0; i<10; i++)
    {
        scanf("%d", sort+i);
    }

    printf("原数据:");
    for (int i=0; i<10; i++)
    {
        printf("%d ",sort[i]);
    }
    printf("\n");

   
    for (int i=0; i<10; i++)
    {
        int j = i; tree[j] = sort[j];
        while(j!=0)
        {
            for (int c=0; c<10; c++)
            {
                printf("%d\t",tree[c]);
            }

            int up = j;
            if(up%2==0)
            {
                printf("up:-2::%d",up);
                up-=2;
            }
            else
            {
                printf("up:-1::%d",up);
                up-=1;
            }
            up/=2;
            printf("--%d \n",up);
            if (tree[j] < tree[up])
            {
                int temp = tree[j];
                tree[j] = tree[up];
                tree[up] = temp;
                j = up;
            }
            else
            {
                break;
            }
            
        }
    }


    printf("二叉树:");
    for (int i=0; i<10; i++)
    {
        printf("%d ",tree[i]);
    }

    //开始pop
    int pop[10];//排序后的数组
    int tail = 10;//记录尾部

    for (int i=0; i<10; i++)
    {
        pop[i] = tree[0];
        int j = 0;
        tree[0] = tree[--tail];

        int br = (int)((10-i)/2);
        while(j < br)
        {

            int max;//两个子节点的最大节点下标
            
            //首先判断是不是单子节点
            if (tail%2==1 && j==(tail-1)/2)
            {
                max = j*2+1;
            }
            else//双节点取最小节点
            {
                if (tree[j*2+1] > tree[j*2+2])
                {
                    max = j*2+2;
                }
                else
                {
                    max = j*2+1;
                }

            }

            if (tree[j] > tree[max])
            {
                int temp = tree[j];
                tree[j] = tree[max];
                tree[max] = temp;
                j = max;
            }
            else
            {
                break;
            }


        }
    }

    printf("\n排序后:");

    for (int i=0; i<10; i++)
    {
        printf("%d ",pop[i]);
    }
}
