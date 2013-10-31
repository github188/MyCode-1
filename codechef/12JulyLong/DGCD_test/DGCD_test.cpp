#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)


typedef struct struct_kdyenbxjdhd{
  int node, nodeMemory;
  int *edgeSize, *edgeMemory;
  int **edge;
}ListGraph;

ListGraph NewListGraph(int maxNode,int maxDegree){
  int i; ListGraph res;
  res.node=0; res.nodeMemory=maxNode;
  res.edgeSize   = (int*)malloc(maxNode*sizeof(int));
  res.edgeMemory = (int*)malloc(maxNode*sizeof(int));
  res.edge = (int**)malloc(maxNode*sizeof(int*));
  rep(i,maxNode) res.edgeMemory[i]=maxDegree;
  if(maxDegree) rep(i,maxNode) res.edge[i]=(int*)malloc(maxDegree*sizeof(int));
  return res;
}

void DeleteListGraph(ListGraph g){
  int i;
  rep(i,g.nodeMemory) if(g.edgeMemory[i]) free(g.edge[i]);
  free(g.edgeSize); free(g.edgeMemory); free(g.edge);
}

void ListGraphSetEmpty(ListGraph *g,int node){
  int i;
  g->node = node;
  rep(i,node) g->edgeSize[i]=0;
}

void ListGraphAddEdge(ListGraph *g,int node1,int node2){
  int s=g->edgeSize[node1]++;
  g->edge[node1][s]=node2;
}

void ListGraphAddBidirectedEdge(ListGraph *g,int node1,int node2){
  int s1,s2;
  if(node1==node2){
    s1=g->edgeSize[node1]++;
    g->edge[node1][s1]=node2;
  } else {
    s1=g->edgeSize[node1]++, s2=g->edgeSize[node2]++;
    g->edge[node1][s1]=node2; g->edge[node2][s2]=node1;
  }
}

void ListGraphOneEdgeReallocEasy(ListGraph *g,int k,int size,int fg){
  if(fg==1 && g->edgeMemory[k]>=size) return;
  if(g->edgeMemory[k]==size) return;
  if(g->edgeMemory[k]) free(g->edge[k]);
  g->edgeMemory[k]=size;
  g->edge[k] = (int*)malloc(size*sizeof(int));
}

void ListGraphSetDirectEdges(ListGraph *g,int from[],int to[],int size){
  int i,n=g->node;
  rep(i,n) g->edgeSize[i]=0;

  rep(i,size) g->edgeSize[from[i]]++;
  rep(i,n) {ListGraphOneEdgeReallocEasy(g,i,g->edgeSize[i],1); g->edgeSize[i]=0;}
  rep(i,size) ListGraphAddEdge(g,from[i],to[i]);
}

void ListGraphSetBidirectEdges(ListGraph *g,int from[],int to[],int size){
  int i,n=g->node;
  rep(i,n) g->edgeSize[i]=0;

  rep(i,size) g->edgeSize[from[i]]++, g->edgeSize[to[i]]++;
  rep(i,n) {ListGraphOneEdgeReallocEasy(g,i,g->edgeSize[i],1); g->edgeSize[i]=0;}
  rep(i,size) ListGraphAddBidirectedEdge(g,from[i],to[i]);
}

/* åãã¼ãã«ã¤ãã¦ï¼ãããã«ã¼ãã¨ããé¨åæ¨ã®ãµã¤ãºãæ±ãã */
void ListGraphGetSubtreeSize(ListGraph *g, int root, int size[], void *workMemory){
  int i, j, k, l, n=g->node;
  int *parent, *stack, stack_size;

  parent = (int*)workMemory; workMemory = (void*)(parent+n);
  stack  = (int*)workMemory; workMemory = (void*)(stack+n);

  stack_size = 0;
  stack[stack_size++] = root;
  parent[root] = -1;

  rep(l,stack_size){
    k = stack[l];
    rep(i,g->edgeSize[k]){
      j = g->edge[k][i];
      if(parent[k]==j) continue;
      stack[stack_size++] = j;
      parent[j] = k;
    }
  }

  for(l=stack_size-1;l>=0;l--){
    k = stack[l];
    size[k] = 1;
    rep(i,g->edgeSize[k]){
      j = g->edge[k][i];
      if(parent[k]==j) continue;
      size[k] += size[j];
    }
  }
}

