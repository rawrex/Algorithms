#include <map>
#include <set>

struct MyCalendar 
{
    struct Event
    {
        friend bool operator<(const Event& a, const Event& b) noexcept
        {
            return a.m_start < b.m_start && a.m_end <= b.m_start;
        }

        int m_start = -1;
        int m_end = -1;
    };

    MyCalendar() = default;

    bool book(int start, int end) 
    {
        if(!m_events_1.emplace(start, end).second)
            return m_events_2.emplace(start, end).second;

        return true;
    }

private:
    std::set<Event> m_events_1;
    std::set<Event> m_events_2;
};

int main()
{

}
