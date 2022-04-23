#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdio>
#include <stdio.h>
#include "data_structure.hpp"
#include <iomanip>
#include <chrono>

using namespace std;
using namespace itis;

void shuffle(int* arr, int N)
{
  // инициализация генератора случайных чисел
  srand(time(NULL));

  // реализация алгоритма перестановки
  for (int i = N - 1; i >= 1; i--) {
    int j = rand() % (i + 1);

    int tmp = arr[j];
    arr[j] = arr[i];
    arr[i] = tmp;
  }
}

void decorator_insert_n_items(int n) {
  Treemap tree;
  int key[n];
  int value[n];
  for (int i = 0; i < n; ++i) {
    key[i] = i + 1;
    value[i] = rand() % 10000000;
  }
  shuffle(key, n);
  shuffle(value, n);

  //создали перечень ключей и значений

  clock_t start = clock(); //начинаем засекать
  for (int i = 0; i < n; ++i) {
    tree.Insert(key[i], value[i]); //вставляем узлы в дерево
  }
  clock_t end = clock(); //конечное время
  double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
  cout << n << " " << seconds << endl; //выводим результаты взависимости от кол-ва узлов
}

int key[100000000]; // объявляем массив ключей
int value[100000000]; // объявляем массив значений

void decorator_contains_one_item()
{
  int n = 50000000;
  Treemap tree;

  for (int i = 0; i < n; ++i) {
    key[i] = i + 1;
    value[i] = rand() % n;
  }
  shuffle(key, n);
  shuffle(value, n);
  for (int i = 0; i < n; ++i) {
    tree.Insert(key[i], value[i]); //создали дерево над которым будем проводить операции
    if ((i%10000==0) and (i>=100)){
      clock_t start = clock(); //старт таймера
      tree.Contains(key[i]); //проверка только добавленного узла спустя 10000 узлов
      clock_t end = clock(); //конечное время
       double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
      cout << i << " " << seconds << endl; //выводим результаты взависимости от кол-ва узлов
    }
  }
}

void decorator_remove_one_item() {
  int n = 10000000;
  Treemap tree;
  for (int i = 0; i < n; ++i) {
    key[i] = i + 1;
    value[i] = rand() % n;
  }
  shuffle(key, n);
  shuffle(value, n);
  for (int i = 0; i < n; ++i) {
    tree.Insert(key[i], value[i]);
  }

  //создали дерево над которым будем проводить операции

  shuffle(key, n); //перемешиваем ключи чтобы рандомно удалять узлы
  for (int i = 0; i < n; ++i) {
    if (i%10000 == 0){
      clock_t start = clock(); //старт таймера
      tree.Remove(key[i]); //проверяем по времени удаление 10000-ного узла
      clock_t end = clock(); //конечное время
      double seconds = ((double)(end - start)) / CLOCKS_PER_SEC;
      cout << i << " " << seconds << endl; //выводим результаты взависимости от кол-ва узлов
    }
    else{
      tree.Remove(key[i]);
    }
  }
}

int main(int args, char** argv) {
  for (int i = 100; i <= 258100; i += 1000) {
    decorator_insert_n_items(i);
  }
  decorator_contains_one_item();
  decorator_remove_one_item();



  return 0;
}