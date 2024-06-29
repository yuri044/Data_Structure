#ifndef V_PRIORITY_QUEUE_H
#define V_PRIORITY_QUEUE_H

#include <vector>

class PriorityQueue
{
    public:
        PriorityQueue(int numPriorites);
        //default constructor
        PriorityQueue(const PriorityQueue& other);
        //Copy constructor
        PriorityQueue& operator=(const PriorityQueue& other);
        PriorityQueue(PriorityQueue&& other) noexcept;
        //Move semantic
        PriorityQueue& operator=(PriorityQueue&& other);
        //Move operator

        void enqueue(int priority, int value);
        int dequeue();

    private:
        struct Node
        {
            int priority;
            int value;

        }

    std::vector<std::vector<Node*>> queues;
    //using pointers for dynamic allocation

    void initializeQueues(int numPriorities);
    void cleanQueues();
    //cleaning queues
};

PriorityQueue::PriorityQueue(int numPriorities)
{
    initializeQueue
}




#endif // V_PRIORITY_QUEUE_H