/* åãã¼ãã«ã¤ãã¦ï¼ã«ã¼ãããã®è·é¢ãæ±ãã */
void ListGraphGetDepth(ListGraph *g, int root, int depth[], void *workMemory){
  int i, j, k, l, n=g->node;
  int *parent, *stack, stack_size;

  stack  = (int*)workMemory; workMemory = (void*)(stack+n);

  stack_size = 0;
  stack[stack_size++] = root;
  rep(i,n) depth[i] = -1;
  depth[root] = 0;

  rep(l,stack_size){
    k = stack[l];
    rep(i,g->edgeSize[k]){
      j = g->edge[k][i];
      if(depth[j]>=0) continue;
      stack[stack_size++] = j;
      depth[j] = depth[k]+1;
    }
  }
}

/* dest[i][j] : å¯¾å¿ãããã¼ãã§ç§»åããåã®ï¼ãªãªã¸ãã«ã®ã°ã©ãã§ã®ãã¼ãçªå· */
/* ãªãªã¸ãã«ã®ãã¼ãiã«å¯¾å¿ããã®ã¯ï¼HLDã®ãã¼ãcnvA[i]ã®ï¼arr[cnvB[i]] */
/* root = 0 */
typedef struct struct_kdyenbxjdhdl{
  ListGraph g;
  int **src, **dest, **arr;
  int *cnvA, *cnvB, *arrLen, *parentE, *arrMemory;
}ListGraphHLD;

ListGraphHLD NewListGraphHLD(int maxNode, int maxDegree){
  int i; ListGraphHLD res;
  res.g = NewListGraph(maxNode, maxDegree);
  res.cnvA   = (int*)malloc(maxNode*sizeof(int));
  res.cnvB   = (int*)malloc(maxNode*sizeof(int));
  res.arrLen = (int*)malloc(maxNode*sizeof(int));
  res.parentE= (int*)malloc(maxNode*sizeof(int));
  res.src    = (int**)malloc(maxNode*sizeof(int*));
  res.dest   = (int**)malloc(maxNode*sizeof(int*));
  res.arr    = (int**)malloc(maxNode*sizeof(int*));
  if(maxDegree) rep(i,maxNode){
    res.src[i]  = (int*)malloc(maxDegree*sizeof(int));
    res.dest[i] = (int*)malloc(maxDegree*sizeof(int));
  }

  res.arrMemory = (int*)malloc(maxNode*sizeof(int));
  rep(i,maxNode) res.arrMemory[i] = 0;

  return res;
}

void ListGraphHLDEdgeMemoryExpandEasy(ListGraphHLD *g,int k,int size,int fg){
  int i, use, old, *tmp;

  if(size==-1){
    size = g->g.edgeMemory[k] * 2;
    if(size < 5) size = 5;
  }

  if(fg==1 && g->g.edgeMemory[k]>=size) return;
  if(g->g.edgeMemory[k]==size) return;

  old = g->g.edgeMemory[k];
  use = g->g.edgeSize[k];
  g->g.edgeMemory[k] = size;

  tmp = (int*)malloc(size*sizeof(int));
  rep(i,use) tmp[i] = g->g.edge[k][i];
  if(old) free(g->g.edge[k]);
  g->g.edge[k] = tmp;

  tmp = (int*)malloc(size*sizeof(int));
  rep(i,use) tmp[i] = g->src[k][i];
  if(old) free(g->src[k]);
  g->src[k] = tmp;

  tmp = (int*)malloc(size*sizeof(int));
  rep(i,use) tmp[i] = g->dest[k][i];
  if(old) free(g->dest[k]);
  g->dest[k] = tmp;
}

