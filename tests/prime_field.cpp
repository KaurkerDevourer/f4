#include "../lib/util/prime_field.h"
#include "testing.h"
#include <iostream>
#include <cassert>

void test_prime_field() {
    NUtils::PrimeField<7> p(3);
    NUtils::PrimeField<7> q(2);
    ASSERT_EQUAL(p * p, q);
    NUtils::PrimeField<7> s(6);
    ASSERT_EQUAL(p * q, s);
    ASSERT_EQUAL(p + p, s);
    ASSERT_EQUAL(q + q + q, s);

    ASSERT_EQUAL(s / p, q);
    ASSERT_EQUAL(s / q, p);

    NUtils::PrimeField<7> f(5);
    NUtils::PrimeField<7> o(1);
    ASSERT_EQUAL(p + q, f);
    ASSERT_EQUAL(f * p, o);
    ASSERT_EQUAL(f * q, p);


    NUtils::PrimeField<7> c(4);
    ASSERT_EQUAL(f / p, c);
    ASSERT_EQUAL(p / q, f);
    ASSERT_EQUAL(-c, p);
    ASSERT_EQUAL(p - q, o);

    NUtils::PrimeField<7> m(-1);

    ASSERT_EQUAL(m, s);

    //NUtils::PrimeField<6> check_not_prime_module(1);

    std::cout << "Successfully tested Prime field" << std::endl;
}