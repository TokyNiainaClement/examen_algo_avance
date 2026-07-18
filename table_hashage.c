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
