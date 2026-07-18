
/* Redimensionnement (resize + rehash) */
void redimensionner(TableHashage *table)
{
    int ancienne_capacite = table->capacite;
    Noeud **anciens_buckets = table->buckets;

    int nouvelle_capacite = ancienne_capacite * 2;
    Noeud **nouveaux_buckets = calloc(nouvelle_capacite, sizeof(Noeud *));

    for (int i = 0; i < ancienne_capacite; i++)
    {
        Noeud *noeud = anciens_buckets[i];
        while (noeud != NULL)
        {
            Noeud *suivant = noeud->suivant;

            unsigned int h = etaler_bits(hash_chaine(noeud->cle));
            int nouvel_indice = indice_bucket(h, nouvelle_capacite);

            noeud->suivant = nouveaux_buckets[nouvel_indice];
            nouveaux_buckets[nouvel_indice] = noeud;

            noeud = suivant;
        }
    }

    free(anciens_buckets);
    table->buckets = nouveaux_buckets;
    table->capacite = nouvelle_capacite;
}


/* put (insertion / mise à jour) */

void table_hashage_put(TableHashage *table, const char *cle, int valeur)
{
    if ((float)(table->taille + 1) / table->capacite > FACTEUR_CHARGE_MAX)
    {
        redimensionner(table);
    }

    unsigned int h = etaler_bits(hash_chaine(cle));
    int indice = indice_bucket(h, table->capacite);

    Noeud *courant = table->buckets[indice];
    while (courant != NULL)
    {
        if (strcmp(courant->cle, cle) == 0)
        {
            courant->valeur = valeur;
            return;
        }
        courant = courant->suivant;
    }

    Noeud *nouveau = malloc(sizeof(Noeud));
    nouveau->cle = malloc(strlen(cle) + 1);
    strcpy(nouveau->cle, cle);
    nouveau->valeur = valeur;
    nouveau->suivant = table->buckets[indice];
    table->buckets[indice] = nouveau;
    table->taille++;
}


/* get (recherche) */

int table_hashage_get(TableHashage *table, const char *cle, int *valeur)
{
    unsigned int h = etaler_bits(hash_chaine(cle));
    int indice = indice_bucket(h, table->capacite);

    Noeud *courant = table->buckets[indice];
    while (courant != NULL)
    {
        if (strcmp(courant->cle, cle) == 0)
        {
            *valeur = courant->valeur;
            return 1;
        }
        courant = courant->suivant;
    }
    return 0;
}

/* remove (suppression) */

int table_hashage_remove(TableHashage *table, const char *cle)
{
    unsigned int h = etaler_bits(hash_chaine(cle));
    int indice = indice_bucket(h, table->capacite);

    Noeud *courant = table->buckets[indice];
    Noeud *precedent = NULL;

    while (courant != NULL)
    {
        if (strcmp(courant->cle, cle) == 0)
        {
            if (precedent == NULL)
            {
                table->buckets[indice] = courant->suivant;
            }
            else
            {
                precedent->suivant = courant->suivant;
            }
            free(courant->cle);
            free(courant);
            table->taille--;
            return 1;
        }
        precedent = courant;
        courant = courant->suivant;
    }
    return 0;
}
