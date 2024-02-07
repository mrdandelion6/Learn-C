
void swap(int* arr, int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void bubble_sort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; i++) {
            if (arr[j-1] > arr[j]) {
                swap(arr, j-1, j);
            }
        }
    }
}

void selection_sort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        int current = i;
        for (int j = i; j < size; j++) {
            if(arr[current] > arr[j]) {
                current = j;
            }
        }
        swap(arr, i, current);
    }
}

void insertion_sort(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i; j > 0 && arr[j-1] > arr[j]; j--) {
            swap(arr, j-1, j);
        }
    }
}