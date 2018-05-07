#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

void Show();

int Chess[8][8] = { {0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0},
					{0,0,0,0,0,0,0,0} };

typedef pair<int,int> Pair;
vector< Pair > Path;

bool isSafe(int Row, int Col){
	
	for (int i=0;i<8;i++)
		if ( Chess[i][Col] == 1 )
			return false;

	for ( int i=Row-1,j=Col-1; i>-1 && j>-1 ;i--,j--)
		if ( Chess[i][j] == 1 )
			return false;

	for (int i=Row-1,j=Col+1; i>-1 && j<8 ;i--,j++)
		if ( Chess[i][j] == 1 )
			return false;

	return true;
}

bool Solve(int Row){
	
	if ( Row == 7 ){
		for ( int j=0; j<8; j++ ){
			if ( isSafe( Row, j ) ){
				Path.push_back( make_pair( Row,j ) );
				return true;
			}
		}
		return false;
	}

	for ( int j=0;j<8;j++ ){
		if ( isSafe( Row, j ) ){
			
			Chess[Row][j] = 1;
			Path.push_back( make_pair( Row,j ) );
			
			if ( Solve( Row+1 ) )
				return true;
			
			Path.pop_back();
			Chess[Row][j] = 0;
		}
	}
	return false;
}

void Show(){

	cout<<endl<<endl<<"The Next Step"<<endl;
	for (int i=0;i<8;i++,cout<<endl)
		for (int j = 0;j<8;j++)
			cout<<Chess[i][j]<<"  ";
	cout<<endl;
}

void PrintPath(){

	for (int i=0;i<8;i++)
		for (int j = 0;j<8;j++)
			Chess[i][j] = 0;

	for (int i=0;i<8;i++){
		Pair Node = Path[i];
		Chess[Node.first][Node.second] = 1;
		Show();
	}
}

int main(){

	srand(time(NULL));
	int Col = rand()%8;
	Chess[0][Col] = 1;
	Path.push_back( make_pair(0,Col) );

	if ( Solve( 1 ) )
		PrintPath();
	else
		cout<<"There No Solution Exsists"<<endl;
	return 0;
}
