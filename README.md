# readInput Module

A simple C module for reading and parsing user input into different types using a union structure.

## Description

This module provides a function `readInput()` to handle typed user input (string, integer, or double) and store it efficiently in a union structure (`type_3`). It helps avoid repetitive boilerplate code when reading different types of input from the user and provides memory safety by allowing dynamic allocation.

---

## Files

- `readInput.c`: Implements the input parsing logic and buffer flushing.
- `readInput.h`: Declares the `readInput` interface and the `type_3` union structure.

---

## Function Usage

### `type_3 *readInput(char *Chaine, int taille, char mode, type_3 *Variable);`

**Parameters:**

1. `Chaine`: Buffer to read the input string into.
2. `taille`: Size of the buffer.
3. `mode`: Character flag to indicate the data type:
   - `'s'` → string
   - `'l'` → long (integer)
   - `'d'` → double (floating-point)
4. `Variable`: A pointer to a `type_3` variable. On first use, pass `NULL`; reuse the returned pointer for subsequent calls to avoid memory leaks.

**Returns:**  
A pointer to a `type_3` union that contains the parsed value (string, long, or double).

---

## Example Usage

Uncomment the example in `readInput.c` to test the function:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readInput.h"

int main(int argc, char *argv[]) {
    char Chaine[PC_TAILLE] = "";
    type_3 *Var = NULL;

    printf("Entrez votre nom:\n");
    Var = readInput(Chaine, PC_TAILLE, 's', NULL);
    printf("Ah! Vous vous appelez donc %s\n", Var->Chaine);

    printf("Quel est votre age:\n");
    readInput(Chaine, PC_TAILLE, 'l', Var);
    printf("Ah! Vous êtes âgé de %ld ans\n", Var->entier);

    printf("Quel est votre moyenne du premier semestre:\n");
    readInput(Chaine, PC_TAILLE, 'd', Var);
    printf("Ah! Vous avez eu %lf de moyenne\n", Var->reel);

    free(Var); // Always free allocated memory
    return 0;
}
````

---

## Structure Definition

```c
#define PC_TAILLE 100

union type_3 {
    char Chaine[PC_TAILLE];
    long entier;
    double reel;
};
typedef union type_3 type_3;
```

---

## ⚠️ Notes

* Always pass `NULL` for the first use of `readInput()`, and reuse the returned pointer for later calls.
* Don’t forget to call `free()` on the returned pointer when you're done using it.
* The internal buffer cleaning is handled to avoid unwanted input effects.

---
