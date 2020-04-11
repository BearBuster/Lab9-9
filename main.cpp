#include <iostream>
#include "Functions.h"

using namespace std;


int main() {
    pNode head = nullptr;
    pNode head_1 = nullptr;
    pNode tmp = nullptr;
    pNode tmp_1 =nullptr;
    int batHeadNum = 0;
    int choice = 0;
    printChoice();
    while (choice != 19){
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice) {
            case 1:
                allocMemoryForNodes(head);
                break;
            case 2:
                fillingNodes(head);
                break;
            case 3:
                if(head)
                    printList(head);
                else
                    cout << "Empety list" << endl;
                break;
            case 4:
                tmp = searchNode(head);
                if( tmp )
                    cout << " Node tmp right now : id = "<< tmp->id << endl;
                break;
            case 5:
                if(tmp)
                    changeNode(tmp);
                else
                    cout << "At first find node" << endl;
                break;
            case 6:
                if(tmp)
                    exchange(head, tmp);
                else
                    cout << "At first find first node" << endl;
                break;
            case 7:
                sort(head);
                break;
            case 8:
                swap(head,head_1);
                swap(tmp , tmp_1);
                break;
            case 9:
                if(tmp) {
                    separationOfList(head_1, tmp);
                    tmp = nullptr;
                    tmp_1 = nullptr;
                }
                else
                    cout << "At first find first node" << endl;
                break;
            case 10:
                if (head && head_1) {
                    connectLists(head, head_1);
                    tmp = nullptr;
                    tmp_1 = nullptr;
                } else
                    cout << "No exist some list" << endl;
                break;
            case 11:
                if(tmp)
                    insertNode(head, tmp);
                else
                    cout << "At first find node" << endl;
                break;
            case 12:
                if(tmp) {
                    deleteOldNode(head, tmp);
                    tmp = nullptr;
                }
                else
                    cout << "At first find node" << endl;
                break;
            case 13:
                readFromFile(head);
                break;
            case 14:
                writeToFile(head);
                break;
            case 15:
                cout << "Your last host address : " << lastAdress(head) << endl;
                break;
            case 16:
                cout << "Right now at list : " << countNodes(head)  << " elements"<< endl;
                break;
            case 17:
                freeMemory(head);
                cout << "memory freed" << endl;
                break;
            case 18:
                printChoice();
                break;
            case 19:
                break;
            default:
                cout << "Try again" << endl;
                break;
        }
    }
    return 0;
}
