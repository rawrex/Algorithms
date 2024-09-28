#include <vector>

class MyCircularDeque
{
public:
    MyCircularDeque(int k) : m_data(k, 0), m_size(k), m_front_index(0)
    {

    }

    bool insertFront(int value)
    {
        if (!isFull())
        {
            m_front_index = (m_front_index - 1 + m_size) % m_size;
            ++m_count;
            m_data[m_front_index] = value;
            return true;
        }
        return false;
    }

    bool insertLast(int value)
    {
        if (!isFull())
        {
            m_data[(m_front_index + m_count) % m_size] = value;
            ++m_count;
            return true;
        }
        return false;
    }

    bool deleteFront()
    {
        if (!isEmpty())
        {
            m_front_index = (m_front_index + 1) % m_size;
            --m_count;
            return true;
        }
        return false;
    }

    bool deleteLast()
    {
        if (!isEmpty())
        {
            --m_count;
            return true;
        }
        return false;
    }

    int getFront()
    {
        if (!isEmpty())
            return m_data[m_front_index];

        return -1;
    }

    int getRear()
    {
        if (!isEmpty())
            return m_data[(m_front_index + m_count - 1) % m_size];
        return -1;
    }

    bool isEmpty() const
    {
        return m_count == 0;
    }

    bool isFull() const
    {
        return m_count == m_size;
    }

private:
    std::vector<int> m_data;

    unsigned m_size = 0;
    unsigned m_count = 0;
    unsigned m_front_index = 0;
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

int main()
{

}