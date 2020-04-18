#ifndef __FIR_H
#define __FIR_H

#include <Arduino.h>
#include <type_traits>

template <int N, typename T>
class Fir {
    static_assert(std::is_arithmetic<T>::value, "T must be numeric");
    int id;
    int counter;
    T memblock [N];
    bool saturated;
  public:
    Fir(int id);
    void Push (T value);
    T Get ();
};

template <int N, typename T>
Fir<N, T>::Fir (int id) {
  this->id = id;
  this->counter = 0;
  for(int i = 0; i < N; i++) {
    memblock[i] = 0;
  }
}

template <int N, typename T>
T Fir<N, T>::Get () {
  if (this->counter == 0)
    return 0;

  int n = N;
  if (!this->saturated)
    n = this->counter;

  T sum = 0;
    
  for(int i = 0; i < n; i++) {
    sum += memblock[i];
  }

  T avg = sum / n;
  return avg;
}

template <int N, typename T>
void Fir<N, T>::Push (T value) {
  memblock[this->counter % N] = value;
  this->counter++;
  if (this->counter == N)
    this->saturated = true;
}

#endif
