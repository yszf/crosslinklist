#include <random>
#include <ctime>

template<typename T>
T GetRandom(T min, T max) {
	static std::default_random_engine engine(static_cast<UINT32>(time(NULL)));

	if (min <= max) {
		std::uniform_int_distribution<T> dis(min, max);
		return dis(engine);
	}
	else {
		std::uniform_int_distribution<T> dis(max, min);
		return dis(engine);
	}
}