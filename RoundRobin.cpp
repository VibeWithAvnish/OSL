#include<iostream>
#include <queue>
using namespace std;

struct Process{
int id;
int at;
int bt;
int wt;
int tat;
};

int main()
{
	int n , tq;
	int i = 0;
	int time = 0;
	Process p[10];

	cout<<"enter number of processes"<<endl;
	cin>>n;
	cout<<"enter time quantum"<<endl;
	cin>>tq;
	
	for(int j = 0; j<n ; j++)
	{
		p[j].id = j;
		cout<<"Enter arrival time of process "<<j<<endl;
		cin>>p[j].at;
		cout<<"Enter burst time of process "<<j<<endl;
		cin>>p[j].bt;
	}
	queue<Process> q;
	q.push(p[i]);

	while(!q.empty())
	{
		Process exe = q.front();
		if(exe.bt > tq)
		{
			exe.bt-=tq;
			time+= tq;
		}
		else
		{
			time+= exe.bt;
			exe.bt= 0;
			for(int j = 0; j < n ; j++)
			{
				if(p[j].id==exe.id)
				{
					p[j].tat = time - p[j].at;
					p[j].wt = p[j].tat - p[j].bt;
				}
			}
			cout<<"process "<<exe.id<<"ended at : "<<time<<endl;
		}
		
		if(p[i+1].at <= time)
		{
			for(int x = i+1 ; x < n ; x++)
			{
				if(p[x].at<=time)
				{
					q.push(p[x]);
					i++;
				}
			}
		}
		if(exe.bt>0)
		{
			q.push(exe);
			q.pop();
		}
		else
		{
			q.pop();
		}
	}
	
	cout<<"pid\tat\tbt\twt\ttat"<<endl;
	float avgWt = 0;
	float avgTat = 0;
	
	for(int j = 0 ; j < n ; j++)
	{
		Process pr = p[j];
		cout<<pr.id<<"\t"<<pr.at<<"\t"<<pr.bt<<"\t"<<pr.wt<<"\t"<<pr.tat<<endl;
		avgWt += pr.wt;
		avgTat+= pr.tat;
	}
	avgWt = avgWt/n;
	avgTat = avgTat/n;
	cout<<"average waiting time : "<<avgWt<<endl;
	cout<<"average turn around time : "<<avgTat<<endl;
	return 0;
}
