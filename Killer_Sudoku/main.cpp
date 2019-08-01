//
//  main.cpp
//  Killer_Sudoku
//
//  Created by Kumar P Miskin on 19/04/18.
//  Copyright © 2018 Kumar P Miskin. All rights reserved.
//
#include<iostream>

using namespace std;



struct cage

{

    int n=0,sum=0;

    int x[100],y[100];

    cage()

    {

        for(int i=0;i<100;i++)

        {

            x[i]=0; y[i]=0;

        }

    }

};



void print(int M[9][9])

{

    for(int i=0;i<9;i++)

    {

        for(int j=0;j<9;j++)

        {

            cout<<M[i][j]<<" ";

        }

        cout<<endl;

    }

    cout<<endl;

}



bool check(int M[9][9],cage cg[],int C, int r, int c)

{

    for(int i=0;i<9;i++)

    {

        if(M[i][c]==M[r][c] && i!=r)

        {M[r][c]=0; return 0;}

    }

    for(int i=0;i<9;i++)

    {

        if(M[r][i]==M[r][c] && i!=c)

        {M[r][c]=0; return 0;}

    }

    for(int i=(3*(r/3));i<(3*( (r/3)+1) );i++)

    {

        for(int k=(3*(c/3));k<( 3*( (c/3)+1) );k++)

        {

            if((i!=r || k!=c) && M[i][k]==M[r][c] )

            {M[r][c]=0; return 0;}

        }

    }

    for(int i=0;i<C;i++)

    {

        for(int j=0;j<cg[i].n;j++)

        {

            if(cg[i].x[j]==r && cg[i].y[j]==c)

            {

                int sum=0;

                bool t=0;

                for(int k=0;k<cg[i].n;k++)

                {

                    if(M[cg[i].x[k]][cg[i].y[k]]==0)

                        t=1;

                }

                if(!t)

                {

                    for(int a=0;a<cg[i].n;a++)

                        sum=sum+M[cg[i].x[a]][cg[i].y[a]];

                    if(sum!=cg[i].sum)

                    {M[r][c]=0; return 0;}

                }

                if(t && M[r][c]>cg[i].sum)

                {M[r][c]=0; return 0;}

                for(int a=0;a<cg[i].n;a++)

                {

                    if(M[cg[i].x[a]][cg[i].y[a]]==M[r][c] && cg[i].x[a]!=r && cg[i].y[a]!=c)

                    {M[r][c]=0; return 0;}

                }

                

            }

        }

    }

    return 1;

}



bool solve(int M[9][9],cage cg[],int C,int r,int c)

{

    for(int x=1;x<10;x++)

    {

        M[r][c]=x;

        if(check(M,cg,C,r,c))

        {

            if(c==8)

            {

                if (solve(M,cg,C,r+1,c-8)) return true;

            }

            else if(c!=8)

            {

                if(solve(M,cg,C,r,c+1)) return true;

            }

            if(r==8 && c==8)

            {

                print(M);

                return true;

            }

            M[r][c]=0;

        }

    }

    return false;

}





int main()

{

    int C,M[9][9];

    cin>>C;

    cage cg[81];

    for(int i=0;i<C;i++)

    {

        cin>>cg[i].n>>cg[i].sum;

        for(int j=0;j<cg[i].n;j++)

        {

            cin>>cg[i].x[j]>>cg[i].y[j];

        }

    }

    for(int i=0;i<9;i++)

    {

        for(int j=0;j<9;j++)

        {

            M[i][j]=0;

        }

    }

    solve(M,cg,C,0,0);

}
