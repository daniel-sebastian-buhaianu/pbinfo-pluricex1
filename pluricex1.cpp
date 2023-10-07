#include <fstream>

#define NMAX 22
#define KMAX 8
#define DMAX 10

using namespace std;

ifstream fin("pluricex1.in");
ofstream fout("pluricex1.out");

int a[NMAX+1][DMAX+1], e[KMAX+1], n, k, D;

bool cond_pluricex();

int main()
{
    int i, nr, j, d, gata;

    fin >> n >> k >> D;

    for (i = 1; i <= n; i++)
    {
        fin >> nr;

        for (j = 1; j <= nr; j++)
        {
            fin >> d;

            a[i][d] = 1;
        }
    }
    
    // selectez prima echipa
    for (i = 1; i <= k; i++)
    {
        e[i] = i;
    }

    gata = 0;

    while (!gata)
    {
        // verific daca echipa curenta indeplineste conditia
        if (cond_pluricex())
        {
            // afisez echipa curenta
            for (i = 1; i <= k; i++)
            {
                fout << e[i] << ' ';
            }

            fout << '\n';
        }

        // selectez urmatoarea echipa
        for (i = k; i > 0 && e[i] == n-k+i; i--);

        if (i == 0)
        {
            gata = 1; // am ales toate echipele posibile
        }
        else
        {
            e[i]++;

            for (j = i+1; j <= k; j++)
            {
                e[j] = e[j-1] + 1;
            }
        }
    }


    return 0;
}

bool cond_pluricex()
{
    int s[D+1], i, j;

    for (i = 1; i <= D; i++)
    {
        s[i] = 0;
    }

    for (i = 1; i <= D; i++)    
    {
        for (j = 1; j <= k; j++)
        {
            s[i] += a[e[j]][i];
        }

        if (s[i] == 0)
        {
            return 0;
        }
    }

    return 1;
}
// scor 100
