#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
	TDynamicMatrix<int> m(5);

    ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> v(2);
	v[0][0] = 1; v[0][1] = 2; v[1][0] = 3; v[1][1] = 4;
	TDynamicMatrix<int> a(v);
	EXPECT_EQ(a, v);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> v(2);
	v[0][0] = 19; v[0][1] = 42; v[1][0] = 54; v[1][1] = 90;
	TDynamicMatrix<int> a(v);
	v[0][0] = 0; v[0][1] = 0; v[1][0] = 0; v[1][1] = 0;
	EXPECT_EQ(19, a[0][0]);
	EXPECT_EQ(42, a[0][1]);
	EXPECT_EQ(54, a[1][0]);
	EXPECT_EQ(90, a[1][1]);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> v(2);

	EXPECT_EQ(4, v.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> v(2);
	TDynamicMatrix<int> a(v);
	v[0][0] = 4;
	a[0][0] = v[0][0];

	EXPECT_EQ(a, v);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> v(2);
	ASSERT_ANY_THROW(v.at(-1, 0));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> v(2);
	ASSERT_ANY_THROW(v.at(10, 1));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> v(2);
	TDynamicMatrix<int> a(2);
	v[0][0] = 1; v[0][1] = 6;
	v[1][0] = 4; v[1][1] = 9;
	v = v;
	a[0][0] = 1; a[0][1] = 6;
	a[1][0] = 4; a[1][1] = 9;
	EXPECT_EQ(a, v);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> v(2);
	TDynamicMatrix<int> a(2);
	v[0][0] = 1; v[0][1] = 6;
	v[1][0] = 4; v[1][1] = 9;
	a = v;
	EXPECT_EQ(a, v);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> v(2);
	TDynamicMatrix<int> a(3);
	v = a;
	EXPECT_EQ(v.size(), 9);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> v(2);
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> res(3);
	v[0][0] = 1; v[0][1] = 6;
	v[1][0] = 4; v[1][1] = 9;

	a[0][0] = 5;  a[0][1] = 3;  a[0][2] = 7;
	a[1][0] = 2;  a[1][1] = 10; a[1][2] = 21;
	a[2][0] = 56; a[2][1] = 30; a[2][2] = 28;

	res[0][0] = 5;  res[0][1] = 3;  res[0][2] = 7;
	res[1][0] = 2;  res[1][1] = 10; res[1][2] = 21;
	res[2][0] = 56; res[2][1] = 30; res[2][2] = 28;

	v = a;
	EXPECT_EQ(v, res);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> v(3);
	TDynamicMatrix<int> a(3);
	a[0][0] = 5;  a[0][1] = 3;  a[0][2] = 7;
	a[1][0] = 2;  a[1][1] = 10; a[1][2] = 21;
	a[2][0] = 56; a[2][1] = 30; a[2][2] = 28;

	v[0][0] = 5;  v[0][1] = 3;  v[0][2] = 7;
	v[1][0] = 2;  v[1][1] = 10; v[1][2] = 21;
	v[2][0] = 56; v[2][1] = 30; v[2][2] = 28;
	ASSERT_TRUE(v == a);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> v(3);
	v[0][0] = 5;  v[0][1] = 3;  v[0][2] = 7;
	v[1][0] = 2;  v[1][1] = 10; v[1][2] = 21;
	v[2][0] = 56; v[2][1] = 30; v[2][2] = 28;
	ASSERT_TRUE(v == v);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> v(2);
	TDynamicMatrix<int> a(3);
	v[0][0] = 1; v[0][1] = 6;
	v[1][0] = 4; v[1][1] = 9;

	a[0][0] = 1; a[0][1] = 6; a[0][2] = 7;
	a[1][0] = 4; a[1][1] = 9; a[1][2] = 0;
	a[2][0] = 0; a[2][1] = 0; a[2][2] = 0;

	ASSERT_TRUE(v != a);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> v(3);
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> res(3);
	v[0][0] = 5;  v[0][1] = 3;  v[0][2] = 7;
	v[1][0] = 2;  v[1][1] = 10; v[1][2] = 21;
	v[2][0] = 56; v[2][1] = 30; v[2][2] = 28;

	a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
	a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
	a[2][0] = 3; a[2][1] = 4; a[2][2] = 5;

	res[0][0] = 6;  res[0][1] = 5;  res[0][2] = 10;
	res[1][0] = 6;  res[1][1] = 15; res[1][2] = 27;
	res[2][0] = 59; res[2][1] = 34; res[2][2] = 33;
	EXPECT_EQ(v + a, res);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> v(3);
	TDynamicMatrix<int> a(2);
	TDynamicMatrix<int> res(3);
	v[0][0] = 5;  v[0][1] = 3;  v[0][2] = 7;
	v[1][0] = 2;  v[1][1] = 10; v[1][2] = 21;
	v[2][0] = 56; v[2][1] = 30; v[2][2] = 28;

	a[0][0] = 1; a[0][1] = 2;
	a[1][0] = 4; a[1][1] = 5;

	ASSERT_ANY_THROW(v + a);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> v(3);
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> res(3);
	v[0][0] = 5;  v[0][1] = 3;  v[0][2] = 7;
	v[1][0] = 2;  v[1][1] = 10; v[1][2] = 21;
	v[2][0] = 56; v[2][1] = 30; v[2][2] = 28;

	a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
	a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
	a[2][0] = 3; a[2][1] = 4; a[2][2] = 5;

	res[0][0] = 4;   res[0][1] = 1;  res[0][2] = 4;
	res[1][0] = -2;  res[1][1] = 5; res[1][2] = 15;
	res[2][0] = 53;  res[2][1] = 26; res[2][2] = 23;
	ASSERT_TRUE(v - a == res);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> v(3);
	TDynamicMatrix<int> a(2);
	v[0][0] = 5;  v[0][1] = 3;  v[0][2] = 7;
	v[1][0] = 2;  v[1][1] = 10; v[1][2] = 21;
	v[2][0] = 56; v[2][1] = 30; v[2][2] = 28;

	a[0][0] = 1; a[0][1] = 2;
	a[1][0] = 4; a[1][1] = 5;

	ASSERT_ANY_THROW(v + a);
}

TEST(TDynamicMatrix, can_multiply_matrixes_with_equal_size)
{
	TDynamicMatrix<int> v(3);
	TDynamicMatrix<int> a(3);
	TDynamicMatrix<int> res(3);

	v[0][0] = 5; v[0][1] = 3; v[0][2] = 7;
	v[1][0] = 2; v[1][1] = 8; v[1][2] = 1;
	v[2][0] = 6; v[2][1] = 3; v[2][2] = 8;

	a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
	a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
	a[2][0] = 3; a[2][1] = 4; a[2][2] = 5;

	res[0][0] = 38; res[0][1] = 53; res[0][2] = 68;
	res[1][0] = 37; res[1][1] = 48; res[1][2] = 59;
	res[2][0] = 42; res[2][1] = 59; res[2][2] = 76;

	ASSERT_TRUE(v * a == res);
}

TEST(TDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> v(3);
	TDynamicMatrix<int> a(2);
	TDynamicMatrix<int> res(3);
	v[0][0] = 5;  v[0][1] = 3;  v[0][2] = 7;
	v[1][0] = 2;  v[1][1] = 10; v[1][2] = 21;
	v[2][0] = 56; v[2][1] = 30; v[2][2] = 28;

	a[0][0] = 1; a[0][1] = 2;
	a[1][0] = 4; a[1][1] = 5;

	ASSERT_ANY_THROW(v * a);
}

