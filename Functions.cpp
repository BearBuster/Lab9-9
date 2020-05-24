#include <iostream>
#include <fstream>
#include "Functions.h"

using namespace std;
int i,choice;

//Фундаментальные функции
pNode createNewNode(int id){
    pNode newNode = new node;
    newNode->id = id;
    newNode->next = nullptr;
    return newNode;
}
void allocMemoryForNodes(pNode& head) {
    if (head != nullptr) {
        cout << " Memory already alloced " << endl;
    } else {
        int n;
        cout << "How many nodes do you want to be" << endl;
        cin >> n;
        for (i = 0; i < n; i++) {
            addLast(head, createNewNode(0));
        }
        cout << "Memory was alloced for " << n << " elements" << endl;
    }
}
//Вставка узла
void insertNode(pNode &head , pNode tmp){
    cout << "1.Add first" << endl;
    cout << "2.Add before" << endl;
    cout << "3.Add after" << endl;
    cout << "4.Add at the end" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    cout << "Enter new node's id : ";
    cin >> i;
    switch (choice) {
        case 1:
            addFirst(head, createNewNode(i));
            break;
        case 2:
            addBefore(head, tmp, createNewNode(i));
            break;
        case 3:
            addAfter(tmp, createNewNode(i));
            break;
        case 4:
            addLast(head, createNewNode(i));
            break;
        default:
            break;
    }
}
void addFirst( pNode &head , pNode newNode){
    newNode->next = head;
    head = newNode;
}
void addBefore(pNode &head ,pNode p , pNode newNode){
    pNode tmp = head;
    if(p==head){
        addFirst(head, newNode);
    }else{
        while(tmp && tmp->next != p)
            tmp = tmp->next;
        addAfter(tmp, newNode);
    }
}
void addAfter( pNode p , pNode newNode){
    newNode->next = p->next;
    p->next = newNode;
}
void addLast(pNode &head , pNode newNode){
    pNode tmp = head;
    if  (head == nullptr){
        addFirst(head, newNode);
        return;
    }
    while(tmp->next != nullptr)
        tmp = tmp->next;
    tmp->next = newNode;
}
//Выводы
void printList(pNode head){
    pNode tmp = head;
    while ( tmp != nullptr){
        cout << "id : " << tmp->id << endl;
        tmp = tmp->next;
    }
}
void printChoice(){
    cout << "1.Alloc memory" << endl;
    cout << "2.Enter info from keyboard" << endl;
    cout << "3.Print List" << endl;
    cout << "4.Search node" << endl;
    cout << "5.Change Node" << endl;
    cout << "6.Exchange Nodes" << endl;
    cout << "7.Sort" << endl;
    cout << "8.Change list" << endl;
    cout << "9.Split list" << endl;
    cout << "10.Connect lists" << endl;
    cout << "11.Insert node" << endl;
    cout << "12.Delete old node" << endl;
    cout << "13.Read from file" << endl;
    cout << "14.Write to file" << endl;
    cout << "15.Last nods adress" << endl;
    cout << "16.Number of nodes" << endl;
    cout << "17.Memeory delet" << endl;
    cout << "18.Print choice" << endl;
    cout << "19.End" << endl;
}
//Заполнение массива
void fillingNodes(pNode head) {
    pNode tmp = head;
    i = 0;
    while (tmp != nullptr) {
        cout << "Enter node's id : ";
        cin >> i;
        tmp->id = i;
        tmp = tmp->next;
    }
    cout << "List was filled " << endl;
}
//Поиск элемента
pNode searchNode(pNode head ){
    int shear;
    pNode tmp = head;
    cout << "Enter node's id : " ;
    cin >> shear;
    while(tmp != nullptr){
        if(tmp->id == shear)
            return tmp;
        tmp = tmp->next;
    }
    cout << "Node with that id not exist" << endl;
    return nullptr;
}
//Изменение узла
void changeNode( pNode tmp ){
    cout << "Enter new id for node < TMP > : ";
    cin >> tmp->id;
}
//Рокировка
void exchange(pNode &head , pNode tmp){
    pNode tmp_2;
    cout << "With wich node do you want exchange " << endl;
    tmp_2 = searchNode(head);
    if(tmp_2)
        swap(tmp->id , tmp_2->id);
}
//Сортировка
void sort(pNode head){
    cout << "At first say sort will be (1)ascending or (2)descending : ";
    cin >> choice;
    switch(choice){
        case 1:
            sortAscending(head);
            break;
        case 2:
            sortDescending(head);
            break;
        default:
            break;
    }
}
void sortAscending(pNode head){
    pNode tmp_1 = head , tmp_2;
    while(tmp_1 != nullptr){
        tmp_2 = head;
        while(tmp_2 != nullptr){
            if(tmp_1->id < tmp_2->id)
                swap(tmp_1->id ,tmp_2->id);
            tmp_2 = tmp_2->next;
        }
        tmp_1 = tmp_1->next;
    }
}
void sortDescending(pNode head){
    pNode tmp_1 = head , tmp_2;
    while(tmp_1 != nullptr){
        tmp_2 = head;
        while(tmp_2 != nullptr){
            if(tmp_1->id > tmp_2->id)
                swap(tmp_1->id ,tmp_2->id);
            tmp_2 = tmp_2->next;
        }
        tmp_1 = tmp_1->next;
    }
}
//Разделение Списка
void separationOfList(pNode &head_1, pNode tmp) {
    pNode tmp_1 = tmp->next;
    tmp->next = nullptr;
    if(head_1 != nullptr){
        cout << "Do you want unite second path of list with second list ? (1)Yes  (2)No : ";
        cin >> choice;
        if( choice == 1){
            pNode tmp_2 = head_1;
            while(tmp_2->next != nullptr){
                tmp_2 = tmp_2->next;
            }
            tmp_2->next = tmp_1;
        } else {
            freeMemory(head_1);
            head_1 = tmp_1;
        }
    }else
        head_1 = tmp_1;
}
//Слияние Списков
void connectLists( pNode head , pNode &head_1){
    pNode tmp = head;
    while(tmp->next != nullptr)
        tmp = tmp->next;
    tmp->next = head_1;
    head_1 = nullptr;
}
//Удаление Узла
void deleteOldNode(pNode &head , pNode oldNode){
    pNode tmp = head;
    if(oldNode == head){
        head = tmp->next;
    }else{
        while(tmp && tmp->next != oldNode )
            tmp = tmp->next;
        if(tmp == nullptr)
            return;
        tmp->next = oldNode->next;
    }
    delete oldNode;
    cout << "Note was deleted" << endl;
}
//Чтение из файла
void readFromFile( pNode &head){
    fstream fl;
    fl.open("/Users/guardi/CLionProjects/Lab_8-9/input-output.txt");
    if(fl.is_open()) {
        if (head != nullptr) {
            cout << "Do you want unite your list with list from file ? (1)Yes  (2)No : ";
            cin >> choice;
            if (choice == 1) {
                while(fl >> i) {
                    addLast(head, createNewNode(i));
                }
            }else {
                freeMemory(head);
                while(fl >> i) {
                    addLast(head, createNewNode(i));
                }
                return;
            }
        }else{
            while(fl >> i)
                addLast(head, createNewNode(i));
        }
    }else
        cout << "Error with opening file" << endl;
    fl.close();
}
//Ввод в файл
void writeToFile( pNode head){
    ofstream fl;
    fl.open("/Users/guardi/CLionProjects/Lab_8-9/input-output.txt");
    if(fl.is_open()) {
        pNode tmp = head;
        while(tmp != nullptr){
            fl << tmp->id << ' ';
            tmp = tmp->next;
        }
    }else
        cout << "Error with opening file" << endl;
    fl.close();
}
//Адрес последнего
pNode lastAdress( pNode head ){
    while( head && head->next )
        head = head->next;
    return head;
}
//Количество узлов
int countNodes(pNode head){
    pNode tmp = head;
    if(head == nullptr)
        return 0;
    else{
        int count = 1;
        while(tmp->next != nullptr){
            tmp = tmp->next;
            count++;
        }
        return count;
    }
}
//Освобождение памяти
void freeMemory(pNode &head){
    if(!head)
        cout << "List already empty" << endl;
    else{
        pNode tmpBefore;
        while(head){
            tmpBefore = head;
            head = head->next;
            delete tmpBefore;
        }
    }
}