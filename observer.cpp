#include <iostream>
#include <string>
#include <map>
/*
#include <boost/foreach.hpp>

class SupervisedString;
class IObserver{
public:
    virtual void handleEvent(const SupervisedString&) = 0;
};


class SupervisedString{ // Observable class
    std::string _str;
    std::map<IObserver* const, IObserver* const> _observers;

    typedef std::map<IObserver* const, IObserver* const>::value_type item;

    void _Notify(){
        BOOST_FOREACH(item iter, _observers){
            iter.second->handleEvent(*this);
        }
    }

public:
    void add(IObserver& ref){
        _observers.insert(item(&ref, &ref));
    }

    void remove(IObserver& ref){
        _observers.erase(&ref);
    }

    const std::string& get() const{
        return _str;
    }

    void reset(std::string str){
        _str = str;
        _Notify();
    }
};


class Reflector: public IObserver{ // Prints the observed string into std::cout
public:
    virtual void handleEvent(const SupervisedString& ref){
        std::cout<<ref.get()<<std::endl;
    }
};

class Counter: public IObserver{  // Prints the length of observed string into std::cout
    virtual void handleEvent(const SupervisedString& ref){
        std::cout<<"length = "<<ref.get().length()<<std::endl;
    }
};

int main(){

    SupervisedString str;
    Reflector refl;
    Counter    cnt;

    str.add(refl);
    str.reset("Hello, World!");
    std::cout<<std::endl;

    str.remove(refl);
    str.add   (cnt);
    str.reset("World, Hello!");
    std::cout<<std::endl;

    return 0;
}

 //*/