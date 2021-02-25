#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;


struct Pizza
{
    int id;
    vector<string> Pizzaing;

    void read(int _id)
    {
        id = _id;
        int cnt;
        scanf("%d", &cnt);
        for (int i = 0; i < cnt; i++)
        {
            static char s[105];
            scanf("%s", s);
            Pizzaing.push_back(string(s));
        }
    }
};

int main()
{
    int m, t[5];
    scanf("%d", &m);
    for (int i = 2; i <= 4; i++)
    {
        scanf("%d", &t[i]);
    }
    vector<Pizza> pizzas(m);
    for (int i = 0; i < m; i++)
    {
        pizzas[i].read(i);
    }
    vector<bool> used(m);
    vector<vector<int> > output;
    int pizzas_used = 0;
    for (int i = 4; i >= 2; --i)
    {
        
        for (int rep = 0; rep < t[i]; ++rep)
        {
            cerr<<(double) pizzas_used*100/pizzas.size()<<"% ";
            if (pizzas_used + i <= (int)pizzas.size())
            {
                pizzas_used += i;
                set<string> usedIngredients;
                vector<int> delivery;
                for (int x = 0; x < i; x++)
                {
                    pair<int, int> best;
                    best.first=-1;
                    best.second=-1;
                    int iterated=0;
                    for (int id = 0; id < m; id++)
                    {

                        if (!used[id])
                        {
                            if(++iterated==10000){
                                break;
                            }
                            int improvement = 0;
                            for (string s : pizzas[id].Pizzaing)
                            {
                                if (!usedIngredients.count(s))
                                {
                                    improvement++;
                                }
                            }
                            if(improvement>best.first){
                                best=make_pair(improvement,id);
                            }
                        }
                    }
                    assert(best.second!=-1);
                    int id = best.second;
                    delivery.push_back(id);
                    used[id] = true;
                    for (string s : pizzas[id].Pizzaing)
                    {
                        usedIngredients.insert(s);
                    }
                }
                output.push_back(delivery);
            }
        }
    }
    printf("%d\n", (int)output.size());
    for (vector<int> delivery : output)
    {
        set<string> set;
        printf("%d", (int)delivery.size());
        for (int id : delivery)
        {
            for(string s: pizzas[id].Pizzaing){
                set.insert(s);
            }
            printf(" %d", id);
        }
        puts("");
    }
    return 0;
}