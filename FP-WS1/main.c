#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 9
#define ROW_BLOCK_SIZE 4
#define COL_BLOCK_SIZE 8

int map[2*SIZE+1][2*SIZE+1] = {0};

int players[2][2];

char players_pawn[2] = {'X', 'O'};

char visual_map[4*SIZE+1][8*SIZE+1];

void print();
void add_block_at(int i,int j);
void init_table();
void add_pawn(int number_player,int i, int j);
void remove_pawn(int i, int j);
bool check_move(int player_pos[],int direction);
void apply_move(int player, int direction);


int main()
{
    printf("Please select your pawn: (O = 1/X = 0) \n");

    int select_of_player,opponets_of_player;
    int x,y;
    int i = 0 , j = 0;
    scanf("%d",&select_of_player);
    if (select_of_player == 1)
    {
        opponets_of_player = 0;
    }
    else
    {
        opponets_of_player = 1;
    }
    do{
        init_table();
        i = 2;
        j = 36;
        add_pawn(select_of_player,i,j);
    } while(2 < 1);

    printf("Please select your block:\n");
    scanf("%d %d",&x,&y);

    init_table();
    add_block_at(x,y);

    remove_pawn(i,j);
    add_pawn(select_of_player, i + 4, j + 8);
    print();
}

void init_table() {
    int i;
	for(i = 0; i <= ROW_BLOCK_SIZE * SIZE; i++)
	{
	    int j;
		for(j = 0;j <= COL_BLOCK_SIZE * SIZE; j++)
		{
			if(j % COL_BLOCK_SIZE == 0 && i % ROW_BLOCK_SIZE == 0)
				visual_map[i][j] = '+';

			else if(i % ROW_BLOCK_SIZE == 0)
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

void add_block_at(int i, int j)
{
	map[i][j] = 1;
	if(i % 2 == 0 && j % 2 == 1)
	{
		i /= 2;
		j /= 2;
		i *= ROW_BLOCK_SIZE;
		j *= COL_BLOCK_SIZE;
		int jj;
		for(jj = j + 1; jj < j + 8; jj++)
			visual_map[i][jj] = '-';
	}
	else if(i % 2 == 1 && j % 2 == 0)
	{
		i /= 2;
		j /= 2;
		i *= ROW_BLOCK_SIZE;
		j *= COL_BLOCK_SIZE;
		int ii;
		for(ii = i + 1; ii < i + 4; ii++)
			visual_map[ii][j] = '|';
	}
}

void print(){
 int i,j;
 for (i = 0; i <= ROW_BLOCK_SIZE * SIZE; i++){
    for (j = 0;j <= COL_BLOCK_SIZE * SIZE; j++)
    {
        printf("%c",visual_map[i][j]);
    }
    printf("\n");
 }
}

void add_pawn(int number_player,int i, int j)
{
    char position = players_pawn[number_player];
    int index_of_oppone = 1 - number_player;
    char charactor_oppone = players_pawn[index_of_oppone];
    map[i][j] = 0;
    visual_map[i][j] = position;
    visual_map[34][36] = charactor_oppone;
    print();
}

void remove_pawn(int i, int j)
{
    visual_map[i][j] = ' ';
    //print();
}

void apply_move(int player, int direction)
{
    if (check_move(player,direction))
    {

    }
}

bool check_move(int player_position[], int direction)
{
    int i = player_position[0];
    int j = player_position[1];

    switch (direction) {
    case 0: //Up
        if (map[i-2][j] == 0 && i > 2)
        {
            if (map[i-1][j] == 1)
                return false;
            return true;
        }
        //return (map[i-2][j] == 0 && i - 2 > 0);
        break;

    case 1: //Right
        if (map[i][j + 2] == 0 && j + 2 <= 2*SIZE)
        {
            if ([i][j + 1] == 1)
                return false;
            return true;
        }
        //return (map[i][j + 2] == 0 && j + 2 <= 2*SIZE);
        break;

    case 2: //Down
         if (map[i+2][j] == 0 && i + 2 <= 2*SIZE)
        {
            if (map[i+1][j] == 1)
                return false;
            return true;
        }
        //return (map[i+2][j] == 0 && i + 2 <= 2*SIZE);
        break;

    case 3: //Left
        if (map[i][j - 2] == 0 && j > 2)
        {
            if ([i][j - 1] == 1)
                return false;
            return true;
        }
        //return (map[i][j - 2] == 0 && j - 2 > 0);
        break;

    default:
        return false;
    }
}
