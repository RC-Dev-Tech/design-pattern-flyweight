/*
 * Design Pattern - Flyweight 享元模式
 * 
 * 在這個範例中，Flyweight 是一個介面，由 ConcreteFlyweight 類別來實現。
 * ConcreteFlyweight 保存享元的共享狀態，並實現 Operation 方法。
 * FlyweightFactory 是享元的工廠類別，維護一個享元池，用於存儲已創建的享元對象。
 * 當客戶端請求一個享元時，如果池中已經存在相應的對象，則直接返回該對象，否則創建一個新的對象並將其添加到池中。
 * Client 使用 FlyweightFactory 來創建和存取 Flyweight 物件，並使用 Operation 方法操作享元的共享狀態。
 * 由於 Client 只操作享元的共享狀態，所以可以與具體的 Flyweight 實現解耦。
 * 透過享元模式，可以節省內存空間並提高系統效能，尤其是當需要創建大量具有相同內容的物件時。
 */

#include <iostream>
#include <unordered_map>

/*
 * Flyweight - 定義享元介面.
 */
class Flyweight {
public:
    virtual ~Flyweight() {}
    virtual void Operation(const std::string& extrinsicState) = 0;
};

/*
 * ConcreteFlyweight - 實現享元介面並保存共享狀態.
 */
class ConcreteFlyweight : public Flyweight {
private:
    std::string intrinsicState;

public:
    ConcreteFlyweight(const std::string& intrinsicState) : intrinsicState(intrinsicState) {}

    void Operation(const std::string& extrinsicState) override {
        std::cout << "ConcreteFlyweight: Intrinsic State = " << intrinsicState;
        std::cout << ", Extrinsic State = " << extrinsicState << std::endl;
    }
};

/*
 * FlyweightFactory - 維護享元池，用於存儲已創建的享元對象.
 */
class FlyweightFactory {
private:
    std::unordered_map<std::string, Flyweight*> flyweights;

public:
    Flyweight* GetFlyweight(const std::string& key) {
        if (flyweights.find(key) == flyweights.end()) {
            flyweights[key] = new ConcreteFlyweight(key);
        }
        return flyweights[key];
    }
};

/*
 * Client - 使用 FlyweightFactory 來創建和存取 Flyweight 物件.
 */
int main() {
    FlyweightFactory* factory = new FlyweightFactory();

    Flyweight* flyweight1 = factory->GetFlyweight("Flyweight1");
    flyweight1->Operation("Extrinsic State 1");

    Flyweight* flyweight2 = factory->GetFlyweight("Flyweight2");
    flyweight2->Operation("Extrinsic State 2");

    Flyweight* flyweight3 = factory->GetFlyweight("Flyweight1");
    flyweight3->Operation("Extrinsic State 3");

    delete factory;
    delete flyweight3; // flyweight1 跟 flyweight3 所指向的記憶位置是同一份，所以這邊刪一次就好.
    delete flyweight2;
 
    return 0;
}
