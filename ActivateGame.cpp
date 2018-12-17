#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

#define VIT(i, v) for (i = 0; i < v.size(); i++) 
#define IT(it, ds) for (it = ds.begin(); it != ds.end(); it++)
#define FUP(i, n) for (i = 0; i < n; i++)
#define O1(v) cout << v << endl
#define O2(v1, v2) cout << v1 << " " << v2 << endl
#define O3(v1, v2, v3) cout << v1 << " " << v2 << " " << v3 << endl
#define OVEC(v) { int iii; VIT(iii, v) cout << v[iii] << " " ; cout << endl; }
typedef vector <string> SVec;

class Edge {
   public:
      int n1;
      int n2;
      int diff;
};

class Disjoint {
  public:
    Disjoint(int nelements);
    int Union(int s1, int s2);
    int Find(int element);
    void Print();
  protected:
    vector <int> links;
    vector <int> ranks;
};

Disjoint::Disjoint(int nelements)
{
  links.resize(nelements, -1);
  ranks.resize(nelements, 1);
}

int Disjoint::Find(int element)
{
  while (links[element] != -1) element = links[element];
  return element;
}

int Disjoint::Union(int s1, int s2)
{
  int p, c;

  if (links[s1] != -1 || links[s2] != -1) {
    cerr << "Must call union on a set, and not just an element.\n";
    exit(1);
  }
  if (ranks[s1] > ranks[s2]) {
    p = s1;
    c = s2;
  } else {
    p = s2;
    c = s1;
  }
  links[c] = p;
  ranks[p] += ranks[c];    /* HERE */
  return p;
}

class ActivateGame {
  public:
    int findMaxScore(vector <string> grid);
};

int ActivateGame::findMaxScore(vector <string> grid)
{
  vector < vector <int> > gridINT;
  multimap <int, Edge*> mmap;
  multimap <int, Edge*>::reverse_iterator mmit;
  Edge *newEdge;
  Disjoint *disjoint;
  int sum = 0;

  gridINT.resize(grid.size());
  for (int i = 0; i < grid.size(); i++) {
     gridINT[i].resize(grid[i].size());
  }

//convert to ints
  for (int i = 0; i < grid.size(); i++) {
     for (int j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] <= '9' && grid[i][j] >= '0') {
           gridINT[i][j] = grid[i][j] - '0';
        }
        else if (grid[i][j] <= 'z' && grid[i][j] >= 'a') {
           gridINT[i][j] = grid[i][j] - 'a' + 10;
        }
        else if (grid[i][j] <= 'Z' && grid[i][j] >= 'A') {
           gridINT[i][j] = grid[i][j] - 'A' + 36;
        }
        printf("%d, %c\n", gridINT[i][j], grid[i][j]);
     }
  }

//create graph
  for (int i = 0; i < gridINT.size(); i++) {
     for (int j = 0; j < gridINT[i].size(); j++) {
  printf("HI5\n");
  fflush(stdout);
        if (i != 0) {
           newEdge = new Edge;
           newEdge->n1 = i * gridINT[i].size() + j;
           newEdge->n2 = (i-1) * gridINT[i].size() + j;
           newEdge->diff = abs(gridINT[i][j] - gridINT[(i-1)][j]);
           mmap.insert(make_pair(newEdge->diff, newEdge));

           newEdge = new Edge;
           newEdge->n2 = i * gridINT[i].size() + j;
           newEdge->n1 = (i-1) * gridINT[i].size() + j;
           newEdge->diff = abs(gridINT[i][j] - gridINT[(i-1)][j]);
           mmap.insert(make_pair(newEdge->diff, newEdge));
        }
  printf("HI4\n");
  fflush(stdout);

        if (i != gridINT.size()-1) {
           newEdge = new Edge;
           newEdge->n1 = i * gridINT[i].size() + j;
           newEdge->n2 = (i+1) * gridINT[i].size() + j;
           newEdge->diff = abs(gridINT[i][j] - gridINT[i+1][j]);
           mmap.insert(make_pair(newEdge->diff, newEdge));

           newEdge = new Edge;
           newEdge->n2 = i*gridINT[i].size() + j;
           newEdge->n1 = (i+1)*gridINT[i].size() + j;
           newEdge->diff = abs(gridINT[i][j] - gridINT[i+1][j]);
           mmap.insert(make_pair(newEdge->diff, newEdge));
        }
  printf("HI3\n");
  fflush(stdout);

        if (j != 0) {
           newEdge = new Edge;
           newEdge->n1 = i*gridINT[i].size() + j;
           newEdge->n2 = i*gridINT[i].size() + j - 1;
           newEdge->diff = abs(gridINT[i][j] - gridINT[i][j-1]);
           mmap.insert(make_pair(newEdge->diff, newEdge));

           newEdge = new Edge;
           newEdge->n2 = i*gridINT[i].size() + j;
           newEdge->n1 = i*gridINT[i].size() + j - 1;
           newEdge->diff = abs(gridINT[i][j] - gridINT[i][j-1]);
           mmap.insert(make_pair(newEdge->diff, newEdge));
        }
  printf("HI2\n");
  fflush(stdout);

        if (j != gridINT[i].size()-1) {
           newEdge = new Edge;
           newEdge->n1 = i*gridINT[i].size() + j;
           newEdge->n2 = i*gridINT[i].size() + j + 1;
           newEdge->diff = abs(gridINT[i][j] - gridINT[i][j+1]);
           mmap.insert(make_pair(newEdge->diff, newEdge));

           newEdge = new Edge;
           newEdge->n2 = i*gridINT[i].size() + j;
           newEdge->n1 = i*gridINT[i].size() + j + 1;
           newEdge->diff = abs(gridINT[i][j] - gridINT[i][j+1]);
           mmap.insert(make_pair(newEdge->diff, newEdge));
        }
     }
  }
  printf("HI1\n");
  fflush(stdout);

  disjoint = new Disjoint(mmap.size());

  for (mmit = mmap.rbegin(); mmit != mmap.rend(); mmit++) {
    if (disjoint->Find(mmit->second->n1) != disjoint->Find(mmit->second->n2)) {
       sum += mmit->first;
       disjoint->Union(disjoint->Find(mmit->second->n1), disjoint->Find(mmit->second->n2));
    }
  }

  return sum;
}
