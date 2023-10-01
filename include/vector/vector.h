#include <random>
#include <complex>
#include <stdexcept>

template<class T>
class vector {
	size_t _cnt_coords;
	T* _coords;
public:
	vector() : _cnt_coords(0), _coords(nullptr) {};

	vector(size_t cnt_coords, const T* coords) : _cnt_coords(cnt_coords), _coords(new T[_cnt_coords]) {
		for (int i = 0; i < _cnt_coords; ++i) {
			_coords[i] = coords[i];
		}
	}

	vector(const vector& copy) :_cnt_coords(copy._cnt_coords), _coords(new T[_cnt_coords]) {
		for (size_t i = 0; i < _cnt_coords; ++i) {
			_coords[i] = copy[i];
		}
	}

	vector(size_t cnt_coords, double min_value, double max_value) : _cnt_coords(cnt_coords), _coords(new T[_cnt_coords]) {
		std::mt19937 re;
		std::uniform_real_distribution<double> dist(min_value, max_value);
		for (size_t i = 0; i < cnt_coords; ++i) {
			_coords[i] = dist(re);
		}
	}
	//overloaded operators
	T& operator[] (size_t index)
	{
		if (index < 0 || index >= _cnt_coords) {
			throw std::out_of_range("invalid_index");
		}
		return _coords[index];
	}

	const T& operator[] (size_t index) const
	{
		if (index < 0 || index >= _cnt_coords) {
			throw std::out_of_range("invalid_index");
		}
		return _coords[index];
	}

	vector& operator+=(const vector& second) {
		if (second._cnt_coords!=this->_cnt_coords) {
			throw std::invalid_argument("unequal_lengths");
		}
		for (size_t i = 0; i < _cnt_coords; ++i) {
			this->_coords[i] += second._coords[i];
		}
		return *this;
	}

	friend vector operator+(const vector& first,const vector& second){
		auto copy(first);
		return copy+=second;
	}

	vector& operator=(const vector& second) {
		_cnt_coords = second._cnt_coords;
		for (size_t i = 0; i < _cnt_coords; ++i) {
			_coords[i] = second[i];
		}
	}

	vector& operator-=(const vector& second) {
		if (second._cnt_coords != this->_cnt_coords) {
			throw std::invalid_argument("unequal_lengths");
		}
		for (size_t i = 0; i < _cnt_coords; ++i) {
			this->_coords[i] -= second._coords[i];
		}
		return *this;
	}

	friend vector operator-(const vector& first, const vector& second) {
		auto copy(first);
		return copy -= second;
	}

	//methods
	T get_coord(int i) {
		if (i < 0 || i >= _cnt_coords) {
			throw std::out_of_range("invalid_index");
		}
		return _coords[i];
	}

	double get_length() {
		double sum = 0;
		for(size_t i = 0; i < _cnt_coords; ++i) {
			sum += pow(_coords[i], 2);
		}
		return sqrtf(sum);
	}

	size_t get_cnt_coords() {
		return _cnt_coords;
	}

	~vector() {
		delete[] _coords;
	}
	
};

template<class T>
class vector<std::complex<T>> {
	size_t _cnt_coords;
	std::complex<T>* _coords;
public:
	vector(size_t cnt_coords, const std::complex<T>* coords) : _cnt_coords(cnt_coords), _coords(new std::complex<T>[_cnt_coords]) {
		for (int i = 0; i < _cnt_coords; ++i) {
			_coords[i] = coords[i];
		}
	}

	vector(size_t cnt_coords, double min_value, double max_value) : _cnt_coords(cnt_coords), _coords(new std::complex<T>[_cnt_coords]) {
		std::mt19937 re;
		std::uniform_real_distribution<double> dist(min_value, max_value);
		for (int i = 0; i < _cnt_coords; ++i) {
			_coords[i] = std::complex<T>(dist(re), dist(re));
		}
	}

	vector(const vector<std::complex<T>>& copy) :_cnt_coords(copy._cnt_coords), _coords(new std::complex<T>[_cnt_coords]) {
		for (size_t i = 0; i < _cnt_coords; ++i) {
			_coords[i] = copy[i];
		}
	}

	//overloaded operators
	std::complex<T>& operator[] (size_t i)
	{
		if (i < 0 || i >= _cnt_coords) {
			throw std::out_of_range("invalid_index");
		}
		return _coords[i];
	}

	const std::complex <T>& operator[] (size_t i) const
	{
		if (i < 0 || i >= _cnt_coords) {
			throw std::out_of_range("invalid_index");
		}
		return _coords[i];
	}

	vector<std::complex<T>>& operator+=(const vector<std::complex<T>>& second) {
		if (second._cnt_coords != this->_cnt_coords) {
			throw std::invalid_argument("unequal_lengths");
		}
		for (size_t i = 0; i < _cnt_coords; ++i) {
			this->_coords[i] += second._coords[i];
		}
		return *this;
	}

	friend vector<std::complex<T>> operator+(const vector<std::complex<T>>& first, const vector<std::complex<T>>& second) {
		auto copy(first);
		return copy += second;
	}

	vector<std::complex<T>>& operator-=(const vector<std::complex<T>>& second) {
		if (second._cnt_coords != this->_cnt_coords) {
			throw std::invalid_argument("unequal_lengths");
		}
		for (size_t i = 0; i < _cnt_coords; ++i) {
			this->_coords[i] -= second._coords[i];
		}
		return *this;
	}

	friend vector<std::complex<T>> operator-(const vector<std::complex<T>>& first, const vector<std::complex<T>>& second) {
		auto copy(first);
		return copy -= second;
	}

	//methods
	std::complex<T> get_length() {
		std::complex<T> sum = { 0.0, 0.0 };
		for (size_t i = 0; i < _cnt_coords; ++i) {
			sum += std::pow(_coords[i],2);
		}
		return std::sqrt(sum);
	}

	std::complex<T> get_coord(int i) {
		if (i < 0 || i >= _cnt_coords) {
			throw std::out_of_range("invalid_index");
		}
		return _coords[i];
	}

	~vector() {
		delete[] _coords;
	}
};