/*
 * @Descripttion: 
 * @version: 1.0.0
 * @Author: CWSY
 * @Date: 2020-11-19 19:21:20
 * @LastEditors: sueRimn
 * @LastEditTime: 2020-11-19 21:17:30
 */
template<typename... Values> class Mytuple; //类模板的声明

template<>
class Mytuple<> {}; //类模板的一个特例化实现(由于都没有模板参数了，可以认为是模板全特化)

template<typename Head, typename... Tail>
class Mytuple<Head, Tail...> : private Mytuple<Tail...> //类模板的另外一个特例化实现(从参数数量上的特化,而非传统意义上的对模板类型的特化,可以认为是模板偏特化)
{   
    typedef Mytuple<Tail...> inherited;
    public:
        Mytuple() = delete;
        Mytuple(const Head& head, const Tail&... tail) : head_(head), inherited(tail...) {cout << "cur tail size: " << sizeof...(Tail) << endl;}
        ~Mytuple() {}
        const Head& head() const {return head_;}
        const inherited& tail() const {return *this;} 
        
    private:
        Head head_;
};

