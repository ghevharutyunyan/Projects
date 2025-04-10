#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Object{
    public:
    std::string name; //type name
    void* value;// value
    int cnt = 0;

    Object(std::string m_name,void * m_value, int c):name(m_name),value(m_value),cnt(c){}

    virtual ~Object() {}

    virtual std::string _str_(){
        return  "Object";
    }

    virtual Object* _add_(Object* ptr){
        throw ;
    }

    virtual Object* _minus_(Object* ptr){
        throw;
    }

     virtual Object* _multip_(Object* ptr){
        throw;
    }

     virtual Object* _div_(Object* ptr){
        throw;
    }

    virtual Object* _div_by_percent(Object* ptr){
        throw;
    }


};
//////////////  INT ////////////////////////////

class Int:Object{
    public:
    Int():Object("Amboxj", new int{0}, 0){}

    Int(int value):Object("Amboxj",new int{value},0){}

    Int(Object* ptr):Object("Amboxj", new int{0}, 0){
        if(ptr->name == "Amboxj"){
            this->value = new int{*static_cast<int*>(ptr->value)};
        }else if(ptr->name == "Irakan"){
            this->value = new int{static_cast<int>(*static_cast<double*>(ptr->value))};
        }else if(ptr->name == "Tox"){
            this->value = new int{std::stoi(*static_cast<std::string*>(ptr->value))};
        }else if(ptr->name == "Logikakan"){
            this->value = new int{*static_cast<bool*>(ptr->value)};
        }
        else{
            throw std::invalid_argument("Unsupported type");
        }

}
    
public:

    Object* _add_(Object* rptr) override{
        Int* int_ptr = dynamic_cast<Int*>(rptr);
        if(int_ptr == nullptr){
            throw std::invalid_argument("Argument type is not Int");
        }
        int result = *static_cast<int*>(this->value) + *static_cast<int*>(int_ptr->value);
        return new Int(result);
    }

    Object* _minus_(Object* rptr) override{
        Int* int_ptr = dynamic_cast<Int*>(rptr);
        if(int_ptr == nullptr){
            throw std::invalid_argument("Argument type is not Int");
        }
        int result = *static_cast<int*>(this->value) - *static_cast<int*>(int_ptr->value);
        return new Int(result);
    }

    Object* _multip_(Object* rptr) override{
        Int* int_ptr = dynamic_cast<Int*>(rptr);
        if(int_ptr == nullptr){
            throw std::invalid_argument("Argument type is not Int");
        }
        int result = (*static_cast<int*>(this->value)) * (*static_cast<int*>(int_ptr->value));
        return new Int(result);
    }

    Object* _div_(Object* rptr) override{
        Int* int_ptr = dynamic_cast<Int*>(rptr);
        if(int_ptr == nullptr){
            throw std::invalid_argument("Argument type is not Int ");
        }
        if(int_ptr->value == 0){
            throw std::runtime_error("Division by zero ");
        }
        int result = (*static_cast<int*>(this->value)) / (*static_cast<int*>(int_ptr->value));
        return new Int(result);
    }

    Object* _div_by_percent(Object* rptr) override{
        Int* int_ptr = dynamic_cast<Int*>(rptr);
        if(int_ptr == nullptr){
            throw std::invalid_argument("Argument type is not Int ");
        }
        if(int_ptr->value == 0){
            throw std::runtime_error("Division by zero ");
        }
        int result = (*static_cast<int*>(this->value)) % (*static_cast<int*>(int_ptr->value));
        return new Int(result);
    }

    std::string _str_() override {
        return "Amboxj: "  + std::to_string(*static_cast<int*>(value));
    }
 
};







////////////////////// DOUBLE ////////////////////////

class Double:Object{
    public:
    Double():Object("Irakan",new double{0.0},0){}

    Double(double m_value):Object("Irakan",new double{m_value},0){}

