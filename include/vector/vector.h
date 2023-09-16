template <typename T>
class vector {
	struct coordinates {
		T x, y;
	};
	coordinates* _data;
	size_t _cnt_crds;
public:
	vector(const coordinates& data,size_t count_crds);
	vector(T min_value, T max_value,size_t _count_crds);

	T& operator[](const int ind);
	const T& operator[](const int ind) const;

	vector operator+(const vector& second) const;
	vector& operator-(const vector& second) const;
	T operator*(const vector& second) const;
	vector operator*(const T) const;
	vector operator/(const T) const;
};