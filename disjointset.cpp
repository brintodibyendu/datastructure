//created by brinto dibyendu :)
#include<bits/stdc++.h>
using namespace std;
class Disjoint;
map<int,Disjoint*> m;
class Disjoint
{
public:
    int d,r;
    Disjoint *p;
    //map<Disjoint*,int> m;
    Disjoint()
    {

    }
    void makeset(int x)
    {
        Disjoint *a=new Disjoint();
        a->r=0;
        a->d=x;
        a->p=a;
        m.insert(make_pair(x,a));
    }
    Disjoint* findset(Disjoint *a)
    {
        if(a->p==a)
        {
            return a->p;
        }
        a->p=findset(a->p);
        return a->p;
    }
    void Union(int a,int b)
    {
        Disjoint *n1=m[a];
        Disjoint *n2=m[b];
        Disjoint *p1=findset(n1);
        Disjoint *p2=findset(n2);
        if(p1->d==p2->d)
        {
            return;
        }
        else if(p1->r>=p2->r)
        {
            p1->r=(p1->r==p2->r)?(p1->r+1):p1->r;
            p2->p=p1;
        }
        else
        {
            p1->p=p2;
        }
    }
};
int main()
{
    int x=0;
    Disjoint *d=new Disjoint();
    d->makeset(1);
    d->makeset(2);
    d->makeset(3);
    d->makeset(4);
    d->makeset(5);
    d->makeset(6);
    d->makeset(7);

    d->Union(1, 2);
    d->Union(2, 3);
    d->Union(4, 5);
    d->Union(6, 7);
    d->Union(5, 6);
    d->Union(3, 7);
    for(int i=1;i<=7;i++)
    {
        Disjoint *d1=d->findset(m[i]);
        printf("%d\n",d1->d);
    }
}
