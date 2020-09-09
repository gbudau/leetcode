int subVersion(char **v)
{ 
    char *s = *v;
    int n = 0;
    
    while (*s && *s != '.')
        n = n * 10 + *s++ - '0';
    *v = s;
    return n;
}

int diffVersion(char *s, int v)
{
    while (*s)
        if (*s != '.' && *s != '0')
            return v;
        else
            s++;
    return 0;
}

int compareVersion(char * v1, char * v2){
        
    int n1 = 0, n2 = 0;
    
    while (*v1 && *v2 && n1 == n2)
    {
        n1 = subVersion(&v1);
        n2 = subVersion(&v2);
        if (*v1 && *v2)
        {
            v1++;
            v2++;
        }
    }
    if ((n1 == n2) && (*v1 || *v2))
        return (*v1 ? diffVersion(v1, 1) : diffVersion(v2, -1));
    if (n1 > n2)
        return 1;
    if (n1 < n2)
        return -1;
    return 0;
}
