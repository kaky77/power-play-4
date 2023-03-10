#include<iostream>
#include<time.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstdlib>

using namespace std;

int Nb_aleatoire()
{
	time_t temps; 
	temps = time(NULL);
	srand(unsigned int(temps));
	return (rand() % 7);
}

void afficher_Tab(char tab[6][7])   // affiche le tableau!!!
{
	system("cls");
	cout << "  -----------------------------" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			cout << "  |" << tab[i][j];
		}
		cout << "  |" << endl;
	}
	cout << "  -----------------------------" << endl;

}

void joueur(char tab[6][7],char pion, int colonne)
{
	//Nb_aleatoire(); // la colonne où le joueur decide de jouer 
	int ligne = 5; // la dernière ligne  
	while (ligne>=0) // verifions si la dernière case est vide sinon on verifie la case precedente 
	{
		if (tab[ligne][colonne] != ' ') // case pas vide donc on passe à la case précedente 
		{
			ligne--;// decrementer la ligner
			continue;
		}
		else
		{
			if (tab[0][colonne] != ' ') //si la première colonne de la case n'est pas vide alors toute la colonne est pleine  
			{
				joueur(tab,pion, colonne); // donc on redonne la main au joueur 
			}
			tab[ligne][colonne] = pion; // le joueur joue avec les pions  
			break;
		}
		//ligne--;  
	}
}

bool verifie_vainqueur(char tab[6][7], char pion)
{
	//parcours en horizontale 
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tab[i][j] == pion && tab[i][j]==tab[i][j+1] && tab[i][j] == tab[i][j+2] && tab[i][j] == tab[i][j+3])
			{
					return 1;
			}
		}
	}

	//parcours en verticale
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (tab[j][i] == pion && tab[j][i] == tab[j+1][i] && tab[j][i] == tab[j+2][i] && tab[j][i] == tab[j+3][i])
			{
				return 1;
			}
		}
	}

	//parcours en diagonale 
	int cmp_diagonale = 0;
	//diagonale assendante 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tab[i][j] == tab[i+1][j+1] && tab[i][j]== tab[i+2][j+2] && tab[i][j] == tab[i + 3][j + 3] && tab[i][j] == pion)
			{
					return 1;
			}
		}
		
	}
	for (int i = 3; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (tab[i][j] == tab[i - 1][j + 1] && tab[i][j] == tab[i - 2][j + 2] && tab[i][j] == tab[i - 3][j + 3] && tab[i][j] == pion)
			{
				return 1;
			}
		}
	}

	return 0;
}


int main()
{
	char Tab[6][7];
	char first_pion = 'X';
	char second_pion = 'O';
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			Tab[i][j] = ' '; // initialiser le tableau les case à vide  
		}
	}
	cout << "\n";

	int p[2] = { 0 };

	if (pipe(p) == -1)
	{
		cout << "Échec de création du tube\n";
		exit(1);
	}
	// Le tube est ouvert
	int n = 0;
	if ((n = fork()) == -1)
	{
		cout << "Échec du fork()\n";
		exit(2);
	}

	if (n == 0) // premier fils
	{
		//close(p[0]); 

		/*close(p[1]);*/

		//sleep(3);
		
	}
	else 
	{
		int x = 0;
		if ((x = fork()) == -1)
		{
			cout << "Échec du fork()\n";
			exit(2);
		}
		if (x == 0) //second fils 
		{

		}
		else //père  
		{

		}
		//close(p[1]); 

	}



	/*for (auto i = 1; i <= 21; i++)
	{
		joueur(Tab, first_pion, Nb_aleatoire());
		afficher_Tab(Tab);
		if (verifie_vainqueur(Tab, first_pion) == 1)
		{
			cout << "le gagnant est :" << first_pion << "\n";
			break;
		}
		cout << "A toi de jouer (indique le numéro de ta colonne)\n";
		int Colonne;
		cin >> Colonne;
		joueur(Tab, second_pion,Colonne);
		afficher_Tab(Tab);
		if (verifie_vainqueur(Tab, second_pion) == 1)
		{
			cout << "le gagnant est :" << second_pion << "\n";
			break;
		}
	}	*/
	
	return 0; 
}