#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    int weight;
    Node *next;
};

class Disjoint_Set
{
    int *height;
    int *parent;
    int n;

public:
    Disjoint_Set(int n)
    {
        this->n = n;
        height = new int[n]{0};
        parent = new int[n];
        makeset();
    }
    void makeset()
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y)
    {
        int l = find(x);
        int r = find(y);

        if (l == r)
            return;
        if (height[l] < height[r])
            parent[l] = r;
        else if (height[l] > height[r])
            parent[r] = l;
        else
        {
            parent[r] = l;
            height[l]++;
        }
    }
    friend class Graph_Matrix;
};

class List
{
private:
    Node *head, *tail;

public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    Node *get_head()
    {
        return head;
    }
    void push_front(int d, int weight = 0)
    {
        Node *temp = new Node;
        temp->data = d;
        temp->weight = weight;

        if (head == NULL)
        {
            head = temp;
            tail = temp;
            head->next = NULL;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void push_back(int data, int weight = 0)
    {
        Node *tmp = new Node;
        tmp->data = data;
        tmp->weight = weight;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    int front()
    {
        if (head == NULL && tail == NULL)
            return -1;
        return head->data;
    }
    int back()
    {
        if (tail == NULL && head == NULL)
            return -1;
        return tail->data;
    }

    void pop_back()
    {
        if (tail == NULL && head == NULL)
            return;
        Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
        tail = temp;
    }
    void pop_front()
    {
        if (head == NULL && tail == NULL)
            return;
        Node *t = head;
        head = head->next;
        delete t;
    }

    bool empty()
    {
        if (head == NULL and tail == NULL)
            return true;
        return false;
    }
    void print()
    {
        Node *temp = head->next;
        cout << head->data;
        while (temp != NULL)
        {
            cout << "->" << temp->data;
            temp = temp->next;
        }
        cout << endl;
    }
    int size()
    {
        Node *t = head;
        int c = 0;
        while (t != NULL)
        {
            c++;
            t = t->next;
        }
        return c;
    }

    Node *SortedMerge(Node *a, Node *b)
    {
        Node *result = NULL;

        if (a == NULL)
            return (b);
        else if (b == NULL)
            return (a);

        if (a->data <= b->data)
        {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else
        {
            result = b;
            result->next = SortedMerge(a, b->next);
        }
        return (result);
    }

    void FrontBackSplit(Node *source,
                        Node **frontRef, Node **backRef)
    {
        Node *fast;
        Node *slow;
        slow = source;
        fast = source->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *frontRef = source;
        *backRef = slow->next;
        slow->next = NULL;
    }

    void MergeSort(Node **headRef)
    {
        Node *head = *headRef;
        Node *a;
        Node *b;

        /* Base case -- length 0 or 1 */
        if ((head == NULL) || (head->next == NULL))
        {
            return;
        }

        /* Split head into 'a' and 'b' sublists */
        FrontBackSplit(head, &a, &b);

        /* Recursively sort the sublists */
        MergeSort(&a);
        MergeSort(&b);

        /* answer = merge the two sorted lists together */
        *headRef = SortedMerge(a, b);
    }

    void sort_list()
    {
        MergeSort(&head);
    }
};

class Stack
{
    List l;

public:
    Stack() {}
    void push(int x)
    {
        l.push_front(x);
    }
    void pop()
    {
        l.pop_front();
    }
    bool empty()
    {
        return l.empty();
    }
    int top()
    {
        return l.front();
    }
    void print()
    {
        l.print();
    }
};

class Queue
{
    List l;

public:
    Queue() {}
    void push(int x)
    {
        l.push_back(x);
    }
    void pop()
    {
        if (l.get_head() == NULL)
            return;
        l.pop_front();
    }
    bool empty()
    {
        return l.empty();
    }
    int front()
    {
        return l.front();
    }
    void print()
    {
        l.print();
    }
};

class Graph_List
{
    int v;
    List *l;

public:
    Graph_List(int v)
    {
        this->v = v;
        l = new List[v];
    }
    void add_edge(int x, int y, bool undir = true)
    {
        l[x].push_back(y);
        if (undir)
            l[y].push_back(x);
    }

    void Sort_list()
    {
        for (int i = 0; i < v; i++)
            l[i].sort_list();
    }

    void print()
    {
        for (int i = 0; i < v; i++)
            l[i].sort_list();

        for (int i = 0; i < v; i++)
        {
            cout << "|| " << i << " ||"
                 << "-->>:";
            if (l[i].get_head())
                l[i].print();
            else
                cout << endl;
        }
        cout << endl;
    }
    bool *vis = new bool[v];

    void bfs(int s = 0)
    {
        for (int i = 0; i < v; i++)
            vis[i] = 0;
        for (int i = 0; i < v; i++)
            l[i].sort_list();
        Queue q;
        vis[s] = true;
        q.push(s);

        while (!q.empty())
        {
            int f = q.front();
            cout << f << " ";
            q.pop();
            List j = l[f];
            Node *t = j.get_head();
            while (t != NULL)
            {
                if (!vis[t->data])
                {
                    vis[t->data] = true;
                    q.push(t->data);
                }

                t = t->next;
            }
        }
    }
    void Dfs(int s)
    {
        vis[s] = true;
        cout << s << " ";
        List j = l[s];
        Node *t = j.get_head();
        while (t != NULL)
        {
            if (!vis[t->data])
                Dfs(t->data);
            t = t->next;
        }
    }
    void dfs(int s = 0)
    {
        for (int i = 0; i < v; i++)
            l[i].sort_list();
        for (int i = 0; i < v; i++)
            vis[i] = 0;
        Dfs(s);
    }

    void topo_sort()
    {
        for (int i = 0; i < v; i++)
            l[i].sort_list();
        int ind[v] = {0};

        for (int i = 0; i < v; i++)
        {
            Node *t = l[i].get_head();
            while (t != NULL)
            {
                ind[t->data]++;
                t = t->next;
            }
        }

        Queue q;
        for (int i = 0; i < v; i++)
            if (!ind[i])
                q.push(i);

        while (!q.empty())
        {
            int f = q.front();
            cout << f << " ";
            q.pop();

            List j = l[f];
            Node *t = j.get_head();
            while (t != NULL)
            {
                ind[t->data]--;
                if (!ind[t->data])
                    q.push(t->data);
                t = t->next;
            }
        }
    }
};

class Graph_Matrix
{
    int **a;
    int v;

public:
    Graph_Matrix(int v)
    {
        this->v = v;
        a = new int *[v];
        for (int i = 0; i < v; i++)
            a[i] = new int[v];
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                a[i][j] = 0;
    }
    bool *vis = new bool[v];
    void add_edge(int x, int y, int w = 1, bool undir = true)
    {
        a[x][y] = w;
        if (undir)
            a[y][x] = w;
    }
    void print()
    {
        for (int i = 0; i < v; i++)
        {
            cout << " | ";
            for (int j = 0; j < v; j++)
            {
                cout << a[i][j] << " | ";
            }
            cout << endl;
        }
    }

    int **get_mat()
    {
        int **x = new int *[v];
        for (int i = 0; i < v; i++)
            x[i] = new int[v];
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                x[i][j] = a[i][j];
        return x;
    }

    int kruskal()
    {
        int cost[v][v];
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
            {
                if (!a[i][j])
                    cost[i][j] = INT_MAX;
                else
                    cost[i][j] = a[i][j];
            }
        int mincost = 0;

        Disjoint_Set s(v);

        // Include minimum weight edges one by one
        int edge_count = 0;
        while (edge_count < v - 1)
        {
            int min = INT_MAX, a = -1, b = -1;
            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < v; j++)
                {
                    if (s.find(i) != s.find(j) && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
            mincost += min;
            s.unite(a, b);

            cout << "Edge " << edge_count++ << ":(" << a << "," << b << ")  cost:" << min << endl;
        }
        cout << "MINIMUM COST IS :->";
        return mincost;
    }

    bool prim_Util(int u, int v, bool *x)
    {
        if (u == v)
            return false;
        if (x[u] == false && x[v] == false)
            return false;
        else if (x[u] == true && x[v] == true)
            return false;
        return true;
    }
    int prim()
    {

        for (int i = 0; i < v; i++)
            vis[i] = 0;

        int cost[v][v];
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
            {
                if (!a[i][j])
                    cost[i][j] = INT_MAX;
                else
                    cost[i][j] = a[i][j];
            }
        int mincost = 0;
        vis[0] = true;

        int edge_count = 0;
        while (edge_count < v - 1)
        {

            int min = INT_MAX, a = -1, b = -1;
            for (int i = 0; i < v; i++)
            {
                for (int j = 0; j < v; j++)
                {
                    if (cost[i][j] < min)
                    {
                        if (prim_Util(i, j, vis))
                        {
                            min = cost[i][j];
                            a = i;
                            b = j;
                        }
                    }
                }
            }
            if (a != -1 && b != -1)
            {
                mincost += min;
                cout << "Edge " << edge_count++ << ":(" << a << "," << b << ")  cost:" << min << endl;
                vis[b] = vis[a] = true;
            }
        }
        cout << "MINIMUM COST IS :->";
        return mincost;
    }

    int djikstra_Util_1(int dist[], bool visited[])
    {
        int min = INT_MAX;
        int min_index;
        for (int i = 0; i < v; i++)
            if (dist[i] <= min and visited[i] == false)
                min = dist[i], min_index = i;
        return min_index;
    }

    void djikstra_Util_2(int dist[])
    {
        cout << "Vertex \t Distance from Source" << endl;
        for (int i = 0; i < v; i++)
            cout << i << " \t\t" << dist[i] << endl;
    }

    void djikstra(int src)
    {
        int dist[v];
        for (int i = 0; i < v; i++)
            vis[i] = 0, dist[i] = INT_MAX;

        dist[src] = 0;

        for (int count = 0; count < v; count++)
        {
            int u = djikstra_Util_1(dist, vis);
            vis[u] = true;
            for (int V = 0; V < v; V++)

                if (!vis[V] && a[u][V] && dist[u] != INT_MAX && dist[u] + a[u][V] < dist[V])
                    dist[V] = dist[u] + a[u][V];
        }
        djikstra_Util_2(dist);
    }

    void floyd_warshal()
    {
        int dist[v][v];
        int i, j, k;
        for (i = 0; i < v; i++)
        {
            for (j = 0; j < v; j++)
            {
                if (!a[i][j])
                    dist[i][j] = INT_MAX;
                else
                    dist[i][j] = a[i][j];
            }
        }

        for (k = 0; k < v; k++)
            for (i = 0; i < v; i++)
                for (j = 0; j < v; j++)
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

        for (i = 0; i < v; i++)
        {
            cout << "| ";
            for (j = 0; j < v; j++)
            {
                if (dist[i][j] = INT_MAX)
                    cout << "^ |";
                else
                    cout << dist[i][j] << " |";
            }
            cout << endl;
        }
    }

    void bfs(int source = 0)
    {
        Queue q;
        for (int i = 0; i < v; i++)
            vis[i] = 0;

        q.push(source);
        vis[source] = true;

        while (!q.empty())
        {
            int f = q.front();
            cout << f << " ";

            q.pop();
            for (int i = 0; i < v; i++)
            {
                if (a[f][i])
                {
                    if (!vis[i])
                    {
                        vis[i] = 1;
                        q.push(i);
                    }
                }
            }
        }
    }

    void Dfs(int s)
    {
        vis[s] = true;
        cout << s << " ";
        for (int i = 0; i < v; i++)
        {
            if (a[s][i])
            {
                if (!vis[i])
                {
                    Dfs(i);
                }
            }
        }
    }

    void dfs(int s = 0)
    {
        for (int i = 0; i < v; i++)
            vis[i] = 0;
        Dfs(s);
    }
    void topo_sort()
    {
        int indegree[v] = {0};
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                indegree[i] += a[j][i];
        Queue q;
        for (int i = 0; i < v; i++)
            if (indegree[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int f = q.front();
            cout << f << " ";
            q.pop();
            for (int i = 0; i < v; i++)
                if (a[f][i])
                {
                    indegree[i]--;
                    if (!indegree[i])
                        q.push(i);
                }
        }
    }
};

class Heap_min
{
    int *a;
    int size;
    int capacity;

public:
    Heap_min(int c)
    {
        capacity = c;
        a = new int[c]{0};
        size = 0;
    }

    int parent(int i)
    {
        return ((i - 1) / 2);
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int s = i;
        if (l < size and a[l] < a[i])
            s = l;
        if (r < size and a[r] < a[i])
            s = r;
        if (s != i)
        {
            swap(a[i], a[s]);
            heapify(s);
        }
    }
    void insert(int x)
    {
        if (size == capacity)
            return;
        size++;
        int i = size - 1;
        a[i] = x;

        while (i != 0 && a[parent(i)] > a[i])
        {
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }
    int extract_min()
    {
        if (size <= 0)
            return INT_MAX;
        if (size == 1)
        {
            size--;
            return a[0];
        }
        int x = a[0];
        a[0] = a[size - 1];
        size--;
        heapify(0);
        return x;
    }
    void decrease_index(int i, int n)
    {
        a[i] = n;
        while (i != 0 && a[parent(i)] > a[i])
        {
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }

    void remove(int i)
    {
        decrease_index(i, INT_MIN);
        extract_min();
    }

    int get_min()
    {
        return a[0];
    }
    void print()
    {
        for (int i = 0; i < size; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};

class Heap_max
{
    int *a;
    int size;
    int capacity;

public:
    Heap_max(int c)
    {
        capacity = c;
        a = new int[c]{0};
        size = 0;
    }

    int parent(int i)
    {
        return ((i - 1) / 2);
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }
    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int s = i;
        if (l < size and a[l] > a[i])
            s = l;
        if (r < size and a[r] > a[i])
            s = r;
        if (s != i)
        {
            swap(a[i], a[s]);
            heapify(s);
        }
    }
    void insert(int x)
    {
        if (size == capacity)
            return;
        size++;
        int i = size - 1;
        a[i] = x;

        while (i != 0 && a[parent(i)] < a[i])
        {
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }
    int extract_max()
    {
        if (size <= 0)
            return INT_MIN;
        if (size == 1)
        {
            size--;
            return a[0];
        }
        int x = a[0];
        a[0] = a[size - 1];
        size--;
        heapify(0);
        return x;
    }
    void increase_index(int i, int n)
    {
        a[i] = n;
        while (i != 0 && a[parent(i)] < a[i])
        {
            swap(a[i], a[parent(i)]);
            i = parent(i);
        }
    }

    void remove(int i)
    {
        increase_index(i, INT_MAX);
        extract_max();
    }

    int get_max()
    {
        return a[0];
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << a[i] << " ";
        cout << endl;
    }
};

class Array
{
    int n;
    int *a;

public:
    Array(int n)
    {
        this->n = n;
        a = new int[n]{0};
    }
    void make_array(int *arr)
    {
        for (int i = 0; i < n; i++)
            a[i] = arr[i];
    }

    void print()
    {
        for (int i = 0; i < n; i++)
            cout << a[i] << "  ";
        cout << endl;
    }

    int partition(int *arr, int low, int high)
    {

        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
            if (arr[j] < pivot)
            {
                i++;
                swap(arr[j], arr[i]);
            }
        }
        swap(arr[high], arr[i + 1]);
        return i + 1;
    }

    void qs(int *arr, int low, int high)
    {
        if (low < high)
        {
            int p = partition(a, low, high);
            qs(arr, low, p - 1);
            qs(arr, p + 1, high);
        }
    }
    void quick_sort()
    {
        qs(a, 0, n - 1);
    }

    void merge(int *arr, int low, int mid, int high)
    {
        int i = low;
        int j = mid + 1;
        int k = low;
        int b[high + 1];
        while (i <= mid && j <= high)
        {
            if (arr[i] < arr[j])
            {
                b[k] = a[i];
                i++;
                k++;
            }
            else
            {
                b[k] = arr[j];
                j++;
                k++;
            }
        }
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
        while (j <= high)
        {
            b[k] = arr[j];
            j++;
            k++;
        }

        for (int i = low; i <= high; i++)
            arr[i] = b[i];
    }
    void ms(int arr[], int low, int high)
    {
        int mid;
        if (low < high)
        {
            mid = (low + high) / 2;
            ms(arr, low, mid);
            ms(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }
    void merge_sort()
    {
        ms(a, 0, n - 1);
    }

    void heapify(int *arr, int n, int i)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if (left < n && arr[left] > arr[largest])
            largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }
    void hs(int *arr, int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);
        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[i], arr[0]);
            heapify(arr, i, 0);
        }
    }
    void heap_sort()
    {
        hs(a, n);
    }
};
