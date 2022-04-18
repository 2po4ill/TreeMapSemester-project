#pragma once

// Заголовочный файл с объявлением структуры данных
#include "node.hpp"
#include <optional>

namespace itis {

  struct BinarySearchTree final {

    /**
     * Конструктор по умолчанию.
     */
    BinarySearchTree() = default;

    /**
     * Операция эквивалентна Clear.
     */
    ~BinarySearchTree();

    /**
     * Добавление нового узла в дерево.
     *
     * В случае существования элемента с указанным ключом,
     * хранимое по ключу значение обновляется.
     *
     * @param key - ключ узла
     * @param value - данные узла
     */
    void Insert(int key, int value);

    /**
     * Удаление узла дерева по ключу.
     *
     * @param key - ключ удаляемого узла
     * @return true - узел удален, false - узел не найден
     */
    bool Remove(int key);

    /**
     * Высвобождение выделенной под узлы дерева памяти.
     */
    void Clear();

    /**
     * Поиск узла по ключу.
     *
     * @param key - ключ узла
     * @return хранимое значение узла
     */
    std::optional<int> Find(int key) const;

    /**
     * Проверка наличия элемента по ключу.
     *
     * Подсказка: используйте метод Find.
     *
     * @param key - значение ключа
     * @return true - элемент присутствует, false - элемент отсутствует
     */
    bool Contains(int key) const;

    /**
     * Проверка дерева на наличие узлов.
     *
     * @return true - дерево пустое, false - в дереве есть узлы
     */
    bool IsEmpty() const;

    /**
     * Поиск узла с минимальным значением ключа в дереве.
     *
     * @return значение ключа или ничего
     */
    std::optional<int> FindMin() const;

    /**
     * Поиск узла с максимальным значением ключа в дереве.
     *
     * @return значение ключа или ничего
     */
    std::optional<int> FindMax() const;

    /**
     * Возвращает корневой узел дерева.
     *
     * Внимание: метод опасен, используется лишь в целях обучения.
     * V. Чем опасен данные метод? К чему его использование может потенциально привести?
     *
     * @return указатель на корневой узел
     */
    Node *root() const;

   private:
    // корень дерева
    Node *root_{nullptr};

    // вспомогательные методы

    void insert(int key, int value, Node *&node);

    bool remove(int key, Node *&node);

    void clear(Node *node);

    Node *find(int key, Node *node) const;

    Node *find_min(Node *node) const;

    Node *find_max(Node *node) const;
  };

}  // namespace itis