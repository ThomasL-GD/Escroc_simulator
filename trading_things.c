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
	int nTempo;
	printf("\n");
	
	for (int i = 0; i < 20; i++){ 
		for (int j = 0; j < 20; j++){
			if (strcmp(inventory[i].name, inventory[j].name) < 0){
				
				strcpy(tempo, inventory[i].name);
				strcpy(inventory[i].name, inventory[j].name);
				strcpy(inventory[j].name, tempo);
				
				nTempo = inventory[i].price;
				inventory[i].price = inventory[j].price;
				inventory[j].price = nTempo;
				
			}
		}
	}
	
	for (int k = 0; k<20; k++){
		
		if(strcmp(inventory[k].name, "z") != 0){
			printf("%d-%s \n", k+1, inventory[k].name);
		}
		
	}
	
};

void Shop (item shopItems[20]){
	
	char tempo[150];
	int nTempo;
	printf("\n");
	
	for (int i = 0; i < 20; i++){ 
		for (int j = 0; j < 20; j++){
			if (shopItems[i].price > shopItems[j].price){
				
				strcpy(tempo, shopItems[i].name);
				strcpy(shopItems[i].name, shopItems[j].name);
				strcpy(shopItems[j].name, tempo);
				
				nTempo = shopItems[i].price;
				shopItems[i].price = shopItems[j].price;
				shopItems[j].price = nTempo;
				
			}
		}
	}
	
	for (int k = 0; k<20; k++){
		
		if(strcmp(shopItems[k].name, "z") != 0){
			printf(" %d) %dPO - %s \n", k+1, shopItems[k].price, shopItems[k].name);
		}
		
	}
	
};

void Buy (item inventory[20],item shopItems[20], int index, int * money){
	
	printf("Buy function in");
	
	int nRecep = 19;
	
	for(int i = 0; i<20; i++){
		
		if(strcmp(inventory[i].name, "z") == 0){
			
			nRecep = i;
			i = 21;
			
		}
		
	}
	
	*money -= shopItems[index].price;
	
	strcpy(inventory[nRecep].name, shopItems[index].name);
	inventory[nRecep].price = shopItems[index].price;
	strcpy(shopItems[index].name, "z");
	shopItems[index].price = 0;
	
	printf("\nYou succesfully bought the item named \"%s\" ! \n",inventory[nRecep].name);
	
};

int main (){
	
	srand(time(NULL));
	
	int nChoice = 0;
	int nConfirm = 0;

	int money = rand()%1001 + 1000;
	item inventory[20] = {"Bottes en cuir de yak",150,"Graine de haricot presque magique",60,"Baguette de pain magique",400,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0,"z",0};
	item shopItems[20] = {"Epee sacree du futur draconien de glace",1500,"Grenouille potentiellement princesse",50,"XP en poudre",350,"Casque en plastique massif",100,"Potion a base de plantes douteuses",80,"Armure d'ecailles de truite",500,"Cottes de mailles de laine",850,"Suite Adobe",2000,"Anti-moustiques reelement efficace",145,"Gilet jaune",5,"Fragment de corne de licorne MyLittlePony inc.",785,"Billet de 100PO",101,"Canard en plastique pour Ogre (5m de diametre)",1000,"Du talent en algorithmie",200,"Dragon blanc aux yeux turquoise et aux griffes grises avec des reflets jaunes a pois verts",945,"Malediction de mutisme (a lancer sur les eleves)",320,"z",0,"z",0,"z",0,"z",0};
	
	
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
			
			Inventory(inventory);
	
			printf("\nYou currently have %dPOs\n", money);
			
		}
		
		// Going to the shop
		if(nChoice == 2){
			
			printf("\n");
			
			Shop(shopItems);
			
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
						
							printf("	Are you sure you want to buy \"%s\" for %dPO ? (type 1 for yes and 0 for no)\n", shopItems[nChoice].name, shopItems[nChoice].price);
						
							scanf("%d", &nConfirm);
						
						}
						
						if(nConfirm == 1){
							
							if (money >= shopItems[nChoice].price){
							
								Buy(inventory, shopItems, nChoice, &money);
							
							}
							else if (money < shopItems[nChoice].price){
								
								printf("You don't have enough POs...\n");
								
							}
							
						}
						
					}
					
				}
				
				nChoice = 2;
			
			}
			
		}

	}
	
	nConfirm = 0.;
	while (nConfirm == 0){
		
		printf("T_T I'm very sad you left ! T_T Ctrl + C to quit T_T ");
		
	}
	
	return 0;
}