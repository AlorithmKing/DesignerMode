//
// Created by 24091 on 2023-03-31.
//

#include <iostream>
#include <memory>
#include <string>
#include <algorithm>

/*适配体的核心思想是：将一个类的接口转换成客户希望的另外一个接口。适配器让原本接口不兼容的类可以合作无间。
 *是一种结构型设计模式，它能使接口不兼容的对象能够相互合作。
 * 适配器模式的核心优点在于它可以使得原本不兼容的接口能够协同工作，从而提高代码的复用性和灵活性。
 * 此外，适配器模式也可以用来解决接口的版本升级问题，或者在开发过程中引入新的功能而不破坏现有代码的情况下进行扩展
 * */
// 目标接口
class Target {
public:
    virtual ~Target() = default;

    virtual std::string request() const {
        return "Target: The default target's behavior.";
    }
};

// 被适配的类
class Adaptee {
public:
    std::string specificRequest() const {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

// 适配器类 继承目标接口 调用需要被适配类的具体成员函数
class Adapter : public Target {
public:
    Adapter(std::shared_ptr<Adaptee> adaptee) : m_adaptee(std::move(adaptee)) {}

    std::string request() const override {
        std::string result = m_adaptee->specificRequest();
        std::reverse(result.begin(), result.end());
        return "Adapter: (TRANSLATED) " + result;
    }

private:
    std::shared_ptr<Adaptee> m_adaptee;//被适配的类
};

// 客户端代码
void clientCode(const std::shared_ptr<Target> &target) {
    std::cout << target->request() << std::endl;
}

int main() {
    std::shared_ptr<Target> target = std::make_shared<Target>();
    clientCode(target);
    std::shared_ptr<Adaptee> adaptee = std::make_shared<Adaptee>();
    std::cout << "Adaptee: " << adaptee->specificRequest() << std::endl;
    /*
     * 可以理解为 生成一个Adapter类的指针 隐式转换为Target类的指针 换句话说 Target->Adapter
     * */
    std::shared_ptr<Target> adapter = std::make_shared<Adapter>(adaptee);
    clientCode(adapter); //调用 Adapter->request()...

    return 0;
}

