#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class AllOne
{
    struct Bucket
    {
        Bucket(int c) : count(c) 
        {

        }

        int count;
        std::unordered_set<std::string> keys;
    };

public:
    AllOne() {}

    void inc(const std::string& key)
    {
        // If the key is already in the map, increment its count
        if (m_data.contains(key))
        {
            auto current_bucket_iter = m_data[key];
            auto next_bucket_iter = std::next(current_bucket_iter);

            // If the next bucket doesn't exist or its count is not current+1, create it
            if (next_bucket_iter == m_buckets.end() || next_bucket_iter->count != current_bucket_iter->count + 1)
                next_bucket_iter = m_buckets.emplace(next_bucket_iter, current_bucket_iter->count + 1);

            // Move the key to the next bucket
            next_bucket_iter->keys.insert(key);
            m_data[key] = next_bucket_iter;

            // Remove the key from the current bucket
            current_bucket_iter->keys.erase(key);
            if (current_bucket_iter->keys.empty())
                m_buckets.erase(current_bucket_iter);
        }
        else
        {
            // If the key is new, insert it into the bucket with count 1
            if (m_buckets.empty() || m_buckets.begin()->count != 1)
                m_buckets.emplace_front(1);

            m_buckets.begin()->keys.insert(key);
            m_data[key] = m_buckets.begin();
        }
    }

    void dec(const std::string& key)
    {
        // If the key exists in the map, decrement its count
        if (m_data.contains(key))
        {
            auto current_bucket_iter = m_data[key];

            // If the current count is 1, we remove the key entirely
            if (current_bucket_iter->count == 1)
            {
                current_bucket_iter->keys.erase(key);
                m_data.erase(key);

                // If the bucket is empty, remove the bucket
                if (current_bucket_iter->keys.empty())
                    m_buckets.erase(current_bucket_iter);

                return;
            }

            // Otherwise, move the key to the previous bucket (count - 1)
            auto prev_bucket_iter = std::prev(current_bucket_iter);

            // If the previous bucket doesn't exist or its count is not current-1, create it
            if (current_bucket_iter == m_buckets.begin() || prev_bucket_iter->count != current_bucket_iter->count - 1)
                prev_bucket_iter = m_buckets.emplace(current_bucket_iter, current_bucket_iter->count - 1);

            // Move the key to the previous bucket
            prev_bucket_iter->keys.insert(key);
            m_data[key] = prev_bucket_iter;

            // Remove the key from the current bucket
            current_bucket_iter->keys.erase(key);
            if (current_bucket_iter->keys.empty())
                m_buckets.erase(current_bucket_iter);
        }
    }

    std::string getMaxKey()
    {
        if (m_buckets.empty())
            return {};

        return *(m_buckets.back().keys.begin());
    }

    std::string getMinKey()
    {
        if (m_buckets.empty())
            return {};

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