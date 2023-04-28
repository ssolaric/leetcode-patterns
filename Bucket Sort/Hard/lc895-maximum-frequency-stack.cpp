class FreqStack {
public:
    void push(int x) {
        int freq = ++counter[x];
        maxFreq = max(maxFreq, freq);
        buckets[freq].push(x);
    }
    
    int pop() {
        int num = buckets[maxFreq].top();
        buckets[maxFreq].pop();
        counter[num]--;
        if (buckets[maxFreq].empty()) {
            maxFreq--;
        }
        return num;
    }
private:
    int maxFreq = 0;
    unordered_map<int, int> counter;
    unordered_map<int, stack<int>> buckets;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */