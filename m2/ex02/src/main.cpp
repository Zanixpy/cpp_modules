/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 08:18:07 by omawele           #+#    #+#             */
/*   Updated: 2026/08/19 08:22:36 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
    std::cout << "\n=== " << "Basic main" << " ===" << std::endl;
    Fixed a;
    Fixed const b( Fixed(5.05f) * Fixed(2) );

    std::cout << "a = " << a << std::endl;
    std::cout << "++a = " << ++a << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "a++ = " << a++ << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;

    std::cout << "\n=== " << "comparaisons" << " ===" << std::endl;
    Fixed c(10);
    Fixed d(10);
    Fixed e(42.42f);

    std::cout << "c = " << c << ", d = " << d << ", e = " << e << std::endl;
    std::cout << "c == d : " << (c == d) << std::endl;
    std::cout << "c != d : " << (c != d) << std::endl;
    std::cout << "c <  e : " << (c <  e) << std::endl;
    std::cout << "c <= e : " << (c <= e) << std::endl;
    std::cout << "c >  e : " << (c >  e) << std::endl;
    std::cout << "c >= e : " << (c >= e) << std::endl;

    std::cout << "\n=== " << "arithmetiques" << " ===" << std::endl;
    Fixed x(2.5f);
    Fixed y(4.0f);

    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x + y = " << (x + y) << std::endl;
    std::cout << "x - y = " << (x - y) << std::endl;
    std::cout << "x * y = " << (x * y) << std::endl;
    std::cout << "y / x = " << (y / x) << std::endl;

    std::cout << "\n=== " << "in/decrement" << " ===" << std::endl;
    Fixed incDec(0);

    std::cout << "start incDec = " << incDec << std::endl;

    std::cout << "++incDec = " << ++incDec << std::endl;
    std::cout << "incDec = " << incDec << std::endl;

    std::cout << "incDec++ = " << incDec++ << std::endl;
    std::cout << "incDec = " << incDec << std::endl;

    std::cout << "--incDec = " << --incDec << std::endl;
    std::cout << "incDec = " << incDec << std::endl;

    std::cout << "incDec-- = " << incDec-- << std::endl;
    std::cout << "incDec = " << incDec << std::endl;

    std::cout << "\n=== " << "min / max" << " ===" << std::endl;
    Fixed       m1(1.5f);
    Fixed       m2(3.25f);
    Fixed const cm1(1.5f);
    Fixed const cm2(3.25f);

    std::cout << "m1 = " << m1 << ", m2 = " << m2 << std::endl;
    std::cout << "min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;
    std::cout << "max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;

    std::cout << "cm1 = " << cm1 << ", cm2 = " << cm2 << std::endl;
    std::cout << "min(cm1, cm2) = " << Fixed::min(cm1, cm2) << std::endl;
    std::cout << "max(cm1, cm2) = " << Fixed::max(cm1, cm2) << std::endl;

    return 0;
}
