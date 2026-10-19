#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct MinHeap
{
    int *harr;
    int capacity;
    int heap_size;
};

struct MinHeap *createMinHeap(int capacity);
void MinHeapify(struct MinHeap *h, int i);
int extractMin(struct MinHeap *h);
void decreaseKey(struct MinHeap *h, int i, int new_val);
void deleteKey(struct MinHeap *h, int i);
void insertKey(struct MinHeap *h, int k);

int parent(int i)
{
    return (i - 1) / 2;
}
int left(int i)
{
    return 2 * i + 1;
}
int right(int i)
{
    return 2 * i + 2;
}
int getMin(struct MinHeap *h)
{
    return h->harr[0];
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *h = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    h->capacity = capacity;
    h->heap_size = 0;
    h->harr = (int *)malloc(capacity * sizeof(int));
    return h;
}

void insertKey(struct MinHeap *h, int k)
{
    if (h->heap_size == h->capacity)
    {
        printf("\nOverflow: Could not insertKey");
        return;
    }

    h->heap_size++;
    int i = h->heap_size - 1;
    h->harr[i] = k;

    while (i != 0 && h->harr[parent(i)] > h->harr[i])
    {
        swap(&h->harr[i], &h->harr[parent(i)]);
        i = parent(i);
    }
}

int extractMin(struct MinHeap *h)
{
    if (h->heap_size <= 0)
    {
        return INT_MAX;
    }

    if (h->heap_size == 1)
    {
        h->heap_size--;
        return h->harr[0];
    }

    int root = h->harr[0];
    h->harr[0] = h->harr[h->heap_size - 1];
    h->heap_size--;
    MinHeapify(h, 0);

    return root;
}

void MinHeapify(struct MinHeap *h, int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < h->heap_size && h->harr[l] < h->harr[i])
    {
        smallest = l;
    }

    if (r < h->heap_size && h->harr[r] < h->harr[smallest])
    {
        smallest = r;
    }

    if (i != smallest)
    {
        swap(&h->harr[i], &h->harr[smallest]);
        MinHeapify(h, smallest);
    }
}

void decreaseKey(struct MinHeap *h, int i, int new_val)
{
    h->harr[i] = new_val;

    while (i != 0 && h->harr[parent(i)] > h->harr[i])
    {
        swap(&h->harr[i], &h->harr[parent(i)]);
        i = parent(i);
    }
}

void deleteKey(struct MinHeap *h, int i)
{
    decreaseKey(h, i, INT_MIN);
    extractMin(h);
}

int main()
{
    struct MinHeap *h = createMinHeap(11);
    insertKey(h, 3);
    insertKey(h, 2);
    deleteKey(h, 1);
    insertKey(h, 15);
    insertKey(h, 5);
    insertKey(h, 4);
    insertKey(h, 45);

    printf("%d ", extractMin(h));
    printf("%d ", getMin(h));
    decreaseKey(h, 2, 1);

    printf("%d ", getMin(h));

    free(h->harr);
    free(h);
    return 0;
}