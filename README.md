Paul Roger-Dauvergne, Alexandre Vieu et Augustin Nguon présentent
# Zack_and_Robin_against_Humans

Un jeu multijoueur de notre imagination, pour mettre en oeuvre les notions de programmation orientée objet.
## Bibliothèques utilisées : 
* Bibliothèque graphique SFML
* Bibliothèque standard stdlib.h
* Bibliothèque temporelle time.h et features-time64.h

## Lancement du programme : 
* Placer l'ensemble des fichiers de l'archive ou du git dans un dossier
* S'assurer d'avoir la bibliothèque SFML, ou l'installer. Différentes méthodes sont possibles selon l'OS.
* Ouvrir le dossier dans un terminal
* Taper "make"
* Taper "./ZandRVSH"

Vous êtes dans le jeu !

## Jeu :
Dans ce jeu coopératif le premier joueur incarne un marcheur (créature morte-vivante), tandis que le second incarne son robot personnel.
Il vous faudra suivre le chemin pour atteindre le bout du jeu, mais attention, de terribles dangers vous attendent !

### Commandes et rôles
Le marcheur peut se déplacer (Z,Q,S,D), attaquer (E) et passer à la région suivante.
Le robot peut se déplacer (I,J,K,L), attaquer (O), et rendre des points de vie au zombie.

### Dégâts et PV
Le marcheur possède 6 points de vie. Lorsqu'il subit des dégâts, un de ses membres est éjecté sur le terrain. Il perd alors 1 point de vie.
Le robot possède une vie infinie. Il ne peut pas prendre de dégâts, mais il est le seul capable de ramasser les membres du marcheur, et de les lui ramener.
Il lui suffit de se déplacer sur un membre tombé au sol pour le ramasser, et se déplacer sur le marcheur pour le lui rendre. La récupération est automatique.

### Ennemis et attaques
Les humains sont les ennemis de ce jeu. Ils possèdent 5 points de vie. 
Le marcheur inflige 3 dégâts par attaque, il lui suffit donc de 2 coups pour éliminer un méchant humain.
Le robot inflige 1 dégât par attaque, il lui faut donc 5 coups pour éliminer un terrible humain. Le rôle du robot n'est en effet pas d'attaquer.

### Carte
La carte est divisée en 9 régions. Vous aurez l'occasion de visiter des paysages variés.
Pour passer à la région suivante il suffit de suivre le chemin. La fin du jeu se déclenche quand vous atteignez la fin du chemin sur la dernière région.

## Programme
*commentaire sur comment votre programme est conçu, ce que vous avez fait, ce qui ne marche pas, et ce qui vous parait intéressant (i.e. ce quie vous avez envie que votre correcteur regarde en détail) dans votre réalisation.*

## Organisation du trinôme
*qui a fait quoi, comment vous avez travaillé ensemble, etc...*


