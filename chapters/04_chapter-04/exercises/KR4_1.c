int strIndex(char source[],char searchFor[]){
    int i,j,k,indexes[10],n=0;

    for(i=0;source[i]!='\0';i++){
        for(j=i,k=0;searchFor[k]!='\0' && source[j]==searchFor[k];j++,k++)
            ;
        if(k>0 && searchFor[k]=='\0')
            indexes[n++]=i;
    }
    return indexes[--n];
}
