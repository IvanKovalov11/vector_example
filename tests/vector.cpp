#include <catch.hpp>
#include <sstream>

#include "vector.hpp"

TEST_CASE("creating vector")
{
	vector_t<int> vector;
	REQUIRE( vector.size() == 0 );
	REQUIRE( vector.capacity() == 0 );
}

TEST_CASE("copying vector")
{
	vector_t<double> vector;
	vector.push_back(0.33);

	vector_t<double> copy(vector);
	REQUIRE( copy == vector );
}

TEST_CASE("assigning vector")
{
	vector_t<int> vector1;
	vector_t<int> vector2;

	vector1.push_back(1);
	vector2.push_back(2);

	vector1 = vector2;
	REQUIRE( vector1 == vector2 );
}

TEST_CASE("equaling vector")
{
	vector_t<int> vector1;
	vector_t<int> vector2;

	vector1.push_back(1);
	vector2.push_back(1);

	REQUIRE( vector1 == vector2 );

	vector1.push_back(2);
	REQUIRE( vector1 != vector2 );
}

TEST_CASE("indexing vector")
{
	vector_t<int> vector;

	vector.push_back(1);

	REQUIRE( vector[0] == 1 );

	vector_t<int> const copy(vector);
	REQUIRE( copy[0] == 1 );
}

TEST_CASE("pushing elements")
{
	vector_t<int> vector;

	vector.push_back(1);
	REQUIRE( vector.size() == 1 );
	REQUIRE( vector.capacity() == 1 );

	vector.push_back(2);
	REQUIRE( vector.size() == 2 );
	REQUIRE( vector.capacity() == 2 );

	vector.push_back(3);
	REQUIRE( vector.size() == 3 );
	REQUIRE( vector.capacity() == 4 );

	vector.push_back(4);
	REQUIRE( vector.size() == 4 );
	REQUIRE( vector.capacity() == 4 );

	vector.push_back(5);
	REQUIRE( vector.size() == 5 );
	REQUIRE( vector.capacity() == 8 );
}

TEST_CASE("poping elements")
{
	vector_t<int> vector;

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(5);
	vector.push_back(6);

	vector.pop_back();
	REQUIRE( vector.size() == 5 );
	REQUIRE( vector.capacity() == 8 );

	vector.pop_back();
	REQUIRE( vector.size() == 4 );
	REQUIRE( vector.capacity() == 8 );

	vector.pop_back();
	REQUIRE( vector.size() == 3 );
	REQUIRE( vector.capacity() == 8 );

	vector.pop_back();
	REQUIRE( vector.size() == 2 );
	REQUIRE( vector.capacity() == 4 );

	vector.pop_back();
	REQUIRE( vector.size() == 1 );
	REQUIRE( vector.capacity() == 2 );

	vector.pop_back();
	REQUIRE( vector.size() == 0 );
	REQUIRE( vector.capacity() == 1 );
}
TEST_CASE("Range_good")
{
	vector_t<int> vector ;
	vector.push_back(2);
	REQUIRE_NOTHROW ( vector.at(0));
}
TEST_CASE("Range_bad")
{
	vector_t<int> vector ;
	vector.push_back(2);
	REQUIRE_THROWS_AS( vector.at(1) , std::out_of_range);
}
TEST_CASE("Other_type")
{
	vector_t<double> vector ;
	vector.push_back(2.1);
	REQUIRE( vector.at(0) == 2.1);
}
