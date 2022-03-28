# Projet de fin 

### Louis Merlaud, Clamadieu-Tharaud Adrien

## Morse

#### Notre projet consiste a écrire du texte sur putty, texte qui sera envoyé a la carte,qui traduira le texte en morse via une led

## Avant propos
On active l’USAR2 via cubemx, il faudra configurer le putty avec le même valeurs
(on doit également trouver le port de la carte stm32 via le gestionnaire de périphérique) :

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
on commence par appeller la fonction *read string* comme dit dit précédement, cette fonction va permettre de récupérer le message entrer par l'utilisateur dans la console putty, cette fonction utiliser *lis_txt*

![image](https://user-images.githubusercontent.com/80094480/160454268-541e8b6e-d50b-4759-a6bb-d201818ef0a1.png)

On appelle ensuite la fonction *wordToMorse* qui va convertir la chaine de l'utilisateur en code morse grâce aux tableaux déclaré au début du main, pour ce faire :
on effectue une boucle qui à chaque tour appelle la fonction *morseToLight* qui prend en paramètre un tableau tampon, ainsi que la fonction *charToMorse* qui elle même prend en paramètre un autre tableau tampon ainsi que le caractère actuel de la chaine de caractère

![image](https://user-images.githubusercontent.com/80094480/160455757-4018f221-9937-4386-bdf5-4872357a2d46.png)

La fonction *charToMorse* associe le charactère envoyer en paramètre à son équivalent en morse et le copie dans le tableau tampon que l'on renvoie,
on appelle dans cette fonction, une autre fonction qui s'appelle *indexOfP* qui nous permet de retrouver l'index auquel ce situe le caractère dans le tableau *arrChar*

![image](https://user-images.githubusercontent.com/80094480/160455881-e8a56d27-fcf9-4396-9056-0f8d7a0df1b2.png)

![image](https://user-images.githubusercontent.com/80094480/160456658-8f2c0e57-6ddc-4446-a122-1d0809392a0d.png)

Enfin la fonction *morseToLight* va nous permettre de convertir le morse en lumière, pour cela on bocle sur notre chaine de caractère en morse, et on détermine sa longueur avec la fonction *nbInstance*, dans la boucle, on regarde si le signal est long ou court, s'il est long, on laisse la LED allumé 300 millisecondes, sinon 100.
ON met également un delais de 700 millisecondes entre chaque signal.

![image](https://user-images.githubusercontent.com/80094480/160457531-08d6e7e5-6524-4150-ba60-decd5d27dca3.png)


