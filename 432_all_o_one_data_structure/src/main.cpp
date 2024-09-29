#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class AllOne
{
    struct Bucket
    {
        int count;
        std::unordered_set<std::string> keys;
        Bucket(int c) : count(c) {}
    };

public:
    AllOne() {}

    void inc(const std::string& key)
    {
        // If the key is already in the map, increment its count
        if (m_data.count(key))
        {
            auto current_bucket_it = m_data[key];
            auto next_bucket_it = std::next(current_bucket_it);

            // If the next bucket doesn't exist or its count is not current+1, create it
            if (next_bucket_it == m_buckets.end() || next_bucket_it->count != current_bucket_it->count + 1)
            {
                next_bucket_it = m_buckets.insert(next_bucket_it, Bucket(current_bucket_it->count + 1));
            }

            // Move the key to the next bucket
            next_bucket_it->keys.insert(key);
            m_data[key] = next_bucket_it;

            // Remove the key from the current bucket
            current_bucket_it->keys.erase(key);
            if (current_bucket_it->keys.empty())
            {
                m_buckets.erase(current_bucket_it);
            }
        }
        else
        {
            // If the key is new, insert it into the bucket with count 1
            if (m_buckets.empty() || m_buckets.begin()->count != 1)
            {
                m_buckets.emplace_front(1);
            }
            m_buckets.begin()->keys.insert(key);
            m_data[key] = m_buckets.begin();
        }
    }

    void dec(const std::string& key)
    {
        // If the key exists in the map, decrement its count
        if (m_data.count(key))
        {
            auto current_bucket_it = m_data[key];

            // If the current count is 1, we remove the key entirely
            if (current_bucket_it->count == 1)
            {
                current_bucket_it->keys.erase(key);
                m_data.erase(key);

                // If the bucket is empty, remove the bucket
                if (current_bucket_it->keys.empty())
                {
                    m_buckets.erase(current_bucket_it);
                }
                return;
            }

            // Otherwise, move the key to the previous bucket (count - 1)
            auto prev_bucket_it = std::prev(current_bucket_it);

            // If the previous bucket doesn't exist or its count is not current-1, create it
            if (current_bucket_it == m_buckets.begin() || prev_bucket_it->count != current_bucket_it->count - 1)
            {
                prev_bucket_it = m_buckets.insert(current_bucket_it, Bucket(current_bucket_it->count - 1));
            }

            // Move the key to the previous bucket
            prev_bucket_it->keys.insert(key);
            m_data[key] = prev_bucket_it;

            // Remove the key from the current bucket
            current_bucket_it->keys.erase(key);
            if (current_bucket_it->keys.empty())
            {
                m_buckets.erase(current_bucket_it);
            }
        }
    }

    std::string getMaxKey()
    {
        if (m_buckets.empty())
        {
            return "";
        }
        return *(m_buckets.back().keys.begin());
    }

    std::string getMinKey()
    {
        if (m_buckets.empty())
        {
            return "";
        }
        return *(m_buckets.front().keys.begin());
    }

private:
    std::list<Bucket> m_buckets;
    std::unordered_map<std::string, std::list<Bucket>::iterator> m_data;
};

int main()
{
    AllOne foo;
    foo.inc("a");
    foo.inc("b");
    foo.inc("b");
    foo.inc("b");
    foo.inc("b");
    foo.inc("b");
    foo.inc("b");
    foo.getMaxKey();
    foo.getMinKey();
}