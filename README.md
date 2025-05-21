# readInput Utility (C)

A lightweight and flexible input handling utility written in C. It simplifies user input collection from the console by supporting different data types via a unified interface, using a tagged union and dynamic memory management.

## 📦 Files

- `readInput.c`: Core logic for input reading and parsing based on data type.
- `readInput.h`: Header file containing the union definition and function prototypes.

## 🚀 Features

- Accepts and processes string (`char*`), long integer (`long`), and double (`double`) inputs.
- Uses a `union` to store multiple data types in the same memory location.
- Automatically clears input buffers to prevent unexpected behavior.
- Dynamically allocates memory for user input handling on first use and reuses it later.

## 🛠️ Usage

To use this utility in a program:

1. Include `readInput.h`.
2. Compile both `readInput.c` and your main program file together.
3. Call `readInput()` with the correct mode and input buffer.

### 📄 Example

```c
#include <stdio.h>
#include "readInput.h"

int main() {
    char buffer[PC_TAILLE] = "";
    type_3 *userData = NULL;

    printf("Entrez votre nom:\n");
    userData = readInput(buffer, PC_TAILLE, 's', NULL);
    printf("Ah! Vous vous appelez donc %s\n", userData->Chaine);

    printf("Quel est votre age:\n");
    readInput(buffer, PC_TAILLE, 'l', userData);
    printf("Ah! Vous êtes âgé de %ld ans\n", userData->entier);

    printf("Quel est votre moyenne du premier semestre:\n");
    readInput(buffer, PC_TAILLE, 'd', userData);
    printf("Ah! Vous avez eu %.2lf de moyenne\n", userData->reel);

    free(userData); // Always free memory!
    return 0;
}
````

Compile it using:

```sh
gcc -o main main.c readInput.c
```

## 📚 Function Reference

```c
type_3 *readInput(char *Chaine, int taille, char mode, type_3 *Variable);
```

* `Chaine`: Buffer for temporary input.
* `taille`: Size of the input buffer.
* `mode`: One of `'s'` (string), `'l'` (long), `'d'` (double).
* `Variable`: `NULL` on first call, then reuse the returned pointer.

## 🧠 Design Notes

* Input buffer is always sanitized (`voidBuffer`) to prevent trailing newline issues.
* Memory is only allocated once, reused on subsequent calls to avoid memory leaks.
* Modular design makes this easy to integrate into other projects.

## 📝 License

This project is licensed under the **Creative Commons Attribution 4.0 International License (CC BY 4.0)**.

You are free to:

* **Share** — copy and redistribute the material in any medium or format.
* **Adapt** — remix, transform, and build upon the material for any purpose, even commercially.

Under the following terms:

* **Attribution** — You must give appropriate credit, provide a link to the license, and indicate if changes were made.

Read more: [https://creativecommons.org/licenses/by/4.0/](https://creativecommons.org/licenses/by/4.0/)

---

© 2025 Kevin Simpore
