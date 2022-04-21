#pragma once

namespace itis
{
  struct Node //конструктор узла
  {
    int key;
    int value;

    Node *left{nullptr}; //левый потомок
    Node *right{nullptr}; //правый потомок


    Node(int key, int value) : key{key}, value{value} {} //объявление узла и его ключа со значением
  };
}