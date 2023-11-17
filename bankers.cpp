#include <iostream>

using namespace std;

int no_processes = 5;
int no_resources = 3;

int allocated_matrix[5][3] = {
	{0,1,0},
	{2,0,0},
	{3,0,2},
	{2,1,2},
	{0,0,2}
};

int max_need_matrix[5][3] = {
	{7,5,3},
	{3,2,2},
	{9,0,2},
	{2,2,2},
	{4,3,3}
};

int available[3] = {3,3,2};
int remaining[5][3];

void rem()
{
	for(int i = 0; i< no_processes; i++)
	{
		for(int j = 0; j<no_resources; j++)
		{
			remaining[i][j] = max_need_matrix[i][j] - allocated_matrix[i][j];
		}
	}
}

int finish[5] = {0,0,0,0,0};
int ans[5] = {0,0,0,0,0};
int index;

void avil()
{
	for(int m = 0; m< no_processes; m++)
	{
		for(int n = 0; n<no_processes; n++)
		{
			if(finish[n]==0)
			{
				int flag=0;
				for(int p=0; p<no_resources; p++)
				{
					if(remaining[n][p] > available[p])
					{
						flag = 1;
						break;
					}
				}
				
				if(flag == 0)
				{
					ans[index++] = n;
					
					for(int a = 0; a<no_resources; a++)
					{
						available[a] += allocated_matrix[n][a];
					}
					finish[n]=1;
				}
			}
		}
	}
}

void print()
{
	cout<<"----------------------------------------------------"<<endl;
	cout<<"|   Processes   |  Allocated | Max_Need | Rem_need |"<<endl;
	cout<<"----------------------------------------------------"<<endl;
	for(int i = 0; i<no_processes; i++)
	{
		cout<<"|	p-"<<i<<"	|";
		for(int j = 0; j<no_resources; j++)
		{
			cout<<allocated_matrix[i][j]<<" ";
		}
		cout<<" | ";
		for(int j = 0; j<no_resources; j++)
		{
			cout<<max_need_matrix[i][j]<<" ";
		}
		cout<<" | ";
		for(int j = 0; j<no_resources; j++)
		{
			cout<<remaining[i][j]<<" ";
		}
		cout<<" | ";
		cout<<endl;
	}
	cout<<"\n\tSafe Sequence: ";
	for(int i=0; i< no_processes; i++)
	{
		cout<<"p"<<ans[i];
		if(i!=4)
		{
			cout<<" -> ";
		}
	}
	cout<<"\n\n";
}

int main()
{
	rem();
	avil();
	print();
	return 0;
}

/*
----------------------------------------------------
|   Processes   |  Allocated | Max_Need | Rem_need |
----------------------------------------------------
|	p-0	|0 1 0  | 7 5 3  | 7 4 3  | 
|	p-1	|2 0 0  | 3 2 2  | 1 2 2  | 
|	p-2	|3 0 2  | 9 0 2  | 6 0 0  | 
|	p-3	|2 1 2  | 2 2 2  | 0 1 0  | 
|	p-4	|0 0 2  | 4 3 3  | 4 3 1  | 

	Safe Sequence: p1 -> p3 -> p4 -> p0 -> p2
*/
		
