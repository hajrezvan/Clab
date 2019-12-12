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


int main() {
    print();
}


void apply_move(int player, int direction) {
}

bool check_move(int player_pos[], int direction) {
    int i = player_pos[0];
    int j = player_pos[1];

    switch (direction) {
    case 0: //Up
        return (map[i-2][j] == 0 && i - 2 > 0);
        break;
    case 1: //Right
        return (map[i][j + 2] == 0 && j + 2 <= 2*SIZE);
        break;
    case 2: //Down
        return (map[i+2][j] == 0 && i + 2 <= 2*SIZE);
        break;
    case 3: //Left
        return (map[i][j - 2] == 0 && j - 2 > 0);
        break;
    default:
        return false;
    }
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
