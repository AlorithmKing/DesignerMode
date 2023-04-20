#include <iostream>
#include <memory>
#include <optional>
#include <variant>

// 抽象产品类A
class AbstractProductA {
public:
    virtual ~AbstractProductA() = default;
    virtual void doSomethingA()  = 0;
};

// 抽象产品类B
class AbstractProductB {
public:
    virtual ~AbstractProductB() = default;
    virtual void doSomethingB()  = 0;
};

// 具体产品类A1
class ProductA1 : public AbstractProductA {
public:
    void doSomethingA()  override {
        std::cout << "ProductA1 is doing something\n";
    }
};

// 具体产品类A2
class ProductA2 : public AbstractProductA {
public:
    void doSomethingA()  override {
        std::cout << "ProductA2 is doing something\n";
    }
};

// 具体产品类B1
class ProductB1 : public AbstractProductB {
public:
    void doSomethingB()  override {
        std::cout << "ProductB1 is doing something\n";
    }
};

// 具体产品类B2
class ProductB2 : public AbstractProductB {
public:
    void doSomethingB()  override {
        std::cout << "ProductB2 is doing something\n";
    }
};

// 抽象工厂类
class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;
    virtual std::unique_ptr<AbstractProductA> createProductA()  = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB()  = 0;
};

// 具体工厂类1
class ConcreteFactory1 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA()  override {
        return std::make_unique<ProductA1>();
    }
    std::unique_ptr<AbstractProductB> createProductB()  override {
        return std::make_unique<ProductB1>();
    }
};

// 具体工厂类2
class ConcreteFactory2 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA()  override {
        return std::make_unique<ProductA2>();
    }
    std::unique_ptr<AbstractProductB> createProductB()  override {
        return std::make_unique<ProductB2>();
    }
};

int main() {
    std::unique_ptr<AbstractFactory> factory1 = std::make_unique<ConcreteFactory1>();
    auto productA1 = factory1->createProductA();
    auto productB1 = factory1->createProductB();
    productA1->doSomethingA();
    productB1->doSomethingB();
    
    std::unique_ptr<AbstractFactory> factory2 = std::make_unique<ConcreteFactory2>();
    auto productA2 = factory2->createProductA();
    auto productB2 = factory2->createProductB();
    productA2->doSomethingA();
    productB2->doSomethingB();
    
    return 0;
}
