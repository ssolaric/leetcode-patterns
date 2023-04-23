class MedianFinder {
public:
    void addNum(int num) {
        if (totalSize == 0) {
            firstHalf.push(num);
        }
        else if (totalSize % 2 != 0) {
            int firstTop = firstHalf.top();
            if (num <= firstTop) {
                firstHalf.push(num);
                int newTop = firstHalf.top();
                firstHalf.pop();
                secondHalf.push(newTop);
            }
            else {
                secondHalf.push(num);
            }
        }
        else {
            int firstTop = firstHalf.top();
            if (num <= firstTop) {
                firstHalf.push(num);
            }
            else {
                secondHalf.push(num);
                int newTop = secondHalf.top();
                secondHalf.pop();
                firstHalf.push(newTop);
            }
        }
        totalSize++;
    }

    double findMedian() {
        if (totalSize % 2 != 0) {
            return firstHalf.top();
        }
        else {
            return (firstHalf.top() + secondHalf.top()) / 2.0;
        }
    }

private:
    priority_queue<int> firstHalf;
    priority_queue<int, vector<int>, greater<int>> secondHalf;
    int totalSize = 0;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
