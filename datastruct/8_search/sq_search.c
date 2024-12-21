int SQ_Search(int *a, int n, int key)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if (a[i - 1] == key)
        {
            return i;
        }
    }
    return 0;
}

int SQ_SearchBetter(int *a, int n, int key)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if (a[i - 1] == key)
        {
            return i;
        }
    }
    return 0;
}