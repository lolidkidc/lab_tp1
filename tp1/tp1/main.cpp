#include <iostream>
#include <locale>
#include "queue.h"
#include "queue1.h"

using namespace std;

// 1 Вариант - Подсчет среднего арифметического.

template <class T>

void chosen_class(T* queue, int num) {

    int c;
    int flag = 1;
    int value;
    int index = 0;
    int count = 1;
    int res= 0;
    int choseNum;

    while (flag == 1) {

        cout << "1 - Add an item to the queue" << endl;
        cout << "2 - Delete an item from the queue" << endl;
        cout << "3 - Display the queue" << endl;
        cout << "4 - Calculation of the arithmetic mean" << endl;
        cout << "5 - Create a copy of the queue" << endl;
        cout << "6 - Merging two queues" << endl;
        cout << "7 - Select the current queue" << endl;
        cout << "8 - The number of the current queue" << endl;
        cout << "0 - Back to choice of inharit class" << endl;
        cout << "> ";
        cin >> c;

        switch (c) {

        case 1:
            cout << "Enter a value: ";
            cin >> value;
            queue[index].push(value);
            cout << "Item was added to the queue\n" << endl;
            break;

        case 2:
            if (queue[index].isEmpty()) {
                cout << "The queue is empty\n " << endl;
                break;
            } else {
                value = queue[index].pop();
                cout << "Deleted item: " << value << endl;
                cout << "\n";
            }
            break;

        case 3:
            if (queue[index].isEmpty()) {
                cout << "The queue is empty\n" << endl;
                break;
            } else {
                cout << "---------------------------------" << endl;
                queue[index].print();
                cout << "---------------------------------" << endl;
                cout << "\n";
            }
            break;

        case 4:

            if (queue[index].isEmpty()) {
                cout << "The queue is empty\n" << endl;
                break;
            } else {
                res= queue[index].fun();
                cout << "Аrithmetic mean: " << res<< endl;
                cout << "\n";
            }
            break;

        case 5:
            if (queue[index].isEmpty()) {
                cout << "The queue is empty\n" << endl;
                break;
            }
            else {
                if (count == num) {
                    cout << "Impossible to make copy of the queue, the number of queues is max\n" << endl;
                    break;
                }
                queue[count].copy(queue[index]);
                cout << "The queue was copied\n" << endl;
                count++;
            }
            break;

        case 6:

            if (count == 1) {
                cout << "There is only one queue\n" << endl;
                break;
            }
            else {
                cout << "Select the queue for merging" << endl;
                cin >> choseNum;
                if ((choseNum <= 0) || (choseNum > num) || (choseNum == index+1)) {
                    cout << "Ivalid number\n" << endl;
                    break;
                }
                if (queue[choseNum-1].isEmpty()) {
                    cout << "Impossible to merge, second queue is empty\n" << endl;
                    break;
                }
                queue[index].merge(queue[choseNum-1]);
                
                cout << "\n";
            }
            break;

        case 7:
            cout << "Now you are working with " << index+1 << " queue" << endl;
            cout << "Enter the number from 1 to " << num << " you want to choose: ";
            cin >> choseNum;

            if ((choseNum <= 0) || (choseNum > num) || (choseNum == index+1)) {
                cout << "Invalid number or the number of queues is max\n" << endl;
            } else {
                index = choseNum-1;
                cout << "Chosen the queue number " << index+1 << endl;
                cout << "\n";
            }
            break;

        case 8:
            cout << "Now you are working with " << index+1 << " queue" << endl;
            cout << "\n";
            break;

        case 0:
            cout << "\n";
            flag = 0;
            break;
        }
    }
}

int main() {

    int numOfq;
    int c;
    int flag = 1;
    childQueuePrivate* qF = NULL;
    childQueueProtected* qS = NULL;
    childQueuePublic* qT = NULL;
    cout << "Enter the number of queues: ";
    cin >> numOfq;
    cout << "Which inharit class you want to choose: " << endl;

    while (flag == 1) {
        cout << "1 - private" << endl;
        cout << "2 - protected" << endl;
        cout << "3 - public" << endl;
        cout << "0 - exit" << endl;
        cout << "-> ";
        cin >> c;

        switch (c) {

        case 1:
            qF = new childQueuePrivate[numOfq];
            chosen_class(qF, numOfq);
            delete[] qF;

            break;

        case 2:

            qS = new childQueueProtected[numOfq];
            chosen_class(qS, numOfq);
            delete[] qS;
            break;

        case 3:

            qT = new childQueuePublic[numOfq];
            chosen_class(qT, numOfq);
            delete[] qT;

            break;

        case 0:
            flag = 0;
            break;

        default:
            cout << "Incorrect value" << endl;
            break;
        }
    }
    return 0;
}
