class MyCircularDeque {
    int front;
    int rear;
    int size;
    int capacity;
    int* arr;

public:
    MyCircularDeque(int k) {
        this->capacity = k;
        size = 0;
        front = -1;
        rear = -1;
        arr = new int[k];
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {  // First element insertion
            front = rear = 0;
        } else if (front == 0) {  // Wrap around to the end
            front = capacity - 1;
        } else {
            front--;
        }

        arr[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }

        if (isEmpty()) {  // First element insertion
            front = rear = 0;
        } else if (rear == capacity - 1) {  // Wrap around to the start
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }

        if (front == rear) {  // Only one element left
            front = rear = -1;
        } else if (front == capacity - 1) {  // Wrap around
            front = 0;
        } else {
            front++;
        }

        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }

        if (front == rear) {  // Only one element left
            front = rear = -1;
        } else if (rear == 0) {  // Wrap around
            rear = capacity - 1;
        } else {  // General case
            rear--;
        }

        size--;
        return true;
    }

    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};
