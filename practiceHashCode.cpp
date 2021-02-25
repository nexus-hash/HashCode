#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <unordered_set>
#include <algorithm>
#include <cassert>
#include <unordered_map>
using namespace std;

unordered_map<string, int> ingd_map;
unordered_set<string> ing_set;
int ing_count = 0;

struct Pizza
{
    int id;
    vector<int> ingreds;

    void read(int _id)
    {
        id = _id;
        int cnt;
        scanf("%d", &cnt);
        for (int i = 0; i < cnt; i++)
        {
            static char s[105];
            scanf("%s", s);
            int set_size_before_insertion = ing_set.size();
            string s_temp = string(s);
            ing_set.insert(s_temp);
            int set_size_after_insertion = ing_set.size();
            if (set_size_after_insertion != set_size_before_insertion) 
            {
                count++;
                ingd_map[s_temp] = count;
            }
            ingreds.push_back(ingd_map[s_temp]);
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

    bool used[m] = {false};
    vector<vector<int> > output;
    int pizzas_used = 0;

    for (int i = 4; i >= 2; --i)
    {   
        for (int rep = 0; rep < t[i]; ++rep)
        {
            cerr << (double) pizzas_used * 100 / pizzas.size() << "% ";

            if (pizzas_used + i <= (int) pizzas.size())
            {
                pizzas_used += i;
                unordered_set<int> usedIngredients;
                vector<int> delivery;
                
                for (int x = 0; x < i; x++)
                {
                    pair<int, int> best;
                    best.first = -1;
                    best.second = -1;
                    int iterated = 0;
                    for (int id = 0; id < m; id++)
                    {

                        if (!used[id])
                        {
                            if (++iterated == 1000000){
                                break;
                            }
                            int improvement = 0;
                            for (int s : pizzas[id].ingreds)
                            {
                                if (!usedIngredients.count(s))
                                {
                                    improvement++;
                                }
                            }
                            if(improvement > best.first){
                                best = make_pair(improvement,id);
                            }
                        }
                    }
                    assert(best.second != -1);
                    int id = best.second;
                    delivery.push_back(id);
                    used[id] = true;
                    for (int s : pizzas[id].ingreds)
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
        unordered_set<int> set;
        printf("%d", (int)delivery.size());
        for (int id : delivery)
        {
            for(int s: pizzas[id].ingreds){
                set.insert(s);
            }
            printf(" %d", id);
        }
        puts("");
    }
    return 0;
}