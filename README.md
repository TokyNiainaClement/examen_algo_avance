# Projet : Table de Hachage en C

## Description

Ce projet implémente une **table de hachage** en langage C, avec gestion des collisions par chaînage (listes chaînées) et redimensionnement automatique (rehashing) lorsque le facteur de charge dépasse 0.75.

### Fonctionnalités principales

- `creer_table_hashage()` : initialisation d'une table avec une capacité de départ de 8 buckets.
- `table_hashage_put()` : insertion ou mise à jour d'une paire clé/valeur.
- `table_hashage_get()` : recherche d'une valeur à partir d'une clé.
- `table_hashage_remove()` : suppression d'une entrée.
- `redimensionner()` : doublement de la capacité et redistribution des éléments (rehash) quand le facteur de charge maximal est atteint.
- Fonction de hachage inspirée du `hashCode` de Java, suivie d'une étape de "spreading" des bits (`etaler_bits`) pour mieux répartir les clés dans les buckets.

## Compilation

```bash
gcc -o table_hashage table_hashage.c
./table_hashage
```

## Remarque importante

Nous n'avons **pas pu réaliser la capture vidéo** de la démonstration du programme comme demandé, en raison d'un problème technique rencontré avec les logiciels d'enregistrement d'écran testés (**Vokoscreen** et **Bandicam**). Malgré plusieurs tentatives, l'enregistrement n'a pas pu être finalisé correctement dans les délais impartis.

Nous restons disponibles pour effectuer une démonstration en direct si nécessaire.
- Membre 3

*(à compléter avec les noms du groupe)*
