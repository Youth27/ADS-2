// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double chisl = value;
  if (n == 0) {
    return 1;
  }
  for (uint16_t i = 1; i < n; i++) {
    chisl = chisl * value;
  }
  return chisl;
}

uint64_t fact(uint16_t n) {
  if (n <= 1) {
    return 1;
  }
  return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double e = 0;
  uint64_t perem = 0;
    while (perem <= count) {
      e = e + pown(x, perem) / fact(perem);
      perem = perem + 1;
    }
    return  e;
  }

double sinn(double x, uint16_t count) {
  double znach = 0;
  for (uint16_t i = 1; i <= count; i++) {
    znach = znach + pown(-1, (i - 1)) * calcItem(x, (2 * i - 1));
  }
  return znach;
}

double cosn(double x, uint16_t count) {
  double znachh = 0;
  for (uint16_t j = 1; j <= count; j++) {
    znachh = znachh + pown(-1, (j - 1)) * calcItem(x, (2 * j - 2));
  }
  return znachh;
}
