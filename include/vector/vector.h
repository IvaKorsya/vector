#include <random>
#include <complex>
template<class T>
class vector{
	size_t _cnt_coords;
	T* _coords;
public:
	vector(size_t cnt_coords,const T* coords) : _cnt_coords(cnt_coords), _coords(new T[_cnt_coords]) {
		for (int i = 0; i < _cnt_coords; ++i) {
			_coords[i] = coords[i];
		}
	}

	T& operator[] (size_t index){
		return _coords[index];
	}

	const T& operator[] (size_t index) const{
		return _coords[index];
	}
	//vector(size_t cnt_coords, T min_value, T max_value, bool complex=0) :_cnt_coords(cnt_coords), _coords(new T[_cnt_coords]) {
	//	std::default_random_engine rnd{ std::random_device{}() };
	//	if (std::is_same<T, int>::value) {
	//		std::uniform_int_distribution<> dist(min_value, max_value);
	//		for (int i = 0; i < _cnt_coords; ++i) {_coords[i] = dist(rnd);}
	//	}
	//	if else(std::is_same<T, std::complex<int>>::value) {
	//		std::uniform_int_distribution<> value_real_dist(min_value.real(), max_value.real());
	//		std::uniform_int_distribution<> value_imag_dist(min_value.imag(), max_value.imag());
	//		for (int i = 0; i < _cnt_coords; ++i) { _coords[i] = std::complex<int>(value_real_dist(rnd), value_imag_dist(rnd)); }
	//	}
	//	//	std::uniform_real_distribution<double> dist(lower, upper);

	//	//	double r = dist(rnd);
	//	//}
	//	
	//}
	~vector() {
		delete[] _coords;
	}
	T get_coord(int i) {
		return _coords[i];
	}
};