    Double(Object* ptr):Object("Irakan", new double{0.0}, 0){
        if(ptr->name == "Irakan"){
            this->value = new double{*static_cast<double*>(ptr->value)};
        
        }else if(ptr->name == "Amboxj"){
            this->value = new double{static_cast<double>(*static_cast<int*>(ptr->value))};
        }else if(ptr->name == "Logikakan"){
            this->value = new double{static_cast<double>(*static_cast<bool*>(ptr->value))};
        }else if(ptr->name == "Tox"){
            this->value = new double{std::stod(*static_cast<std::string*>(ptr->value))};
        }else{
            throw std::invalid_argument("Unsupported type");
        }
    }

    public:

    Object* _add_(Object* rptr) override{
        Double* double_ptr = dynamic_cast<Double*>(rptr);
        if(double_ptr == nullptr){
            throw std::invalid_argument("Argument type is not Int");
        }
        double result = *static_cast<double*>(this->value) + *static_cast<int*>(double_ptr->value);
        return new Double(result);
    }
    Object* _minus_(Object* rptr) override{
        Double* double_ptr = dynamic_cast<Double*>(rptr);
        if(double_ptr == nullptr){
            throw std::invalid_argument("Argument type is not Int");
        }
        double result = *static_cast<double*>(this->value) - *static_cast<int*>(double_ptr->value);
        return new Double(result);
    }

    Object* _multip_(Object* rptr) override{
        Double* double_ptr = dynamic_cast<Double*>(rptr);
        if(double_ptr == nullptr){
            throw std::invalid_argument("Argument type is not Irakan");
        }
        double result = (*static_cast<double*>(this->value)) * (*static_cast<double*>(double_ptr->value));
        return new Double(result);
    }

    Object* _div_(Object* rptr) override{
        Double* double_ptr = dynamic_cast<Double*>(rptr);
        if(double_ptr == nullptr){
            throw std::invalid_argument("Argument type is not Irakan ");
        }
        if(double_ptr->value == 0){
            throw std::runtime_error("Division by zero ");
        }
        double result = (*static_cast<double*>(this->value)) / (*static_cast<int*>(double_ptr->value));
        return new Double(result);
    }

    Object* _div_by_percent(Object* rptr) override{
        Double* double_ptr = dynamic_cast<Double*>(rptr);
        if(double_ptr == nullptr){
            throw std::invalid_argument("Argument type is not Irakan ");
        }
        if(double_ptr->value == 0){
            throw std::runtime_error("Division by zero ");
        }
        double result = (*static_cast<double*>(this->value)) / (*static_cast<int*>(double_ptr->value));
        return new Double(result);
    }

    std::string _str_() override {
        return "Irakan: "  + std::to_string(*static_cast<double*>(value));
    }   
};

/////////////////////////// STRING //////////////////////////////////////

class String : public Object {
public:
    String() : Object("Tox", new std::string{""}, 0) {}

    String(const std::string& m_value) : Object("Tox", new std::string{m_value}, 0) {}

    String(Object* ptr) : Object("Tox", new std::string{""}, 0) {
        if (ptr->name == "Tox") {
            this->value = new std::string{*static_cast<std::string*>(ptr->value)};
        } else if (ptr->name == "Irakan") {
            this->value = new std::string{std::to_string(*static_cast<double*>(ptr->value))};
        } else if (ptr->name == "Amboxj") {
            this->value = new std::string{std::to_string(*static_cast<int*>(ptr->value))};
        } else if (ptr->name == "bool") {
            this->value = new std::string{*static_cast<bool*>(ptr->value) ? "true" : "false"};
        } else {
            throw std::invalid_argument("Unsupported type");
        }
    }

    Object* _add_(Object* ptr) override {
        String* string_ptr = dynamic_cast<String*>(ptr);
        if (string_ptr == nullptr) {
            throw std::invalid_argument("Argument type is not String");
        }
        std::string result = *static_cast<std::string*>(this->value) + *static_cast<std::string*>(string_ptr->value);
        return new String(result);
    }
    std::string _str_() override {
        return "Tox "  + *static_cast<std::string*>(value);
    }   
};

