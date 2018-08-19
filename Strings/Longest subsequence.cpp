/*
The program takes two strings from the user (max size 20) and prints the longest common subsequence.
*/

#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

char ch, str1[20], str2[20];
int n=0, m=0;
int mat[10][10];

void print()
{
    for(int i=0;i<n;i++)
    {   for(int j=0;j<m;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }
}

int Greater(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int len()
{
    int x=0,y=0;
    while(x!=n) 
    {   
        if(str1[x]==str2[y])
        {   mat[x][y]=1;
            while(x!=n-1)
                mat[++x][y]=1;
            break;
        }
        x++;
    }
    
    x=0; y=0;
    while(y!=m) 
    {   
        if(str1[x]==str2[y])
        {   mat[x][y]=1;
            while(y!=m-1)
                mat[x][++y]=1;
            break;
        }
        y++;
    }
    
    x=0; y=0;
    for(x=1;x<n;x++)
    {
        for(y=1;y<m;y++)
        {
            mat[x][y]=Greater(mat[x-1][y], mat[x][y-1]);
            if(str1[x]==str2[y])
                mat[x][y]=mat[x-1][y-1]+1;
        }
    }
    
    print();
    return mat[n-1][m-1];
        
}


void sub(int x, int y)
{
    if(mat[x][y]==0)                                                //Base case 1. No common elements left
    {
        cout<<"\nThe longest subsequence is ";
        return;
    }
    
    if(x==0 && y==0)                                                //Base case 2. Reached the first block of the table
    {
        cout<<"\nThe longest subsequence is ";
        if(str1[x]==str2[y])
            cout<<str1[x];
            
        return;
    }
    
    if(str1[x]==str2[y])                                            //Print. Move diagonally up.
    {
        sub(x-1,y-1);
        cout<<str1[x];
    }
    else if(x==0)                                                   //Slide around the edge (No choice)
    {
        sub(x,y-1);
    }
    else if(y==0)                                                   //Slide around the edge (No choice)
    {
        sub(x-1,y);
    }
    else if(mat[x-1][y]>mat[x][y-1])                                //Choose the greated amongst left or top (if available)
    {
        sub(x-1,y);
    }
    else
    {
        sub(x,y-1);
    }
}

int main()
{
    cout<<"Enter two strings"<<endl;
    
    fgets(str1, 20, stdin);
    fgets(str2, 20, stdin);
    n=strlen(str1);
    m=strlen(str2);
    
    str1[n-1]='\0';
    str2[m-1]='\0';
    n=n-1;
    m=m-1;
    
    cout<<"\nThe strings are "<<str1<<" and "<<str2<<endl;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            mat[i][j]=0;
            
    int l = len();                  //Length of the longest subsequence
    sub(n-1,m-1);
    cout<<endl<<endl;
    return 0;
}
