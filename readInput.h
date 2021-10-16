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
/* 
*description de la fonction*
Cette fonction prends en paramètre 4 éléments 
* élément 1: la chaîne dans laquelle écrire
* élément 2: la taille de la chaîne
* élément 3: le genre d'écriture... 'd' pour un double, 'l' pour un long, 's' pour une chaine de caractère.
* élément 4: La variable de type type_3 a utilisé. Pour la première utilisation envoyé NULL et pour les autres utilisations utilisées l'adresse renvoyée par la fonction lors de la première utilisation.
* un exemple d'utilisation a été fournie en commentaire dans le fichier readInput.c. Please uncomment to test.
*/

#endif
