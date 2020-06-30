class FreqStack {
public:
    void push(int x) {
        counter[x]++;
        pq.push({counter[x], used, x});
        used++;
    }
    
    int pop() {
        auto [freq, index, num] = pq.top();
        counter[num]--;
        pq.pop();
        return num;
    }
private:
    int used = 0;
    unordered_map<int, int> counter;
    // Save tuples (frequency, index, number).
    // Give more priority to higher frequencies, then to higher indices
    priority_queue<tuple<int, int, int>> pq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */