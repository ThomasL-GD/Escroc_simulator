#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Item {
	
	char name[150];
	int price;
	
};
typedef struct Item item;

void Inventory (item inventory[20], int * money){
	
	char tempo[150];
	printf("\n");
	
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
		
		if(strcmp(inventory[k].name, "z") != 0){
			printf("%d-%s \n", k+1, inventory[k].name);
		}
		
	}
	
	printf("\nYou currently have %dPOs\n", *money);
	
};

void Buy (){};

int main (){
	
	srand(time(NULL));
	
	int nChoice = 0;
	int nConfirm = 0;
	
	int money = rand()%101 + 300;
	item inventory[20] = {"Bottes en cuir de yak",150,"Graine de haricot presque magique",60,"Baguette de pain magique",500,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0};
	item shopItems[20] = {"Epee sacree du futur draconien de glace",1500,"Grenouille potentiellement princesse",50,"XP en poudre",350,"Casque en plastique massif",100,"Potion a base de plantes douteuses",80,"Armure d'ecailles de truite",500,"Cottes de mailles de laine",850,"Moustache de gentleman",625,"Anti-moustiques reelement efficace",145,"Gilet jaune",5,"Fragment de corne de licorne MyLittlePony inc.",785,"Billet de 100PO",101,"Canard en plastique pour Ogre (5m de diametre)",1000,"Du talent en algorithmie",200,"Dragon blanc aux yeux turquoise et aux griffes grises avec des reflets jaunes a pois verts",945,"Malediction de mutisme (a lancer sur les eleves)",320,"z",0,"z",0,"z",0,"z",0};
	
	
	// Clearing the screen ┐(・。・┐)♪
	for(int i = 0; i< 70; i++){
		
		printf("\n");
		
	}
	
	while (nChoice != 4){
		
		nChoice = 0;
	
		while(nChoice != 1 && nChoice != 2 && nChoice != 4){
			
			printf("\n	Choose something to do :\n 1) Check inventory\n 2) Buy something to the shop\n 4) Quit T_T\n");
			
			scanf("%d",&nChoice);
			
		}
		
		// Checking inventory
		if(nChoice == 1){
			
			Inventory(inventory, &money);
			
		}
		
		// Going to the shop
		if(nChoice == 2){
			
			printf("\n");
			
			for (int i = 0; i<20; i++){
				
				if(strcmp(shopItems[i].name, "z") != 0){
					printf(" %d) %dPO - %s \n", i+1, shopItems[i].price, shopItems[i].name);
				}
		
			}
			
			nChoice = -2;
			
			while(nChoice < -1 || nChoice > 19){
			
				printf("\n	Wanna buy something ? (type 0 to quit)\n");
				
				scanf("%d", &nChoice);
				
				nChoice -= 1;
				
				if(nChoice > -1){
				
					// If the player choose an item non-owned by the shop
					if(strcmp(shopItems[nChoice].name, "z") == 0){
						nChoice = -2;
						printf("Item no existing");
					}
					else{
						
						nConfirm = 2;
						
						while(nConfirm != 0 && nConfirm != 1){
						
							printf("	Are you sure you want to buy \"%s\" for %dPO ?\n", shopItems[nChoice].name, shopItems[nChoice].price);
						
							scanf("%d", &nConfirm);
						
						}
						
						if(nConfirm == 1){
							
							//buyItem();
							
						}
						
					}
					
				}
				
				nChoice = 2;
			
			}
			
		}

	}
	
	return 0;
}