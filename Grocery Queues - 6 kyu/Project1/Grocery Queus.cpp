#include <algorithm>
#include <vector>

bool finished(std::vector<int> customers) {
    bool finished = true;
    for (int i = 0; i < (int)customers.size(); i++) {
        if (customers[i] != 0) {
            finished = false;
            break;
        }
    }
    return finished;
}

long queueTime(std::vector<int> customers, int n) {

    if (customers.size()==0) return 0;
    long time = -1;
    std::vector<int> queues;
    queues.resize(n);
    std::reverse(customers.begin(), customers.end());
    
    for (int i = 0; i < n; i++) queues[i] = 0;
   
    while (customers.size() >= 1 || !finished(queues)) {
        ++time;
        for (int i = 0; i < n; i++) {            
            if (time >= 1 && queues[i] != 0) --queues[i];
            if (queues[i] == 0) {
                if (customers.size() != 0) {
                    queues[i] = customers.back();
                    customers.pop_back();
                }
            }
        }
    }
    return (time==-1)?0:time;
}

int main() {
    long result;
    result = queueTime(std::vector<int>{2, 2, 3, 3, 4, 6, 4, 3, 4}, 4);// Equals(10));
    result = queueTime(std::vector<int>{}, 1);// Equals(0));
    result = queueTime(std::vector<int>{1, 2, 3, 4}, 1);// Equals(10));
    result = queueTime(std::vector<int>{2, 2, 3, 3, 4, 4}, 2);// Equals(9));
    result = queueTime(std::vector<int>{1, 2, 3, 4, 5}, 100);// Equals(5));

    return 0;
}