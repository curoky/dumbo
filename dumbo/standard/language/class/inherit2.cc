#include <catch2/catch.hpp>

#include <iostream>
#include <memory>

/*
class A {
 public:
  ~A() { std::cout << "~A" << std::endl; }
};

class B : A {
 public:
  ~B() { std::cout << "~B" << std::endl; }
};

class C : B {
 public:
  // virtual ~C() = default;
};

TEST_CASE("[Inherit2]: example") {
  std::cout << "" << std::endl;
  std::shared_ptr<C> c_ptr = std::make_shared<C>();
}
/**/

// class TTransport {
//  public:
//    ~TTransport() { std::cout << "~TTransport" << std::endl; }
//   virtual void close() {
//     std::cout << "TTransport::close" << std::endl;
//     // throw TTransportException(TTransportException::NOT_OPEN, "Cannot close base TTransport.");
//   }
//   virtual void open() {
//     std::cout << "TTransport::open" << std::endl;
//     // throw TTransportException(TTransportException::NOT_OPEN, "Cannot close base TTransport.");
//   }
// };
// class TTransportDefaults : public TTransport {
//  protected:
//   TTransportDefaults() {}
// };

// class TVirtualTransport : public TTransportDefaults {
//  protected:
//   TVirtualTransport() {}
// };

// class TSocket : public TVirtualTransport {
//  public:
//   TSocket() {}
//   // ~TSocket() override;
//   ~TSocket();
//   // virtual void close() { std::cout << "TSocket::close" << std::endl; }
//   void close() override { std::cout << "TSocket::close" << std::endl; }
//   void open() override { std::cout << "TSocket::open" << std::endl; }
// };

// TSocket::~TSocket() {
//   close();
//   std::cout << "~TSocket" << std::endl;
// }

// class ThriftSocket : public TSocket {
//  public:
//   ThriftSocket() {}
//   virtual void open() override {}
// };

// TEST_CASE("[Inherit2]: example") {
//   std::cout << "" << std::endl;
//   std::shared_ptr<ThriftSocket> c_ptr = std::make_shared<ThriftSocket>();
//   // c_ptr->close();
// }
