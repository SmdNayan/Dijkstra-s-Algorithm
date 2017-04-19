#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include<conio.h>
#include<fstream>
#include <windows.h>
#define INFINITY 9999
#define MAX 10

using namespace std;

class dijkstra
{
    int G[MAX][MAX],i,j,n,startnode,temp[20]= {},p,distance[MAX],pred[MAX];
public:

    //Cost Matrix
    void cost_matrix()
    {
        ofstream output("file.txt");
        printf("\nEnter no. of vertices: ");
        //output<<"Number of vertices: ";
        scanf("%d",&n);
        output<<n<<endl;
        printf("\nEnter the adjacency cost matrix:\n");
        //output<<"\nEnter the adjacency matrix:\n";

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%d",&G[i][j]);
                output<<G[i][j]<<" ";
            }
            output<<endl;
        }
        printf("\nEnter the starting node within (1 - %d): ",n);
        scanf("%d",&startnode);
    }

    //Path Matrix

    void path_matrix()
    {
        int cost[MAX][MAX];
        int visited[MAX],count,mindistance,nextnode,i,j;

        //pred[] stores the predecessor of each node
        //count gives the number of nodes seen so far
        //create the cost matrix
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
                if(G[i][j]==0)
                    cost[i][j]=INFINITY;
                else
                    cost[i][j]=G[i][j];

        //initialize pred[],distance[] and visited[]
        for(i=1; i<=n; i++)
        {
            distance[i]=cost[startnode][i];
            pred[i]=startnode;
            visited[i]=0;
        }

        distance[startnode]=0;
        visited[startnode]=1;
        count=1;

        while(count<n-1)
        {
            mindistance=INFINITY;

            //nextnode gives the node at minimum distance
            for(i=1; i<=n; i++)
                if(distance[i]<mindistance&&!visited[i])
                {
                    mindistance=distance[i];
                    nextnode=i;
                }

            //check if a better path exists through nextnode
            visited[nextnode]=1;
            for(i=1; i<=n; i++)
                if(!visited[i])
                    if(mindistance+cost[nextnode][i]<distance[i])
                    {
                        distance[i]=mindistance+cost[nextnode][i];
                        pred[i]=nextnode;
                    }
            count++;
        }
        //
    }

    //WHOLE LIST DISPLAY
    void whole_display()
    {
        //print the path and distance of each node
        int count;
        for(i=1; i<=n; i++)
            if(i!=startnode)
            {
                printf("\n%d to %d the lowest cost is: %d \n",startnode,i,distance[i]);
                count=0;
                temp[count]=i;
                j=i;
                do
                {
                    count++;
                    j=pred[j];
                    temp[count]=j;
                }
                while(j!=startnode);
                printf("Path is ");
                for(p=count; p>=0; p--)
                {
                    printf("=>%d ",temp[p]);
                }
                cout<<endl;

            }
    }

    //SOURCE TO DESTINATION LIST DISPLAY
    void source_display(int a)
    {
        //print the path and distance of each node
        int dist=a, count;
        for(i=1; i<=n; i++)
            if(i!=startnode && i==dist)
            {
                printf("\n%d to %d the lowest cost is: %d \n",startnode,i,distance[i]);
                count=0;
                temp[count]=i;
                j=i;
                do
                {
                    count++;
                    j=pred[j];
                    temp[count]=j;
                }
                while(j!=startnode);
                printf("Path is ");
                for(p=count; p>=0; p--)
                {
                    printf("=>%d ",temp[p]);
                }
                cout<<endl;

            }
    }

    //File input
    void file_input()
    {
        ifstream input("file.txt");
        input>>n;
        cout<<"Number of Vertices is: "<<n<<endl;
        printf("\nAdjacency Matrix and vertices read from file.\n");

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                input>>G[i][j];
            }

        }

        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                cout<<G[i][j]<<" ";
            }
            cout<<endl;
        }

        printf("\nEnter the starting node within (1 - %d): ",n);
        scanf("%d",&startnode);
    }

    //Text Position
    void gotoxy(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }
    //Loading....
    void load()
    {
        int row,col,r,c,q;
        gotoxy(50,14);
        printf("loading...");
        gotoxy(30,15);
        for(r=1; r<=45; r++)
        {
            for(q=0; q<=10000000; q++); //to display the character slowly
            printf("%c",177);
        }
    }

    //Header
    void header()
    {
        gotoxy(25,1);
        cout<<"Dijkstra's Shortest Path Algorithm Implementation"<<endl;
        gotoxy(25,2);
        cout<<"================================================="<<endl;
    }

    //Note
    void note(string nt)
    {
        system("CLS");
        header();
        gotoxy(40,5);
        cout<<"-----------------";
        gotoxy(40,6);
        cout<<"| "<<nt<<" |"<<endl;
        gotoxy(40,7);
        cout<<"-----------------"<<endl<<endl;
    }
    //menuprintf("\n last no %d\n",temp[p]);
    void menu ()
    {
        system("CLS");
        header();
        gotoxy(30,5);
        cout<<"Choose your option: \n";
        gotoxy(40,7);
        cout<<"1 : Whole list\n";
        gotoxy(40,8);
        cout<<"2 : Source to Destination\n";
        gotoxy(30,12);
        cout<<"Enter your option: ";
    }
};

