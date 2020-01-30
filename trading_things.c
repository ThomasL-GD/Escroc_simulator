#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Item {
	
	char name[150];
	int price;
	
};
typedef struct Item item;

void Inventory (item inventory[20]){
	
	char tempo[150];

	for (int i = 0; i < 20; i++){ 
		for (int j = 0; j < 20; j++){
			if (strcmp(inventory[i].name, inventory[j].name) < 0){
				
				strcpy(tempo, inventory[i].name);
				strcpy(inventory[i].name, inventory[j].name);
				strcpy(inventory[j].name, tempo);
				
			}
		}
	}
	
	for (int k = 0; k<20; k++){
		
		if(inventory[k].name != "z"){
			printf("%s \n", inventory[k].name);
		}
		
	}
	
};

int main (){
	
	srand(time(NULL));
	
	int nChoice = 0;
	
	item inventory[20] = {"bottes en cuir de yak",150,"graine de haricot presque magique",60,"bebe chocobo",500,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0};
	
	// Clearing the screen ┐(・。・┐)♪
	for(int i = 0; i< 70; i++){
		
		printf("\n");
		
	}
	
	while (nChoice != 2){
		
		nChoice = 0;
	
		while(nChoice != 1 && nChoice != 2){
			
			printf("\n	Choose something to do :\n 1) Check inventory\n 2) Quit T_T\n");
			
			scanf("%d",&nChoice);
			
		}
		
		if(nChoice == 1){
			
			Inventory(inventory);
			
		}

	}
	
	printf("\n\n\nGoodbye, you traitor, you could have played a bit more but you decided to give up now... That's kinda sad... You know, when I was a kid I use to play I was a rich trader too, but I guess I have not played enough... I'm just a poor man making voice for a trader video game... But wait, this is a textual game, isn't it? ... This means I am currently making something useless... Or maybe I'm just a robot who can type things...");
	
	return 0;
}