/* node1 -> node2 */
void ListGraphHLDAddBidirectedEdgeAdv(ListGraphHLD *g, int node1, int node2, int o_node1, int o_node2){
  int s1 = g->g.edgeSize[node1], s2 = g->g.edgeSize[node2];

  if(g->g.edgeMemory[node1] < s1 + 1) ListGraphHLDEdgeMemoryExpandEasy(g, node1, -1, 1);
  if(g->g.edgeMemory[node2] < s2 + 1) ListGraphHLDEdgeMemoryExpandEasy(g, node2, -1, 1);

  g->g.edge[node1][s1] = node2;
  g->g.edge[node2][s2] = node1;
  g->src[node1][s1] = g->dest[node2][s2] = o_node1;
  g->src[node2][s2] = g->dest[node1][s1] = o_node2;
  g->parentE[node2] = s2;

  g->g.edgeSize[node1]++; g->g.edgeSize[node2]++;
}

void ListGraphHeavyLightDecomposition(ListGraph *g, ListGraphHLD *res, int root, void *workMemory){
  int i, j, k, next, now, n = g->node;
  int stack_size, array_size;
  int *subtreeSize, *added, *stack, *array;

  subtreeSize = (int*)workMemory; workMemory = (void*)(subtreeSize+n);
  added       = (int*)workMemory; workMemory = (void*)(added+n);
  stack       = (int*)workMemory; workMemory = (void*)(stack+n);
  array       = (int*)workMemory; workMemory = (void*)(array+n);

  ListGraphGetSubtreeSize(g, root, subtreeSize, workMemory);

  now = 0;
  rep(i,n) added[i] = 0;
  stack_size = 0;
  stack[stack_size++] = root;

  rep(i,n) res->g.edgeSize[i] = 0;
  res->g.node = 0;
  res->cnvA[root] = res->g.node++;
  res->parentE[res->cnvA[root]] = -1;

  while(stack_size){
    array_size = 0;
    k = stack[--stack_size];
    now = res->cnvA[k];

    while(k>=0){
      added[k] = 1;
      array[array_size++] = k;

      next = -1;
      rep(i,g->edgeSize[k]){
        j = g->edge[k][i];
        if(added[j]) continue;
        if(2*subtreeSize[j] >= subtreeSize[k]){
          next = j;
        } else {
          res->cnvA[j] = res->g.node++;
          ListGraphHLDAddBidirectedEdgeAdv(res, res->cnvA[k], res->cnvA[j], k, j);
          stack[stack_size++] = j;
        }
      }
      res->cnvA[next] = res->cnvA[k];
      k = next;
    }

    if(res->arrMemory[now] < array_size){
      if(res->arrMemory[now]) free(res->arr[now]);
      res->arrMemory[now] = array_size;
      res->arr[now] = (int*)malloc(array_size * sizeof(int));
    }
    res->arrLen[now] = array_size;
    rep(i,array_size){
      res->arr[now][i] = array[i];
      res->cnvB[array[i]] = i;
    }
  }
}



int GCD(int a,int b){
  int r;
  if(a<0) a=-a;
  if(b<0) b=-b;
  while(a){r=b; b=a; a=r%a;}
  return b;
}

void segtree_build(int node, int left, int right, int arr[], int sum[], int gcd[]){
  int sz = right - left;
  int n1 = node*2 + 1, n2 = node*2 + 2;

  if(sz == 1){
    sum[node] = gcd[node] = arr[left];
    if(gcd[node] < 0) gcd[node] = -gcd[node];
    return;
  }
  segtree_build(n1, left, left+sz/2, arr, sum, gcd);
  segtree_build(n2, left+sz/2, right, arr, sum, gcd);
  sum[node] = sum[n1] + sum[n2];
  gcd[node] = GCD(gcd[n1], gcd[n2]);
}