//main function
int main()
{
    system("color f0");
    int op,op2,op3,desti;
    string nt1="Invalid Input",nt2="  Thank You! ";
    dijkstra d;
    d.load();
    system("CLS");
Start:
    d.header();
    d.gotoxy(30,5);
    cout<<"Choose your option: "<<endl;
    d.gotoxy(40,7);
    cout<<"1: Standard Input (Runtime)"<<endl;
    d.gotoxy(40,8);
    cout<<"2: File Input"<<endl;
    d.gotoxy(40,9);
    cout<<"3: Exit"<<endl;
    d.gotoxy(30,12);
    cout<<"Enter your option: ";
    cin>>op;
    switch(op)
    {
    case 1 ://Standard Input
        d.menu();
        cin>>op2;
        switch(op2)
        {
        case 1 ://Whole list
            system("CLS");
            d.header();
            d.cost_matrix();
            d.path_matrix();
            d.whole_display();
            cout<<endl<<endl<<"Press any key to continue!"<<endl;
            cout<<"=========================";
            getch();
            system("CLS");
            goto Start;
            break;
        case 2 : //Source to Destination
            system("CLS");
            d.header();
            d.cost_matrix();
            cout<<"Enter the destination node: ";
            cin>>desti;
            d.path_matrix();
            d.source_display(desti);
            cout<<endl<<endl<<"Press any key to continue!"<<endl;
            cout<<"=========================";
            getch();
            system("CLS");
            goto Start;
            break;
        default: //Invalid Input
            d.note(nt1);
            cout<<endl<<endl<<"Press any key to continue!"<<endl;
            cout<<"=========================";
            getch();
            system("CLS");
            goto Start;
            break;
        }
        break;
    case 2 ://from file input
        d.menu();
        cin>>op3;
        switch(op3)
        {
        case 1 ://from file Whole list
            system("CLS");
            d.header();
            d.file_input();
            d.path_matrix();
            d.whole_display();
            cout<<endl<<endl<<"Press any key to continue!"<<endl;
            cout<<"=========================";
            getch();
            system("CLS");
            goto Start;
            break;

        case 2 ://from file Source to Destination
            system("CLS");
            d.header();
            d.file_input();
            cout<<"Enter the destination node: ";
            cin>>desti;
            d.path_matrix();
            d.source_display(desti);
            cout<<endl<<endl<<"Press any key to continue!"<<endl;
            cout<<"=========================";
            getch();
            system("CLS");
            goto Start;
            break;

        default://Invalid Input
            d.note(nt1);
            cout<<endl<<endl<<"Press any key to continue!"<<endl;
            cout<<"=========================";
            getch();
            system("CLS");
            goto Start;
            break;
        }

        break;

    case 3 : //Exit
        d.note(nt2);
        getch();
        break;

    default: //Invalid Input
        d.note(nt1);
        cout<<endl<<endl<<"Press any key to continue!"<<endl;
            cout<<"=========================";
            getch();
            system("CLS");
            goto Start;
        break;
    }
    return 0;
}
