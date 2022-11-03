#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
    ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
    TDynamicVector<int> v(10);

    ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v(4);
	v[0] = 1; v[1] = 2; v[2] = 3; v[3] = 4;
	TDynamicVector<int> a(v);
	EXPECT_EQ(a, v);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v(4);
	v[0] = 1; v[1] = 2; v[2] = 3; v[3] = 4;
	TDynamicVector<int> a(v);
	for (int i = 0; i < 4; i++)
		v[i] = 0;
	EXPECT_EQ(1, a[0]);
	EXPECT_EQ(2, a[1]);
	EXPECT_EQ(3, a[2]);
	EXPECT_EQ(4, a[3]);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
	TDynamicVector<int> v(4);
	TDynamicVector<int> a(v);
	v[0] = 4;
	a[0] = v[0];

	EXPECT_EQ(a, v);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v.at(-2));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v.at(10000));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(2);
	TDynamicVector<int> a(2);
	v[0] = 1; v[1] = 8;
	v = v;
	a[0] = 1; a[1] = 8;
	EXPECT_EQ(a, v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v(3);
	TDynamicVector<int> a(3);
	v[0] = 1; v[1] = 8; v[2] = 6;
	a = v;
	EXPECT_EQ(a, v);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v(3);
	TDynamicVector<int> a(5);
	v = a;
	EXPECT_EQ(v.size(), 5);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v(2);
	TDynamicVector<int> a(4);
	TDynamicVector<int> res(4);
	v[0] = 1; v[1] = 2;
	a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4;
	res[0] = 1; res[1] = 2; res[2] = 3; res[3] = 4;
	v = a;
	EXPECT_EQ(v, res);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v(3);
	TDynamicVector<int> a(3);
	v[0] = 3; v[1] = 6; v[2] = 10;
	a[0] = 3; a[1] = 6; a[2] = 10;
	ASSERT_TRUE(v == a);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v(3);
	v[0] = 3; v[1] = 6; v[2] = 10;
	ASSERT_TRUE(v == v);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v(3);
	TDynamicVector<int> a(4);
	v[0] = 3; v[1] = 6; v[2] = 10;
	a[0] = 3; a[1] = 6; a[2] = 9; a[3] = 0;
	ASSERT_TRUE(v != a);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> res(3);
	a[0] = 3; a[1] = 6; a[2] = 9;
	res[0] = 5; res[1] = 8; res[2] = 11;
	ASSERT_TRUE(a + 2 == res);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> res(3);
	a[0] = 3; a[1] = 6; a[2] = 9;
	res[0] = 0; res[1] = 3; res[2] = 6;
	ASSERT_TRUE((a - 3) == res);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> res(3);
	a[0] = 3; a[1] = 6; a[2] = 9;
	res[0] = 9; res[1] = 18; res[2] = 27;
	ASSERT_TRUE((a * 3) == res);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(3);
	TDynamicVector<int> res(3);
	a[0] = 3; a[1] = 6; a[2] = 9;
	b[0] = 5; b[1] = 9; b[2] = 2;
	res[0] = 8; res[1] = 15; res[2] = 11;
	EXPECT_EQ(a + b, res);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(4);
	a[0] = 3; a[1] = 6; a[2] = 9;
	b[0] = 5; b[1] = 9; b[2] = 2; b[3] = 5;
	ASSERT_ANY_THROW(a + b);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(3);
	TDynamicVector<int> res(3);
	a[0] = 3; a[1] = 6; a[2] = 9;
	b[0] = 5; b[1] = 9; b[2] = 2;
	res[0] = -2; res[1] = -3; res[2] = 7;
	EXPECT_EQ(a - b, res);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(4);
	a[0] = 3; a[1] = 6; a[2] = 9;
	b[0] = 5; b[1] = 9; b[2] = 2; b[3] = 5;
	ASSERT_ANY_THROW(a - b);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(3);
	a[0] = 3; a[1] = 6; a[2] = 9;
	b[0] = 5; b[1] = 9; b[2] = 2;
	EXPECT_EQ(a * b, 87);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(4);
	a[0] = 3; a[1] = 6; a[2] = 9;
	b[0] = 5; b[1] = 9; b[2] = 2; b[3] = 5;
	ASSERT_ANY_THROW(a * b);
}

