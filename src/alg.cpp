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
int countPairs2(int *arr, int len, int value) {
  int result = 0;
  int left = 0, right = len - 1;
  while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum < value) {
      int l = left, r = right;
      int leftCount = 1;
      int leftCount = 1;
      while(l + 1 < r && arr[l + 1] == arr[left]) {++l; ++leftCount;}
      while(r - 1 > l && arr[r - 1] == arr[right]) {--r; ++rightCount;}
      if(arr[left] == arr[right]) {
        int n = right - left + 1;
        result += n * (n - 1) / 2;
        break;
      } else if (sum > value) {
        result += leftCount * rightCount;
        left = l + 1;
        right = r - 1;
      }
    } else if(sum < value) {
      ++left;
    } else {
      --right;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; ++i) {
    int target = value - arr[i];
    int l = i + 1, r = len - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (arr[m] == target) {
        int left_bound = m;
        int right_bound = m;
        left_bound--;
        right_bound++;
        count += (right_bound - left_bound + 1);
        break;
      } else if (arr[m] < target) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
  }
  return count;
}
