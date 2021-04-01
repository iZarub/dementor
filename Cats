Coon* find_the_most_fed_cat(Coon* atc, unsigned int n_cats) {
    double max = 0;
    for (unsigned int i = 0; i < n_cats; i++) {
        if (atc[i].food / atc[i].weight > max) {
            max = atc[i].food / atc[i].weight;
        }
    }

    for (unsigned int i = 0; i < n_cats; i++) {
        if (atc[i].food / atc[i].weight == max) {
            return &atc[i] ;
        }
    }
    
    return NULL;
}
