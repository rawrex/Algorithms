#include <map>
#include <set>
#include <memory>

struct MyCalendar 
{
    MyCalendar() = default;

    bool book(int start, int end) 
    {
        ++m_bookings[start];
        --m_bookings[end];

        unsigned count = 0; 
        for (const auto& [time, booking_count] : m_bookings) 
        {
            // If count ever comes to more that two
            // It will mean that there are more that two consequtive (and overlapping) bookings present
            count += booking_count;

            // Undo the changes
            if (count > 2) 
            {
                --m_bookings[start];
                ++m_bookings[end];
                return false;
            }
        }

        return true;
    }

    std::map<int, int> m_bookings;
};

int main()
{

}
