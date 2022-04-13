#include <bits/stdc++.h>

using namespace std;
struct Node
{
    int data;
    Node *next;
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
    void push_front(int d)
    {
        Node *temp = new Node;
        temp->data = d;

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
    void push_back(int data)
    {
        Node *tmp = new Node;
        tmp->data = data;
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

        /* Advance 'fast' two nodes, and advance 'slow' one node */
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
            l[i].print();
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
    void add_edge(int x, int y, bool undir = true)
    {
        a[x][y] = 1;
        if (undir)
            a[y][x] = 1;
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