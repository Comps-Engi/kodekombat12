#include "bot.h"
/*
You are player 1. Your opponent player 2
pac1.r, pac1.c is the location of player1's pacman 
pac2.r, pac2.c is the location of player2's pacman
There are 4 ghosts with each player.
ghosts1[i].r ghosts1[i].c is the location of player 1's i'th ghost
ghosts2[i].r ghosts2[i].c is the location of player 1's i'th ghost 

s1 indicates the no of moves for which the pacman1 remains in power mode
similarly s2
Map is available to you through a 2D character array map_state.
Read the pdf file for the details on what each character stands for.

For any further queries read README or visit website engineer.org.in/kodekombat
*/
int move_pacman()
{


/*************************************************************************\
Your code to move the pacman can go here
It should return a value 1-4 indicating the direction you want to move to
\*************************************************************************/

	int r=pac1.r,c=pac1.c,i;
	char el[10];
	if(s1!=0)
		strcpy(el,"abcdeE");
	else 
		strcpy(el,"eE");
	
	for(i=0;i<strlen(el);i++)
		if(map_state[r-1][c]==el[i])return 1;		
	
	for(i=0;i<strlen(el);i++)
		if(map_state[r+1][c]==el[i])return 2;

	for(i=0;i<strlen(el);i++)
		if(map_state[r][c-1]==el[i])return 3;

	for(i=0;i<strlen(el);i++)
		if(map_state[r][c+1]==el[i])return 4;		

	randnum+=rand()%1000;

	return randnum%4+1;	
}

int move_ghost(int N)
{
/******************************************************************
Your code to move the N'th ghost can go here
It returns a value 1-4 indicating the direction you want to move to.
******************************************************************/

	int r=ghosts1[N].r,c=ghosts1[N].c,i;
	char el[10],av[10];
	
	randnum+=rand()%10000;	

	return randnum%4+1;
}

int main()
{
	read_state();
	//fprintf(stderr,"%d %d %d %d %d",move_ghost(0),move_ghost(1),move_ghost(2),move_ghost(3),move_pacman());
	printf("%d %d %d %d %d",move_ghost(0),move_ghost(1),move_ghost(2),move_ghost(3),move_pacman());
	return 0;
}

