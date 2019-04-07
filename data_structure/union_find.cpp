/*
 * disjoint set
 * Find(int v) : v is node
 *             : returns v's root
 * Union(int v1, int v2) : v1, v2 are node
 *                       : get roots of v1, v2 and union
*/

int disjoint[100001];

int Find(int v);
void Union(int v1, int v2);

int Find(int v)
{
    while(disjoint[v] > 0)
        v = disjoint[v];
    return v;
}

void Union(int v1, int v2)
{
    int r1 = Find(v1);
    int r2 = Find(v2);
    if(r1 == r2)
        return;
    if(disjoint[r1] < disjoint[r2])
        disjoint[r2] = r1;
    else if(disjoint[r1] > disjoint[r2])
        disjoint[r1] = r2;
    else {
        disjoint[r2] = r1;
        disjoint[r1]--;
    }
}