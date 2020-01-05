#include <Windows.h>

namespace fsk
{
class timer
{
	long long m_value;
	double m_frequency;
public:
	timer() : m_value(0) {
		LARGE_INTEGER result;
		QueryPerformanceFrequency(&result);
		m_frequency = static_cast<double>(result.QuadPart);
	}

	//返回上次的调用clock到这次调用clock的时间差
	//第一次调用clock时，由于没有上次调用所以返回值不可用。
	float clock()
	{
		LARGE_INTEGER now;
		QueryPerformanceCounter(&now);
		double result = static_cast<double>(now.QuadPart - m_value);
		m_value = now.QuadPart;
		return static_cast<float>(result / m_frequency);
	}
};
} // namespace fsk