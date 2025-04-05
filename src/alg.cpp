// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0, left = 0, right = len - 1;
  for (int i = 0; i < right; ++i) {
    for (int j = right - 1; j > left; --j) {
      if (arr[j] > value) {
        right -= 1;
      }
      if (arr[i] + arr[j] == value) {
        count += 1;
      }
    }
    left += 1;
  }
  return count;
}
int binSearch(int* array, int start, int end, int val) {
  int firstOccurrence = -1, lastOccurrence = -1;
  int low = start, high = end;
  while (low <= high) {
    int middle = low + (high - low) / 2;
    if (array[middle] >= val) {
      if (array[middle] == val) {
        firstOccurrence = middle;
      }
      high = middle - 1;
    } else {
      low = middle + 1;
    }
  }
  if (firstOccurrence == -1) return 0;
  low = firstOccurrence;
  high = end;
  while (low <= high) {
    int middle = low + (high - low) / 2;
    if (array[middle] <= val) {
      if (array[middle] == val) {
        lastOccurrence = middle;
      }
      low = middle + 1;
    } else {
      high = middle - 1;
    }
  }
  return (lastOccurrence - firstOccurrence) + 1;
}
int countPairs3(int* arr, int len, int value) {
  int pairs = 0;
  for (int i = 0; i < len; i++) {
    pairs += binSearch(arr, i + 1, len - 1, value - arr[i]);
  }
  return pairs;
}
