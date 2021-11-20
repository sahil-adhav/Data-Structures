#include<iostream>
using namespace std;

template <typename T>
class QueueUsingArray{
    T *data;
    int size, nextIndex, firstIndex, capacity;

public:
        QueueUsingArray(int s){
            data = new int[s];
            size = 0;
            nextIndex = 0;
            firstIndex = -1;
            capacity = s;
        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return size == 0;
        }

        void enqueue(T element){
            if(size == capacity){
                cout << "Queue is Full ! " << endl;
                return;
            }
            data[nextIndex] = element;
            nextIndex = (nextIndex+1) % capacity;
            if(firstIndex == -1){
                firstIndex = 0;
            }
            size++;
        }

        T deque(){
            if(isEmpty()){
                cout << "Queue is Empty !" << endl;
                return 0;
            }
            T ans = data[firstIndex];
            firstIndex = (firstIndex+1) % capacity;
            size--;
            if(size == 0){
                firstIndex = -1;
                nextIndex = 0;
            }
            return ans;
        }

        T Front(){
            if(isEmpty()){
              cout << "Queue is Empty !" << endl;
              return 0;  
            }
            return data[firstIndex];
        }
};

int main()
{
    QueueUsingArray <int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout << q.Front() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.deque() << endl;
    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
    return 0;
}