void segtree_add(int node, int left, int right, int ind, int val, int arr[], int sum[], int gcd[]){
  int sz = right - left;
  int n1 = node*2 + 1, n2 = node*2 + 2;

  if(ind < left || ind >= right) return;
  if(sz==1){
    arr[left] += val;
    sum[node] = gcd[node] = arr[left];
    if(gcd[node] < 0) gcd[node] = -gcd[node];
    return;
  }
  segtree_add(n1, left, left+sz/2, ind, val, arr, sum, gcd);
  segtree_add(n2, left+sz/2, right, ind, val, arr, sum, gcd);
  sum[node] = sum[n1] + sum[n2];
  gcd[node] = GCD(gcd[n1], gcd[n2]);
}

int segtree_sum(int node, int left, int right, int a, int b, int arr[], int sum[], int gcd[]){
  int sz = right - left;
  int n1 = node*2 + 1, n2 = node*2 + 2;
  int s1, s2;

  if(a < left) a = left;
  if(b > right) b = right;
  if(a >= right || b <= left) return 0;
  if(a==left && b==right) return sum[node];

  s1 = segtree_sum(n1, left, left+sz/2, a, b, arr, sum, gcd);
  s2 = segtree_sum(n2, left+sz/2, right, a, b, arr, sum, gcd);

  return s1+s2;
}

int segtree_gcd(int node, int left, int right, int a, int b, int arr[], int sum[], int gcd[]){
  int sz = right - left;
  int n1 = node*2 + 1, n2 = node*2 + 2;
  int g1, g2;

  if(a < left) a = left;
  if(b > right) b = right;
  if(a >= right || b <= left) return 0;
  if(a==left && b==right) return gcd[node];

  g1 = segtree_gcd(n1, left, left+sz/2, a, b, arr, sum, gcd);
  g2 = segtree_gcd(n2, left+sz/2, right, a, b, arr, sum, gcd);

  return GCD(g1,g2);
}


int arrMem[120000];
int sumMem[420000], gcdMem[420000];
int *sum[120000], *gcd[120000], *arr[120000];
int depth[120000];

int A[120000];
int a[120000], b[120000];


int get_gcd(int k, int a, int b, int n){
  int s, g;
  if(a > b) s=a, a=b, b=s;

  s = segtree_sum(0, 0, n, 0, a+1, arr[k], sum[k], gcd[k]);
  g = segtree_gcd(0, 0, n, a+1, b+1, arr[k], sum[k], gcd[k]);

//  printf("sum %d : gcd %d (%d %d %d)\n",s,g,k,a,b);

  return GCD(s,g);
}

void unionInit(int d[],int s){int i;rep(i,s)d[i]=i;}
int unionGet(int d[],int n){int t=n,k;while(d[t]!=t)t=d[t];while(d[n]!=n)k=d[n],d[n]=t,n=k;return n;}
int unionConnect(int d[],int a,int b){a=unionGet(d,a);b=unionGet(d,b);if(a==b)return 0;d[a]=b;return 1;}

int unionInd[51000];

