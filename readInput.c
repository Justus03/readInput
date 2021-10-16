#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ****************************** */
#include "module.h"

/*
int main(int argc,char *argv[])
{
  char Chaine[PC_TAILLE]="";
  type_3 *Var=NULL;
  
  printf("Entrez votre nom:\n");
  Var=readInput(Chaine,PC_TAILLE,'s',NULL);
  printf("Ah! Vous vous appelez donc %s \n",Var->Chaine);
  printf("Quel est votre age:\n");
  readInput(Chaine,PC_TAILLE,'l',Var);
  printf("Ah! Vous etes agé de %d ans\n",Var->entier);
  printf("Quel est votre moyenne du premier semestre:\n");
  readInput(Chaine,PC_TAILLE,'d',Var);
  printf("Ah! Vous avez eu %lf de moyenne\n",Var->reel);
  free(Var);
  
  return 0;
}
*/

void voidBuffer()
{
	while(getchar()!='\n');
}
type_3 *readInput(char *Chaine,int taille,char mode,type_3 *Variable)
{
  char *Caract=strchr(fgets(Chaine,taille,stdin),'\n');

  if(Caract==NULL)
    voidBuffer();
  else
    *Caract='\0';
  if(Variable)
    {
      switch(mode)
	{
	case 's':
	  strcpy(Variable->Chaine,Chaine);
	  return Variable;
	  break;
	case 'l':
	  Variable->entier=strtol(Chaine,NULL,10);
	  return Variable;
	  break;
	case 'd':
	  Variable->reel=strtod(Chaine,NULL);
	  return Variable;
	  break;
	default:
	  printf("readInput(): Eureur de mode...\n");
	  break;
	}
    }
  else
    {
      type_3 *var=calloc(sizeof(type_3),1);

      switch(mode)
	{
	case 's':
	  strcpy(var->Chaine,Chaine);
	  return var;
	  break;
	case 'l':
	  var->entier=strtol(Chaine,NULL,10);
	  return var;
	  break;
	case 'd':
	  var->reel=strtod(Chaine,NULL);//cette fonction ne prends pas en compte le 3ieme parametre de la fonction strtol(la base)
	  return var;
	  break;
	default:
	  printf("readInput(): Eureur de mode...\n");
	  break;
	}
    }
}
