/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int maxValue(int first, int second){
    if(first >= second) return first;
    else return second;
}
int knapseak_deynamic(int n, int pt[], int wt[], int m, int k[n][m]){
    int i, j;
    //int k[n][m];
    for(i=0; i<n; i++){
        for(j=0;j<m;j++){
            if(i==0 || j==0){
                k[i][j] = 0 ;
            }
            else if(wt[i] <= j){
                k[i][j] = maxValue((pt[i]+k[i-1][j-wt[i]]), k[i-1][j]);
            }
            else{
                k[i][j] = k[i-1][j];
            }
        
        }
    }
    
    int a, b;
    a = n;
    b= m;
     while(a>0 && b > 0){
        if(k[a][b] == k[a-1][b]){
            printf("0, ");
            a = a-1;
        }else{
            printf("1,");
            a = a-1;
            b = b-wt[a];
        }
    }
        printf("\n");

    return k[n-1][m-1];
}

// void print_optimal(int n, int m, int k[n][m], int wt[]){
//     int i, j;
//     i = n;
//     j= m;
//     while(i>0 && j > 0){
//         if(k[i][j] == k[i-1][j]){
//             printf("0, ");
//             i = i-1;
//         }else{
//             printf("1,");
//             i = i-1;
//             j = j-wt[i];
//         }
//     }
// }
int main()
{
    int n = 5;
    int m=6;
    int weight[] = {5,7, 8, 9, 12};
    int profit[] = {2,1, 3, 3, 2};
    int k[n][m];
    int maxProfit = knapseak_deynamic(n, weight, profit, m, &k);
    printf("Max profit is %d", maxProfit);
    
   // print_optimal(n, m, k, weight);
    return 0;
}