int main(){
    freopen("1.txt","r",stdin);
    freopen("2(2).txt","w",stdout);
  int i, j, k, l, res;
  int st1, st2;
  int N, u, v, Q, d, q;
  int ss, ee, tt, g1, g2;
  int t_s, t_g;
  char com[10];

  ListGraph g = NewListGraph(51000, 10);
  ListGraphHLD hld = NewListGraphHLD(51000, 10);
  void *workMemory = malloc(20000000);

  assert( scanf("%d",&N)==1 );
  assert( 1 <= N && N <= 50000 );

  rep(i,N-1){
    assert( scanf("%d%d",a+i,b+i)==2 );
    assert( 0<=a[i] && a[i]<N && 0<=b[i] && b[i]<N );
  }

  if(1){
    unionInit(unionInd, N);
    rep(i,N-1) assert(unionConnect(unionInd,a[i],b[i])==1);
  }

  rep(i,N){
    assert( scanf("%d",A+i)==1 );
    assert( 1 <= A[i] && A[i] <= 10000 );
  }

  g.node = N;
  ListGraphSetBidirectEdges(&g, a, b, N-1);
  ListGraphHeavyLightDecomposition(&g, &hld, 0, workMemory);
  ListGraphGetDepth(&(hld.g), 0, depth, workMemory);

  st1 = st2 = 0;
  rep(k, hld.g.node){
    arr[k] = arrMem + st1;
    sum[k] = sumMem + st2;
    gcd[k] = gcdMem + st2;
    st1 += hld.arrLen[k] + 1;
    st2 += 4 * (hld.arrLen[k] + 1);

    arr[k][0] = A[hld.arr[k][0]];
    REP(i,1,hld.arrLen[k]) arr[k][i] = A[hld.arr[k][i]] - A[hld.arr[k][i-1]];
    segtree_build(0, 0, hld.arrLen[k], arr[k], sum[k], gcd[k]);
  }

  assert( scanf("%d",&Q)==1 );
  assert( 1<=Q && Q<=50000 );
  rep(q,Q){
    assert( scanf("%s",com)==1 );
    assert(com[1] == '\0');
    if(com[0]=='F'){
      assert( scanf("%d%d",&u,&v)==2 );
      assert(0 <= u && u < N && 0 <= v && v < N );
      res = 0;
      for(;;){
        if(hld.cnvA[u] == hld.cnvA[v]){
          if(hld.cnvB[u] > hld.cnvB[v]) k=u, u=v, v=k;
          k = get_gcd(hld.cnvA[u], hld.cnvB[u], hld.cnvB[v], hld.arrLen[hld.cnvA[u]]);
          res = GCD(res, k);
          break;
        }
        if(depth[hld.cnvA[u]] < depth[hld.cnvA[v]]) k=u, u=v, v=k;
        ss = hld.cnvA[u]; ee = hld.parentE[ss]; tt = hld.g.edge[ss][ee];
        k = get_gcd(ss, hld.cnvB[u], hld.cnvB[hld.src[ss][ee]], hld.arrLen[ss]);
        res = GCD(res, k);
        u = hld.dest[ss][ee];
      }
      printf("%d\n",res);
    } else if(com[0]=='C'){
      assert( scanf("%d%d%d",&u,&v,&d)==3 );
      assert(0 <= u && u < N && 0 <= v && v < N );
      assert(0 <= d && d <= 10000);
      if(d) for(;;){
        if(hld.cnvA[u] == hld.cnvA[v]){
          if(hld.cnvB[u] > hld.cnvB[v]) k=u, u=v, v=k;
          k = hld.cnvA[u]; l = hld.arrLen[k];
          segtree_add(0, 0, l, hld.cnvB[u], d, arr[k], sum[k], gcd[k]);
          segtree_add(0, 0, l, hld.cnvB[v]+1, -d, arr[k], sum[k], gcd[k]);
          break;
        }
        if(depth[hld.cnvA[u]] < depth[hld.cnvA[v]]) k=u, u=v, v=k;
        ss = hld.cnvA[u]; ee = hld.parentE[ss]; tt = hld.g.edge[ss][ee];
        k = ss; l = hld.arrLen[k];
        g1 = hld.cnvB[u]; g2 = hld.cnvB[hld.src[ss][ee]];
        if(g1 > g2) i = g1, g1 = g2, g2 = i;
        segtree_add(0, 0, l, g1, d, arr[k], sum[k], gcd[k]);
        segtree_add(0, 0, l, g2+1, -d, arr[k], sum[k], gcd[k]);
        u = hld.dest[ss][ee];
      }
    } else {
      assert(0);
    }
  }

  return 0;
}
