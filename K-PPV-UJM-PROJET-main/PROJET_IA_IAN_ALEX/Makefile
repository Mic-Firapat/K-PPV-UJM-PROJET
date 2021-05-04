#######################################################################################
# /*                                                                                  #
# *********************************************************************************   #
# *********************************************************************************   #
# *********************************************************************************   #
# *********************************************************************************   #
# ** Nom du fichier : Makefile                                                   **   #
# ** Auteur : RIVIERE Ian & MARINE Alexandre                                     **   #
# ** Date de création : 18/03/2021                                               **   #
# **                                                                             **   #
# ** Contenu : Ce fichier comporte :                                             **   #
# **                - La création des exécutables                                **   #
# **                - La déclaration des dépendances                             **   #
# **                - Des fonctions utilitaires                                  **   #
# **                                                                             **   #
# **                                                                             **   #
# **                                                                             **   #
# **                                                                             **   #
# *********************************************************************************   #
# *********************************************************************************   #
# *********************************************************************************   #
# *********************************************************************************   #
# */                                                                                  #
#######################################################################################

# RAPPEL DES RACCOURCIS makefile:
# wildcard permet d'utiliser $\* en dehors d'une commande
# $\* correspond au nom d'un fichier sans son suffixe
# $\@ => correspond à la cible
# $\^ => correspond à la liste des dépendances
# $\< => correspond à la première dépendance

#Bienvenue dans ce magnifique MAKEFILE


#Détails des macros :
CC = gcc
OPTIONS = -g -W -Wall -std=c89 -pedantic -O3
OPTIONS_MLV_1 = `pkg-config --cflags MLV` `pkg-config --libs-only-other --libs-only-L MLV`
OPTIONS_MLV_2 = `pkg-config --libs-only-l MLV`
EXEC = executable
TEST = test_fct
CIBLE = $(EXEC) $(TEST)

# Cette commande récupère les sources
SOURCE= $(wildcard *.c) $(wildcard */*/*.c)

# Cette commande permet de récupérer les objets depuis nos sources:
OBJET	:= $(SOURCE: .c=.o)

# Cette commande récupère tout nos fichiers en-tête
HEADER=$(wildcard */*.h) $(wildcard */*/*.h)

# Ce qu'il faut effacer
TOCLEAN = *.o *~ */*~ */*/*~

# Pour clean_all
TOCLEAN_ALL = $(TOCLEAN) $(CIBLE)

# PROG :

# Phony pour empêcher la confusion avec un fichier all, cible executable
.PHONY: all
all: $(CIBLE)
	make clean

# Déclaration de la cible executable :

# RAPPEL DES RACCOURCIS :
# $\@ => correspond à la cible
# $\^ => correspond à la liste des dépendances
# $\< => correspond à la première dépendance

executable: $(OBJET)
	$(CC) $(OPTIONS) $^ $(OPTIONS_MLV_2) -o $@ 

# Déclaration de la cible test_fct :

test_fct: $(OBJET)
	$(CC) $^ -o $@


# DEPENDANCE :

# Nouvelle version chaque objet dépendent des en-têtes

%.o: %.c $(HEADER)
	$(CC) $(OPTIONS) $(OPTIONS_MLV_1) -c $< -o $@ 

# UTILITAIRE :
# Déclaration de clean :

.PHONY:clean
clean:
	rm -f $(TOCLEAN)

clean_all: clean
	rm -f $(CIBLE)
