#include <iostream>
#include <vector>



class Fruit {
public:
    Fruit(std::string name, double weight) : name(name), weight(weight) {}

    std::string getName() const { return name; }
    void setName(std::string name) { this->name = name; }

    double getWeight() const { return weight; }
    void setWeight(double weight) { this->weight = weight; }

private:
    std::string name;
    double weight;
};

class Tree {
public:
    Tree(std::string name, int age, int numFruits) : name(name), age(age), numFruits(numFruits) {
        fruits = new Fruit * [numFruits];
    }

    ~Tree() {
        delete[] fruits;
    }

    std::string getName() const { return name; }
    void setName(std::string name) { this->name = name; }

    int getAge() const { return age; }
    void setAge(int age) { this->age = age; }

    int getNumFruits() const { return numFruits; }
    void setNumFruits(int numFruits) { this->numFruits = numFruits; }

    Fruit** getFruits() const { return fruits; }
    void setFruits(Fruit** fruits) { this->fruits = fruits; }

    void createFruit(std::string name, double weight) {
        fruits[numFruits++] = new Fruit(name, weight);
    }

    Fruit* dropFruit(int index) {
        Fruit* fruit = fruits[index];
        for (int i = index; i < numFruits - 1; i++) {
            fruits[i] = fruits[i + 1];
        }
        numFruits--;
        return fruit;
    }

    void printTree() {
        std::cout << "Tree: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Number of fruits: " << numFruits << std::endl;
        for (int i = 0; i < numFruits; i++) {
            std::cout << "Fruit " << i + 1 << ": " << fruits[i]->getName() << ", " << fruits[i]->getWeight() << std::endl;
        }
    }

private:
    std::string name;
    int age;
    int numFruits;
    Fruit** fruits;
};

int main() {
    Tree tree("Apple Tree", 10, 3);

    tree.createFruit("Apple 1", 1.5);
    tree.createFruit("Apple 2", 2.0);
    tree.createFruit("Apple 3", 2.5);

    tree.printTree();

    Fruit* fruit = tree.dropFruit(1);

    std::cout << "Dropped fruit: " << fruit->getName() << ", " << fruit->getWeight() << std::endl;

    tree.printTree();

    return 0;
}
/*Задание
Создайте класс Fruit, который обладает следующими
полями: название плода, вес плода.
Также создайте класс Tree, в котором содержатся следующие
поля: название дерева, возраст дерева в годах, количество
плодов на дереве, динамический массив объектов класса Fruit
(обозначает все растущие в данный момент на дереве плоды).
Обоим вышеуказанным классам добавьте конструкторы
класса и геттеры/сеттеры для всех элементов классов. Классу
Tree добавьте следующие дополнительные методы:
● createFruit, добавляющий новый фрукт в массив плодов на
дереве;
● dropFruit, принимающий число-индекс. Метод возвращает
плод из массива плодов под указанным индексом, после
чего удаляет соответствующий плод из массива;
● printTree, выводящий в консоль информацию о всех
плодах на дереве.
*/