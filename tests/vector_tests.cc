#include <vector/vector.h>
#include <gtest/gtest.h>
#include <iostream>
#include <complex>
//1
TEST(vector_tests,constructor_params) {
	int* i_coords = new int[2];
	float* f_coords = new float[2];
	double* d_coords = new double[2];
	std::complex<float>* cf_coords = new std::complex<float>[2];
	std::complex<double>* cd_coords = new std::complex<double>[2];
	i_coords[1] = 20;
	i_coords[0] = 0;
	f_coords[1] = (float)20.23;
	f_coords[0] = (float)0.03;
	d_coords[1] = 20.2343;
	d_coords[0] = 0.2223;
	cf_coords[0] = { 2.23, 4.45 };
	cf_coords[1] = { 2.509, 9.451 };
	cd_coords[0] = { 6.0092, 499.45757 };
	cd_coords[1] = { 2.504939, 7548.451 };
	auto i_vect = vector<int>(2,i_coords);
	auto f_vect = vector<float>(2, f_coords);
	auto d_vect = vector<double>(2, d_coords);
	auto cf_vect = vector<std::complex<float>>(2, cf_coords);
	auto cd_vect = vector<std::complex<double>>(2, cd_coords);
	ASSERT_EQ(i_vect.get_coord(1), 20);
	ASSERT_NEAR(f_vect.get_coord(0), 0.03,0.000000001);
	ASSERT_NEAR(d_vect.get_coord(1), 20.2343, 0.000000001);
	ASSERT_NEAR(cf_vect.get_coord(1).real(), 2.509, 0.001);
	ASSERT_NEAR(cd_vect.get_coord(0).imag(), 499.45757, 0.001);
	delete[] i_coords;
	delete[] f_coords;
	delete[] d_coords;
	delete[] cf_coords;
	delete[] cd_coords;
}
TEST(vector_tests, overloading_brackets) {
	int* i_coords = new int[2];
	float* f_coords = new float[2];
	double* d_coords = new double[2];
	std::complex<float>* cf_coords = new std::complex<float>[2];
	std::complex<double>* cd_coords = new std::complex<double>[2];
	i_coords[1] = 20;
	i_coords[0] = 0;
	f_coords[1] = (float)20.23;
	f_coords[0] = (float)0.03;
	d_coords[1] = 20.2343;
	d_coords[0] = 0.2223;
	cf_coords[0] = { 2.23, 4.45 };
	cf_coords[1] = { 2.509, 9.451 };
	cd_coords[0] = { 6.0092, 499.45757 };
	cd_coords[1] = { 2.504939, 7548.451 };
	auto i_vect = vector<int>(2, i_coords);
	auto f_vect = vector<float>(2, f_coords);
	auto d_vect = vector<double>(2, d_coords);
	auto cf_vect = vector<std::complex<float>>(2, cf_coords);
	auto cd_vect = vector<std::complex<double>>(2, cd_coords);
	ASSERT_EQ(i_vect[1], 20);
	ASSERT_NEAR(f_vect[0], 0.03, 0.000000001);
	ASSERT_NEAR(d_vect[1], 20.2343, 0.000000001);
	ASSERT_NEAR(cf_vect[1].real(), 2.509, 0.001);
	ASSERT_NEAR(cd_vect[0].imag(), 499.45757, 0.001);
	delete[] i_coords;
	delete[] f_coords;
	delete[] d_coords;
	delete[] cf_coords;
	delete[] cd_coords;
}
