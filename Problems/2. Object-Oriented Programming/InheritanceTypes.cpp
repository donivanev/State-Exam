#include <iostream>

// Inheritance types
// Simple   B -> A
// Hierarchical     A
//                / | \
//               B  C  D
// Multi-level      C -> B -> A
// Multiple         C -> A
//                   \
//                    B
// Hybrid

// Diamond problem - a combination of hierarchical and multiple inheritance (hybrid)
//      A
//    /   \
//   B     C
//    \   /
//      D
// The concept of virtual based classes removes the ambiguity

class A {

};

class B : virtual public A {

};

class C : virtual public B {

};

class D : public B, public C {

};

// Ways of Inheritance ???

// Parent protected -> Child protected
// Parent public -> Child public
// Granchild can access the protected and public data of Parent/Child
class Parent {};
class Child : public Parent {};
class Grandchild : public Child {};

// Parent protected -> Child protected
// Parent public -> Child protected
// Granchild can access the protected data of Parent/Child
class Parent {};
class Child : protected Parent {};
class Grandchild : public Child {};

// Parent protected -> Child private
// Parent public -> Child private
// Granchild can't access the members of the Parent class
class Parent {};
class Child : private Parent {};
class Grandchild : public Child {};

// Generalization vs Specialization