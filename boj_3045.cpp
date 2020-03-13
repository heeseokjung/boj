#include <cstdio>
#include <cstdlib>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Node {
    int id;
    struct Node* prev;
    struct Node* next;
}Node;

int N, M;
vector<pair<char, pair<int, int> > > cmd;
Node* head;
Node* pos[500001];
int dp[500001];
int past[500001];
bool valid[500001];
#define inf 1000000

void init() {
    head = (Node*)malloc(sizeof(Node));
    head->id = 1;
    pos[1] = head;
    Node* p = head;
    for(int i = 2; i <= N; ++i) {
        Node* tmp = (Node*)malloc(sizeof(Node));
        tmp->id = i;
        pos[i] = tmp;
        p->next = tmp;
        tmp->prev = p;
        p = tmp;
    }
    p->next = head;
    head->prev = p;
}

Node* remove(Node* p) {
    if(p == head)
        head = p->next;
    p->next->prev = p->prev;
    p->prev->next = p->next;
    return p;
}

void insert_front(Node* x, Node* y) {
    if(y == head)
        head = x;
    x->next = y;
    x->prev = y->prev;
    y->prev = x;
    x->prev->next = x;
}

void insert_back(Node* x, Node* y) {
    x->next = y->next;
    x->prev = y;
    y->next = x;
    x->next->prev = x;
}

void runcmd() {
    for(int i = 0; i < M; ++i) {
        char c = cmd[i].first;
        int x = cmd[i].second.first;
        int y = cmd[i].second.second;
        switch(c) {
            case 'A': {
                Node* p = remove(pos[x]);
                insert_front(p, pos[y]);
                break;
            }
            case 'B': {
                Node* p = remove(pos[x]);
                insert_back(p, pos[y]);
                break;
            }
            default: 
                break;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    cmd.reserve(M);
    getchar();
    for(int i = 0; i < M; ++i) {
        char c;
        int x, y;
        scanf("%c %d %d", &c, &x, &y);
        cmd.push_back(make_pair(c, pair<int, int>(x, y)));
        getchar();
    }

    init();
    runcmd();

    dp[0] = 0;
    for(int i = 1; i <= N; ++i)
        dp[i] = inf;
    
    int mx = 0, k;
    Node* p = head;
    for(int i = 0; i < N; ++i) {
        int d = (int)(upper_bound(dp, dp + N, p->id) - dp);
        dp[d] = p->id;
        past[p->id] = dp[d-1];
        mx = (mx < d) ? d : mx;
        p = p->next;
    }
    k = N - mx;

    vector<int> v;
    int x = dp[mx];
    while(x) {
        valid[x] = true;
        v.push_back(x);
        x = past[x];
    }
    reverse(v.begin(), v.end());

    printf("%d\n", k);
    int i = 0, j = 1;
	while (i < mx) {
		if (j == v[i]) 
            ++i;
		else 
            printf("A %d %d\n", j, v[i]);
		++j;
	}
    int end = v.back();
    while(j <= N) {
        printf("B %d %d\n", j, end);
        end = j;
        ++j;
    }
    
    return 0;
}