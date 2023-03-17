#include <stdio.h>
#include<stdlib.h>
struct Array {
    int a[10];
    int size;
    int length;
};
void display(struct Array arr) {
    printf("Elements in the array: \n");
    for (int i = 0; i < arr.length; i++) {
        printf("%d ", arr.a[i]);
    }
}
void append(struct Array* arr, int x) {
    if (arr->length < arr->size) {
        arr->a[arr->length] = x;
    }
    arr->length++;
}
void deleteElement(struct Array* arr, int index) {
    if (index >= arr->length || index < 0) {
        return;
    }
    else {
        for (int i = index; i < arr->length - 1; i++) {
            arr->a[i] = arr->a[i + 1];
        }
        arr->length--;
    }
}
void insert(struct Array* arr, int index, int x) {
    if (index >= arr->size || index < 0) {
        return;
    }
    else {
        for (int i = arr->length; i > index; i--) {
            arr->a[i] = arr->a[i - 1];
        }
        arr->a[index] = x;
        arr->length++;
    }
}
int linearsearch(struct Array arr, int x) {
    for (int i = 0; i < arr.length; i++) {
        if (x == arr.a[i])
            return i;
    }
    return -1;
}
int bsearch(struct Array arr, int x) {
    int l, h, mid;
    l = 0;
    h = arr.length - 1;
    
    while (l <= h) {
        mid = (l + h) / 2;
        if (x == arr.a[mid])
            return mid;
        else if (x < arr.a[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}
struct Array* mergearray(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length) {
        if (arr1->a[i] < arr2->a[j])
            arr3->a[k++] = arr1->a[i++];
        else
            arr3->a[k++] = arr2->a[j++];
    }
    for(;i<arr1->length;i++)
        arr3->a[k++] = arr1->a[i];
    for (; j < arr2->length; j++)
        arr3->a[k++] = arr2->a[j];
    arr3->length = arr1->length + arr2->length;
    arr3->size = 10;
    return arr3;
}
struct Array* unionarray(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length) {
        if (arr1->a[i] < arr2->a[j])
            arr3->a[k++] = arr1->a[i++];
        else if (arr2->a[j] < arr1->a[i])
            arr3->a[k++] = arr2->a[j++];
        else {
            arr3->a[k++] = arr1->a[i++];
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->a[k++] = arr1->a[i];
    for (; j < arr2->length; j++)
        arr3->a[k++] = arr2->a[j];
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
struct Array* interarray(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length) {
        if (arr1->a[i] < arr2->a[j])
            i++;
        else if (arr2->a[j] < arr1->a[i])
            j++;
        else {
            arr3->a[k++] = arr1->a[i++];
            j++;
        }
    }
  
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
struct Array* diffarray(struct Array* arr1, struct Array* arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));
    while (i < arr1->length && j < arr2->length) {
        if (arr1->a[i] < arr2->a[j])
            arr3->a[k++] = arr1->a[i++];
        else if (arr2->a[j] < arr1->a[i])
            j++;
        else {
            i++;
            j++;
        }
    }
    for (; i < arr1->length; i++)
        arr3->a[k++] = arr1->a[i];
    arr3->length = k;
    arr3->size = 10;
    return arr3;
}
int main()
{
    struct Array arr1 = { {1,2,3,4,5},10,5 };
    struct Array arr2 = { {5,7,8,9,10},10,5 };
    struct Array *arr3;

    arr3 = diffarray(&arr1, &arr2);
    display(*arr3);
    return 0;
}

