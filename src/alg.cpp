// Copyright 2021 NNTU-CS
int UniBinSearch(int* arr, int len, int value) {
    int right = len - 1, left = 0, uni = 0;
    int midle = (right + left) / 2;
    if (len == 0) {
        return 0;
    }
    if (arr[midle] == value) {
        int end = midle, start = midle;
        while (start >= 0 && arr[--start] == value) {}
        while (end < len && arr[++end] == value) {}
        return end - start - 1;
    } else if (arr[midle] > value) {
        right = midle;
        return UniBinSearch(arr, midle - left, value);
    } else {
        left = midle;
        return UniBinSearch(&(arr[midle + 1]), right - midle, value);
    }
}
int countPairs1(int *arr, int len, int value) {
  int uni = 0;
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                uni++;
            }
        }
    }
    return uni;
}
int countPairs2(int *arr, int len, int value) {
  int uni = 0;
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] <= value) {
            for (int j = i + 1; j < len; j++) {
                if (arr[i] + arr[j] == value) {
                    uni++;
                }
            }
        }
    }
    return uni;
}
int countPairs3(int *arr, int len, int value) {
  int uni = 0;
    for (int i = 0; i < len - 1; i++) {
       if (arr[i] > value / 2) {
           break;
       }
       uni += UniBinSearch(&(arr[i+1]), len-i-1, value-arr[i]);
    }
  return uni;
}
