class MyCircularDeque {
public:
    int size = 0;
    int front = -1;
    int rear = -1;
    vector<int> deque;
    MyCircularDeque(int k) {
        size = k;
        deque.resize(k);
    }

    bool insertFront(int value) {
        if (isFull())
            return false;
        else if (isEmpty()) {
            rear = front = 0;
        } else {
            front = (front - 1 + size) % size;
        }
        deque[front] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        } else if (isEmpty()) {
            rear = front = 0;
        } else {
            rear = (rear + 1) % size;
        }
        deque[rear] = value;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + size) % size;
        }
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        } else
            return deque[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        } else
            return deque[rear];
    }

    bool isEmpty() {
        if (front == -1 && rear == -1)
            return true;
        else
            return false;
    }

    bool isFull() {
        if ((rear + 1) % size == front) {
            return true;
        } else
            return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */