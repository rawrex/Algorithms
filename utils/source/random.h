#include <random>
#include <ctime>

template<typename Value_t>
class Random
{
public:
	Random(Value_t a, Value_t b) noexcept : m_engine(time(0)), m_distribution(a, b)
	{

	}

	Value_t operator()() noexcept
	{
		return m_distribution(m_engine);
	}

private:
	std::default_random_engine				m_engine;
	std::uniform_int_distribution<Value_t>	m_distribution;
};

std::vector<int> randomIntVector(size_t size, int range_beg, int range_end)
{
	std::vector<int> result;
	result.reserve(size);

	Random<int> random(range_beg, range_end);

	while (size)
	{
		result.emplace_back(random());
		--size;
	}

	return result;
}