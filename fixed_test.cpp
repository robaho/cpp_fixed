#define BOOST_TEST_MODULE fixed
#include <boost/test/included/unit_test.hpp>

#include "fixed.h"

BOOST_AUTO_TEST_CASE( basic_test ) {
    BOOST_TEST(std::string(Fixed("0"))=="0");
    BOOST_TEST(std::string(Fixed("0.1"))=="0.1");
    BOOST_TEST(std::string(Fixed("123.456"))=="123.456");
    BOOST_TEST(std::string(Fixed("1.123456789"))=="1.1234567");
}

BOOST_AUTO_TEST_CASE( string_view ) {
    BOOST_TEST(std::string(Fixed(std::string_view("0")))=="0");
    BOOST_TEST(std::string(Fixed(std::string_view("0.1")))=="0.1");
    BOOST_TEST(std::string(Fixed(std::string_view("123.456")))=="123.456");
    BOOST_TEST(std::string(Fixed(std::string_view("1.123456789")))=="1.1234567");
    BOOST_TEST(std::string(Fixed(std::string_view("123.456",4)))=="123");
    BOOST_TEST(std::string(Fixed(std::string_view("123.456",5)))=="123.4");
}

BOOST_AUTO_TEST_CASE(exponent ) {
    BOOST_TEST(std::string(Fixed("1.0E1"))=="10");
    BOOST_TEST(std::string(Fixed("1.0E-1"))=="0.1");
    BOOST_TEST(std::string(Fixed("1.2345E4"))=="12345");
    BOOST_TEST(std::string(Fixed("1.2345e4"))=="12345");
}

BOOST_AUTO_TEST_CASE( to_double ) {
    BOOST_TEST(double(Fixed("0.1"))==0.1);
}

BOOST_AUTO_TEST_CASE( abs_test ) {
    Fixed f("-1.5");

    BOOST_TEST(f=="-1.5");
    BOOST_TEST(f.abs()=="1.5");
}

BOOST_AUTO_TEST_CASE( stringN ) {
    BOOST_TEST(Fixed("-1.5").stringN(3)=="-1.500");
    BOOST_TEST(Fixed("1.5678").stringN(1)=="1.5");
}

BOOST_AUTO_TEST_CASE( add_subtract) {
    BOOST_TEST(Fixed("1")+Fixed("2")=="3");
    BOOST_TEST(Fixed("1")-Fixed("2")=="-1");
    BOOST_TEST(Fixed("1")+Fixed(".001")=="1.001");
    BOOST_TEST(Fixed("1")-Fixed(".001")=="0.999");
}

BOOST_AUTO_TEST_CASE( multiply_divide ) {
    BOOST_TEST(Fixed("123.456")*Fixed("1000")=="123456");
    BOOST_TEST(Fixed("123456")*Fixed("0.0001")=="12.3456");
    BOOST_TEST(Fixed("123.456")*Fixed("-1000")=="-123456");
    BOOST_TEST(Fixed("-123.456")*Fixed("-1000")=="123456");
    BOOST_TEST(Fixed("-123.456")*Fixed("-1000")=="123456");
    BOOST_TEST(Fixed("10000.1")*Fixed("10000")=="100001000");
    BOOST_TEST(Fixed("100001000")/Fixed("10000")=="10000.1");
    BOOST_TEST(Fixed("2")/Fixed("3")=="0.6666667");
    BOOST_TEST(Fixed("1000")/Fixed("10")=="100");
    BOOST_TEST(Fixed("1000")/Fixed("0.1")=="10000");
    BOOST_TEST(Fixed("1")*Fixed("0.1")=="0.1");
    BOOST_TEST(Fixed("0.000001")*Fixed("0.066248")=="0.0000001");
    BOOST_TEST(Fixed("-0.000001")*Fixed("0.066248")=="-0.0000001");
}

BOOST_AUTO_TEST_CASE( compare) {
    BOOST_TEST(Fixed("123.456")<Fixed("123.457"));
    BOOST_TEST(Fixed("123.457")>Fixed("123.456"));
}

BOOST_AUTO_TEST_CASE( nan_test) {
    BOOST_TEST(Fixed<7>::NaN()=="NaN");
}

BOOST_AUTO_TEST_CASE( different_scale ) {
    typedef Fixed<2> Fixed2;

    Fixed2 f0_2("1.23456");
    BOOST_TEST(std::string(f0_2)=="1.23");

    Fixed2 f1_2("1.23678");
    BOOST_TEST(std::string(f1_2)=="1.23");

}

BOOST_AUTO_TEST_CASE( str ) {
    char buffer[Fixed<7>::BUFFER_SIZE];

    Fixed f("1234.5678");

    f.str(buffer);

    BOOST_TEST(strcmp(buffer,"1234.5678")==0,buffer);
}

