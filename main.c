#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int min=1;
    int max,nbMystere,nbPropose,nbTrouve;
    int coups,nouvellePartie=1,nbJoueurs,difficulte;

    //jeu
    do
    {
        printf("\n<----------------------------- Le nombre mystere ----------------------------->\n");

        //nb de joueurs
        do
        {
            printf("\n\nVoulez-vous jouer a 1 ou 2 joueurs ? ");
            scanf("%d",&nbJoueurs);
        }while((nbJoueurs!=1) && (nbJoueurs!=2));

        //difficulté
        do
        {
            printf("\nDifficulte 1 (1-100), 2 (1-500) ou 3 (1-1000) ou 4 (personnalise) ? ");
            scanf("%d",&difficulte);
        }while((difficulte!=1)&&(difficulte!=2)&&(difficulte!=3)&&(difficulte!=4));

        switch (difficulte)
        {
            case 1 :
                max=100;
                break;
            case 2 :
                max=500;
                break;
            case 3 :
                max=1000;
                break;
            case 4 :
                printf("Tapez le maximum souhaite : ");
                scanf("%d",&max);
        }

        //définition du nombre mystère
        srand(time(NULL));
        nbMystere = rand()%(max-min+1)+min;
        nbTrouve=0;
        coups=0;

        //1 joueur
        if (nbJoueurs==1)
        {
            do
            {
                ++coups;

                printf("\nTapez un nombre : ");
                scanf("%d",&nbPropose);

                if (nbPropose==nbMystere)
                {
                    nbTrouve=1;
                    printf("\nVous avez gagne en %d coups! Le nombre mystere est bien %d !\n",coups,nbMystere);
                }
                else
                {
                    if (nbPropose>nbMystere)
                        printf("C'est plus petit !\n");
                    else
                        printf("C'est plus grand !\n");
                }
            }while(nbTrouve!=1);

        }

        //2 joueurs
        else
        {
            do
            {
            ++coups;

            if (coups%2==1)
                printf("\nJoueur 1 - ");
            else
                printf("\nJoueur 2 - ");

            printf("Tapez un nombre : ");
            scanf("%d",&nbPropose);

            if (nbPropose==nbMystere)
            {
                nbTrouve=1;
                if (nbJoueurs==1)
                    printf("\nVous avez gagne en %d coups! Le nombre mystere est bien %d !\n",coups,nbMystere);
                else
                {
                    printf("Le joueur %d a gagne ! Le nombre mystere est bien %d !\n", (coups+1)%nbJoueurs+1,nbMystere);
                }
            }
            else
            {
                if (nbPropose>nbMystere)
                    printf("C'est plus petit !\n");
                else
                    printf("C'est plus grand !\n");
            }

            }while(nbTrouve!=1);
        }

        //demande si on rejoue ou non
        do
        {
            printf("\nVoulez-vous rejouer (oui : 1, non : 0) ?");
            scanf("%d",&nouvellePartie);
        }while((nouvellePartie!=0)&&(nouvellePartie!=1));

        //si "oui", effacement de l'ancienne partie
        if(nouvellePartie==1)
        {
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif
        }

    }while(nouvellePartie==1);//tant qu'on joue et rejoue


    return 0;
}