template <typename T>
class Array:Object{
    public:
    Array():Object("Zangvac", new std::vector<Object*>{},0){}

    Array(const std::vector<Object*>& m_value):Object("Zangvac", new std::vector<Object*>{m_value},0){}

    Array(Object* ptr) : Object("Zangvac", new std::vector<Object*>{}, 0) {
        if (ptr->name == "Zangvac") {
            this->value = new std::vector<Object*>{*static_cast<std::vector<Object*>*>(ptr->value)};
        } else {
            throw std::invalid_argument("Unsupported type for array conversion");
        }
    }

    Object* _add_(Object* ptr) override{
        if(ptr->name != "Zangvac"){
            throw std::invalid_argument("Argument type is not Zangvac");
        }
        std::vector<Object*> result = *static_cast<std::vector<Object*>*>(this->value);
        std::vector<Object*> other = *static_cast<std::vector<Object*>*>(ptr->value);

        result.insert(result.end(),other.begin(),other.end());

        return new Array(result);
    }

    void push_back(Object* value) {
        std::vector<Object*>* vec = static_cast<std::vector<Object*>*>(this->value);
        vec->push_back(value);
    }



    void insert(size_t pos, Object* value) {
        std::vector<Object*>* vec = static_cast<std::vector<Object*>*>(this->value);
        if (pos >= 0 && pos <= static_cast<int>(vec->size())) {
            vec->insert(vec->begin() + pos, value);
        } else {
            throw std::out_of_range("Index out of range");
        }
    }

    void remove(size_t position) {
        std::vector<Object*>* vec = static_cast<std::vector<Object*>*>(this->value);
        if (position < 0 || position >= vec->size()) {
            throw std::out_of_range("Position out of range");
        }
        vec->erase(vec->begin() + position);
    }

    void update( size_t position, Object value) {
        std::vector<Object*>* vec = static_cast<std::vector<Object*>*>(this->value);
        if (position < 0 || position >= vec->size()) {
            throw std::out_of_range("Position out of range");
        }
        (*vec)[position] = value;
    }

    std::string _str_() override {
        std::vector<Object*> *vec = static_cast<std::vector<Object*>*>(value);
        std::string result = "Zangvac: [";
        for (size_t i = 0; i < vec->size(); ++i) {
            result += (*vec)[i]->_str_();
            if (i < vec->size() - 1) {
                result += ", ";
            }
        }
        result += "]";
        return result;
    }

};
////////////////////////////////////////////  Bool  ////////////////////////////////////////////////////////////

struct Bool:Object{
    public:
    Bool():Object("Logikakan", new bool{false}, 0){}

    Bool(bool m_value):Object("Logikakan",new bool{m_value},0){}

    Bool(Object* ptr):Object("Logikakan",new bool{false},0){
        if(ptr->name == "Logikakan"){
            this->value = new bool{*static_cast<bool*>(ptr->value)};
        
        }else if(ptr->name == "Amboxj"){
            this->value = new bool{static_cast<bool>(*static_cast<int*>(ptr->value))};
        }else if(ptr->name == "Double"){
            this->value = new bool{static_cast<bool>(*static_cast<double*>(ptr->value))};
        }else if(ptr->name == "Tox"){
            std::string val = *static_cast<std::string*>(ptr->value);
            if(val == "True"){
                this->value = new bool{true};
            }else if(val == "False"){
                this->value = new bool{false};
            }else{
                throw std::invalid_argument("Unsupported string value for boolean conversion");
            }
        }else{
            throw std::invalid_argument("Unsupported type for boolean conversion");
        }
    }
    std::string _str_() override {
        return "Bool: " + std::string(*static_cast<bool*>(value) ? "True" : "False");
    }


};

//////////////////////////////////////////// INTERPRETER  /////////////////////////////////////////////////

struct INTERPRETER{
    std::vector<std::vector<std::string>> parsed_code;
    std::unordered_map<std::string , Object*> vars;

    Object* eval(std::string){

    }

    Object* exec(std::vector<std::string>){

    }




    void run(){


    }
};






int main(){}