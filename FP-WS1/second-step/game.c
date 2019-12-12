#include <stdio.h>
#include <stdbool.h>


#define SIZE 9
#define ROW_BLOCK_SIZE 4
#define COL_BLOCK_SIZE 8
int map[2*SIZE+1][2*SIZE+1];

char visual_map[4*SIZE+1][8*SIZE+1];

void init_table();
void print();
void add_block_at(int i, int j);


int main() {
    init_table();
    print();
}


void add_block_at(int i, int j)
{
	map[i][j] = 1;
	if(i%2 == 0 && j%2 == 1)
	{
		i/=2;
		j/=2;
		i*=ROW_BLOCK_SIZE;
		j*=COL_BLOCK_SIZE;
		int jj;
		for(jj=j+1;jj<j+8;jj++)
			visual_map[i - 2][jj] = '-';
	}
	else if(i%2 == 1 && j%2 == 0)
	{
		i/=2;
		j/=2;
		i*=ROW_BLOCK_SIZE;
		j*=COL_BLOCK_SIZE;
		int ii;
		for(ii=i+1;ii<i+4;ii++)
			visual_map[ii][j - 3] = '|';
	}
}



void init_table() {
	for(int i = 0; i <= ROW_BLOCK_SIZE*SIZE; i++)
	{
		for(int j=0;j<=COL_BLOCK_SIZE*SIZE;j++)
		{
			if(j%COL_BLOCK_SIZE == 0 && i%ROW_BLOCK_SIZE == 0)
				visual_map[i][j] = '+';
			
			else if(i%ROW_BLOCK_SIZE == 0)
			{
				if(j % 2 == 0)
					visual_map[i][j] = '*';
				else
					visual_map[i][j] = ' ';
			}
			else if(j%COL_BLOCK_SIZE == 0)
			{
				visual_map[i][j] = '*';
			}

			else 
				visual_map[i][j] = ' ';
		}
	}
}

void print(){
}
