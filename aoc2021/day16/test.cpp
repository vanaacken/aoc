

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;

// print out 2D array
void printMatrix(int arr[][N])
{

	for(int i = 0; i < N; i++)
	{		
		for(int j = 0; j < N; j++)
		{
			cout<<"\t"<<arr[i][j]<<" ";
		}	
		cout<<endl;
	}
}


bool areEqualArrays(int a[][N], int b[][N])
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(a[i][j] != b[i][j])
				return false;
		}
	}

	return true;
}

// return best cost to go from neighbor from i,j
int minNeighborCostToGo(int C[][N], int r, int c, int &mr, int &mc)
{
	int minCost = C[r][c];

	if(r > 0)
	{
		if(C[r-1][c] < minCost)
		{
			mr = r-1;
			mc = c;
			minCost = C[r-1][c];	
		}
	}
	if(c > 0)
	{
		if(C[r][c-1] < minCost)
		{
			minCost = C[r][c-1];
			mr = r;
			mc = c-1;
		}
	}
	if(r < N-1)
	{
		if(C[r+1][c] < minCost)
		{
			minCost = C[r+1][c];
			mr = r+1;
			mc = c;
		}
	}
	if (c < N - 1)
	{
		if(C[r][c+1] < minCost)
		{
			minCost = C[r][c+1];
			mr = r;
			mc = c + 1 ;
		}
	}

	return minCost;
}

int main()
{

	// define starting position
	int startc = 0;
	int startr = 0;

	// define goal position
	int goalc = N-1;
	int goalr = N-2;

	// define cost matrix
	int C[N][N];

	// set initial cost to 1
	
	{

	}
	fill(&C[0][0], &C[N-1][N-1], 1);

	// cost to go from goal is 0
	C[goalr][goalc] = 0;

	int obsr = 2;
	int obsc = 2;

	C[obsr][obsc] = 100;

	bool converged = false;

	int Ctemp[N][N];

	int mr, mc;

	while(!converged)
	{	

		// copy matrix from C to Ctemp
		copy(&C[0][0], &C[N-1][N-1]+1,&Ctemp[0][0]);

		// loop and update cost matrix
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(i == goalr && j == goalc)
				{				
					C[i][j] = 0;
				}
				if(i == obsr && j == obsc)
					C[i][j] = 10;
				else
					C[i][j] = 1 + minNeighborCostToGo(C, i, j, mr, mc);
			}
		}

		if(areEqualArrays(C,Ctemp))
			converged = true;

	}

	cout<<"Here is the cost matrix :"<<endl;
	printMatrix(C);

	int r = startr;
	int c = startc;

	while(!(r == goalr && c == goalc))
	{
		// get min neighbor cost
		int minCost = minNeighborCostToGo(C,r,c, mr, mc);

		cout<<"Got to: "<<mr<<" "<<mc<<endl;

		r = mr;
		c = mc;

	}

	cout<<"End!"<<endl;
	return 0;
}
