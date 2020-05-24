#ifndef LAB_8_9_FUNCTIONS_H
#define LAB_8_9_FUNCTIONS_H
struct node {
    int id = 0;
    node *next;
};
typedef node *pNode;
//Фундаментальные функции
pNode createNewNode( int ); //Создание Узла
void allocMemoryForNodes( pNode& ); //Выделение памяти
//Вставка узла
void insertNode( pNode& , pNode );//Выбор вставки
void addFirst( pNode&  , pNode ); //В начало
void addAfter( pNode  , pNode ); //После
void addBefore( pNode& , pNode  , pNode ); //До
void addLast( pNode& , pNode ); //В конец
//Выводы
void printList( pNode ); //Списка
void printChoice(); //Выбор
//Заполнение массива
void fillingNodes( pNode );
//Поиск элемента
pNode searchNode( pNode );
//Изменение узла
void changeNode( pNode );
//Рокировка
void exchange( pNode& , pNode );
//Сортировка
void sort( pNode );
void sortAscending( pNode );
void sortDescending( pNode );
//Разделение Списка
void separationOfList(pNode &head_1, pNode tmp);
//Слияние Списков
void connectLists( pNode , pNode& );
//Удаление Узла
void deleteOldNode( pNode& , pNode );
//Чтение из файла
void readFromFile( pNode& );
//Ввод в файл
void writeToFile( pNode );
//Адрес последнего
pNode lastAdress( pNode );
//Количество узлов
int countNodes( pNode );
//Освобождение памяти
void freeMemory( pNode& );
#endif
