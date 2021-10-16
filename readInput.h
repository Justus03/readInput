#define PC_TAILLE 100
#ifndef _MODULE_H_

#define _MODULE_H_
union type_3
{
  char Chaine[PC_TAILLE];
  long entier;
  double reel;
};
typedef union type_3 type_3;
void voidBuffer();
type_3 *readInput(char *Chaine,int taille,char mode,type_3 *Variable);

#endif
