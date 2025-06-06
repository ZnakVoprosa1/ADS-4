// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      } else if (arr[i] + arr[j] > value) {
        break;
      }
    }
  }
  return count;
}
  int count = 0;
  int right = len - 1;
  while (right > 0) {
    if (arr[right] > value) {
      right--;
    } else {
      break;
    }
  }
  for (int left = 0; left < len; left++) {
    for (int r = right; r > left; r--) {
      if (arr[left] + arr[r] == value)
        count++;
    }
  }
  return count;
}
int search(int* arr, int left, int right, int value) {
  int first = -1;
  int l = left, r = right;
    int m = l + (r - l) / 2;
    if (arr[m] >= value) {
      r = m - 1;
      if (arr[m] == value) first = m;
    } else {
      l = m + 1;
    }
  }
  if (first == -1) return 0;
  int last = first;
  l = first;
  r = right;
    int m = l + (r - l) / 2;
    if (arr[m] <= value) {
      l = m + 1;
      if (arr[m] == value) last = m;
    } else {
      r = m - 1;
    }
  }
  return last - first + 1;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int left = 0; left < len; ++left) {
    count += search(arr, left + 1, len - 1, value - arr[left]);
  }
  return count;
}
