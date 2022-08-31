#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <set>
#include <vector>
#include <time.h> 

bool is_odd(int n){
   return n % 2 != 0; 
}

const double PI {3.141592653589793238462643383279502884197169399375105820974944592308620899862803482534211706798214808651328320664};

template<typename T>
class TemplateClass; // forward declare to make function declaration possible
 
template<typename T>
void some_func( TemplateClass<T>); // declaration . Func is a template function because it has
						// template<typename T> in front of it, the compiler will
						// generate an instance for it with concrete types as template
						//arguments when needed.

template <typename T>
class TemplateClass{
    friend void some_func<T>(TemplateClass<T>  param);
public : 
     explicit TemplateClass<T>(){
      
     }
     void set_up(T param) {
         m_var = param;
     }
     void do_something(const T a, T b){
         std::cout << "Doing something with " << a << " and " << b << std::endl;
     }
private : 
     T m_var;
};

template <typename T>
void some_func(TemplateClass<T>  param){
    std::cout << "Inside some_func , accessing private data of TemplateClass : "
        << param.m_var << std::endl;
}



int main(){
    
        std::cout << "=======================" << std::endl;
        
    time_t start, end;
    
    time(&start);
    
        time_t timer;
      struct tm y2k = {0};
      double seconds1;
    
      y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
      y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
    
    double seconds0;
    seconds0 = difftime(timer,mktime(&y2k));

	TemplateClass<int> object1;
    object1.set_up(10);
    
    TemplateClass<double> object2;
    object2.set_up(12.2);
    
    some_func(object1);
    some_func(object2);
    
        std::cout << "=======================" << std::endl;
    
    
       std::vector<int> collection{2,6,8,49,64,71};
    //std::set<int> collection{2,6,8,40,64,70};
    //int collection[] {2,6,8,40,64,70};

    //std::all_of , lambda function predicate
    if (std::all_of(std::begin(collection), std::end(collection), [](int i){ return i % 2 == 0; })) {
        std::cout << "(std::all_of) :  All numbers in collection are even" << std::endl;
    }else{
        std::cout << "(std::all_of) : Not all numbers in collection are even" << std::endl;
    }

    std::cout << "------" << std::endl;

    //std::any_of ,functor as predicate 
    class DivisibleBy
    {
        private : 
            const int d;
        public : 
            DivisibleBy(int n) : d(n) {}
            bool operator()(int n) const { return n % d == 0; }
    };
 
    if (std::any_of(std::begin(collection),std::end(collection), DivisibleBy(7))) {
        std::cout << "(std::any_of) : At least one number is divisible by 7" << std::endl;
    }else{
        std::cout << "(std::any_of) : None of the numbers is divisible by 7" << std::endl;
    }

    std::cout << "-------" << std::endl;

    //std::none_of , function pointer as predicate
    if (std::none_of(std::begin(collection), std::end(collection), is_odd)) {
        std::cout << "(std::none_of) :  None of the numbers is odd" << std::endl;
    }else{
        std::cout << "(std::none_of) : At least one number is odd" << std::endl;
    }
    
        std::cout << "=======================" << std::endl;
    
        int int_data{33};
    double double_data{55};

    //References
    int& ref_int_data{int_data};
    double& ref_double_data{double_data};

    //Print stuff out
    std::cout << "int_data : " << int_data << std::endl;
    std::cout << "&int_data : " << &int_data << std::endl;
    std::cout << "double_data : " << double_data << std::endl;
    std::cout << "&double_data : " << &double_data << std::endl;

    std::cout << "=======================" << std::endl;

    std::cout << "ref_int_data : " << ref_int_data << std::endl;
    std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
    std::cout << "ref_double_data : " << ref_double_data << std::endl;
    std::cout << "&ref_double_data : " << &ref_double_data << std::endl;

    int_data = 111;
    double_data = 67.2;


    //Print stuff out
    std::cout << std::endl;
    std::cout << "int_data : " << int_data << std::endl;
    std::cout << "&int_data : " << &int_data << std::endl;
    std::cout << "double_data : " << double_data << std::endl;
    std::cout << "&double_data : " << &double_data << std::endl;

    std::cout << "=======================" << std::endl;

    std::cout << "ref_int_data : " << ref_int_data << std::endl;
    std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
    std::cout << "ref_double_data : " << ref_double_data << std::endl;
    std::cout << "&ref_double_data : " << &ref_double_data << std::endl;


    ref_int_data = 1012;
    ref_double_data = 1000.45;


   //Print stuff out
    std::cout << std::endl;
    std::cout << "int_data : " << int_data << std::endl;
    std::cout << "&int_data : " << &int_data << std::endl;
    std::cout << "double_data : " << double_data << std::endl;
    std::cout << "&double_data : " << &double_data << std::endl;

    std::cout << "=======================" << std::endl;

    std::cout << "ref_int_data : " << ref_int_data << std::endl;
    std::cout << "&ref_int_data : " << &ref_int_data << std::endl;
    std::cout << "ref_double_data : " << ref_double_data << std::endl;
    std::cout << "&ref_double_data : " << &ref_double_data << std::endl;
    
    for(size_t i=0; i<5000; i++){
            std::cout << "=======================" << std::endl;
    }
    
      time(&timer);  /* get current time; same as: timer = time(NULL)  */
    
      seconds1 = difftime(timer,mktime(&y2k));
    
      printf ("%.f seconds since January 1, 2000 in the current timezone", seconds1);

    
    time(&end);
    
    std::cout << "=======================" << std::endl;
     
     
    long double time_taken = double(end - start);
    long double time_taken1 = double(seconds0 - seconds1);
    
    std::cout << "Time taken by program is : " << std::scientific
         << time_taken << std::setprecision(10);
    
    std::cout << " sec " << std::endl;
    
        std::cout << "=======================" << std::endl;
    
        std::cout << "Time taken by program is : " << std::scientific
         << time_taken1 << std::setprecision(10);
    
    std::cout << " sec " << std::endl;
   
    return 0;
}
