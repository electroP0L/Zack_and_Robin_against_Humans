Paul Roger-Dauvergne, Alexandre Vieu et Augustin Nguon présentent
# Zack_and_Robin_against_Humans

Un jeu multijoueur de notre imagination, pour mettre en oeuvre les notions de programmation orientée objet.
## Bibliothèques utilisées : 
* Bibliothèque graphique SFML (SFML/Graphics)
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
Dans ce jeu coopératif le premier joueur incarne un marcheur Zack (créature morte-vivante), Zack, tandis que le second incarne son robot personnel, Robin.
Il vous faudra suivre le chemin pour atteindre le bout du jeu, mais attention, de terribles dangers vous attendent !

### Commandes et rôles
Le marcheur peut se déplacer (Z,Q,S,D), attaquer (E) et changer de région.
Le robot peut se déplacer (I,J,K,L), attaquer (O), rendre des points de vie au marcheur, et changer de région.

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
Notre code suit une logique assez simple d'interactions diverses entre les objets qu'il implémente. 
Pour permettre ces interactions, notre code s'articule beaucoup autour de la classe Contexte, qui fournit aux différents objets décisionnaires un aperçu de leur environnement (et permet aussi à la classe Game d'opérer des changements dans l'environnement).

Nous sommes assez fiers des éléments suivants de notre jeu :
- La solution trouvée pour la gestion des passages entre les régions appelés Waypoints. Il s'agit d'une map de la bibliothèque standard dans laquelle une paire d'entiers entre 0 et 1000 est associée à un coté de l'écran (String). Ces deux points marquent la délimitation de la zone de passage sur le coté spécifié.
- Le système de suivi des humains, assez agressif, a été implémenté grâce à un observateur. Chaque humain observe la position du marcheur quand celui-ci se déplace, et s'avance vers la nouvelle position.
- Afin d'alléger la classe Game, nous avons fait en sorte que les textures soient chargées dans le Texturemanager, et que l'écran de fin soit un objet à part entière, implémenté dans la classe GameoverScreen

Quelques pistes d'améliorations :
- Nous avions initialement prévu de modifier le Sprite du marcheur à chaque coup qu'il recevait, pour rendre compte physiquement de la perte de ses membres. Seulement, cela nous aurait pris beaucoup de création de graphismes, et la solution de l'affichage des points de vie a été privilégiée.
- Nous souhaitions également ajouter une petite fin à notre jeu. Arrivés à la dernière Zone, Zack & Robin pourraient enfin se reposer dans leurs maisons respectives.
- Il serait envisageable d'ajouter un écran de début de jeu, et de rendre l'écran de Game Over plus interactif.
- En l'état, il est techniquement possible pour n'importe quel living (Ennemis compris) de déclencher les changements de région. En théorie, le fonctionnement des humains rend cela impossible, mais cela pourrait poser problème à l'ajout de nouveaux PNJs.



## Organisation du trinôme
*qui a fait quoi, comment vous avez travaillé ensemble, etc...*


