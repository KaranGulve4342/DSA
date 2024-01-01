// LEETCODE 641
/*
class MyCircularDeque {
public:
    vector<int> deque;
    int front;
    int rear;
    int capacity;

    MyCircularDeque(int k) {
        capacity = k + 1;  // We need an extra slot for determining full/empty
        deque.resize(capacity);
        front = 0;
        rear = 0;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        front = (front - 1 + capacity) % capacity;
        deque[front] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        deque[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        rear = (rear - 1 + capacity) % capacity;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return deque[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return deque[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return front == rear;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};
*/
