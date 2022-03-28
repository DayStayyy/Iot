# Iot - Projet final - Traductor morse

notre projet consiste à traduire une chaine de caractère reçu via un terminal putty, en code morse via une LED de la carte STM32


on commence par activer l'USART2 dans cube MX :

![image](https://user-images.githubusercontent.com/80094480/160366463-d9872563-6574-4f47-9133-d5daca2054d1.png)

on déclare également deux tableaux, un contenant les lettres + les chiffres, et un autre contenant leur équivalent en morse

![image](https://user-images.githubusercontent.com/80094480/160370230-73cc1728-2d1e-452c-af64-c6c63a0f52cf.png)

![image](https://user-images.githubusercontent.com/80094480/160370359-fb66a513-8f5e-424f-a0c6-7dc5b6b50b32.png)

On utilisera également les fonction *ecrit_char*, *ecrit_txt* et *lis_txt* qui on été utiliser dans les tp précédent.

## boucle while
![image](https://user-images.githubusercontent.com/80094480/160368217-0b3c25ff-e19e-4f7e-8d43-4af69d951c0b.png)

Dans cette boucle, on va demander à l'utilisateur d'écrire un message via la console putty,
on utilise la fonction *read_string* pour lire le message de l'utilisateur, on le récupère ensuite via un *sprintf*, 
et enfin on utilise la fonction *wordToMorse* pour d'abord convertir ce message en morse, puis via des appels successif en lumière

## fonctions
