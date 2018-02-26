//北航13年机试第二题，简单版八皇后
#include <stdio.h>
int chess [8][8] = {0};
int sum = 0;
bool check (int row,int col)//前面row-1行已经排好，确认第row行如何放置皇后
{
    if(row == 0) return true;
    int i;
    for(i=0;i<row;i++)//该列不能有1
    {
        if (chess[i][col]==1)
          return false;
    }
    int l,k;
    //左上至右下不能有1
    l = row - 1;
    k = col - 1;
    while((l>=0)&&(k>=0))
    {
        if(chess[l][k]==1)
           return false;
        l--;
        k--;
    }

    //右上至左下不能有1
    l = row - 1;
    k = col + 1;
     while((l>=0)&&(k<=7))
    {
        if(chess[l][k]==1)
           return false;
        l--;
        k++;
    }

    return true;
}

void output()
{
    int i,j;
    sum++;
    printf("answer%d: \n",sum);
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        printf("%d ",chess[i][j]);

        printf("\n");
    }
}

int solve(int row)
{
    int i;
    for(i=0;i<8;i++)
    {
        chess[row][i] = 1;
        if(check(row,i)==1)
        {
            if(row==7)output();
            else solve(row+1);
        }
        chess[row][i] = 0;
    }
}
int main()
{
    solve(0);
    return 0;
}
