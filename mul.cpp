#include "./mul.hpp"
#include "./json11.hpp"
unsigned int B = 10;
unsigned int X = 542351;

digit randDigit(){
    X = 443143 * X + 6412431;
    return X % B;
}

void randInteger(integer& a){
    int n = a.size();
    rep(i,n){
        a[i] = randDigit();
    }
}

inline double cpuTime(){
    return double(clock()) / CLOCKS_PER_SEC;
}


int main(){
    vector<double> school_time, karatsuba4_time, karatsuba32_time;
    for(int n = 4; n <= 65536; n *= 4){
        integer a(n), b(n);
        randInteger(a);
        randInteger(b);

        double T = cpuTime();
        int k = 0;
        while(cpuTime() - T < 1){
            mult(a,b);
            k++;
        }
        school_time.push_back((cpuTime() - T)/k);
        cout << "\n" << n << " school = " << (cpuTime() - T) / k;

        T = cpuTime();
        k = 0;
        while(cpuTime() - T < 1){
            Karatsuba(a,b,4);
            k++;
        }
        karatsuba4_time.push_back((cpuTime() - T)/k);
        cout << " Karatsuba4 = " << (cpuTime() - T) / k;
        cout.flush();

        T = cpuTime();
        k = 0;
        while(cpuTime() - T < 1){
            Karatsuba(a,b,32);
            k++;
        }
        karatsuba32_time.push_back((cpuTime() - T)/k);
        cout << " Karatsuba32 = " << (cpuTime() - T) / k;
        cout.flush();
    }
    ofstream outputfile1("json/school.json");
    outputfile1<< "var schoolTime = "<< json11::Json(school_time).dump();
    outputfile1.close();
    ofstream outputfile2("json/karatsuba4.json");
    outputfile2<< "var karatsuba4Time = " <<json11::Json(karatsuba4_time).dump();
    outputfile2.close();
    ofstream outputfile3("json/karatsuba32.json");
    outputfile3<< "var karatsuba32Time = " << json11::Json(karatsuba32_time).dump();
    outputfile3.close();
    return 0;
}
