#include <stdio.h>
#include <stdbool.h>


#define SIZE 9
#define ROW_BLOCK_SIZE 4
#define COL_BLOCK_SIZE 8
int map[2*SIZE+1][2*SIZE+1];
int players[2][2];
char players_pawn[2] = {'x', 'o'};

char visual_map[4*SIZE+1][8*SIZE+1];


void print();
void add_block_at(int i,int j);
void init_table();
void add_pawn(int player,int i, int j);
void remove_pawn(int i, int j);
bool check_move(int player_pos[],int direction);
void apply_move(int player, int direction); 
bool check_block(int place[], int direction); 
void apply_block(int place[], int direction);
bool check_inside(int i, int j);


int main() {
    print();
}

void apply_move(int player, int direction) {
}

bool check_move(int player_pos[], int direction) {
    return false;
}

bool check_inside(int i, int j)
{
	if(i < 0 || i > 2*SIZE || j < 0 || j > 2*SIZE)
	       return false;
	return true;	
}

bool check_block(int place[], int direction) {
	int i = place[0];
	int j = place[1];
	if(direction == 0) // horizontal
	{
		if(i == 1) // can not put block in first row
			return false;
		if(check_inside(i-1,j) && check_inside(i-1,j+2) && !map[i-1][j] && !map[i-1][j+2] && !map[i-1][j+1])
			return true;
		return false;
	}
	else if(direction == 1) // vertical
	{
		if(j == 1) // can not put block in first column
			return false;
		if(check_inside(i,j-1) && check_inside(i+2,j-1) && !map[i][j-1] && !map[i+2][j-1] && !map[i+1][j-1])
			return true;
		return false;
	}
	return false;
}
void apply_block(int place[], int direction)
{
}



void add_pawn(int player,int i, int j)
{
	
}


void remove_pawn(int i, int j)
{

}

void add_block_at(int i, int j)
{
}

void init_table()
{
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
void print()
{

}
